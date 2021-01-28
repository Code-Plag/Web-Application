#include<iostream>
#include<iomanip>
using namespace std;

struct Node
{
public:
    string name;
    double rating;    
    int flag;
};

int main()
{
    int i,j,k=0;
    struct Node arr[50];
    struct Node temp;
//    struct Node *temp1;
//    temp1=arr;
    for(i=0;i<50;i++)
    {
        arr[i].flag=0;
    }
    string movie;
    double rate;
    cin>>movie>>rate;
    if(movie==""THE_END"")
        return 0;
    arr[0].name=movie;
    arr[0].rating=rate;
    arr[0].flag=1;
    k=1;
    while(1)
    {
        j=0;
        cin>>movie;
        if(movie!=""THE_END"")
        {   
            cin>>rate;
//            for(j=0;arr[j].flag!=0;j++)
            while(arr[j].flag!=0)
            {
                if(movie==arr[j].name)
                {
                    arr[j].rating+=rate;
                    arr[j].flag++;
                    break;
                }
                else 
                    j++;
            }
            if(arr[j].flag==0)
            {
                arr[j].name=movie;
                arr[j].rating=rate;
                arr[j].flag=1;    
                k++;
            }
        }
        else
            break;
    }
    for(i=0;i<k-1;i++)
        for(j=i+1;j<k;j++)
            if(arr[i].name>arr[j].name)
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
    for(i=0;i<k-1;i++)
        for(j=i+1;j<k;j++)
            if((arr[i].rating/arr[i].flag)<(arr[j].rating/arr[j].flag))
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }        
    cout<<arr[0].name<<"" ""<<fixed<<setprecision(1)<<(arr[0].rating/arr[0].flag);        
    return 0;
}