/*#include<iostream>
using namespace std;
int add(int a,int b){
	return a+b;

}
int main(){
	cout<<"hello world"<<endl;
	int a =2;
	int b=3;
	int c=add(2,3);
	cout<<"value of c is :"<<c;
	return 0;

}*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cout << "Program is running";
    vector <string> tab(103);
    string nazwa;
    int index = 0;
    do  {
        for (int i = 0; i < 10; i++) {
            getline(cin, nazwa);
            if (!nazwa.empty() && nazwa[nazwa.size() - 1] == '\n')
                nazwa.erase(nazwa.size() - 1);
            if (!nazwa.empty() && nazwa[nazwa.size() - 1] == '\r')
                nazwa.erase(nazwa.size() - 1);
            tab[i] = nazwa;
        }
        for (int i = 0; i < 9; i++) {
            cout << index << ": " << i+1 << endl;
        }
        index++;
    } while (true);
    return 0;
}	