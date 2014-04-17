
public class p15 {
	public static long latticePaths(long down, long right){
		if(down==1){
			return right+1;
		}
		if(right==1){
			return down+1;
		}
		return latticePaths(down-1, right)+latticePaths(down, right-1);
	}
	public static void main(String[] args) {
		System.out.println(latticePaths(20,20));
	}

}
