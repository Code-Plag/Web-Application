#include<iostream>
using namespace std;
int main(){
    int arr[]={1,5,2,3,4};
    int counter = 0;
     int index=0;
    for(int  i = 0 ; i < 5 ; i++ ){
       index=i;
        int count = 0;
        bool flag = false;
        counter++;
        for(int  j= i+1 ;j<5;j++){
            if(arr[j] < arr[index]){
                index = j;
                flag=true;
            }
            if(arr[j]<arr[j+1] && j < 5-1){
                count++;
            }
        }
        if(flag==false && count==4-(i+1)){
            cout<<"i broke "<<endl;
            break;
        }
        swap(arr[index],arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<endl;
    }
    cout <<"counter" <<counter<<endl;
    return 0;

}