package p1;

import java.util.Scanner;



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
