#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
class Match
{
	private:
		int ip;
		int it;
		int len;
		string m;
	public:
		Match(){}
		Match(int ip,int it,int len,string m){
			this->ip=ip;
			this->it=it;
			this->len=len;
			this->m=m;
		}
		int getip(){
			return ip;	
		}
		int getit(){
			return it;
		}
		int getlen(){
			return len;
		}
		string getmatch(){
			return m;
		}
		
};
class Greedy
{
	private:
		string tile;
		string p;
		string t;
		int sen;
		int *visp;
		int *vist;
		vector<Match>matches;
		vector<Match>tiles;
	public:
		Greedy(string p,string t,int sen){
			this->p=p;
			this->t=t;
			visp=new int[p.length()];
			vist=new int[t.length()];
			tile="";
			this->sen=sen;
			for(int i=0;i<p.length();i++)
			visp[i]=0;
			for(int i=0;i<t.length();i++)
			vist[i]=0;
		}
		int isoccluded(Match m){
			int flag=0;
			for(int i=m.getip();i<(m.getip()+m.getlen());i++){
				if(visp[i]==1){
					flag=1;
				}
			}
			if(flag==0){
				for(int i=m.getit();i<(m.getit()+m.getlen());i++){
					if(vist[i]==1){
						flag=1;
					}
				}
			}
			if(flag==1)
			return  0;
			else 
			return 1;
		}
		
		void greedy_sting_tiling (){
			int length_oftoken=0;
			int maxmatch=0;
			int n1=p.length();
			int n2=t.length();
			do{
				maxmatch=sen;
				for(int i=0;i<n1 /*&& visp[i]==0*/;i++){//a b g h h h g
					for(int j=0;j<n2 /*&& vist[j]==0*/;j++){// a f b g h g
						int currentlen=0;
						string temp="";
						while(p[i+currentlen]==t[j+currentlen] && visp[i+currentlen]==0 && vist[j+currentlen]==0){
							temp=temp+p[i+currentlen];
							currentlen++;
						}
						if(currentlen==maxmatch){
							matches.push_back(Match(i,j,currentlen,temp));
							temp="";
						}
						else if(currentlen>maxmatch){// 8 9 10 11
							matches.clear();
							matches.push_back(Match(i,j,currentlen,temp));
							temp="";
							maxmatch=currentlen; 
						}
					}
				}
				for(int i=0;i<matches.size();i++){
					//cout<<"match= "<<matches[i].getmatch()<<" | ip = "<<matches[i].getip()<<" | it = "<<matches[i].getit()<<" | length = " <<matches[i].getlen()<<endl; 
					if(isoccluded(matches[i])){
						for(int j=0;j<matches[i].getlen()-1;j++){
							visp[matches[i].getip()+j]=1;
							vist[matches[i].getit()+j]=1;
						}
						tiles.push_back(matches[i]);
						length_oftoken=length_oftoken+maxmatch;
					}
				}
			}
			while(maxmatch>sen);
		}
		void tiling(){
			cout<<"Matches"<<endl;
			cout<<"-----------------"<<endl;
			for(int i=0;i<tiles.size();i++){
				cout<<"Tile = "<<tiles[i].getmatch()<<"| ip = "<<tiles[i].getip()<<" | it= "<<tiles[i].getit()<<"| length"<<tiles[i].getlen()<<endl;
			}
		}
		
		

};
int main(){
	cout<<"Enter the first string : "<<endl;
	string s1;
	cin>>s1;
	cout<<"Enter the second string : "<<endl;
	string s2;
	cin>>s2;
	cout<<"Enter the sensitivity"<<endl;
	int sen;
	cin>>sen;
	Greedy g1(s1,s2,sen);
	g1.greedy_sting_tiling();
	g1.tiling();
	return 0;
	
}
