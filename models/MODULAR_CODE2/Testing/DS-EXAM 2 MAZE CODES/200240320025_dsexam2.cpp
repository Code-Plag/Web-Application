#include<iostream>
using namespace std;
int countData;
int rowData,colData;
char coloumData;
char **matrixForGraph;
int **visitedDataInProgram;
int posOne1,posTwo2;
void graphFunctionForFill(int mValue,int nValue);       
void addEdgeInGraph();
int getPosOne1();
int findPathFunction(int roData,int coloumData);
int getPosTwo2();


int main()
{
    
    int roData,coloumData;
    cin>>roData>>coloumData;
    graphFunctionForFill (roData,coloumData);
    addEdgeInGraph();
    
    if(findPathFunction(getPosOne1(),getPosTwo2()))
    {
        cout<<countData<<endl;
    }
    
    return 0;
}

        void graphFunctionForFill(int mValue,int nValue)
        {
            
            rowData=mValue;
            colData=nValue;
            matrixForGraph=new char*[mValue];
            visitedDataInProgram=new int*[mValue];
            for(int x=0;x<mValue;x++)
            {
                
                matrixForGraph[x]=new char[nValue];
                visitedDataInProgram[x]=new int [nValue];
            }
            
            for(int y=0;y<mValue;y++)
            {
                
                for(int q=0;q<nValue;q++)
                {
                    
                   // mat[i][j]='O';
                    visitedDataInProgram[y][q]=0;
                }
            }
        }
        
        void addEdgeInGraph()
        {
             for(int i=0;i<rowData;i++)
             {
                 
                  for(int j=0;j<colData;j++)
                  
                  {
                      
                      cin>>matrixForGraph[i][j];
                      if(matrixForGraph[i][j]=='#')
                      {
                          
                          posOne1=i;
                          posTwo2=j;
                      }
                  }
             }
            
        }
        
        int findPathFunction(int roData,int coloumData)
        {
            
            if(roData>=rowData||coloumData>=colData||roData<0||coloumData<0)
            {
                return 0;
            }
            if(matrixForGraph[roData][coloumData]=='@')
            {
                return 1;
            }
            if(roData<rowData && coloumData<colData && visitedDataInProgram[roData][coloumData]==0 && (matrixForGraph[roData][coloumData]=='1' || matrixForGraph[roData][coloumData]=='#'))
            {
                visitedDataInProgram[roData][coloumData]=1;
                
                if(findPathFunction(roData+1,coloumData))
                {
                    countData++;
                    return 1;
                }
                
                if(findPathFunction(roData,coloumData+1))
                {
                    countData++;
                    return 1;
                }
                
                 if(findPathFunction(roData-1,coloumData))
                {
                    countData++;
                    return 1;
                }
                
                 if(findPathFunction(roData,coloumData-1))
                {
                    countData++;
                    return 1;
                }
                
                else
                {
                    
                    return 0;
                }
            }
            
            return 0;
        }
        
        int getPosOne1()
        {
            return posOne1;
        }
        
        int getPosTwo2()
        {
            return posTwo2;
        }
//};