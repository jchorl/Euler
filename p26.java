import java.util.ArrayList;
import java.math.BigInteger;
public class p26{
	public static ArrayList<Integer> primes(){
		int[] candidates= new int[999];
		candidates[0]= 0;
		candidates[1]= 0;
		for(int i= 2; i<candidates.length; i++){
			candidates[i]= 1;
		}
		for(int i= 2; i<candidates.length; i++){
			if(candidates[i]==1){
				for(int j= i*2; j<candidates.length; j+=i){
					candidates[j]= 0;
				}
			}
		}
		candidates[2]= 0;
		candidates[5]= 0;//must be coprime with 10
		ArrayList<Integer> p= new ArrayList<Integer>();
		for(int i= 2; i<candidates.length; i++){
			if(candidates[i]==1){
				p.add(i);
			}
		}
		return p;
	}
	//returns the period of 1/p
	public static int period(int p){
		int period;
		for(period= 1; !BigInteger.TEN.modPow(new BigInteger(Integer.toString(period)), new BigInteger(Integer.toString(p))).equals(BigInteger.ONE); period++){}
		return period;
	}
	public static void main(String[] args){
		ArrayList<Integer> p= primes();
		int maxP= 0;
		int number= 0;
		for(int i= 0; i<p.size(); i++){
			int period= period(p.get(i));
			if(period>maxP){
				maxP= period;
				number= p.get(i);
			}
		}
		System.out.println("Max period: " + maxP + ", Number: " + number);
	}
}
