import java.util.*;
class Student{
    int rollno;
    double percentage;

    Student(){

    }
    Student(int rollno, double percentage){
        this.rollno = rollno;
        this.percentage = percentage;
    }

    void show(){
        System.out.println("Rollno: " + rollno + "Per: " + percentage );
    }
}

class CollegeStudent extends Student{
    int semester;

    CollegeStudent(){}
    CollegeStudent(int rollno, double percentage, int semester){
        super(rollno,percentage);
        this.semester = semester;
    }
    void show(){
        super.show();
        System.out.println("Semester: " + semester);
    }

}
class SchoolStudent extends Student{
    int className;

    SchoolStudent(){

    }
    SchoolStudent(int rollno, double percentage, int className){
        super(rollno,percentage);
        this.className = className;
    }
    void show(){
        super.show();
        System.out.println("Class Name: " + className);
    }
}

class demo{
    public static void main(String[] args) {
        Student c[] =  { new CollegeStudent(), 
                        new CollegeStudent(), 
                        new SchoolStudent(), 
                        new SchoolStudent(), 
                        new SchoolStudent() };   
        
        Scanner sc = new Scanner(System.in);

        for( int i = 0 ; i < c.length ; i++ ){
            
            if( c[i] instanceof SchoolStudent ){
                System.out.println("Enter school std data: ");
                int roll = sc.nextInt();
                double per = sc.nextDouble();
                int cname = sc.nextInt();
                c[i] = new SchoolStudent(roll,per,cname);
            }
            else{
                System.out.println("Enter clg std data: ");
                int roll = sc.nextInt();
                double per = sc.nextDouble();
                int sem = sc.nextInt();
                c[i] = new CollegeStudent(roll,per,sem);
            }
        }

        System.out.println("Roll no to be searched: ");
        int x = sc.nextInt();
        int count = 0;
        for( Student s : c ){   
            if( s.rollno == x ){
                System.out.println("Roll no found ");
                if( s instanceof SchoolStudent ){
                    System.out.println("This is a school std.");
                }
                else{
                    System.out.println("This is a clg std.");
                }
            }
            if( s.percentage > 75 ){
                count++;
            }
        }
        System.out.println("Count of std having A grade: " + count);
    }
}