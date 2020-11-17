# include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class MOVIE_RATING
{
    string movieName; // stores movie name
    float totalRating; // stores sum total of all ratings
    float totalReviewer; // stores sum total of all reviewers

public:

    MOVIE_RATING()  // zero parameter constructor
    {
        movieName = ""\0"";
        totalRating = -1;
        totalReviewer = -1;
    }
    MOVIE_RATING ( string movieName, float totalRating ) //parameterized constructor
    {
        this->movieName = movieName;
        this->totalRating = totalRating;
        this->totalReviewer = 1;
    }

    //Getter-Setter Functions
    float get_totalRating()
    {
        return totalRating;
    }
    void set_totalRating(float totalRating)
    {
        this->totalRating = totalRating;
    }

    string get_movieName()
    {
        return movieName;
    }
    float get_totalReviewer()
    {
        return totalReviewer;
    }
    void set_totalReviewer() //function call increases reviewers by 1;
    {
        totalReviewer++;
    }

    //average calculation function
    float get_avgRating() // function to get avg rating
    {
        float avg = totalRating/totalReviewer;
        avg = (int)(avg * 10 + 0.5); //round off average to one decimal
        avg = (float)avg / 10; // round off average to one decimal
        return avg;
    }
};
int search_MovieName(string current_movieName, vector <MOVIE_RATING> movie_List) //search function to see if movie is already present
    {
        for(int i = 0; i< movie_List.size(); i++)
        {
            if(movie_List[i].get_movieName() == current_movieName)
                return i; //return index of the vector where movie is present
        }
        return -1; //returns -1 if movie not present
    }
int main()
{
    vector <MOVIE_RATING> movie_List; //vector to store all movies
    float current_rating;
    string current_movie;
    while(1)
    {
        cin >> current_movie; // stores current movie

        if(current_movie == ""THE_END"") //loop break condition
            break;
        else
        {
            cin >> current_rating; // stores current rating

            int Movie_Index = search_MovieName(current_movie, movie_List); //search if movie is already in the vector

            if(Movie_Index == -1) // if movie not present in vector add movie in vector
            {
                MOVIE_RATING newMovie(current_movie, current_rating);
                movie_List.push_back(newMovie);
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                float new_totRating = movie_List[Movie_Index].get_totalRating();
                new_totRating = new_totRating + current_rating; // new sum total of rating
                movie_List[Movie_Index].set_totalRating(new_totRating); //insert new sum total of rating to the same movie index
                movie_List[Movie_Index].set_totalReviewer();  //increases reviewers count by 1
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    float max_avgRating = movie_List[0].get_avgRating();
    string max_movie_name = movie_List[0].get_movieName();

    for(int i = 1; i < movie_List.size(); i++)
    {
        string movie = movie_List[i].get_movieName();
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
}