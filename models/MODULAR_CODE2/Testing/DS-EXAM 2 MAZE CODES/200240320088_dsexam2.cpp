#include<iostream>
#include<cstring>

using namespace std;
int count=0;
class Graph
{
    private:
        int row;
        int col;
        char **matrix;
        int **visitedNode;
        int position;
        int position1;
        int *mapping;
        
    public:
        Graph()
        {
            
        }
        
        /*
        Graph(int row, int col)
        {
            this->row = row;
            this->col = col;
            
            mapping = new char[row];
            
            position = new char[row];
            position1 = new char[row];
            
            matrix = new char *[row];
            
            for(int i=0; i<row; i++)
            {
                matrix[i] = new char *[row]; 0; 
                
                mapping[i]=' ';
            }
            
            for(int i =0; i<row ; i++ )
            {
            for(int j =0; j<row; j++)
            {
            matrix[i][j] = 0;
            }
            }
            
        
        
        
        }
        
        void addValue(int s, int d; char value)
        {
                matrix[s][d] = value;
                
                for(int j =0; j<col; j++)
                {
                for(int j =0; j<col; j++)
                {
                cout<<matrix[i][j]<<" ";
                }
                
                cout<<endl;
                }
        
        
        }
        
        
        
        
        
        */
        
        
        Graph(int r, int c)
        {
            row = r;
            col = c;
            
            matrix = new char*[r];
            visitedNode = new int*[r];
            
            for(int i=0; i<r; i++)
            {
                matrix[i] = new char[c];
                visitedNode[i] = new int[c];
            }
            
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    matrix[i][j] = '0';
                    visitedNode[i][j] = 0;
                }
            }
        
        }
        
        void addEdge()
        {
            for(int i=0; i<row; i++)
            {
                for(int j=0; j<col; j++)
                {
                    cin>>matrix[i][j];
                    if(matrix[i][j] == '#')
                    {
                        position = i;
                        position1 = j; 
                    }
                }
            }
        }
        
        /*
        bool isSafe(char matrix[row][col], int *visited, int x, int y)
        {
            
            if(matrix[x][y] == 0 ||*(visited +((x*y) +y)))
            return false;
            return true;
        
        
        }
        
        
        bool isValid(int x, int y)
        {
            if(c<row && y<col && x>=0 && y>=0)
            return true;
            return false;
        
        
        }
        */
        
        /*
            findShortestPath(int visited[row][col], int &x, int y)
            {
                if(i ==x && j==y)
                {
                    min_dist = min(dist. min_dist);
                    return -1;
                
                }
                
                *(visited + ((i*j)+j))=1;
                
                if(isValid(i+1, j)&& isSafe(matrix, visited, i+1,j))
                findShortestPath(visited, i+1, dist+1);
            
                if(isValid(i, j+1)&& isSafe(matrix, visited, i,j+1))
                findShortestPath(visited, j+1, dist+1);
                
                if(isValid(i-1, j)&& isSafe(matrix, visited, i-1,j))
                findShortestPath(visited, i-1, dist+1);
                
                if(isValid(i, j-1)&& isSafe(matrix, visited, i,j-1))
                findShortestPath(visited, j-1, dist+1);
                
                *(visited +((i*j)+j))=0;
            
            }
        
        */
        int getPosition()
        {
            return position;
        }
        
        int getPosition1()
        {
            return position1;
        }
        
        int findMazePath(int r, int c)
        {
            
            if(r>=row || c>=col || r<0 || c<0)
            {
                return 0;
            }
            
            if(matrix[r][c]=='@')
            {
                return 1;
            }
            
            if(r<row && c<col && visitedNode[r][c]==0 && (matrix[r][c]== '1' || matrix[r][c] == '#'))
            {
                visitedNode[r][c] =1;
                
                if(findMazePath(r+1, c))
                {
                    count++;
                    return 1;
                }
                
                if(findMazePath(r, c+1))
                {
                    count++;
                    return 1;
                }
                
                if(findMazePath(r-1, c))
                {
                    count++;
                    return 1;
                }
                
                if(findMazePath(r, c-1))
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

};

int main()
{
    
    //setvbuf(stdout, NULL, _IONBF, 0);
    //char val;
    int number_Of_Row, number_Of_Column;
    cin>>number_Of_Row>>number_Of_Column;
    
    Graph graph(number_Of_Row, number_Of_Column);
    
    /*
    
    for(int i = 0; i<number_Of_Row; i++)
    {
        for(int j=0; j<number_Of_Column; j++)
        {
        cin>>val;
        graph.addValue(i, j, val);
        }
    }
    
    int min_dist = INT_MAX;
    
    int visited[number_Of_Row][number_Of_Column];
    
    grapgh.findShortestPath(visited,min_dis, 0;);
    */
    
    graph.addEdge();
    
    if(graph.findMazePath(graph.getPosition(), graph.getPosition1()))
    {
        cout<<count<<endl;
    }
       
    return 0;
}