#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main()
{
    map<string,float> movie;
    vector<string> mname;
    string st;
    int rating;
    while(1)
    {
        cin>>st>>rating;
        if(st == ""THE_END"")
            break;
            mname.push_back(st);
            if(movie.find(st)!=movie.end())
            {
                movie[st]+=rating;
            }
            else{
                
                    movie[st]=rating;        
            }
    }
    sort(mname.begin(),mname.end());
    int count=1;
    st=mname[0];
    for(int i=1; i<mname.size() ;i++)
    {
        if(st==mname[i])
        {
            count++;
            if(i==mname.size()-1)
            {
                 movie[st]=(float)movie[st]/count;
                 break;
            }
        }
        else{
            movie[st]=(float)movie[st]/count;
            st=mname[i];
            count=1;
             if(i==mname.size()-1)
            {
                 movie[st]=(float)movie[st]/count;
                 break;
            }
        }
    }
    float maxi=movie[mname[0]];
    string maxm=mname[0];
    for(int i=1;i<mname.size();i++)
    {
        if(maxi<movie[mname[i]])
        {
            maxm=mname[i];
            maxi=movie[mname[i]];
            
        }
    }
    cout<<maxm<<"" "";
    printf(""%.1f"", maxi);
    
    return 0;
}