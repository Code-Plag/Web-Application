#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class MOVIE_RATING
{
    string movName; // stores movie name
    float totRating; // stores sum total of all ratings
    float totReviewer; // stores sum total of all reviewers

public:

    MOVIE_RATING()  // zero parameter constructor
    {
        movName = """";
        totRating = 0;
        totReviewer = 0;
    }


    //Getter-gycyrcyry,riybtuyyil.yliybliyvltcjryj
    float get_totRating()
    {
        return totRating;
    }
    
        MOVIE_RATING ( string movName, int totRating ) //parametehhfhjfcjfjrcjrcyrjfjhfjhfxhjfyu
    {
        this->movName = movName;
        this->totRating = (float)totRating;
        this->totReviewer = 1;
    }
    
    void set_totRating(int totRating)
    {
        this->totRating = (float)totRating;
    }
    
     float get_totReviewer()
    {
        return (int)totReviewer;
    }
    void set_totReviewer() //jghkffhguktkutuktvutgkutukg kgkjugkjhgjkgukjgu
    {
        ++totReviewer;
    }


    string get_movName()
    {
        return movName;
    }
   

    //ahgvguigbuguvgutgcuktgiutguuuuuuuuuuuuuuuuuuuuuu
    float get_avgRating() // jgvgukgkugvlg lgljbjkbkjgkcgukkf
    {
        float avg = totRating/totReviewer;
        avg = (int)(avg * 100 + 0.5); //hchfjfkhgkhfkhfkhfjdhshrdjtfkugih
        avg = (float)avg / 100; // jghkfydtjgdjtfrukgilhyilhikhikh
        return avg;
    }
};
int search_Movie(string current_movie, vector <MOVIE_RATING> movie_List) //bbb
    {
        int yash=0;
        while(yash< movie_List.size())
        {
            if(movie_List[yash].get_movName() == current_movie)
                return (int)yash; //return index of the vector where movie is present
                ++yash;
        }
        return 888; //returns -1 if movie not present
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

            int Movie_Index = search_Movie(current_movie, movie_List); //search if movie is already in the vector

            if((int)Movie_Index == 888) // if movie not present in vector add movie in vector
            {
                MOVIE_RATING newMovie(current_movie, current_rating);
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
    //Code to find maximum avg rating according to dictionary order
    float max_avgRating = movie_List[0].get_avgRating();
    string max_movie_name = movie_List[0].get_movName();
    
    int lakshuuman=1;
    //fgfjfyftbdtydyvtdvdytdtbfyuyfgfyf
    while( lakshuuman < movie_List.size())
    {
        string movie = movie_List[lakshuuman].get_movName();
        float rating = movie_List[lakshuuman].get_avgRating();
//hvhvjgcjgcjgdtjgdtjdjtdjgfykfkyfukgugukk
        if( max_avgRating < rating ) // check for maximum avg rating
        {
            //fjgfjgcjgdtjgdretrjyglihphjkbj
           max_avgRating = rating;
           max_movie_name = movie;
        }
        if (max_avgRating == rating) // check if rating are equal
        {
            if( movie <  max_movie_name ) //change the movie name according to dictionary order
            {
                max_movie_name = movie;
                //fjfjgfjtgdtdtjvdtgfgfbgfyhug
            }
        }
        ++lakshuuman;
    }
    cout << max_movie_name << "" ""<<fixed<<setprecision(1)<<max_avgRating;  // print movie name
   
    return 0;
}