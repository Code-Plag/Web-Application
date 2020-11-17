package p1;

import java.util.Scanner;

public class Q52{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		
		String temp = str.replaceAll("\\s+","");
		temp = temp.toLowerCase();
		temp = temp.replaceAll("[aeiou]"," ");
		//System.out.println(temp);
		int count = 0;
		for( int i = 0 ; i < temp.length() ; i++ ) {
			if( temp.charAt(i) == ' ' ) {
				count++;
			}
		}
		System.out.println(count);
		sc.close();
		
	}

}
