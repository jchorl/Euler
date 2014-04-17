
public class p21 {
	public static int d(int n){
		int sum= 1;
		for(int i= 2; i<=Math.sqrt(n); i++){
			if(n%i==0){
				sum+=i;
				sum+=(n/i);
			}
		}
		return sum;
	}
	public static boolean checkAmicable(int n){
		if(d(d(n))==n&&d(n)!=n){
			return true;
		}
		return false;
	}
	public static void main(String[] args){
		int sum= 0;
		for(int i= 1; i<10000; i++){
			if(checkAmicable(i)){
				sum+=i;
			}
		}
		System.out.println(sum);
	}
}
