import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.Collections;
import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;
import java.util.TreeMap;
import java.util.SortedMap;
import java.util.stream.Collectors;


public class p54 {
	private static String vals = "23456789TJQKA";

	public static void read(File file){
		try{
			BufferedReader br = new BufferedReader(new FileReader(file));
			String line;
			int p1 = 0;
			while ((line = br.readLine()) != null) {
				List<Card> hands = parseLine(line);
				Hand h1 = new Hand(hands.subList(0, 5));
				Hand h2 = new Hand(hands.subList(5, 10));
				int h1val = h1.getHandVal();
				int h2val = h2.getHandVal();

				if(h1val > h2val){
					p1++;
				}
				else if(h1val == h2val){
					List<Integer> h1tieBreakers = h1.getTieBreakers();
					List<Integer> h2tieBreakers = h2.getTieBreakers();

					for(int i = 0; i < h1tieBreakers.size(); i++){
						if(h1tieBreakers.get(i) > h2tieBreakers.get(i)){
							p1++;
							break;
						}
						else if(h1tieBreakers.get(i) < h2tieBreakers.get(i)){
							break;
						}
					}
				}
			}
			br.close();
			System.out.println(p1);
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	public static List<Card> parseLine(String line) {
		List<Card> hands = new ArrayList<Card>();
		String handString[] = line.split("\\s");
		for(String str:handString){
			Card c = new Card(str.charAt(0), str.charAt(1));
			hands.add(c);
		}
		return hands;
	}

	public static void main(String[] args){
		read(new File("poker.txt"));

	}

	static class Card {
		private int val;
		private int suit;
		public Card(char val, char suit) {
			this.val = vals.indexOf(val);
			this.suit = (int)suit;
		}

		public int getVal() {
			return val;
		}

		public int getSuit() {
			return suit;
		}

		@Override
		public boolean equals(Object other){
			return this.getVal() == ((Card)other).getVal();
		}

		@Override
		public int hashCode(){
			return val;
		}
	}

	static class Hand {
		private static final int HIGH_CARD = 0;
		private static final int PAIR = 1;
		private static final int TWO_PAIR = 2;
		private static final int THREE_OF_A_KIND = 3;
		private static final int STRAIGHT = 4;
		private static final int FLUSH = 5;
		private static final int FULL_HOUSE = 6;
		private static final int FOUR_OF_A_KIND = 7;
		private static final int STRAIGHT_FLUSH = 8;
		private List<Integer> tieBreakers;

		private int value = -1;

		private List<Card> cards;

		public Hand() {
			cards = new ArrayList<Card>();
		}

		public Hand(List<Card> cards) {
			setCards(cards);
		}

		public void addCard(Card c) {
			cards.add(c);
		}

		private void setCards(List<Card> cards) {
			this.cards = cards;
		}

		public int getHandVal(){
			boolean straight = straight();
			boolean flush = flush();
			if(straight && flush){
				value = STRAIGHT_FLUSH;
			}
			if(!pairs() && !straight && !flush){
				value = HIGH_CARD;
				tieBreakers = sortByVal().stream().mapToInt(c -> c.getVal()).boxed().collect(Collectors.toList());
			}
			return value;
		}

		public List<Integer> getTieBreakers(){
			return tieBreakers;
		}

		private List<Card> sortByVal(){
			Collections.sort(cards, BY_VAL);
			return cards;
		}

		private List<Card> sortBySuit(){
			Collections.sort(cards, BY_SUIT);
			return cards;
		}

		private boolean flush(){
			boolean flush = cards.parallelStream().allMatch((Card c) -> c.getSuit() == cards.get(0).getSuit());
			if(flush && value < FLUSH){
				tieBreakers = sortByVal().stream().mapToInt(c -> c.getVal()).boxed().collect(Collectors.toList());
				value = FLUSH;
			}
			return flush;
		}

		private boolean straight(){
			List<Card> sorted = sortByVal();
			for(int i = 1; i < sorted.size(); i++){
				if(sorted.get(i).getVal() != sorted.get(i-1).getVal()-1){
					return false;
				}
			}

			if(value < STRAIGHT){
				value = STRAIGHT;
				tieBreakers = sorted.stream().mapToInt(c -> c.getVal()).boxed().collect(Collectors.toList());
				return true;
			}
			else{
				return false;
			}
		}

		private boolean pairs(){
			//map of frequencies, <cardVal, frequency>
			//this will be in descending order sorted by key
			SortedMap<Integer, Integer> frequencies = new TreeMap<>(Collections.reverseOrder());

			//get all frequencies
			for(int i = 0; i < 4; i++){

				//ensure that the card has not already been counted in a fequency
				if(!frequencies.containsKey(cards.get(i).getVal())){

					//get frequency
					int freq = Collections.frequency(cards, cards.get(i));


					if(freq > 1){
						//put it in map with card val
						frequencies.put(cards.get(i).getVal(), freq);
					}
				}
			}

			if(frequencies.size() == 1){
				int cardVal = frequencies.firstKey();
				int freq = frequencies.get(cardVal);
				if(freq == 4 && value < FOUR_OF_A_KIND){
					value = FOUR_OF_A_KIND;
				}
				else if(freq == 3 && value < THREE_OF_A_KIND){
					value = THREE_OF_A_KIND;
				}
				else if(freq == 2 && value < PAIR){
					value = PAIR;
				}
				tieBreakers = new ArrayList<>();
				tieBreakers.add(cardVal);
				cards.stream().filter(c -> c.getVal() != cardVal).sorted(BY_VAL).forEach(c -> tieBreakers.add(c.getVal()));
				return true;
			}
			else if(frequencies.size() == 2){
				int higherVal = frequencies.firstKey();
				int freqForHigherVal = frequencies.get(higherVal);
				int lowerVal = frequencies.lastKey();
				int freqForLowerVal = frequencies.get(lowerVal);
				tieBreakers = new ArrayList<>();
				if(freqForHigherVal != freqForLowerVal && value < FULL_HOUSE){
					value = FULL_HOUSE;
					if(freqForHigherVal > freqForLowerVal){
						tieBreakers.add(higherVal);
						tieBreakers.add(lowerVal);
					}
					else{
						tieBreakers.add(lowerVal);
						tieBreakers.add(higherVal);
					}
				}
				else if(freqForHigherVal == freqForLowerVal && value < TWO_PAIR){
					value = TWO_PAIR;
					tieBreakers.add(higherVal);
					tieBreakers.add(lowerVal);
				}
				cards.stream().filter(c -> c.getVal() != higherVal && c.getVal() != lowerVal).sorted(BY_VAL).forEach(c -> tieBreakers.add(c.getVal()));
				return true;
			}
			else{
				return false;
			}
		}
	}

	static final Comparator<Card> BY_VAL = new Comparator<Card>() {
		public int compare(Card c1, Card c2){
			return c2.getVal() - c1.getVal();
		}
	};

	static final Comparator<Card> BY_SUIT = new Comparator<Card>() {
		public int compare(Card c1, Card c2){
			return c1.getSuit() - c2.getSuit();
		}
	};
}
