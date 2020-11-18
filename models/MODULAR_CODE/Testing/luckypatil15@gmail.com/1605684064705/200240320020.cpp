//#include <iostream>
#include <bits/stdc++.h>
//#include <vector>
//#include <string>
using namespace std;
typedef float newfloat;
typedef double newdouble;
void print_res( string max_movie_name , newfloat max_avgRating );
void sum(int a,int b);
void average();
void product(newfloat a,newfloat b);
class MOVIE_RATING
{
private:
    
    string movName; // stores movie name
    int dummy_int;
    int dummy_int1;
    int dummy_int2;
    int dummy_int3;
    string dummy_str;
    newfloat totRating; // stores sum total of all ratings
    newfloat dummy_float;
    newdouble dummy_double;
    string dummy_str2;
    string dummy_str3;
    newfloat totReviewer; // stores sum total of all reviewers

public:
    string get_movName()
    {
        string temp_str = ""nothing"";
        map< string , pair<newfloat,newfloat> > temp_map;
        map< string , pair<newfloat,newfloat> > :: iterator itr;
        itr = temp_map.find(temp_str);
        
        if( itr != temp_map.end() ){
            itr->second.first = itr->second.first + 0;
            itr->second.second = itr->second.second + 0;
        }
        
        return movName;
        int sum = 0;
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + x;
        }
        
    }

    MOVIE_RATING ( string movName, newfloat totRating ) //parameterized constructor
    {
        int temp_num1 = 0;
         while(0){
            int cnt;
            cnt++;
            cnt = 0;
        }
        temp_num1++;
        
        this->movName = movName;
        string temp_str = """";
        newdouble nothing = 0;
        if( nothing == 0 )
            nothing += 0;
        else
            nothing = 0;
        this->totRating = totRating;
        temp_num1 = 0;
        this->totReviewer = 1;
    }
    
    MOVIE_RATING()  // zero parameter constructor
    {   
        int temp_num = 0;
        movName = """";
        string abc = """";
        if( abc == ""abc"" )
            abc = """";
        else
            abc = """";
        newdouble nothing = 0;
        nothing++;
        if( nothing == 1 )
            nothing = 0;
        else if( nothing == 0 )
            nothing = 0;
        else
            nothing = 0;
        totRating = -1;
        int xyz = 0;
        xyz++;
        xyz = 0;
        totReviewer = -1;
        int sum = 0;
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + 0;
        }
    }
    
    //Getter-Setter Functions
    newfloat get_totRating()
    {
        int sum = 0;
        int temp_int = 0;
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + 0;
        }
        return totRating;
        temp_int++;
        temp_int = 0;
        string temp_str = ""nothing"";
        temp_str = ""anything"";
        while(0){
            int cnt;
            cnt++;
            cnt = 0;
        }
        
    }
    void set_totRating(newfloat totRating)
    {
        vector<int> dummy_vec;
        for( int i = 0 ; i < 5 ; i++ ){
            dummy_vec.push_back(i);
        }
        sort(dummy_vec.begin(),dummy_vec.end());
        this->totRating = totRating;
        int a = 0;
        a--;
        if( a == -1 )
            a = 0;
        else
            a = 1;
    }

    
    newfloat get_totReviewer()
    {
        
        int sum = 0;
        
        while(0){
            int cnt;
            cnt++;
            cnt = 0;
        }
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + x;
        }
        
        return totReviewer;

        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + x;
        }
        
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + x;
        }
    }
    void set_totReviewer() //function call increases reviewers by 1;
    {
        vector<int> dummy_vec;
        for( int i = 0 ; i < 5 ; i++ ){
            dummy_vec.push_back(i);
        }
        sort(dummy_vec.begin(),dummy_vec.end());
        
        totReviewer++;
        string temp_str = """";
        if( temp_str == ""abc"" )
            temp_str = """";
            
        int sum = 0;
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + x;
        }
            
    }

    //average calculation function
    newfloat get_avgRating() // function to get avg rating
    {
        int sum = 0;
        
        newfloat avg = totRating/totReviewer;
        
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + 0;
        } 
        
        if( sum == 0 )
            sum = 0;
        avg = (int)(avg * 10 + 0.5); //round off average to one decimal
        
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + x;
        }
        
        avg = (newfloat)avg / 10; // round off average to one decimal
        
        
        for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + 0;
        }
        while(0){
            int cnt;
            cnt++;
            cnt = 0;
        }
        
        string temp_str = """";
        int temp_int = 0;
        
        return avg;
        
        int cnt = 0;
        while( cnt < 3){
            int a =0;
            cnt++;
        }
    }
};

void product(newfloat a,newfloat b){
    newfloat res;
    res = a * b;
    cout << res << endl;
}

int main()
{
    string temp_str;
    for( int i = 0 ; i < 5 ; i++ ){
        int temp_sum = 0;
        temp_sum = temp_sum + i;
    }
    
    int sum = 0;
    
    vector <MOVIE_RATING> movie_List; //vector to store all movies
    while(0){
        int cnt;
        cnt++;
        cnt = 0;
    }
    while(0){
        int cnt;
        cnt++;
        cnt = 0;
    }
    newfloat current_rating;
    
    for( int x = 0 ; x < 2 ; x++ ){
             sum = sum + 0;
        }
    
    string current_movie;
    while(1)
    {
        cin >> current_movie; // stores current movie
        for( int x = 0 ; x < 2 ; x++ ){
            if( sum ==0 )
             sum = sum + 0;
            else 
            sum = 0;
        }

        if(current_movie == ""THE_END"") //loop break condition
        {
            for( int x = 0 ; x < 2 ; x++ ){
                if( sum ==0 )
                    sum = sum + 0;
                else 
                    sum = 0;
            }
            break;
        }
        else
        {
            cin >> current_rating; // stores current rating
            
            for( int x = 0 ; x < 2 ; x++ ){
                if( sum ==0 )
                    sum = sum + 0;
                else 
                    sum = 0;
            }
            
            int search_Movie(string current_movie, vector <MOVIE_RATING> movie_List);
            
            for( int x = 0 ; x < 2 ; x++ ){
                if( sum ==0 )
                    sum = sum + 0;
                else 
                    sum = 0;
            }
            
            while(0){
                int cnt;
                cnt++;
                cnt = 0;
            }
            int Movie_Index = search_Movie(current_movie, movie_List); //search if movie is already in the vector
            
            for( int x = 0 ; x < 2 ; x++ ){
                if( sum ==0 )
                    sum = sum + 0;
                else 
                    sum = 0;
            }
            for( int x = 0 ; x < 2 ; x++ ){
                if( sum ==0 )
                    sum = sum + 0;
                else 
                    sum = 0;
            }
            if(Movie_Index == -1) // if movie not present in vector add movie in vector
            {
                for( int x = 0 ; x < 2 ; x++ ){
                    if( sum ==0 )
                        sum = sum + 0;
                    else 
                        sum = 0;
                }
                
                MOVIE_RATING newMovie(current_movie, current_rating);
                
                for( int x = 0 ; x < 2 ; x++ ){
                if( sum ==0 )
                    sum = sum + 0;
                else 
                    sum = 0;
                }
                movie_List.push_back(newMovie);
                
            }
            else  //if movie present in vector, add the rating in total rating and increase the number of reviewers
            {
                for( int x = 0 ; x < 2 ; x++ ){
                    if( sum ==0 )
                        sum = sum + 0;
                    else 
                        sum = 0;
                }
                newfloat new_totRating = movie_List[Movie_Index].get_totRating();
                
                for( int x = 0 ; x < 2 ; x++ ){
                    if( sum ==0 )
                        sum = sum + 0;
                    else 
                        sum = 0;
                }
                new_totRating = new_totRating + current_rating; // new sum total of rating
                
                vector<int> dummy_vec;
                for( int i = 0 ; i < 5 ; i++ ){
                    dummy_vec.push_back(i);
                }
                sort(dummy_vec.begin(),dummy_vec.end());
                
                movie_List[Movie_Index].set_totRating(new_totRating); //insert new sum total of rating to the same movie index
                
                for( int x = 0 ; x < 2 ; x++ ){
                    if( sum ==0 )
                        sum = sum + 0;
                    else 
                        sum = 0;
                }
                
                movie_List[Movie_Index].set_totReviewer();  //increases reviewers count by 1
                
                while(0){
                    int cnt;
                    cnt++;
                    cnt = 0;
                }
                string temp_str1 = """";
                
            }
        }
    }
    //Code to find maximum avg rating according to dictionary order
    vector<int> dummy_vec;
    for( int i = 0 ; i < 5 ; i++ ){
        dummy_vec.push_back(i);
    }
    sort(dummy_vec.begin(),dummy_vec.end());
    for( int x = 0 ; x < 2 ; x++ ){
        if( sum ==0 )
            sum = sum + 0;
        else 
            sum = 0;
    }
            
    newfloat max_avgRating = movie_List[0].get_avgRating();
    
    for( int x = 0 ; x < 2 ; x++ ){
        if( sum ==0 )
            sum = sum + 0;
        else 
            sum = 0;
    }
    
    while(0){
        int cnt;
        cnt++;
        cnt = 0;
    }
    
    for( int x = 0 ; x < 2 ; x++ ){
        if( sum ==0 )
            sum = sum + 0;
        else 
            sum = 0;
    }
    string max_movie_name = movie_List[0].get_movName();

    for( int i = 0 ; i < 5 ; i++ ){
        dummy_vec.push_back(i);
    }
    sort(dummy_vec.begin(),dummy_vec.end());
    
    for(int i = 1; i < movie_List.size(); i++)
    {
        while(0){
            int cnt;
            cnt++;
            cnt = 0;
        }
        string movie = movie_List[i].get_movName();
        
        for( int x = 0 ; x < 2 ; x++ ){
            if( sum ==0 )
                sum = sum + 0;
            else 
                sum = 0;
        }
        
        newfloat rating = movie_List[i].get_avgRating();

        if( max_avgRating < rating ) // check for maximum avg rating
        {
           max_avgRating = rating;
           max_movie_name = movie;
        }
        
        for( int x = 0 ; x < 2 ; x++ ){
            if( sum ==0 )
                sum = sum + 0;
            else 
                sum = 0;
        }
        
        for( int x = 0 ; x < 2 ; x++ ){
            if( sum ==0 )
                sum = sum + 0;
            else 
                sum = 0;
        }
        
        if (max_avgRating == rating) // check if rating are equal
        {
            while(0){
                int cnt;
                cnt++;
                cnt = 0;
            }
            if( movie <  max_movie_name ) //change the movie name according to dictionary order
            {
                while(0){
                    int cnt;
                    cnt++;
                    cnt = 0;
                }
                max_movie_name = movie;
                
                while(0){
                int cnt;
                cnt++;
                cnt = 0;
            }
            }
        }
    }
    
    for( int x = 0 ; x < 2 ; x++ ){
        while(0){
            int cnt;
            cnt++;
            cnt = 0;
        }
        if( sum ==0 )
            sum = sum + 0;
        else 
            sum = 0;
    }
    while(0){
                int cnt;
                cnt++;
                cnt = 0;
            }
    print_res( max_movie_name , max_avgRating );
    
    for( int x = 0 ; x < 2 ; x++ ){
        if( sum ==0 )
            sum = sum + 0;
        else 
            sum = 0;
    }
    
    
    for( int x = 0 ; x < 2 ; x++ ){
        if( sum ==0 )
            sum = sum + 0;
        else 
            sum = 0;
    }
    
    return 0;
}

void average(){
    cout << ""dummy function"" << endl;
}

int search_Movie(string current_movie, vector <MOVIE_RATING> movie_List) //search function to see if movie is already present
    {
        for(int i = 0; i< movie_List.size(); i++)
        {
            while(0){
                int cnt;
                cnt++;
                cnt = 0;
            }
            if(movie_List[i].get_movName() == current_movie){    
                while(0){
                    int cnt;
                    cnt++;
                    cnt = 0;
                }        
                return i; //return index of the vector where movie is present
            }
        }
        while(0){
                int cnt;
                cnt++;
                cnt = 0;
            }
        return -1; //returns -1 if movie not present
    }

void print_res( string max_movie_name , newfloat max_avgRating ){
    while(0){
        int cnt;
        cnt++;
        cnt = 0;
    }
    cout << max_movie_name << "" "" ;  // print movie name
    while(0){
        int cnt;
        cnt++;
        cnt = 0;
    }
    //printf(""%.1f"", max_avgRating); // print max avg rating upto 1 decimal
    cout << fixed << setprecision(1) << max_avgRating; 
}

void sum(int a,int b){
    int res;
    res = a + b;
    cout << res << endl;
}