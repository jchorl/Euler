import java.math.BigInteger;


public class p16 {
	public static void main(String[] args) {
		BigInteger initial= (new BigInteger("2")).pow(1000);
		BigInteger sum= new BigInteger("0");
		for(char s:initial.toString().toCharArray()){
			String str= ""+s;
			sum= sum.add(new BigInteger(str));
		}
		System.out.println(sum);
	}

}
