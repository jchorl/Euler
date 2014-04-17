
public class p14 {
	public static long collatz(long n){
		if(n%2==0){
			return n/2;
		}
		return 3*n+1;
	}
	public static void main(String[] args){
		int startingNum= 0;
		int maxCount= 0;
		for(int i= 2; i<1000000; i++){
			int count= 0;
			long n= i;
			while(n!=1){
				n= collatz(n);
				count++;
			}
			if(count>maxCount){
				maxCount= count;
				startingNum= i;
			}
		}
		System.out.println(startingNum);
	}
}
