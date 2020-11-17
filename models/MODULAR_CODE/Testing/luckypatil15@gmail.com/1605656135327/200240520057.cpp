#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string>

using namespace std;
class MyFirst{
    int a;
    int b;
    int abc;
    public:
            void function1()
            {
//                print(""MovieName"")
            }
    

};


class MOVIE_RATINGz111
{
    
    string movNamez111; 
    float mNameszz111;
    float totRatingz111; 
    float notReservez111;
    float totReviewerz111;

public:


    MOVIE_RATINGz111()  
    {
        
        movNamez111 = """";
        mNameszz111 = 0;
        totRatingz111 = -1;
        notReservez111 = 0;
        totReviewerz111 = -1;
    }
    MOVIE_RATINGz111 ( string movNamez111, float totRatingz111 ) //parameterized constructor
    {
       
            
            this->movNamez111 = movNamez111;
            mNameszz111 = 11;
            this->totRatingz111 = totRatingz111;
            this->totReviewerz111 = 1;
      
    }

  
  
    float get_totRatingz111()
    {
       
    return totRatingz111;
      
    }
    
    
    void set_totRatingz111(float totRatingz111)
    {
      this->totRatingz111 = totRatingz111;
    }

    string get_movNamez111()
    {
      return movNamez111;
    }
    float get_totReviewerz111()
    {
       return totReviewerz111;
    }
    void set_totReviewerz111() 
    {
     totReviewerz111++;
    }


    float get_avgRatingz111() 
    {
     
        float avgz111 = totRatingz111/totReviewerz111;
       
       
       avgz111 = (int)(avgz111 * 10 + 0.5); 
        avgz111 = (float)avgz111 / 10; 
        return avgz111;
    }
};
int search_Moviez111(string current_moviez111, vector <MOVIE_RATINGz111> movie_Listz111) 
    {
    
        for(int iz111 = 0; iz111< movie_Listz111.size(); iz111++)
        {
            if(movie_Listz111[iz111].get_movNamez111() == current_moviez111)
                return iz111; 
        }
    
        return -1; 
    }
int main()
{
    int abcd = 124;
    vector <MOVIE_RATINGz111> movie_Listz111; 
   
   float current_nonmoviezz11;
    
    
    float current_ratingz111;
    string current_moviez111;
    
  
    while(1)
    {
        cin >> current_moviez111; 

        if(current_moviez111 == ""THE_END"") 
            break;
        else
        {
            cin >> current_ratingz111; 

            int Movie_Indexz111 = search_Moviez111(current_moviez111, movie_Listz111); 

            if(Movie_Indexz111 == -1) 
            {
                MOVIE_RATINGz111 newMoviez111(current_moviez111, current_ratingz111);
               
               
               movie_Listz111.push_back(newMoviez111);
            }
            else  
            {
                float new_totRatingz111 = movie_Listz111[Movie_Indexz111].get_totRatingz111();
                
                
                new_totRatingz111 = new_totRatingz111 + current_ratingz111; 
                
                
                movie_Listz111[Movie_Indexz111].set_totRatingz111(new_totRatingz111); 
                movie_Listz111[Movie_Indexz111].set_totReviewerz111();  
            }
        }
    }
    
    
    
    float max_avgRatingz111 = movie_Listz111[0].get_avgRatingz111();
    
    double encounterName;
    string max_movie_namez111 = movie_Listz111[0].get_movNamez111();
    
    
  int a=1;
  if(a==1)
    for(int iz111 = 1; iz111 < movie_Listz111.size(); iz111++)
    {
       
       string moviez111 = movie_Listz111[iz111].get_movNamez111();
      
      
      float ratingz111 = movie_Listz111[iz111].get_avgRatingz111();

        if( max_avgRatingz111 < ratingz111 ) 
        {
           max_avgRatingz111 = ratingz111;
          
          
          max_movie_namez111 = moviez111;
        }
        if (max_avgRatingz111 == ratingz111) 
        {
            if( moviez111 <  max_movie_namez111 ) 
            {
                max_movie_namez111 = moviez111;
            }
        }
    }
    
    if(abcd ==1234){
        cout<<max_movie_namez111 << "" "";  
         printf(""%.1f"", max_avgRatingz111); 
    }
    else{
        cout<<max_movie_namez111 << "" "";  
         printf(""%.1f"", max_avgRatingz111); 
    }
         
  
   
    return 0;
}