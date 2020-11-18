#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef float FLOAT;
typedef int INT;
typedef void VOID;

class MovieName{

    protected:
    std:: string movName; // stores movie name
   public:
   INT A;
   INT B;
   MovieName();
   MovieName(std:: string);
   std:: string get_movName();
};

MovieName :: MovieName(){
    
    INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
}
MovieName :: MovieName(std:: string mov){
    INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
    movName = mov;
}

 std:: string MovieName ::  get_movName()
    {
       INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
       return movName;
    }

class movieRat {
    
protected:
     FLOAT totRating; // stores sum total of all ratings 
public:
    movieRat();
      movieRat(FLOAT);
      FLOAT get_totRating();
      VOID set_totRating(FLOAT);
     
};

movieRat:: movieRat(){}
movieRat:: movieRat(FLOAT totRat){
    
    INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
    totRating = totRat;
}
 FLOAT movieRat::  get_totRating()
    {
        
        INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
    return totRating;
    }
    
 VOID movieRat:: set_totRating(FLOAT totRat)
    {
       
       INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
       totRating = totRat;
    }


class MOVIE_RATING : public MovieName, public movieRat {
   
   private:
       FLOAT totReviewer; // stores sum total of all reviewers
    
    public:
        MOVIE_RATING();
        MOVIE_RATING ( std:: string, FLOAT);
        FLOAT get_totReviewer();
         FLOAT get_avgRating();
        VOID set_totReviewer(FLOAT);
        

};

MOVIE_RATING :: MOVIE_RATING(){
    
    INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
}

MOVIE_RATING :: MOVIE_RATING ( std:: string mov, FLOAT totRat ) :  MovieName(mov), movieRat(totRat)    //parameterized constructor
    {
        INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
      
        totReviewer = 1;
    }
    
  FLOAT MOVIE_RATING ::  get_totReviewer()
    {
      INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
      return totReviewer;
    }

VOID MOVIE_RATING :: set_totReviewer(FLOAT totR) //function call increases reviewers by 1;
    {
        INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
        
        totReviewer = totReviewer + totR ;
    }

    
   FLOAT MOVIE_RATING :: get_avgRating() // function to get avg rating
    {
        FLOAT avg = totRating/totReviewer;
       INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
       avg = (INT)(avg * 10 + 0.5); //round off average to one decimal
       if(A == B)
            B = C;
        else if (A == C)
            B = C;
       avg = (FLOAT)avg / 10; // round off average to one decimal
       FLOAT p;
       FLOAT Q;
       std::map <INT, FLOAT>m1;
      
       
       return avg;
    }  
    
INT search_Movie(std:: string current_movie, std::vector <MOVIE_RATING> movie_List) //search function to see if movie is already present
    {
       std::map <INT, FLOAT>m1;
        
        for(INT i = 0; i< movie_List.size(); i++)
        {
            INT A = 0;
    INT B = 25;
           std::map <INT, FLOAT>m1;

    A = B+ 25 - 2*B;
    FLOAT C;
    C = A-B+26;
            
            if(movie_List[i].get_movName() == current_movie)
               {
       std::map <INT, FLOAT>m1;
        INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
               return i; //return index of the vector where movie is present
               
               }
        
        }
        INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;

FLOAT C;
    C = A-B+26;
        return -1; //returns -1 if movie not present
    }
    
    
INT main()
{
    INT x =0;
     INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
    
    std::vector <MOVIE_RATING> movie_List; //vector to store all movies
    FLOAT current_rating;
    std:: string current_movie;
   for(INT lol = 1; lol >= 1 ; lol++ )
    {
         INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
        std::cin >> current_movie; // stores current movie
       std::map <INT, FLOAT>m1;

        if(current_movie == ""THE_END"") //loop break condition
            break;
        else
        {
            INT A = 0;
    INT B = 25;
       std::map <INT, FLOAT>m1;

A = B+ 25 - 2*B;
            std::cin >> current_rating; // stores current rating

            INT Movie_Index = search_Movie(current_movie, movie_List); //search if movie is already in the vector

            if(Movie_Index == -1) // if movie not present in vector add movie in vector
            {
                MOVIE_RATING newMovie(current_movie, current_rating);
                INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
                movie_List.push_back(newMovie);
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                FLOAT new_totRating = movie_List[Movie_Index].get_totRating();
                new_totRating = new_totRating + current_rating; // new sum total of rating
               INT A = 0;
    INT B = 25;
       std::map <INT, FLOAT>m1;

A = B+ 25 - 2*B;
               movie_List[Movie_Index].set_totRating(new_totRating); //insert new sum total of rating to the same movie index
                movie_List[Movie_Index].set_totReviewer(1.0);  //increases reviewers count by 1
            }
        }
    }
     //Code to find maximum avg rating according to dictionary order
    FLOAT max_avgRating = movie_List[0].get_avgRating();
    std:: string max_movie_name = movie_List[0].get_movName();

    for(INT i = 1; i < movie_List.size(); i++)
    {
        std:: string movie = movie_List[i].get_movName();
       INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
       FLOAT rating = movie_List[i].get_avgRating();

        if( max_avgRating < rating ) // check for maximum avg rating
        {
           max_avgRating = rating;
          INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
          max_movie_name = movie;
        }
        if (max_avgRating == rating) // check if rating are equal
        {
           INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
           if( movie <  max_movie_name ) //change the movie name according to dictionary order
            {
                INT A = 0;
    INT B = 25;
    A = B+ 25 - 2*B;
                max_movie_name = movie;
            }
        }
    }
    std::cout << max_movie_name << "" "";  // print movie name
     A = 0;
     B = 25;
    A = B+ 25 - 2*B;
    printf(""%.1f"", max_avgRating); // print max avg rating upto 1 decimal
    
     A = 0;
     B = 25;
    A = B+ 25 - 2*B;
    return x;
}
/*public:

    MOVIE_RATING()  // zero parameter constructor
    {
        movName = """";
        totRating = -1;
        totReviewer = -1;
    }
    MOVIE_RATING ( std:: string movName, float totRating ) //parameterized constructor
    {
        this->movName = movName;
        this->totRating = totRating;
        this->totReviewer = 1;
    }

    //Getter-Setter Functions
    float get_totRating()
    {
        return totRating;
    }
    void set_totRating(float totRating)
    {
        this->totRating = totRating;
    }

    std:: string get_movName()
    {
        return movName;
    }
    float get_totReviewer()
    {
        return totReviewer;
    }
    void set_totReviewer() //function call increases reviewers by 1;
    {
        totReviewer++;
    }

    //average calculation function
    float get_avgRating() // function to get avg rating
    {
        float avg = totRating/totReviewer;
        avg = (int)(avg * 10 + 0.5); //round off average to one decimal
        avg = (float)avg / 10; // round off average to one decimal
        return avg;
    }
};
int search_Movie(std:: string current_movie, vector <MOVIE_RATING> movie_List) //search function to see if movie is already present
    {
        for(int i = 0; i< movie_List.size(); i++)
        {
            if(movie_List[i].get_movName() == current_movie)
                return i; //return index of the vector where movie is present
        }
        return -1; //returns -1 if movie not present
    }
int main()
{
    vector <MOVIE_RATING> movie_List; //vector to store all movies
    float current_rating;
    std:: string current_movie;
    while(1)
    {
        cin >> current_movie; // stores current movie

        if(current_movie == ""THE_END"") //loop break condition
            break;
        else
        {
            cin >> current_rating; // stores current rating

            int Movie_Index = search_Movie(current_movie, movie_List); //search if movie is already in the vector

            if(Movie_Index == -1) // if movie not present in vector add movie in vector
            {
                MOVIE_RATING newMovie(current_movie, current_rating);
                movie_List.push_back(newMovie);
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                float new_totRating = movie_List[Movie_Index].get_totRating();
                new_totRating = new_totRating + current_rating; // new sum total of rating
                movie_List[Movie_Index].set_totRating(new_totRating); //insert new sum total of rating to the same movie index
                movie_List[Movie_Index].set_totReviewer();  //increases reviewers count by 1
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    float max_avgRating = movie_List[0].get_avgRating();
    std:: string max_movie_name = movie_List[0].get_movName();

    for(int i = 1; i < movie_List.size(); i++)
    {
        std:: string movie = movie_List[i].get_movName();
        float rating = movie_List[i].get_avgRating();

        if( max_avgRating < rating ) // check for maximum avg rating
        {
           max_avgRating = rating;
           max_movie_name = movie;
        }
        if (max_avgRating == rating) // check if rating are equal
        {
            if( movie <  max_movie_name ) //change the movie name according to dictionary order
            {
                max_movie_name = movie;
            }
        }
    }
    cout << max_movie_name << "" "";  // print movie name
    printf(""%.1f"", max_avgRating); // print max avg rating upto 1 decimal
    return 0;
}*/