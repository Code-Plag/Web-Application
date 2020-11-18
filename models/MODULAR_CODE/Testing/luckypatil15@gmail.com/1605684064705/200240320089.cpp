#include<bits/stdc++.h>
using namespace std;
bool ispresent(string movie, vector<string> unimovies){
for(int i=0; i<unimovies.size(); i++){
if(movie == unimovies[i]) return true;
}
return false;
}

int main(){
vector <int> movierating;
vector <string> movies;

while(1){
string m; int r;
cin>> m;
if(m== ""THE_END"") break;
cin>> r;
movies.push_back(m);
movierating.push_back(r);
}

vector <string> unimovies;
vector <float> unirating;

for(int i=0; i<movies.size(); i++){
if(!ispresent(movies[i], unimovies)){
unimovies.push_back(movies[i]);
}
}

for(int i=0; i<unimovies.size(); i++){
float r=0, cnt=0;
for(int j=0; j<movies.size(); j++){
if(unimovies[i] == movies[j]){
r += movierating[j];
cnt++;
}
}
unirating.push_back(r/cnt);
}

float maxr= unirating[0];
string ans= unimovies[0];
for(int i=0; i<unirating.size(); i++)
if(maxr< unirating[i]){
maxr= unirating[i];
ans= unimovies[i];
}
else if(maxr == unirating[i] && unimovies[i]< ans ){
    ans= unimovies[i];
}
cout<< ans<< "" "";
printf(""%.1f"",maxr);

}