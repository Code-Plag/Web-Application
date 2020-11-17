package p1;

import java.util.Scanner;

public class Q55 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a string: ");
		String str = sc.nextLine();
		String arr[] = str.split(" ");
		System.out.print(arr.length);	
	}
}
