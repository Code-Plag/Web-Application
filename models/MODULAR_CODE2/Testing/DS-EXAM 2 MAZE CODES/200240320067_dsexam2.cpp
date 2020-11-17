#include<iostream>
using namespace std;

int count=0;

class Library
{
    private:
    
    int rows,cols;
    char c;
    char **matrix;
    int pos,pos1;
    int **vis;
    
    public:
        Library()
        {
    
        }
        
        Library(int x, int y)
        {
            rows=x;
            cols=y;
            matrix=new char*[x];
            vis=new int*[x];
            for(int i=0;i<x;i++)
            {
                matrix[i]=new char[y];
                vis[i]=new int[y];
            }
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<y;j++)
                {
                    matrix[i][j]='O';
                    vis[i][j]=0;
                }
            }
        }
        void insertedge()
        {
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    cin>>matrix[i][j];
                    if(matrix[i][j]=='#')
                    {
                        pos=i;
                        pos1=j;
                    }
                }
            }
        }
        int searchpath(int r, int c)
        {
            if(r>=rows || c>cols || r<0 || c<0)
            {
                return 0;
            }
            if(matrix[r][c]=='@')
            {
                return 1;
            }
            if(r<rows && c<cols && vis[r][c]==0 && (matrix[r][c]=='1' || matrix[r][c]=='#'))
            {
                vis[r][c]=1;
                if(searchpath(r+1,c))
                {
                    count++;
                    return 1;
                }
                if(searchpath(r,c+1))
                {
                    count++;
                    return 1;
                }
                if(searchpath(r-1,c))
                {
                    count++;
                    return 1;
                }
                if(searchpath(r,c-1))
                {
                    count++;
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            return 0;
        }
        int getpos()
        {
            return pos;
        }
        int getpos1()
        {
            return pos1;
        }
};
int main()
{
    int r,c;
    cin>>r>>c;
    Library L(r,c);
    L.insertedge();
    
    if(L.searchpath(L.getpos(),L.getpos1()))
    {
        cout<<count<<endl;
    }
    return 0;
}
