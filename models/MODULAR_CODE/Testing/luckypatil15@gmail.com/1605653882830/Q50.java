package p1;

import java.util.*;

class Employee {
    int empId;
    String name;
    double salary;

    Employee(int empId, String name, double salary ){
        this.empId = empId;
        this.name = name;
        this.salary = salary;
    }

	@Override
	public String toString() {
		return "Employee empId=" + empId + ", name=" + name + ", salary=" + salary;
	}


	@Override
	public boolean equals(Object obj) {
		
		Employee other = (Employee) obj;
			return empId == other.empId;
	}   
	
    
}

class Q50{
	
    public static void main(String[] args) {
       Employee e[] = new Employee[3];
       Scanner sc = new Scanner(System.in);
       int k = 0;
       for( int  i = 0 ; i < e.length ; i++ ){
            System.out.println("Enter emp details: ");
            int id = sc.nextInt();
            sc.nextLine();
            String name = sc.nextLine();
            double sal = sc.nextDouble();

            Employee e1 = new Employee(id, name, sal);
            if( i == 0 ){
                e[i] = e1; 
                k++; //k=1
            }
            else{
            	int flag = 0;
                for( int j = 0 ; j < k ; j++ ){//0 1 2
                	//System.out.println("i: "+i+" j: "+j+" k: "+k);
                	//System.out.println("e1: "+e1+" e"+j+": "+e[j]);
                    if(  e1.equals( e[j] ) ) {                     	
                        System.out.println("empId already exist");
                      //  System.out.println(e1.name+ " " + e[j].name);
                        flag = 1;
                        i = i-1;
                        break;
                    }
                    
                }
                if( flag == 0 ) {
                    k++;
                    e[i] = e1;
                } 
            }
        }
       
       for( Employee x : e ) {
    	   System.out.println( x );
       }
       sc.close();
    }
}