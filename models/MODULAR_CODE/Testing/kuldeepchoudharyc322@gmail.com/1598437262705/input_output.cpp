#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){

ifstream ifs;
ifs.open("stringlength.cpp",ios::in);
int i=ifs.tellg();
cout<<i;

cout<<endl;

cout<<i;
char ch ;
ifs>>ch ;//reading a charcter from a file >> operator skips whitespace character 
cout<<ch<<" ";

while(!ifs.eof())
{


i=ifs.tellg();
cout<<i;
cout<<ch;
ifs>>ch;

}

ifs.clear();
ifs.seekg(0, ios::beg);

i=ifs.tellg();
cout<<i;




char c=ifs.get();//reading first character from file
cout<<c;
char d=ifs.get();//reading second character from file
cout<<d;

ifs.seekg(9, ios::cur);//this is a setter function it doesnt return anything//

cout<<" position after seekg() "<<ifs.tellg();


ifs.seekg(0, ios::beg);
i=ifs.tellg();
cout<<i;

char rf[1000];//defining a charcter array and put file in array 
int k=0;
while(!ifs.eof()){
	ch=ifs.get();
	rf[k++]=ch;
}

cout<<endl;

for(int i=0 ;rf[i]!='\0';i++){

cout<<rf[i];


}
//reading a file in a string as it is

string readfile=" ";
while(!ifs.eof()){
	
readfile += ifs.get();
	
}
//cout<<readfile;//output the file from a string





return 0;
}