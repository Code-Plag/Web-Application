#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
typedef float FLOAT;
//pedef string   STRING;
using namespace std;
class MOVIE_RATING
{
    string movName; // stores movie name
    FLOAT totRating; // stores sum total of all ratings
    FLOAT totReviewer; // stores sum total of all reviewers

public:

    MOVIE_RATING()  // zero parameter constructor
      {
        movName = """";
        totRating = -1;
        totReviewer = -1;
      }
    MOVIE_RATING ( string movName, FLOAT totRating ) //parameterized constructor
      {
         this->movName = movName;
         this->totRating = totRating;
          this->totReviewer = 1;
      }

    //Getter-Setter Functions
       FLOAT get_totRating()
       {
        return totRating;
        }
       void set_totRating(FLOAT totRating)
    {
        this->totRating = totRating;
    }

    string get_movName()
    {
        return movName;
    }
    FLOAT get_totReviewer()
    {
        return totReviewer;
    }
    void set_totReviewer() //function call increases reviewers by 1;
    {
        totReviewer++;
    }

    //average calculation function
    FLOAT get_avgRating() // function to get avg rating
    {
        FLOAT avg = totRating/totReviewer;
        avg = (int)(avg * 10 + 0.5); //round off average to one decimal
        avg = (FLOAT)avg / 10; // round off average to one decimal
        return avg;
    }
};
int search_Movie(string current_movie, vector <MOVIE_RATING> movie_List) //search function to see if movie is already present
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
    FLOAT current_rating;
    string current_movie;
    while(1)
    {
        cin >> current_movie; // stores current movie

        if(current_movie == ""THE_END"") //loop break condition
            break;
        else
        {
            cin>>current_rating; // stores current rating

            int Movie_Index = search_Movie(current_movie, movie_List); //search if movie is already in the vector

            if(Movie_Index == -1) // if movie not present in vector add movie in vector
            {
                MOVIE_RATING newMovie(current_movie, current_rating);
                movie_List.push_back(newMovie);
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                FLOAT new_totRating = movie_List[Movie_Index].get_totRating();
                new_totRating = new_totRating + current_rating; // new sum total of rating
                movie_List[Movie_Index].set_totRating(new_totRating); //insert new sum total of rating to the same movie index
                movie_List[Movie_Index].set_totReviewer();  //increases reviewers count by 1
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    FLOAT max_avgRating = movie_List[0].get_avgRating();
    string max_movie_name = movie_List[0].get_movName();

    for(int i = 1; i < movie_List.size(); i++)
    {
        string movie = movie_List[i].get_movName();
        FLOAT rating = movie_List[i].get_avgRating();

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
    cout<< max_movie_name << "" "";  // print movie name
    printf(""%.1f"", max_avgRating); // print max avg rating upto 1 decimal
    return 0;
}