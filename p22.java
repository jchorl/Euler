import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.Arrays;


public class p22 {
	public static String[] read(File file, int num){
		String[] names= new String[5163];
		try{
			BufferedReader br = new BufferedReader(new FileReader(file));
			String line;
			int i= 0;
			while ((line = br.readLine()) != null) {
				names[i]= line;
				i++;
			}
			br.close();
		}catch(Exception e){}
		return names;
	}
	public static void main(String[] args){
		File f= new File("names.txt");
		int lines= 5163;
		String[] names= read(f, lines);
		Arrays.sort(names);
		long total= 0;
		for(int i= 0; i<names.length; i++){
			int sum= 0;
			for(char s:names[i].toLowerCase().toCharArray()){
				sum+= (s-'a'+1);
			}
			sum*=(i+1);
			total+=sum;
		}
		System.out.println(total);
	}
}
