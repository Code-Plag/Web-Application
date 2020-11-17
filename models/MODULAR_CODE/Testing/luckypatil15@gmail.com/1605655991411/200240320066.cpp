#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

class movie_Rating
{
    string mname; //movie name
    float totalr; //total ratings
    int totalreview; //total reviewers
    
    public:
     movie_Rating()
     {
         mname="" "";
         totalr=-1;
         totalreview=-1;;
     }
     
     movie_Rating(string movien, float treview)
     {
         //cout<<""in constructor"";
         mname=movien;
         totalr=treview;
         totalreview=1;
    }
    
    string get_mname()
    {
        return mname;
    }
    void set_totalr(float treview)
    {
        totalr=treview;
    }
    float get_totalr()
    {
        return totalr;
    }
    void set_totalreview()
    {
        totalreview=totalreview+1;
    }
    
    float avg_rating()
    {
       // cout<<""in avg rating"";
       //cout<<totalr<<"" ""<<totalreview<<endl;
        float average = totalr/totalreview;
        average = (int)(average * 10 + 0.5);
        average = (float)average/10;
        //cout<<""average = ""<<average<<endl;
        return average;
    }
};

int movie_Search(string movie_curr, vector <movie_Rating> mlist)
{   
    for(int i = 0; i< mlist.size(); i++)
    {
        if(mlist[i].get_mname() == movie_curr)
        return i;
    }    
    
    return -1;
    
}

int main()
{
    //cout<<""in main"";
    vector <movie_Rating> mlist;
    float rating_curr;
    string movie_curr;
    
    while(1)
    {
        //cout<<""in while""<<endl;
        cin>>movie_curr;
        //cout<<""movie_curr""<<endl;
        if(movie_curr == ""THE_END"")
            break;
        else
        {
            //cout<<""in 1st else""<<endl;
            cin>>rating_curr;
            //cout<<""got ratings""<<endl;
            int index = movie_Search(movie_curr, mlist);
            //cout<<""index = ""<<index<<endl;
            //cout<<""fun call done""<<endl;
            if(index == -1) 
            {
                //cout<<""in if 1"";
               movie_Rating newm(movie_curr, rating_curr);
               mlist.push_back(newm);
            }
            
            else
            {
                //cout<<""in else 1"";
                float new_total = mlist[index].get_totalr();
                new_total = new_total + rating_curr;
                mlist[index].set_totalr(new_total);
                mlist[index].set_totalreview();
            }
        }
        
     }
     
     float max_rating = mlist[0].avg_rating();
     string max_mname = mlist[0].get_mname();
     
     for(int i=1; i < mlist.size(); i++)
     {
         //cout<<""in for 1"";
         string movie_name = mlist[i].get_mname();
         float mrating = mlist[i].avg_rating();
         
         if(max_rating < mrating )
         {
             //cout<<""in if 2"";
             max_rating = mrating;
             max_mname = movie_name;
         }
         if(max_rating == mrating)
         {
             //cout<<""in if 3"";
             if(movie_name < max_mname)
             {
                 max_mname = movie_name;
             }
         }
     }
     
     cout<<max_mname<<"" "";
     cout<<fixed<<setprecision(1)<<max_rating;
     return 0;
    
}