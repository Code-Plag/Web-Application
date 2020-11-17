package p1;

import java.util.Scanner;

public class Q54 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String str = sc.nextLine();
		System.out.println("Input String: " + str);
		System.out.print("Reversed String: ");
		for( int i = str.length() - 1 ; i >= 0 ; i-- ) {
			System.out.print(str.charAt(i));
		}
	}
}
