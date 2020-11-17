package p1;

import java.io.IOException;



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
