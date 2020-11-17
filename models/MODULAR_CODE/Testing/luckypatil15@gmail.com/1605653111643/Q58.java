package p1;

import java.util.Scanner;

/*58.	Store name of weekdays in an array (starting from “Sunday” at 0 index). Ask day position from user and print day name. 
 * Handle array index out of bound exception and give proper message if user enter day index outside range (0-6). */
public class Q58 {

	public static void main(String[] args) {

		String WeekDays [] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Saturday" };
		
		System.out.print("Enter day position: ");
		Scanner sc = new Scanner(System.in);
		int choice = sc.nextInt();
		
		try {
			System.out.println(WeekDays[choice]);
		}
		catch(Exception E){
			System.out.println("Please enter a valid choice between 0 - 6");
		}
		

	}

}
