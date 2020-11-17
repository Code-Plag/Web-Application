#include <bits/stdc++.h>

using namespace std;

class MOVIE
{
    string movName; // stores movie name
    float totRating; // stores sum total of all ratings
    float totReviewer; // stores sum total of all reviewers

public:

    MOVIE( string name, float rating ) //parameterized constructor
    {
        movName = name;
        totRating = rating;
        totReviewer = 1;
    }

    
    void set_totRating(float totRating)
    {
        this->totRating = totRating;
    }

     float get_totRating()
    {
        return totRating;
    }
    
    string get_movName()
    {
        return movName;
    }
    
     void set_totReviewer() 
    {
        totReviewer++;
    }
    
    float get_totReviewer()
    {
        return totReviewer;
    }
   
    float get_avgRating()
    {
        float avg = totRating/totReviewer;
        avg = (int)(avg * 10 + 0.5); //round off average to one decimal
        avg = (float)avg / 10; // round off average to one decimal
        return avg;
    }
};
int search_Movie(string current_movie, vector <MOVIE> movie_List) //search function to see if movie is already present
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
    vector <MOVIE> movie_List; //vector to store all movies
    float current_rating;
    string current_movie;
    
      do
      {
          
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
                MOVIE newMovie(current_movie, current_rating);
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
    
      }while(1);
      
    float max_avgRating = movie_List[0].get_avgRating();
    string max_movie_name = movie_List[0].get_movName();

    for(int i = 1; i < movie_List.size(); i++)
    {
        string movie = movie_List[i].get_movName();
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
    cout << max_movie_name << "" ""; 
    
    printf(""%.1f"",max_avgRating);
    
  // cout<<setprecision(2)<<max_avgRating;
    
    return 0;
}