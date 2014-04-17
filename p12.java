import java.util.ArrayList;


public class p12 {
	public static int triangle(int n){
		int sum= 0;
		for(int i= 1; i<=n; i++){
			sum+=i;
		}
		return sum;
	}
	public static ArrayList<Integer> factors(int n){
		ArrayList<Integer> f= new ArrayList<Integer>();
		for(int i= 1; i<=Math.sqrt(n); i++){
			if(n%i==0){
				f.add(i);
				f.add(n/i);
			}
		}
		return f;
	}
	public static void main(String[] args) {
		boolean found= false;
		int n= 1;
		while(!found){
			if(factors(triangle(n)).size()>500){
				System.out.println(triangle(n));
				found= true;
			}
			else{
				n++;
			}
		}
	}

}
