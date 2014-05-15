import java.util.ArrayList;
import java.util.Collections;
public class p24{
	private static ArrayList<Character> chars;
	public static void permute(){
		for(int i = 0; i < chars.size(); i++){
			boolean sorted = true;
			for(int j = i; j < chars.size()-1; j++){
				if(chars.get(j)<chars.get(j+1)){
					sorted = false;
				}
			}
			if(i==(chars.size()-1)){
				Character temp = chars.get(chars.size()-1);
				chars.set(chars.size()-1, chars.get(chars.size()-2));
				chars.set(chars.size()-2, temp);
			}
			else if(sorted){
				Character nextGreatest = '9';
				int location = -1;
				for(int j = i; j < chars.size(); j++){
					if(chars.get(j)>chars.get(i-1)&&chars.get(j)<=nextGreatest){
						nextGreatest = chars.get(j);
						location = j;
					}
				}
				chars.set(location, chars.get(i-1));
				chars.set(i-1, nextGreatest);
				Collections.sort(chars.subList(i, chars.size()));
				break;
			}
		}
	}
	public static void main(String[] args){
		chars = new ArrayList<Character>();
		for(int i = 0; i<10; i++){
			chars.add((char)(i+'0'));
		}
		for (int i = 0; i < 999999; i++) {
			permute();
		}
		System.out.println(chars);
	}
}
