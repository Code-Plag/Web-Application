# include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class MOVIE_RATING
{
    string movName; // declaring data members
    float totRating; 
    float totReviewer; 

public:

    MOVIE_RATING()  //  parameterlesss constructor
    {
        movName = """";
        totRating = -1;
        totReviewer = -1;
    }
    MOVIE_RATING ( string movName, float totRating ) // two parameter parameterized constructor
    {
        this->movName = movName;
        this->totRating = totRating;  //initialising data members
        this->totReviewer = 1;
    }

    float get_totRating() //to get the total rating
    {
        return totRating;
    }
    void set_totRating(float totRating) //to set the total rating
    {
        this->totRating = totRating;
    }

    string get_movName()  //to get the movie name
    {
        return movName;
    }
    float get_totReviewer() //to get the review of person
    {
        return totReviewer; 
    }
    void set_totReviewer() //function call increases reviewers by 1;
    {
        totReviewer++;
    }

    float get_avgRating() // function to get avg rating
    {
        float avg = totRating/totReviewer;
        avg = (int)(avg * 10 + 0.5); 
        avg = (float)avg / 10; 
        return avg;
    }
};
int search_Movie(string current_movie, vector <MOVIE_RATING> movie_List) 
    {
        for(int i = 0; i< movie_List.size(); i++)
        {
            if(movie_List[i].get_movName() == current_movie)
                return i; //index of vector 
        }
        return -1; // when there is no movie
    }
int main()
{
    vector <MOVIE_RATING> movie_List; 
    float current_rating;
    string current_movie;
    while(1)
    {
        cin >> current_movie; // taking input of movies from user

        if(current_movie == ""THE_END"") //input breaking condition
            break;
        else
        {
            cin >> current_rating; // taking input of rating of movie from user

            int Movie_Index = search_Movie(current_movie, movie_List); 

            if(Movie_Index == -1) 
            {
                MOVIE_RATING newMovie(current_movie, current_rating);
                movie_List.push_back(newMovie);
            }
            else  
            {
                float new_totRating = movie_List[Movie_Index].get_totRating();
                new_totRating = new_totRating + current_rating; 
                movie_List[Movie_Index].set_totRating(new_totRating); 
                movie_List[Movie_Index].set_totReviewer();  
            }
        }
    }
    
    float max_avgRating = movie_List[0].get_avgRating();
    string max_movie_name = movie_List[0].get_movName();

    for(int i = 1; i < movie_List.size(); i++)
    {
        string movie = movie_List[i].get_movName();
        float rating = movie_List[i].get_avgRating();

        if( max_avgRating < rating )
        {
           max_avgRating = rating;
           max_movie_name = movie;
        }
        if (max_avgRating == rating) 
        {
            if( movie <  max_movie_name ) 
            {
                max_movie_name = movie;
            }
        }
    }
    cout << max_movie_name << "" "";  // print movie name
    printf(""%.1f"", max_avgRating); // print max avg rating upto 1 decimal
    return 0;
}