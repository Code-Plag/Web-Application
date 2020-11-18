#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#define  TM   this->movName 
#define  TRT  this->totRating
#define  TRV  this->totReviewer
#define  CM   cin >> current_movie
#define  CR   cin >> current_rating
#define ct  cout << max_movie_name << "" ""; 
using namespace std;
typedef int i;
typedef float f;
typedef string s;
typedef void v;
class MOVIE_RATING
{
    s movName; // stores movie name
    f totRating; // stores sum total of all ratings
    f totReviewer; // stores sum total of all reviewers

public:

    MOVIE_RATING()  // zero parameter constructor
    {
        movName = """";
        totRating = -1;
        totReviewer = -1;
    }
    MOVIE_RATING ( s movName, f totRating ) //parameterized constructor
    {
        TM = movName;
        TRT = totRating;
        TRV = 1;
    }

    //Getter-Setter Functions
    f get_totRating()
    {
        return totRating;
    }
    v set_totRating(f totRating)
    {
        this->totRating = totRating;
    }

    s get_movName()
    {
        return movName;
    }
    f get_totReviewer()
    {
        return totReviewer;
    }
    v set_totReviewer() //function call increases reviewers by 1;
    {
        totReviewer++;
    }

    //average calculation function
    f get_avgRating() // function to get avg rating
    {
        f avg = totRating/totReviewer;
        avg = (i)(avg * 10 + 0.5); //round off average to one decimal
        avg = (f)avg / 10; // round off average to one decimal
        return avg;
    }
};
typedef vector<MOVIE_RATING> vc;
i search_Movie(s current_movie, vc  movie_List) //search function to see if movie is already present
    {
        for(i i = 0; i< movie_List.size(); i++)
        {
            if(movie_List[i].get_movName() == current_movie)
                return i; //return index of the vector where movie is present
        }
        return -1; //returns -1 if movie not present
    }
i main()
{
	
    vc movie_List; //vector to store all movies
    f current_rating;
    s current_movie;
    while(1)
    {
        CM; // stores current movie

        if(current_movie == "THE_END") //loop break condition
            break;
        else
        {
            CR; // stores current rating
			
            i Movie_Index = search_Movie(current_movie, movie_List); //search if movie is already in the vector

            if(Movie_Index == -1) // if movie not present in vector add movie in vector
            {
                MOVIE_RATING newMovie(current_movie, current_rating);
                movie_List.push_back(newMovie);
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                f new_totRating = movie_List[Movie_Index].get_totRating();
                new_totRating = new_totRating + current_rating; // new sum total of rating
                movie_List[Movie_Index].set_totRating(new_totRating); //insert new sum total of rating to the same movie index
                movie_List[Movie_Index].set_totReviewer();  //increases reviewers count by 1
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    f max_avgRating = movie_List[0].get_avgRating();
    s max_movie_name = movie_List[0].get_movName();
	
    for(i i = 1; i < movie_List.size(); i++)
    {
        s movie = movie_List[i].get_movName();
        f rating = movie_List[i].get_avgRating();

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
    ct // print movie name
    i i;
    printf("%.1f", max_avgRating); // print max avg rating upto 1 decimal
    return 0;
}
