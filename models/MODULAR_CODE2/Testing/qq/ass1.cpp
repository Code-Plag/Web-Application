#include<iostream>
using namespace std;
int main()
{
	int n,SUM,MAX,MIN;
	float AVG;
	cout<<"Enter no. of elements: ";
	cin>>n;
	int arr[n];
	int i=0;
	while(i<n)
	{
		cin>>arr[i];
		i++;
	}
	MAX=MIN=SUM=arr[0];
	i=1;
	while(i<n)
	{
		if(arr[i]>MAX)
		MAX=arr[i];
		if(arr[i]<MIN)
		MIN=arr[i];	
		SUM+=arr[i];
		i++;
	}
	AVG=(float)SUM/n;
	cout<<"Sum = "<<SUM<<endl;
	cout<<"Average = "<<AVG<<endl;
	cout<<"Maximum value = "<<MAX<<endl;
	cout<<"Minimum value = "<<MIN<<endl;
	return 0;
}
