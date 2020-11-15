#include<iostream>
#include<cmath>
#include<map>
#include<bits/stdc++.h>
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
		int getlen()const{
			return len;
		}
		string getmatch(){
			return m;
		}
};return                 
bool operator< (const Match &m1, const Match &m2){
			return m1.getlen()<m2.getlen();
		}
class Greedy
{
	private:
		string tile;
		string p;
		string t;
		int Minimum_Matching_length;
		int *visp;
		int *vist;
		vector < priority_queue< Match > > matches;
		vector < Match > tiles;
		multimap < long long int,int > umap;
		//Queue < Match > queue;	
	public:
		Greedy(string p,string t,int  Minimum_Matching_length){
			this->p=p;
			this->t=t;
			visp=new int[p.length()];
			vist=new int[t.length()];
			tile="";
			this->Minimum_Matching_length=Minimum_Matching_length;
			for(int i=0;i<p.length();i++)
			visp[i]=0;
			for(int i=0;i<t.length();i++)
			vist[i]=0;
		}
		 
		int dist2Nexttile(int pos,int *vis,int searchlength,string t){
			int dist=0;
			if(pos+1 == t.length()){
				return  dist;
			}
			for(dist=0; dist+pos+1 < t.length() && vis[dist+pos+1]==0 ; dist++){//5 6 7 8 9
				if(dist+1==searchlength){
					return dist+1;
				}
			}
			if(pos+dist+1 == t.length()){
				return 0;
			}
			return dist+1;
		}
		
		bool isoccluded(Match m){
			int flag=0;
			for(int i=m.getip();i<m.getip()+m.getlen();i++){
				if(visp[i]==1){
					flag=1;
				}
			}
			for(int i=m.getit();i<m.getit()+m.getlen();i++){
				if(vist[i]==1){
					flag=1;
				}
			}
			if(flag==1){
				return true;
			}
			else return false;
		}
		int jump_2_next_unmarked_token(int pos,int * vis,int searchlength,string t){
			int dist=dist2Nexttile(pos,vis,searchlength,t);
			if(pos+1 == t.length()){
				return  0;
			}
			for(pos+=dist; pos+1 < t.length() && vis[pos+1]==1 ; pos++){}
			if(pos+1 > t.length()-1){
				return 0;
			}
			return pos+1;
		}
		long long int string_to_hash(string s){
			long long int n=s.length();
			const long long int a=pow(10,9);
			long long int val=0;
			const int fval=31;
			long long int power=1;
			long long int e=n-1;
			for(int i=0;i<n;i++){
				val=(val+(int(s[i])*power))%(a+9);
				power=(power*fval)%(a+9);
			}
			return val;
		}

		int scan_pattern (int init_search_length){
			int maxmatch_found=0;
			int searchlength = init_search_length;
			int tpos=0;
			priority_queue<Match>queue1;
			bool no_next_tile=false;
			while(tpos < t.length()){
				if(istMarked(tpos)){
					tpos++;
				}
				else{
					int dist = dist2Nexttile(tpos,vist,searchlength,t);
					if(dist == 0){
						no_next_tile=true;
						dist=t.length()-tpos;
					}
					if(dist < searchlength){
						if(no_next_tile){
							tpos = t.length();
						}
						else{
							tpos=jump_2_next_unmarked_token(tpos,vist,searchlength,t);
							if(tpos==0){
								tpos=t.length();
							}
						}
					}
					else{
						string s1="";
						for(int i=tpos ; i <= tpos+searchlength-1 ; i++){
							s1=s1+t[i];
							umap.insert({string_to_hash(s1),tpos});
						}
						tpos++;
					}
				}
			}
			int ppos=0;
			no_next_tile=false;

			while(ppos < p.length()){
				if(isMarked_p(ppos)){
					ppos++;
				}
				else{
					int dist = dist2Nexttile(ppos,visp,searchlength,p);
					if(dist == 0){
						no_next_tile=true;
						dist=p.length()-ppos;
					}
					if(dist < searchlength){
						if(no_next_tile){
							ppos = p.length();
						}
						else{
							ppos=jump_2_next_unmarked_token(ppos,visp,searchlength,p);
							if(ppos==0){
								ppos=p.length();
							}
						}
					} 
					else{
						string s1="";
						for(int i=ppos ; i <= ppos+searchlength-1 ; i++){
							s1=s1+p[i];
					//		cout<<p[i]<<endl;
						}
					//		cout<<s1<<endl;
						long long int hash1=string_to_hash(s1);
					//	cout<<hash1<<endl;
						auto it = umap.equal_range(hash1);
						vector < int > occurance;
						for(auto itr = it.first ; itr!=it.second ; itr++){
							occurance.push_back(itr->second);
					//		cout<<itr->second<<endl;
						}
						if(occurance.size() != 0){
							for(int j = 0 ; j < occurance.size() ; j++ ){
						//		cout<<occurance[j]<<endl;
								int tstart= occurance[j];
								int currentlen = 0;
								string temp="";		
								while(p[ppos+currentlen]==t[tstart+currentlen] && visp[ppos+currentlen]==0 && vist[tstart+currentlen]==0){
									temp=temp+p[ppos+currentlen];
								//	cout<<temp<<endl;
									currentlen++;
								}
								if(currentlen > 2 * searchlength){
									searchlength=currentlen;		
									temp="";
									return currentlen;
								}
								if(maxmatch_found < searchlength){
									maxmatch_found=searchlength;
								}
								if(maxmatch_found < currentlen){ 
									maxmatch_found = currentlen;
								}
								if(currentlen>=Minimum_Matching_length)
								queue1.push(Match(ppos,tstart,currentlen,temp));
							}
						}
					}ppos++;
				}
			}
			if(!queue1.empty()){
				matches.push_back(queue1);
			}
			return maxmatch_found;
		} 
			
		void markstring (){
			for(priority_queue<Match>q1:matches){
				while(!q1.empty()){
					Match m1=q1.top();
					q1.pop();
					if(!isoccluded(m1)){
						for(int i = 0 ; i < m1.getlen()-1 ; i++){
							visp[m1.getip()+i]=1;
							vist[m1.getit()+i]=1;
						}
						tiles.push_back(m1);
					}	
				}
			}
			matches.clear();
		}
		void Greedy_RabinKarpHash(){
		//	cout<<"Greedy_RabinKarpHash"<<endl;
			 int initsearchSize = 20 ;
			if(Minimum_Matching_length < 3){
				Minimum_Matching_length = 2;
			}
			bool stop = false;
			int searchlength = initsearchSize;
			while(!stop){
		//		cout<<searchlength<<endl;
				int Lmax = scan_pattern(searchlength);
				if(Lmax>2*searchlength){
					searchlength=Lmax;
				}
				else{
					markstring();
					if(searchlength > 2* Minimum_Matching_length){
						searchlength /= 2;
					}
					else if(searchlength   > Minimum_Matching_length){
						searchlength = Minimum_Matching_length;
					}
					else{
						stop=true;
					}
				}
			}
		}
		bool isMarked_p(int pos){
			if(visp[pos]==1){
				return true;
			}
			else
				return false;
		}
		bool istMarked(int pos){
			if(vist[pos]==1){
				return true;
			}
			else
				return false;
		}
		void tiling(){
			for(int i=0;i<tiles.size();i++){
				cout<<"tiles = "<<tiles[i].getmatch()<<" "<<"ip  = "<<tiles[i].getip()<<" it = "<<tiles[i].getit()<<" length = "<<tiles[i].getlen()<<endl;
			}
		}
};
int main(){
	string s1;
		string s2;
		s1="Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis, ultricies nec, pellentesque eu, pretium quis, sem. Nulla consequat massa quis enim. Donec pede justo, fringilla vel, aliquet nec, vulputate eget, arcu. In enim justo, rhoncus ut, imperdiet a, venenatis vitae, justo. Nullam dictum felis eu pede mollis pretium. Integer tincidunt. Cras dapibus. Vivamus elementum semper nisi. Aenean vulputate eleifend tellus. Aenean leo ligula, porttitor eu, consequat vitae, eleifend ac, enim. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus. Phasellus viverra nulla ut metus varius laoreet. Quisque rutrum. Aenean imperdiet. Etiam ultricies nisi vel augue. Curabitur ullamcorper ultricies nisi. Nam eget dui. Etiam rhoncus. Maecenas tempus, tellus eget condimentum rhoncus, sem quam semper libero, sit amet adipiscing sem neque sed ipsum. N";
//	s1="rtaabadefghijkpq";
	cout<<s1<<s1.length()<<endl;
	//cin>>s1;

	//cin>>s2;
//	s2="sssqghijkuuupqaabartwxyzdefrt";
	s2="Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur? At vero eos et accusamus et iusto odio dignissimos ducimus qui blanditiis praesentium voluptatum deleniti atque corrupti quos dolores.";
	cout<<s2<<s2.length()<<endl;
	int  Minimum_Matching_length=5;
	cout<<Minimum_Matching_length<<endl;
	cout<<endl;	
	cout<<endl;
//	cin>> Minimum_Matching_length;
	Greedy g1(s1,s2, Minimum_Matching_length);
	g1.Greedy_RabinKarpHash();
	g1.tiling();
	return 0;
}


// checker points
/*
1.to check hash multimap values+
---------------------------------
multimap<long long int,int>:: iterator itr;
				for (itr = umap.begin(); itr != umap.end(); itr++)
			    {
			        cout << itr->first << "  " << itr->second << endl;
			    }
----------------------------------
2.Flow of code++
	1.Greedy_RabinKarpHash();
		a)scanpattern
			Functions:
				a)dist2nexttile.
				b)jumptonextunmarkedtokenaftertile.
				c)ismarked.
				d)string_to_hash.(hashing function)
			Containers:
				a)queue.
				b)Multimap.
				c)vector occurance.
				d)auto container to store hash returns.
				e)vector matches conatining queue at every index.
		b)markstring
			Functions:
				a)isoccluded
			containers:
				a)queue
				b)Matches-vector
				c)tiles-vector
	2.tiling(to print output)
		container:
			a)tiles--vector
----------------------------------
3.Algorithm
----------------------------------
steps:
1.to hash the text(t) code/string into smaller number of searchlength substring and store in hashtable.
	e.g.text code =a b c d e f g h i j k
	searchlength=4.
	so hashtable would be like
		substring	hashvalue	startpoint 
		abcd		hashval1 	1
		bcde		hashval2	2
		cdef		hashval3	3
			...so on

2.Break pattern code/string in similar lengths and match to hash table get start point of text and expand the match.
3.expanded match should be recorded in queue and store it in vector.
4.markstring for max occluded and maximal match
5.run top layer (greedy_rabin_karp function) and check longest match returned by the scanpattern,
manipulate it so that big matches can be found out.
6.iteration after iteration Searchlength will reduce and come to mml that is sensitivity.
7.all matches are collected in tiles vector.
---------------------------------------------------
*/

	

