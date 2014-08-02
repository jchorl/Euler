import java.math.BigInteger;
import java.util.HashSet;
import java.util.Iterator;
public class p53 {
	public static BigInteger computeFraction(HashSet<Integer> n, HashSet<Integer> r, HashSet<Integer> nmr){
		Iterator<Integer> it = n.iterator();
		while(it.hasNext()){
			int curr = it.next();
			boolean contains = r.contains(curr);
			if(contains){
				it.remove();
				r.remove(curr);
			}
			else{
				contains = nmr.contains(curr);
				if(contains){
					it.remove();
					nmr.remove(curr);
				}
			}
		}
		BigInteger totalNum = BigInteger.ONE;
		BigInteger totalDen = BigInteger.ONE;
		for(it = n.iterator(); it.hasNext();){
			totalNum = totalNum.multiply(BigInteger.valueOf(it.next()));
		}
		for(it = r.iterator(); it.hasNext();){
			totalDen = totalDen.multiply(BigInteger.valueOf(it.next()));
		}
		for(it = nmr.iterator(); it.hasNext();){
			totalDen = totalDen.multiply(BigInteger.valueOf(it.next()));
		}
		return totalNum.divide(totalDen);
	}
	public static void main(String[] args){
		int count = 0;
		BigInteger mil = new BigInteger("1000000");
		for(int n = 23; n <= 100; n++){
			for(int r = 1; r <= n; r++){
				HashSet<Integer> nfacs = new HashSet<Integer>();
				HashSet<Integer> rfacs = new HashSet<Integer>();
				HashSet<Integer> nmrfacs = new HashSet<Integer>();
				for(int i = 1; i <= n; i++){
					nfacs.add(i);
				}
				for(int i = 1; i <= r; i++){
					rfacs.add(i);
				}
				for(int i = 1; i <= n-r; i++){
					nmrfacs.add(i);
				}
				if(computeFraction(nfacs, rfacs, nmrfacs).compareTo(mil)>0){
					count++;
				}
			}
		}
		System.out.println(count);
	}
}


	
