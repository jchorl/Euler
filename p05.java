
public class p05 {
	public static void main(String[] args){
		int num= 2520;
		int[] onetotwenty= {11,12,13,14,15,16,17,18,19,20};
		while(true){
			boolean divisible= true;
			for(int i:onetotwenty){
				if(num%i!=0){
					divisible= false;
				}
			}
			if(divisible){
				break;
			}
			else{
				num++;
			}
		}
		System.out.println(num);
	}
}
