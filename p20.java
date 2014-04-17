import java.math.BigInteger;

public class p20 {
public static BigInteger factorial(BigInteger i){
	if(i.equals(new BigInteger("1"))){
		return new BigInteger("1");
	}
	else{
		return i.multiply(factorial(i.subtract(new BigInteger("1"))));
	}
}
	public static void main(String[] args){
		BigInteger i= new BigInteger("100");
		int sum= 0;
		for(char a:factorial(i).toString().toCharArray()){
			sum+=Character.getNumericValue(a);
		}
		System.out.println(sum);
	}
}
