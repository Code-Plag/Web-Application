#include<iostream>
#include<map>
#include<cstring>
#include<string.h>
#include<vector>
using namespace std;
map <string,int> map2;
string comb(string s){
    string palindrome = "";
    for(int i=s.length()-1 ; i >= 0 ; i--){
        
        palindrome = palindrome + s[i];
    }

    return palindrome;
}

void permutation(string str,string prefix){
    if(str.length()== 0){
        map2[prefix]++;
    }
    for(int i = 0 ; i < str.length() ; i++){
        string rem = str.substr(0,i)+str.substr(i+1);
        permutation(rem,prefix+str[i]);
    }
}
int main(){
    int t; // no of test cases
    cin >> t; 
    for(int i = 0 ; i < t ; i++){// 
        string str;
        cin >> str ;
        map<char,int>map1; // map to check frequencies of the characters
        for(int j = 0 ; j < str.length() ; j++){
            map1[str[j]]++;
        }
      //to manipulate the palindrome taking array
        char ch[str.length()];
        int l = 0 ;   //l index that puts the repeating characters at start and end
        bool flag = false; // flag to leave the  loop as no word can be palindrome if it has 2 characters having odd frequency
        bool no_palindrome_flag = false;// to print the no palindrome statement
      // for loop over map
        for(auto x : map1 ){
            if( (x.second) % 2 == 0 ){ // condition in which frequency is even
                int n =x.second;
                while( n != 0){
                    ch[l]=x.first;                  // to put a letter at start
                    ch[(str.length()-1)-l]=x.first; // to put letter at end
                    l++;
                    n=n-2;
                }
            }
            else if((x.second) % 2 != 0  && flag == false){ // condtion in which frequency is odd
                flag = true; 
                int n = x.second;                   
                ch[(str.length()-1) / 2] =x.first; //to put the letter havingodd frequency at centre
                n--;
                while(n!=0){
                    ch[l]=x.first;
                    ch[(str.length()-1)-l]=x.first;
                    l++;
                    n=n-2;
                }
            }
            else{ // condition for braking loop
                no_palindrome_flag = true;
                break;
            }
        }
        if(no_palindrome_flag){
            cout << "No Palindrome" << endl;
        }
        
        else if(str.length()%2 == 0){
            int counter=1;
            string main(ch);
            int centre_pos = (str.length()/2)-1;
            string centre_part = main.substr(centre_pos,centre_pos+1);
            string permute= main.substr(0,centre_pos+1);
            permutation(permute,"");
            cout<<"All Palindromes of the given string : "<<str <<endl;
            for(auto Y : map2){
                string temp = Y.first;
                string palindrome = comb(temp);
                string output = temp  + palindrome ;
                cout <<counter++<<"-"<<output <<endl;
            }
        }

        else if(str.length()%2 != 0){
            int counter=1;
            string main1(ch);
            string main = main1;
            int centre_pos = (str.length()/2);
            string centre_part = "";
            centre_part=main[centre_pos];
            string permute= main.substr(0,centre_pos);
            permutation(permute,"");
            cout<<"All Palindromes of the given string : "<<str <<endl;
            for(auto Y : map2){
                string temp = Y.first;
                string palindrome = comb(temp);
                string output = temp + centre_part + palindrome ;
                cout <<counter++<<"-"<<output <<endl;
            }
        }
    }

  
    return 0;
}