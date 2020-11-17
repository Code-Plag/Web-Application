#include<iostream>
using namespace std;
int count=0;
//make graph
class graph
{
    private:
        int row,col;
        char c;
        char **mat;
        int **visited;
        int pos,pos1;
    public:
        graph(){}
        
        graph(int m,int n)
        {
            row=m;
            col=n;
            mat=new char*[m];
            visited=new int*[m];
            for(int i=0;i<m;i++)
            {
                mat[i]=new char[n];
                 visited[i]=new int[n];
            }
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    mat[i][j]='O';
                     visited[i][j]=0;
                }
            }
        }
        //graph add weight
        void addedge()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    cin>>mat[i][j];
                    if(mat[i][j]=='#')
                    {
                        pos=i;
                        pos1=j;
                    }
                }
            }
        }
        //find path
        int pathfind(int r,int c)
        {  
            if(r>=row || c>=col || r<0 || c<0)
            {
                return 0;
            }
            if(mat[r][c]=='@')
            {
                return 1;
            }
            if( r<row && c<col && visited[r][c]==0 && (mat[r][c]=='1' || mat[r][c]=='#') )
            {  
                visited[r][c]=1;
                //moving south
                if(pathfind(r+1,c))
                {    
                    count++;
                    return 1;
                }
               //moving east
                if(pathfind(r,c+1))     
                {
                    count++;
                    return 1;
                }
               //moving north
                if(pathfind(r-1,c))
                {
                    count++;
                    return 1;
                }
                 //moving east
                if(pathfind(r,c-1))
                {
                    count++;
                    return 1;
                }
                
                else{    
                    return 0;
                }
            }
        
            return 0;
            
}
               
    int getpos()
    {
        return pos;
    }
    int  getpos1()
    {
        return pos1;
    }
        
        
    /*   void printG()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<col;j++)
                {
                    cout<<mat[i][j]<<" "<<visited[i][j]<<" ";
                }
                cout<<endl;
            }
        }   */
};
        
int main()
{
    int r,c;
    cin>>r>>c;
    graph G(r,c);
    G.addedge();
 //   G.printG();
   if(G.pathfind(G.getpos(),G.getpos1()))
   {
       cout<<count<<endl;
   }
   
    return 0;
    
}
