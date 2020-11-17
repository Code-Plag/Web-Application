#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;
class mr  
{
    string mname; 
    float r; 
    float rev;
public:

    mr()  
    {
        mname = """";
        r = -1;
        rev = -1;
    }
    mr ( string mname, float r ) 
    {
        this->mname = mname;
        this->r = r;
        this->rev = 1;
    }

    
    float get_r()
    {
        return r;
    }
    void set_r(float r)
    {
        this->r = r;
    }

    string get_mname()
    {
        return mname;
    }
    float get_rev()
    {
        return rev;
    }
    void set_rev() 
    {
        rev++;
    }

   
    float avgrat() 
    {
        float avg = r/rev;
        avg = (int)(avg * 10 + 0.5); 
        avg = (float)avg / 10; 
        return avg;
    }
};
int findM(string cm, vector <mr> ml) 
    {
        for(int i = 0; i< ml.size(); i++)
        {
            if(ml[i].get_mname() == cm)
                return i;
        }
        return -1; 
    }
int main()
{
    vector <mr> ml; 
    float cr;
    string cm;
    while(1)
    {
        cin >> cm; 

        if(cm == ""THE_END"")
            break;
        else
        {
            cin >> cr; 

            int mi = findM(cm, ml); 

            if(mi == -1) 
            {
                mr newMovie(cm, cr);
                ml.push_back(newMovie);
            }
            else  
            {
                float new_r = ml[mi].get_r();
                new_r = new_r + cr; // new sum total of rating
                ml[mi].set_r(new_r); //insert new sum total of rating to the same movie index
                ml[mi].set_rev();  //increases reviewers count by 1
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    float max_avgRating = ml[0].avgrat();
    string max_movie_name = ml[0].get_mname();

    for(int i = 1; i < ml.size(); i++)
    {
        string movie = ml[i].get_mname();
        float rating = ml[i].avgrat();

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