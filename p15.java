
public class p15 {
	private static long remaining[];
	public static long latticePaths(int down, int right){
		if(down==1){
			return right+1;
		}
		if(right==1){
			return down+1;
		}
		int cantor = ((down+right)*(down+right+1))/2+Math.min(down,right);
		if(remaining[cantor]==0){
			long lat = 0;
			if(down==right){
				lat = 2*latticePaths(down-1, right);
			}
			else{
				lat = latticePaths(down-1, right)+latticePaths(down, right-1);
			}
			remaining[cantor] = lat;
			return lat;
		}
		else{
			return remaining[cantor];
		}
	}
	public static void main(String[] args) {
		remaining = new long[1000];
		for(int i = 0; i<remaining.length; i++){
			remaining[i] = 0;
		}
		System.out.println(latticePaths(20,20));
	}

}
