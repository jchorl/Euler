import java.util.Vector;


public class p07 {
	public static void main(String[] args){
		Vector<Integer> primes= new Vector<Integer>();
		int[] all= new int[4000000];
		for(int i= 0; i<all.length; i++){
			all[i]= 1;
		}
		for(int i= 2; i<all.length; i++){
			if(all[i]==1){
				primes.add(i);
				for(int j= i*2; j<all.length; j+=i){
					all[j]= 0;
				}
			}
		}
		System.out.println(primes.get(10000));
	}
}
