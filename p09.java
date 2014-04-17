
public class p09 {
	public static void main(String[] args){
		double a, b, c;
		for(a= 1; a<500; a++){
			for(b= 1; b<500; b++){
				c= Math.sqrt(Math.pow(a, 2)+Math.pow(b, 2));
				if(a+b+c==1000){
					System.out.println(a*b*c);
				}
			}
		}
	}
}
