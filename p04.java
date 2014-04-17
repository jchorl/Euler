import java.util.ArrayList;


public class p04 {
	public static boolean checkPalindrome(Integer n){
		if(n.toString().equals(((new StringBuilder(n.toString())).reverse().toString()))){
			return true;
		}
		return false;
	}
	public static void main(String[] args){
		ArrayList<Integer> all= new ArrayList<Integer>();
		for(int i= 999; i>=100; i--){
			for(int q= 999; q>=100; q--){
				if(checkPalindrome(q*i)){
					all.add(q*i);
				}
			}
		}
		int max= 0;
		for(int i= 0; i<all.size(); i++){
			if(all.get(i)>max){
				max= all.get(i);
			}
		}
		System.out.println(max);
	}
}
