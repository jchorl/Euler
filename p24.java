public class p24{
	public static boolean check(long i){
		String str= Long.toString(i);
		if(i<1000000000){
			if(str.contains("1")&&str.contains("2")&&str.contains("3")&&str.contains("4")&&str.contains("5")&&str.contains("6")&&str.contains("7")&&str.contains("8")&&str.contains("9")){
				return true;
			}
			return false;
		}
		else{
			if(str.contains("0")&&str.contains("1")&&str.contains("2")&&str.contains("3")&&str.contains("4")&&str.contains("5")&&str.contains("6")&&str.contains("7")&&str.contains("8")&&str.contains("9")){
				return true;
			}
			return false;
		}
	}
	public static void main(String[] args){
		long original= 123456789;
		for(int i= 1; i<1000000; i++){
			original++;
			while(!check(original)){
				original++;
			}
		}
		System.out.println(original);
	}
}
