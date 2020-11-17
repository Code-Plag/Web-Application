package p1;

import java.util.Scanner;

public class Q56 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String str = sc.nextLine();
		String arr[] = str.split("\\s+");
		
		for( int i = 0 ; i < arr.length ; i++ ) {
			if( arr[i].length() > 1 )
				arr[i] = arr[i].substring(0,1).toUpperCase() + arr[i].substring(1) + " ";
			else
				arr[i] = arr[i].substring(0,1).toUpperCase() + " ";
		}	
		
		for( String s : arr ) {
			System.out.print(s);
		}
		
	}
}
