#include<bits/stdc++.h>
using namespace std;
int main()
{   
    std::multiset<int> ms ;//  8 7 9 1 2 3 4  --- 1 2 3 4 7 8 9
    std::vector<int>vec;// 2 3 4 
    for(int i=0;i<5;i++){
        int data;
        cin>>data;
        ms.insert(data);
    }
    for(int i=0;i<5;i++){
        int data;
        cin>>data;
        vec.push_back(data);
    }
    
    for(int i=0;i<vec.size();i++){
        int counter = 0;
        auto end = ms.upper_bound(vec[i]);
        counter = distance(ms.begin(),end);
        cout << vec[i] <<" ---"<< counter << endl;
    }
    return 0;
  
}





