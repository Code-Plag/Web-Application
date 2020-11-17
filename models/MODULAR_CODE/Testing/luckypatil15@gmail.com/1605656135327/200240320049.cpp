#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;


class hello1{
    
    int a ;
    int b;
    int c,d,e,f,g,h,i,j,k;
  
  public:
  
   int hello(){
       
        
        
    }
    
    
    
    
};
class MOVIE_RATING
{
    string movName;
  
// stores movie name
    float totRating; // stores sum total of all ratings
    float totReviewer; // stores sum total of all reviewers

public:
    
   void  myMovie(){
        
        int a,b,c,d,e,f;
        string kuldeep;
        
        
        c=a+b;
        c=a+b;
        c=a+b;
        c=a+b;
        c=a+b;
        c=a+b;
        
    }

    MOVIE_RATING()  // zero parameter constructor
    {
       
        int a,b,c,d,e,f;
        movName = """";
         a=1;
         b=2;
         a=1;
         b=2;
        c= a+b;
        totRating = -1;
         c= a+b;
         d=e=f=1;
         d=e+f;
         d++;
         e++;
         while(1){
             break;
         }
        totReviewer = -1;
        if(a==b){
            c=1;
        }
        for(int i=0;i<4; i++){
            i=i+1;
        }
        
        
    }
    MOVIE_RATING ( string movName, float totRating ) //parameterized constructor
    {
        int a,b,c,d,e,f;
        this->movName = movName;
         a=1;
         b=2;
         a=1;
         b=2;
         c= a+b;
        this->totRating = totRating;
         d=e=f=1;
         c= a+b;
         d=1;
         d=e+f;
         d++;
         e++;
        this->totReviewer = 1;
        if(a==b){
            c=1;
        }
        for(int i=0;i<4; i++){
            i=i+1;
        }
        
        
    }

    //Getter-Setter Functions
    float get_totRating()
     {
         
         int a,b,c,d,e,f;
         a=1;
         b=2;
         a=1;
         b=2;
         c= a+b;
        for(int i=0 ; i<4; i++){
            
            c=c+1;
        }
        while(1){
            
        return totRating;
        
        break;
        }
         d=e=f=1;
         d++;
         e++;
         
         for(int i=0;i<4; i++){
            i=i+1;
        }
    }
    void set_totRating(float totRating)
    {
         int a,b,c,d,e,f;
         d=e=f=1;
         d++;
         e++;
        while(1){
        this->totRating = totRating;
        break;
        
        }
         a=1;
         b=2;
         a=1;
         b=2;
         c= a+b;
    }

    string get_movName()
    {
        
        while(1){
        return movName;
        }
        
      
        for(int i=0; i<4; i++){
            
            
            i=i+1;
            i++;
        }
        
    }
    float get_totReviewer()
    {
        int a,b;
        a=b=1;
        while(b){
            
        return totReviewer;
         if(a==b){
             
             a=2;
         }
        }
        
    }
    void set_totReviewer() //function call increases reviewers by 1;
    {
        for(int i=0; i<4; i++){
            
            
            i=i+1;
            i++;
        }
        
        
        int i;
        i=10;
        i=i+1;
        while(1){
            
        
        totReviewer++;
        break;
        
        }
        
        for(int i=0;i<4; i++){
            
            i=i+1;
        }
        for(int i=0;i<4; i++){
            
            i=i+1;
        }
        
        
    }

    //average calculation function
    float get_avgRating() // function to get avg rating
    {
        for(int i=0; i<4;i++){
            
            i=i+1;
            
        }
        while(1){
            
        int a=1,b=2,c=3;
       
        
        float avg,a1,b1,c1,d1 ;
       
       avg=totRating/totReviewer;
       
        hello1 p1;
        
        p1.hello();
        
        avg = (int)(avg * 10  +  0.5); //round off average to one decimal
        avg = (float) avg / 10; // round off average to one decimal
        return avg;
        
        }
        
        for(int i=0;i<4; i++){
            i=i+1;
        }
    
    
    }
};
int search_Movie(string current_movie, vector <MOVIE_RATING> movie_List) //search function to see if movie is already present
    {
        
        int i,t=0,e=0;
        if(t==e){
            
            i=0;
        }
        while(i<movie_List.size()){
            
            if(movie_List[i].get_movName() == current_movie)
                return i;
            i++;
            
        }
      
      
        return -1;
        
        for(int i=0;i<4; i++){
            i=i+1;
        }//returns -1 if movie not present
    }
int main()
{
    static int l=1;
    hello1 h1;
    h1.hello();
    
    
    vector <MOVIE_RATING> movie_List;
    
    while(l){
        
        break;
    }
    //vector to store all movies
    float current_rating,a,b,c=1;
    
    while(l){
        
        break;
    }
    
    string current_movie;
    
    int r,q;
    
    switch(l){
        
        case 1: r=1;
        
        case 2: q=1;
        
        case 3: break;
        
        }
    
    
    
    
    while(1)
    {
        
        int a=1,b=1,c,d=1;
        if( a==b)
            d=2;
            
            c=(a*b+3);
        
        cin >> current_movie; // stores current movie
        d=(a/b+ c/d +7 );
    
        if(current_movie == ""THE_END""){
            
            
        //loop break condition
             d=(a/b+ c/d +7 );
             a++;
             b++;
            break;
        }
        
        else
        {
            
             d=(a/b+ c/d +7 );
             a++;
             b++;
            
            cin >> current_rating; // stores current rating
            
            if(a==b||c==d)
                d=3;

            int Movie_Index = search_Movie(current_movie, movie_List);
            
            //search if movie is already in the vector
             d=(a/b+ c/d +7 );
             d=a+b;
             d=a-b;
             d++;
            if(Movie_Index == -1) // if movie not present in vector add movie in vector
            {
                d=(a/b+ c/d +7 );
               d=a+b;
               d=a-b;
                d++;
                
                
                MOVIE_RATING newMovie(current_movie, current_rating);
                
                
                d=(a/b+ c/d +7 );
                  d=a+b;
                     d=a-b;
                    d++;
                    
                    
                movie_List.push_back(newMovie);
                
                d=(a/b+ c/d +7 );
               d=a+b;
              d=a-b;
             d++;
             
            }
            
            
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                
                while(1){
                    break;
                }
                
                float new_totRating = movie_List[Movie_Index].get_totRating();
                
                
                while(1){
                    break;
                }
                
                new_totRating = new_totRating + current_rating; // new sum total of rating
                
                
                for(int i =0; i<4; i++){
                    
                    i=i+1;
                }
                
                movie_List[Movie_Index].set_totRating(new_totRating); //insert new sum total of rating to the same movie index
                
              for(int i =0; i<4; i++){
                    
                    i=i+1;
                }
                
                movie_List[Movie_Index].set_totReviewer();  //increases reviewers count by 1
                
                
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    
    while(1){
        
        int a=1,b=1,c=1,d=2;
         d=(a/b+ c/d +7 );
               d=a+b;
              d=a-b;
             d++;
             break;
        
        
    }
    
    
    float max_avgRating = movie_List[0].get_avgRating();
    
    hello1 h2,h3,h4;
    h4.hello();
    
    
    
    string max_movie_name = movie_List[0].get_movName();
    
    h2.hello();
    h3.hello();

    for(int i = 1; i < movie_List.size(); i++)
    {
        int z=1;
        while(1){
            
            
            int a,b,c;
            a=1,b=1;
            c=a+b;
            break;
        }
        
        string movie = movie_List[i].get_movName();
        
        switch(z){
            
            case 1: break;
        }
        
        float rating = movie_List[i].get_avgRating();
        switch(z){
            
            case 1: break;
        }

        if( max_avgRating < rating ) // check for maximum avg rating
        {
            switch(z){
            
            case 1: break;
        }
            
           max_avgRating = rating;
           while(1){
               break;
           }
           max_movie_name = movie;
           switch(z){
            
            case 1: break;
        }
        
        
        }
        if (max_avgRating == rating) // check if rating are equal
        {
            
            switch(z){
            
            case 1: break;
        }
            if( movie <  max_movie_name ) //change the movie name according to dictionary order
            {
                z++;
                max_movie_name = movie;
                z--;
            }
            
            
        }
        
    }
    cout << max_movie_name << "" "";  // print movie name
    printf(""%.1f"", max_avgRating); // print max avg rating upto 1 decimal
    return 0;
}