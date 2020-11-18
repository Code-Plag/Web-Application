# include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class Ratings
{
    string movie; // stores movie name
    double Rating; // stores sum total of all ratings
    double Reviewer; // stores sum total of all reviewers

public:

    Ratings()  // zero parameter constructor
    {
        movie = """";
        Rating = -1;
        Reviewer = -1;
    }
    Ratings ( string movie, double Rating ) //parameterized constructor
    {
        this->movie = movie;
        this->Rating = Rating;
        this->Reviewer = 1;
    }

    //Getter-Setter Functions
    double get_Rating()
    {
        return Rating;
    }
    void set_Rating(double Rating)
    {
        this->Rating = Rating;
    }

    string get_movie()
    {
        return movie;
    }
    double get_Reviewer()
    {
        return Reviewer;
    }
    void set_Reviewer() //function call increases reviewers by 1;
    {
        ++Reviewer;
    }

    //average calculation function
    double get_averageRating() // function to get avg rating
    {
        double average = Rating/Reviewer;
        average = (int)(average * 10 + 0.5); //round off average to one decimal
        average = (float)average*10 / 100; // round off average to one decimal
        return average;
    }
};
int search(string current_movie, vector <Ratings> movie_List) //search function to see if movie is already present
    {
        int k=0;
        while(k < movie_List.size())
        {
            if(movie_List[k].get_movie() == current_movie)
                return k;//return index of the vector where movie is present
                k++;
        }
        return -1; //returns -1 if movie not present
    }
int main()
{
    vector <Ratings> movie_List; //vector to store all movies
    float current_rating;
    string current_movie;
    for(int j=1;j>=1;j++)
    {
        cin >> current_movie; // stores current movie

        if(current_movie != ""THE_END"") //loop break condition
        {
            cin >> current_rating; // stores current rating

            int Movie_Index = search(current_movie, movie_List); //search if movie is already in the vector

            if(Movie_Index != -1) // if movie not present in vector add movie in vector
            {
                
                double new_Rating = movie_List[Movie_Index].get_Rating();
                new_Rating = new_Rating + current_rating; // new sum total of rating
                movie_List[Movie_Index].set_Rating(new_Rating); //insert new sum total of rating to the same movie index
                movie_List[Movie_Index].set_Reviewer();  //increases reviewers count by 1
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                Ratings newMovie(current_movie, current_rating);
                movie_List.push_back(newMovie);
            }
        }
        else
        {
         break;   
        }
    }
    //Code to find maximum avg rating according to dictionary order
    float maximum_averageRating = movie_List[0].get_averageRating();
    string max_movie_name = movie_List[0].get_movie();
    int x=1;
    while(movie_List.size()>x)
    {
        string movie = movie_List[x].get_movie();
        float rating = movie_List[x].get_averageRating();

        if(rating >maximum_averageRating) // check for maximum avg rating
        {
           maximum_averageRating = rating;
           max_movie_name = movie;
        }
        if (maximum_averageRating == rating) // check if rating are equal
        {
            if( movie <  max_movie_name ) //change the movie name according to dictionary order
            {
                max_movie_name = movie;
            }
        }
        x++;
    }
    cout << max_movie_name << "" "";  // print movie name
    printf(""%.1f"", maximum_averageRating); // print max avg rating upto 1 decimal
    return 0;
}