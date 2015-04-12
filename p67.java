import java.io.BufferedReader;
import java.io.FileReader;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class p67 {
	public static int sum(List<List<Integer>> a){
		for(int i = a.size() - 2; i >= 0; i--){
			for(int j = 0; j < a.get(i).size(); j++){
				if(a.get(i + 1).get(j)>a.get(i + 1).get(j + 1)){
					a.get(i).set(j, a.get(i).get(j) + a.get(i + 1).get(j));
				}
				else{
					a.get(i).set(j, a.get(i).get(j) + a.get(i + 1).get(j + 1));
				}
			}
		}

		return a.get(0).get(0);
	}

	public static void main(String[] args) {
		List<List<Integer>> pyramid = new ArrayList<>();
		try(BufferedReader br = new BufferedReader(new FileReader("triangle.txt"))) {
			for(String line; (line = br.readLine()) != null; ) {
				pyramid.add(new ArrayList<Integer>(
							Arrays.stream(line.split("\\s+"))
							.map(Integer::parseInt)
							.collect(Collectors.toList()))
						);
			}
			System.out.println(sum(pyramid));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
