package p1;

public class Q53 {
	public static void main(String args[]) {
		String str = "1, 2, 3, 4, 5";   
		
		String arr[] = str.split(", ");
		int sum = 0;
		for(String s : arr) {
			sum += Integer.parseInt(s);
			System.out.println(s);
		}
		System.out.println(sum);
	}	
}
