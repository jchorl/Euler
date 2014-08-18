import java.math.BigInteger;
public class p57 {
	public static void main(String[] args){
		int count = 0;
		Fraction prev = new Fraction(BigInteger.ZERO, BigInteger.ONE);
		for(int i = 0; i < 1000; i++){
			Fraction total = new Fraction(prev.getNum(), prev.getDen());
			total.add(new Fraction(BigInteger.valueOf(2), BigInteger.valueOf(1)));
			total.reciprocal();
			prev = new Fraction(total.getNum(), total.getDen());
			total.add(new Fraction(BigInteger.valueOf(1), BigInteger.valueOf(1)));
			if(total.getNum().toString().length() > total.getDen().toString().length()){
				count++;
			}
		}
		System.out.println(count);
	}

	static class Fraction {
		private BigInteger num;
		private BigInteger den;

		public Fraction(BigInteger num, BigInteger den){
			this.num = num;
			this.den = den;
		}

		public BigInteger getNum(){
			return num;
		}

		public BigInteger getDen(){
			return den;
		}

		public void setNum(BigInteger num){
			this.num = num;
		}

		public void setDen(BigInteger den){
			if(den.compareTo(BigInteger.ZERO) == 0){
				System.out.println("Cannot set 0 denominator");
			}
			else{
				this.den = den;
			}
		}

		public Fraction add(Fraction f){
			setNum(getNum().multiply(f.getDen()).add(f.getNum().multiply(getDen())));
			setDen(getDen().multiply(f.getDen()));
			return reduce();
		}

		public Fraction reciprocal(){
			BigInteger temp = getNum();
			setNum(getDen());
			setDen(temp);
			return this;
		}

		public Fraction reduce(){
			BigInteger a = getNum().abs();
			BigInteger b = getDen().abs();
			BigInteger temp;
			while(b.compareTo(BigInteger.ZERO) != 0){
				temp = a.mod(b);
				a = b;
				b = temp;
			}
			setNum(getNum().divide(a));
			setDen(getDen().divide(a));
			if((getNum().compareTo(BigInteger.ZERO) < 0 && getDen().compareTo(BigInteger.ZERO) < 0)||(getDen().compareTo(BigInteger.ZERO) < 0 && getNum().compareTo(BigInteger.ZERO) > 0)){
				setNum(getNum().divide(BigInteger.valueOf(-1)));
				setDen(getDen().divide(BigInteger.valueOf(-1)));
			}
			return this;
		}
	}
}