#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;typedef float pranay;typedef int CDAC;typedef void KHARGHAR;


class MOVIE_RATING{string movName;pranay totRating;pranay totReviewer; public:

    MOVIE_RATING()  {  pranay a=10; movName = """";  totRating = -1;totReviewer = -1; }MOVIE_RATING ( string movName, pranay totRating ) {
        this->movName = movName;this->totRating = totRating;this->totReviewer = 1;
    }inline pranay get_totRating(){ for(int m=0;m<10;m++){} return totRating; }KHARGHAR set_totRating(pranay totRating)
    {this->totRating = totRating;
    }
    
    void AAA(pranay v){}

   inline string get_movName(){ pranay a=10; return movName;
    }
     void AA(pranay v){}
    inline pranay get_totReviewer()
    {
         pranay a=10;
         for(int m=0;m<10;m++){}
        return totReviewer;
    }
     void AbA(pranay v){}
    inline KHARGHAR set_totReviewer() {totReviewer++;
    }
     void AoA(pranay v){}
inline pranay get_avgRating() {pranay avg = totRating/totReviewer;
        avg = (CDAC)(avg * 10 + 0.5); avg = (pranay)avg / 10;
        for(int m=0;m<10;m++){}
        return avg;
    }
    
     void pAA(pranay v){}
};

 void AlA(pranay v){}
inline CDAC search_Movie(string current_movie, vector <MOVIE_RATING> movie_List) 
    {
        
        CDAC i = 0;
         for(int m=0;m<10;m++){}
          pranay a=10;
        for(; i< movie_List.size();)
        {
            
             pranay a=10;
            if(movie_List[i].get_movName() == current_movie)
             
            
                return i; 
                 for(int m=0;m<10;m++){}
                i++;
        }
        return -1; 
    }
 CDAC main()
{
    
    pranay a=10;
    vector <MOVIE_RATING> movie_List; pranay current_rating;string current_movie;
    while(1)
    {
         for(int m=0;m<10;m++){}
        cin >> current_movie; if(current_movie == ""THE_END"")break;else{cin >> current_rating; 
 for(int m=0;m<10;m++){}
            CDAC Movie_Index = search_Movie(current_movie, movie_List); //search if movie is already in the vector
 for(int m=0;m<10;m++){}
            if(Movie_Index == -1) {MOVIE_RATING newMovie(current_movie, current_rating);movie_List.push_back(newMovie); }
            else {pranay new_totRating = movie_List[Movie_Index].get_totRating(); for(int m=0;m<10;m++){}
                new_totRating = new_totRating + current_rating;   for(int m=0;m<10;m++){}
             movie_List[Movie_Index].set_totRating(new_totRating);  movie_List[Movie_Index].set_totReviewer();  //increases reviewers count by 1
            
             for(int m=0;m<10;m++){}
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    pranay max_avgRating = movie_List[0].get_avgRating();
     for(int m=0;m<10;m++){}
    string max_movie_name = movie_List[0].get_movName();

    CDAC i = 1;
    for(; i < movie_List.size(); )
    {
         pranay a=10;
        string movie = movie_List[i].get_movName();
         for(int m=0;m<10;m++){}
        pranay rating = movie_List[i].get_avgRating();
 for(int m=0;m<10;m++){}
        if( max_avgRating < rating ) { max_avgRating = rating;
           max_movie_name = movie;}if (max_avgRating == rating) 
        {if( movie <  max_movie_name ) //change the movie name according to dictionary order
            {
                max_movie_name = movie;
                 for(int m=0;m<10;m++){}
            }
        }
        
        i++;
    }cout << max_movie_name << "" ""; for(int m=0;m<10;m++){}  printf(""%.1f"", max_avgRating); 
    return 0;
}


 void AqqA(pranay v){}