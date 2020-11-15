#include<iostream>
#include<map>
#include<cstring>
#include<string.h>
#include<vector>
using namespace std;

vector<string>vec;


void permutation(string str,string prefix){//laxman -- l axman
    if(str.length()== 0){
       // map2[prefix]++;
        vec.push_back(prefix);
        cout<<prefix<<endl;
    }
    for(int i = 0 ; i < str.length() ; i++){
        string rem = str.substr(0,i)+str.substr(i+1);// l axman-- la xman-- lax man laxman// 2nd la xman
        permutation(rem,prefix+str[i]);// xman 
    }
}
int main(){
    string s1="abcdefghi";
    permutation(s1,"");
    cout<<vec.size()<<endl;
    return 0;
}