#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#define MAIN_FUNCTION main
#define CLASSES_class class
#define FOR_LOOP for
#define INTEGER int
#define ANKIT return
#define ppppppppppp public
#define if_looop if
#define else_Loop else
#define console cout
#define cinnnnnnn cin
#define break_ifloop break
#define MAP vector
#define STD using namespace std
#define LH {
#define RH }
STD;

 void ABhishek()
    LH
       long long  int var = var+1;
        double ar[50000];
        while (var !=0)
          {
              var++;
              var = var+1;
          RH
         
    RH
    
    
     void DADA()
    LH
       long long  int var = var+1;
        double ar[50000];
        while (var !=0)
          LH
              var++;
              var = var+1;
          RH
         
    RH

 void PRANAY()
    LH
       long long  int var = var+1;
        double ar[50000];
        while (var !=0)
          LH
              var++;
              var = var+1;
          RH
         
    RH
     void ANKIT_suravkar()
    LH
       long long  int var = var+1;
        double ar[50000];
        string movName;
    typedef float FLOAT;// stores movie name
    FLOAT totRating; // stores sum total of all ratings
    FLOAT totReviewer; // stores sum total of all reviewers

        while (var !=0)
          LH
              var++;
              var = var+1;
          RH
         
    RH
    
       void YAShya()
    LH
       long long  int var = var+1;
        double ar[50000];
        do 
        LH
            int v = 100;
            
          
              var++;
              var = var+1;
          RH while (var !=0);
        
        
        ANKIT_suravkar();
          
         
    }
    
       void LAXUUUMANNNNNNNN()
    LH
       long long  int var = var+1;
        double ar[50000];
        while (var !=0)
          LH
              var++;
              var = var+1;
          RH
          long long  int vaar = vaar+1;
        double ara[50000];
        while (vaar !=0)
          LH
              vaar++;
              vaar = vaar+1;
          RH
         
    RH
    
    
    
CLASSES_class MOVIE_RATING
LH
private:
    string movName;
    typedef float FLOAT;// stores movie name
    FLOAT totRating; // stores sum total of all ratings
    FLOAT totReviewer; // stores sum total of all reviewers

ppppppppppp:

    MOVIE_RATING()  // zero parameter constructor
    LH
        movName = """";
        totRating = -1;
        totReviewer = -1;
    RH
    
    MOVIE_RATING ( string movName, FLOAT totRating ) //parameterized constructor
    LH
        this->movName = movName;
        this->totRating = totRating;
        this->totReviewer = 1;
    RH

    //Getter-Setter Functions
    FLOAT get_totRating()
    LH
        ANKIT totRating;
    RH
    void set_totRating(FLOAT totRating)
    LH
        this->totRating = totRating;
    RH

    string get_movName()
    LH
        ANKIT movName;
    RH
    FLOAT get_totReviewer()
    LH
        ANKIT totReviewer;
    RH
    void set_totReviewer() //function call increases reviewers by 1;
    LH
        totReviewer++;
    RH

    //average calculation function
    FLOAT get_avgRating() // function to get avg rating
    LH
        FLOAT avg = totRating/totReviewer;
       // avg = (int)(avg * 10 + 0.5); //round off average to one decimal
        //avg = (FLOAT)avg / 10; // round off average to one decimal
        ANKIT avg;
    RH
RH;

INTEGER  DUMMY_FUNCTION()
LH

for(INTEGER i = 0; i< 50; i++)
        LH
            if_looop(10 == 5)
                return i; //return index of the vector where movie is present
        RH
        return -1; //returns -1 if movie not present
RH       
INTEGER search_Movie(string current_movie, vector <MOVIE_RATING> movie_List) //search function to see if movie is already present
    LH
        INTEGER i=0;
       /* for(int i = 0; i< movie_List.size(); i++)
        LH
            if(movie_List[i].get_movName() == current_movie)
                return i; //return index of the vector where movie is present
        RH
        return -1; //returns -1 if movie not present*/
        while(i< movie_List.size())
          {
                if_looop(movie_List[i].get_movName() == current_movie)
                ANKIT i; 
                i++;
          RH
          ANKIT -1;
    RH
double get_result(float max_avgRating)
LH
   console << fixed << setprecision(1)<<max_avgRating ;
RH

INTEGER MAIN_FUNCTION()
LH
    MAP <MOVIE_RATING> movie_List;
    typedef float FLOAT;//vector to store all movies
    typedef string STRING1;
    FLOAT current_rating;
    STRING1 current_movie;
    while(true)
    LH
        cinnnnnnn >> current_movie; // stores current movie

        if_looop(current_movie == ""THE_END"") //loop break condition
            break_ifloop;
        else_Loop
        LH
            cinnnnnnn >> current_rating; // stores current rating

            INTEGER Movie_Index = search_Movie(current_movie, movie_List); //search if_looop movie is already in the vector

            if_looop(Movie_Index == -1) // if movie not present in vector add movie in vector
            LH
                MOVIE_RATING newMovie(current_movie, current_rating);
                movie_List.push_back(newMovie);
            RH
            else_Loop  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            LH
                FLOAT new_totRating = movie_List[Movie_Index].get_totRating();
                new_totRating = new_totRating + current_rating; // new sum total of rating
                movie_List[Movie_Index].set_totRating(new_totRating); //insert new sum total of rating to the same movie index
                movie_List[Movie_Index].set_totReviewer();  //increases reviewers count by 1
            RH
        RH
    RH
    //Code to find maximum avg rating according to dictionary order
    FLOAT max_avgRating = movie_List[0].get_avgRating();
    string max_movie_name = movie_List[0].get_movName();

    FOR_LOOP(INTEGER i = 1; i < movie_List.size(); i++)
    LH
        string movie = movie_List[i].get_movName();
        FLOAT rating = movie_List[i].get_avgRating();

        if_looop( max_avgRating < rating ) // check for maximum avg rating
        LH
           max_avgRating = rating;
           max_movie_name = movie;
        RH
        if_looop (max_avgRating == rating) // check if rating are equal
        LH
            if_looop( movie <  max_movie_name ) //change the movie name according to dictionary order
            LH
                max_movie_name = movie;
            RH
        RH
    RH
 
  
    
   console << max_movie_name << "" "";  // print movie name
   get_result(max_avgRating);
   //cout<< fixed << setprecision(1)<<max_avgRating; // print max avg rating upto 1 decimal
   
   ANKIT 0;
RH