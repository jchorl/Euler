


public class p23 {
	public static boolean abundant(int n){
		int sum= 1;
		for(int i= 2; i<=Math.sqrt(n); i++){
			if(n%i==0){
				sum+=i;
				if(n/i!=i){
					sum+=(n/i);
				}
			}
		}
		if(sum>n){
			return true;
		}
		return false;
	}
	public static void main(String[] args){
		int[] numbers= new int[28124];
		for(int i= 1; i<numbers.length; i++){
			if(abundant(i)){
				numbers[i]= 1;
			}
			else{
				numbers[i]= 0;
			}
		}
		int[] sums= new int[28124];
		for(int i= 1; i<numbers.length; i++){
			if(numbers[i]==1){
				for(int j= i; j<numbers.length; j++){
					if(numbers[j]==1){
						if(i+j<28124){
							sums[i+j]= 1;
						}
					}
				}
			}
		}
		long sum= 0;
		for(int i= 1; i<sums.length; i++){
			if(sums[i]==0){
				sum+=i;
			}
		}
		System.out.println(sum);
	}
}
