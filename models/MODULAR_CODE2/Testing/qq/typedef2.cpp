#include<iostream>
using namespace std;
typedef int adf;
typedef double klj;
typedef float qwe;
int main()
{
	adf n,SUM,MAX,MIN;
	klj AVG;
	cout<<"Enter no. of elements: ";
	cin>>n;
	adf arr[n];
	for(adf i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	MAX=MIN=SUM=arr[0];
	for(adf i=1;i<n;i++)
	{
		if(arr[i]>MAX)
		MAX=arr[i];
		if(arr[i]<MIN)
		MIN=arr[i];	
		SUM+=arr[i];
	}
	AVG=(qwe)SUM/n;
	cout<<"Sum = "<<SUM<<endl;
	cout<<"Average = "<<AVG<<endl;
	cout<<"Maximum value = "<<MAX<<endl;
	cout<<"Minimum value = "<<MIN<<endl;
	return 0;
}
