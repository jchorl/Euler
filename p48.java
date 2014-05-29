import java.math.BigInteger;
public class p48 {
	public static void main(String[] args){
		boolean found = false;
		BigInteger total = BigInteger.ZERO;
		BigInteger thou = new BigInteger("1001");
		for(BigInteger i = new BigInteger("1"); i.compareTo(thou)==-1; i = i.add(BigInteger.ONE)){
			total = total.add(i.pow(i.intValue()));
		}
		System.out.println(total.toString().substring(total.toString().length()-10, total.toString().length()));
	}
}
