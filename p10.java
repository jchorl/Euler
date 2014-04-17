public class p10 {

	public static void main(String[] args) {
		long[] primes= new long[2000000];
		primes[0]= 0;
		primes[1]= 0;
		for(int i= 0; i<primes.length; i++){
			primes[i]= 1;
		}
		long sum= 0;
		for(int i= 2; i<primes.length; i++){
			if(primes[i]==1){
				sum+=i;
				for(int q= 2*i; q<primes.length; q+=i){
					primes[q]= 0;
				}
			}
		}
		System.out.println(sum);
	}

}
