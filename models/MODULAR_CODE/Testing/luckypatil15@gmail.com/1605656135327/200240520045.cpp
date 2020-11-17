#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class MOVER
{
    string mName; 
    float tot_Rat; 
    float tot_Revi; 

public:

    MOVER()  
    {
        mName = """";
        tot_Rat = -1;
        tot_Revi = -1;
    }
    MOVER ( string mName, float tot_Rat ) 
    {
        this->mName = mName;
        this->tot_Rat = tot_Rat;
        this->tot_Revi = 1;
    }

  
    float get_tot_Rat()
    {
        return tot_Rat;
    }
    void set_tot_Rat(float tot_Rat)
    {
        this->tot_Rat = tot_Rat;
    }

    string get_mName()
    {
        return mName;
    }
    float get_tot_Revi()
    {
        return tot_Revi;
    }
    void set_tot_Revi() 
    {
        tot_Revi++;
    }

    
    float get_aR() 
    {
        float avg = tot_Rat/tot_Revi;
        avg = (int)(avg * 10 + 0.5); 
        avg = (float)avg / 10; 
        return avg;
    }
};
int search_Movie(string current_movie, vector <MOVER> movie_List) 
    {
        for(int i = 0; i< movie_List.size(); i++)
        {
            if(movie_List[i].get_mName() == current_movie)
                return i; 
        }
        return -1; 
    }
int main()
{
    vector <MOVER> movie_List; 
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
                MOVER newMovie(current_movie, current_rating);
                movie_List.push_back(newMovie);
            }
            else  
            {
                float new_tot_Rat = movie_List[Movie_Index].get_tot_Rat();
                new_tot_Rat = new_tot_Rat + current_rating; 
                movie_List[Movie_Index].set_tot_Rat(new_tot_Rat); 
                movie_List[Movie_Index].set_tot_Revi(); 
            }
        }
    }
    
    float max_aR = movie_List[0].get_aR();
    string max_movie_name = movie_List[0].get_mName();

    for(int i = 1; i < movie_List.size(); i++)
    {
        string movie = movie_List[i].get_mName();
        float mo = movie_List[i].get_aR();

        if( max_aR < mo ) 
        {
           max_aR = mo;
           max_movie_name = movie;
        }
        if (max_aR == mo) 
        {
            if( movie <  max_movie_name ) 
            {
                max_movie_name = movie;
            }
        }
    }
    cout << max_movie_name << "" "";  
    printf(""%.1f"", max_aR); 
    return 0;
}