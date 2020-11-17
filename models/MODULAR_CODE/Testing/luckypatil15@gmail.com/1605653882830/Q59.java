package p1;

import java.io.IOException;

/*
59.	Create a class Voter(voterId, name, age) with parameterized constructor.  
The parameterized constructor should throw a checked exception if age is less than 18. 
The message of exception is “invalid age for voter ”*/

class Voter{
	int voterId;
	String name;
	int age;
	
	public Voter(int voterId, String name, int age) throws IOException{
		super();
		
		
			if( age < 18 ) {
				throw new IOException();
			}
			else {
				this.age = age;
				this.voterId = voterId;
				this.name = name;
			}
		
		
		
	}

	@Override
	public String toString() {
		return "Voter voterId=" + voterId + ", name=" + name + ", age=" + age;
	}
}

public class Q59 {
	public static void main(String[] args) {
		try {
		Voter v = new Voter(10, "Abhi",1 );
		System.out.println(v);
		}
		catch(IOException i) {
			System.out.println("“invalid age for voter”");
		}
		
		
	}
}
