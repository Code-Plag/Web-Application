# include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class MOVIE_RATING
{
    string movName; 
    float totRating; 
    float totReviewer; 
    
public:

    MOVIE_RATING()  
    {
        movName = """";
        totRating = -1;
        totReviewer = -1;
    }
    MOVIE_RATING ( string movName, float totRating ) 
    {
        this->movName = movName;
        this->totRating = totRating;
        this->totReviewer = 1;
    }

    
    float get_totRating()
    {
        return totRating;
    }
    void set_totRating(float totRating)
    {
        this->totRating = totRating;
    }

    string get_movName()
    {
        return movName;
    }
    float get_totReviewer()
    {
        return totReviewer;
    }
    void set_totReviewer() 
    {
        totReviewer++;
    }

    //average calculation function
    float get_avgRating() 
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
                return i; 
        }
        return -1;
        
    }
int main()
{
    vector <MOVIE_RATING> movie_List; //vector to store all movies
    float current_rating;
    string current_movie;
    while(1)
    {
        cin >> current_movie; 

        if(current_movie == ""THE_END"") 
            break;
        else
        {
            cin >> current_rating; 

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
    cout << max_movie_name << "" "";  
    printf(""%.1f"", max_avgRating); 
    return 0;
}