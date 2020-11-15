#include<iostream>
using namespace std;
int main()
{
	int n,SUM,MAX,MIN;
	float AVG;
	cout<<"Enter no. of elements: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	MAX=MIN=SUM=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>MAX)
		MAX=arr[i];
		if(arr[i]<MIN)
		MIN=arr[i];	
		SUM+=arr[i];
	}
	AVG=(float)SUM/n;
	cout<<"Sum = "<<SUM<<endl;
	cout<<"Average = "<<AVG<<endl;
	cout<<"Maximum value = "<<MAX<<endl;
	cout<<"Minimum value = "<<MIN<<endl;
	return 0;
}
