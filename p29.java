import java.math.BigInteger;
import java.util.Set;
import java.util.HashSet;
public class p29{
	public static void main(String[] args){
		Set<BigInteger> permutations= new HashSet<BigInteger>();
		for(int a= 2; a<101; a++){
			for(int b= 2; b<101; b++){
				permutations.add((new BigInteger(Integer.toString(a))).pow(b));
			}
		}
		System.out.println(permutations.size());
	}
}
