
public class p19 {
	public static boolean isLeap(int year){
		if(year%400==0){
			return true;
		}
		else if(year%100==0){
			return false;
		}
		else if(year%4==0){
			return true;
		}
		return false;
	}
	public static void main(String[] args){
		int[] days= {31,28,31,30,31,30,31,31,30,31,30,31};
		int total= 2;
		int count= 0;
		for(int i= 0; i<1199; i++){
			int year= i/12+1901;
			int month= i%12;
			if(month==1&&isLeap(year)){
				total+=29;
			}
			else{
				total+=days[month];
			}
			total%=7;
			if(total==0){
				count++;
			}
		}
		System.out.println(count);
	}
}
