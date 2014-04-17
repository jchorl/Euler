
public class p06 {
	public static void main(String[] args){
		int sumofsquares= 0;
		for(int i= 1; i<101; i++){
			sumofsquares+=(int)Math.pow(i, 2);
		}
		int squareofsums= 0;
		for(int i= 1; i<101; i++){
			squareofsums+=i;
		}
		squareofsums= (int)Math.pow(squareofsums, 2);
		System.out.println(squareofsums-sumofsquares);
	}
}
