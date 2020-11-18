#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class movieRating
{
    string movie; // stores movie name
    float ratingTot; // stores sum total of all ratings
    float reviewerTot; // stores sum total of all reviewers

public:

    movieRating()  // zero parameter constructor
    {
        movie = """";
        ratingTot = -1;
        reviewerTot = -1;
    }
    movieRating( string movie, float ratingTot ) //parameterized constructor
    {
        this->movie = movie;
        this->ratingTot = ratingTot;
        this->reviewerTot = 1;
    }

    //Getter-Setter Functions
    
    //average calculation function
    float get_avg() // function to get avg rating
    {
        float a = ratingTot/reviewerTot;
        float avg;
        avg = (int)(a * 10 + 0.5); //round off average to one decimal
        avg = (float)avg / 10; // round off average to one decimal
        return avg;
    }
    
    void set_totRating(float ratingTot)
    {
        this->ratingTot = ratingTot;
    }

    string get_movName()
    {
        return movie;
    }
    float get_totReviewer()
    {
        return reviewerTot;
    }
    void set_totReviewer() //function call increases reviewers by 1;
    {
       reviewerTot++;
    }
    float get_totRating()
    {
        return ratingTot;
    }

    
};
int find_Movie(string current_movie, vector <movieRating> movie_List); //search function to see if movie is already present
    
int main()
{
    vector <movieRating> movie_List; //vector to store all movies
    float presentRating;
    string presentMovie;
    do
    {
        cin >> presentMovie; // stores current movie

        if(presentMovie != ""THE_END"") 
        {
            cin >> presentRating; // stores current rating

            int movIndex = find_Movie(presentMovie, movie_List); //search if movie is already in the vector

            if(movIndex == -1) // if movie not present in vector add movie in vector
            {
                movieRating newMovie(presentMovie, presentRating);
                movie_List.push_back(newMovie);
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                float newRating = movie_List[movIndex].get_totRating();
                newRating = newRating + presentRating; // new sum total of rating
                movie_List[movIndex].set_totRating(newRating); //insert new sum total of rating to the same movie index
                movie_List[movIndex].set_totReviewer();  //increases reviewers count by 1
            }
        }
        else
        {
            break;
        }//loop break condition
    }while(1);
    //Code to find maximum avg rating according to dictionary order
    float max_avgRating = movie_List[0].get_avg();
    string max_movie_name = movie_List[0].get_movName();

    for(int i = 1; i < movie_List.size(); i++)
    {
        string movie = movie_List[i].get_movName();
        float rating = movie_List[i].get_avg();

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
int find_Movie(string presentMovie, vector <movieRating> movie_List) //search function to see if movie is already present
    {
        int i=0;
        while(i< movie_List.size())
        {
            if(movie_List[i].get_movName() == presentMovie)
            return i; //return index of the vector where movie is present
                i++;
        }
        return -1; //returns -1 if movie not present
    }