
public class p02 {
	public static long f(long n){
		if(n==1){
			return 1;
		}
		if(n==2){
			return 2;
		}
		return f(n-1)+f(n-2);
	}
	public static void main(String[] args){
		long sum= 0;
		for(long i= 1; f(i)<=4000000; i++){
			if(f(i)%2==0){
				sum+=f(i);
			}
		}
		System.out.println(sum);
	}
}
