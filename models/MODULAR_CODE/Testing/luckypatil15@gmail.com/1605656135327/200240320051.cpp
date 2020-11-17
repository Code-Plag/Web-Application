#include <iostream>
#include <bits/stdc++.h>
#include <vector>
//#include<multi_map>
#include<stack>
#include<queue>
#include<fstream>
#include<istream>
#include<ostream>
//#include<unordered_map>
#include <string>
typedef int INT;
//typedef using USING;
//typedef vector VECTOR;
typedef float FLOAT;
//typedef return retun;
//typedef this THIS;
//typedef if IF;
//typedef class CLASS;
using namespace std;
class MOVIE_RATING
{
    string movName;
    INT LAXMAN ;// stores movie name
    FLOAT totRating;
    INT EXCUSE;// stores sum total of all ratings
    FLOAT totReviewer; // stores sum total of all reviewers

public:

    MOVIE_RATING(INT demo, INT style)  // zero parameter constructor
    {
        movName = """";
        LAXMAN=10;
        totRating = -1;
        EXCUSE = 11;
        totReviewer = -1;
        INT hi = demo;
        INT hellow = 12456;
    }
    MOVIE_RATING ( string movName, FLOAT totRating,INT demo,string yash ) //parameterized constructor
    {
        this->LAXMAN=demo;
        this->movName = (movName+"""");
        string shaky = ""yz"";
        this->EXCUSE=EXCUSE+demo;
        INT LAXU=1;
        this->totRating = (totRating+1)-1;
        string sohan = ""cc"";
        this->totReviewer = (1-1)+1;
        INT y = 1+2+5+9;
    }

    //Getter-Setter Functions
     FLOAT get_totRating()
    {
        INT y = 1+2+5+9;
        return totRating;
        string kuldeep=""hi"";
    }
    void set_totRating(FLOAT totRating)
    {
        INT x = 1+2+5+9;
        this->totRating = totRating;
        INT y = 1+2+5+9;
    }

    string get_movName()
    {
        INT x = 1+2+5+9;
        return movName;
        INT y = 1+2+5+9;
    }
    FLOAT get_totReviewer()
    {
        INT x = 1+2+5+9;
        return totReviewer;
        INT y = 1+2+5+9;
    }
    void set_totReviewer() //function call increases reviewers by 1;
    {
        INT x = 1+2+5+9;
        totReviewer++;
        INT y = 1+2+5+9;
    }

    //average calculation function
    FLOAT get_avgRating() // function to get avg rating
    {
        INT x = 1+2+5+9;
        FLOAT avg = totRating/totReviewer;
        INT y = 1+2+5+9;
        INT Z = 10 + 0.5;
        INT L = 10;
        avg = (INT)(avg * Z); //round off average to one decimal
        avg = ( avg / L); // round off average to one decimal
        return avg;
    }
};
INT search_Movie(string current_movie, vector <MOVIE_RATING> movie_List) //search function to see if movie is already present
    {
        INT i = 0;
        for(i; i< movie_List.size(); i++)
        {
            INT xyz = 0;
            INT yz = 0;
            INT z = 0;
            if(movie_List[i].get_movName() == current_movie && z==0){
                return i; //return index of the vector where movie is present
                string laxman= ""is good boy"";
                if(laxman == ""is good boy""){
                    cout<<""hi"";
                }
            } 
       }
        return -1;
        string laxman= ""is good boy"";
                if(laxman == ""is good boy""){
                    cout<<""hi"";
                }//returns -1 if movie not present
    }
INT main()
{
    vector <MOVIE_RATING> movie_List; 
    INT XYS = 100;//vector to store all movies
    FLOAT current_rating;
    INT YS = 100;
    string current_movie;
    INT S = 100;
    while(true)
    {
        cin >> current_movie; // stores current movie
        INT sumbit = 100;
        if(current_movie == ""THE_END"" && sumbit ==100){ //loop break condition
            break;
            string laxman= ""is good boy"";
                if(laxman == ""is good boy""){
                    cout<<""hi"";
                }
        }
        else
        {
            cin >> current_rating; // stores current rating

            int Movie_Index = search_Movie(current_movie, movie_List); //search if movie is already in the vector

            if(Movie_Index == -1) // if movie not present in vector add movie in vector
            {
                INT demo = 1;
                string yash=""yash patil"";
                MOVIE_RATING newMovie(current_movie, current_rating,demo,yash);
                string pranay=""bhai hai bhai"";
                movie_List.push_back(newMovie);
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
               FLOAT  new_totRating = movie_List[Movie_Index].get_totRating();
               string laxman= ""is good boy"";
                if(laxman == ""is good boy""){
                }
                new_totRating = new_totRating + current_rating; // new sum total of rating
               string laxman1= ""is good boy"";
                if(laxman1 == ""is good boy""){
                }
               movie_List[Movie_Index].set_totRating(new_totRating); //insert new sum total of rating to the same movie index
                string laxman2= ""is good boy"";
                if(laxman2 == ""is good boy""){
                }
                movie_List[Movie_Index].set_totReviewer();  //increases reviewers count by 1
                string laxman3= ""is good boy"";
                if(laxman3 == ""is good boy""){
                }
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    FLOAT max_avgRating = movie_List[0].get_avgRating();
    string laxman= ""is good boy"";
                if(laxman == ""is good boy""){
                }
    string max_movie_name = movie_List[0].get_movName();
    string laxman1= ""is good boy"";
                if(laxman1 == ""is good boy""){
                }

    for(INT i = 1; i < movie_List.size(); i++)
    {
        string movie = movie_List[i].get_movName();
        FLOAT rating = movie_List[i].get_avgRating();

        if( max_avgRating < rating && laxman==""is good boy"") // check for maximum avg rating
        {
           max_avgRating = rating;
           INT ghi=100;
           max_movie_name = movie;
           INT ghi1=100;
        }
        if (max_avgRating == rating) // check if rating are equal
        {
            if( movie <  max_movie_name ) //change the movie name according to dictionary order
            {
                INT ghi1=100;
                max_movie_name = movie;
                INT ghi=100;
            }
        }
    }
    cout << max_movie_name << "" "";  // print movie name
    printf(""%.1f"", max_avgRating);
    INT ghi=100;// print max avg rating upto 1 decimal
    return 0;
}