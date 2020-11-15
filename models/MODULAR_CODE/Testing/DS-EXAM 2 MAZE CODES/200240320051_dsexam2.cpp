#include<iostream>
using namespace std;
class Matrix
{
    private:
        char **mat;
        int rows;
        int column;
        int r;
        int c;
        int **vis;
        int hops;
    public:
        Matrix(){}
        Matrix(int rows,int column){
            this->rows=rows;
            this->column=column;
            r=0;
            hops=0;
            c=0;
            mat=new char*[rows];
            vis=new int*[rows];
            for(int i=0;i<rows;i++){
                mat[i]=new char[column];
                vis[i]=new int[column];
            }
            for(int i=0;i<rows;i++){
                for(int j=0;j<column;j++){
                    mat[i][j]='*';
                    vis[i][j]=0;
                    
                }
            }
        }
        void insert(char **mat1){
            for(int i=0;i<rows;i++){
                for(int j=0;j<column;j++){
                    mat[i][j]=mat1[i][j];
                    if(mat1[i][j]=='#'){
                        r=i;
                        c=j;
                    }
                    
                }
            }
        }
        int di1(){
            if(r>=0 && r<rows && c+1>=0 && c+1<column){
                if((mat[r][c+1]=='1'|| mat[r][c+1]=='@') && vis[r][c+1]==0){
                    r=r;
                    c=c+1;
                    vis[r][c]=1;
                    return 1;
                }
                else 
                return 0; 
            }
            else 
            return 0;
        }
        int di2(){
            if(r+1>=0 && r+1<rows && c>=0 && c<column){
                if((mat[r+1][c]=='1'|| mat[r+1][c]=='@') && vis[r+1][c]==0){
                    r=r+1;
                    c=c;
                    vis[r][c]=1;
                    return 1;
                }
                else 
                return 0; 
            }
            else 
            return 0;
        }
        int di3(){
            if(r>=0 && r<rows && c-1>=0 && c-1<column){
                if((mat[r][c-1]=='1'|| mat[r][c-1]=='@') && vis[r][c-1]==0){
                    r=r;
                    c=c-1;
                    vis[r][c]=1;
                    return 1;
                }
                else 
                return 0; 
            }
            else 
            return 0;
        }
        int di4(){
            if(r-1>=0 && r-1<rows && c>=0 && c<column){
                if((mat[r-1][c]=='1'|| mat[r-1][c]=='@') && vis[r-1][c]==0){
                    r=r-1;
                    c=c;
                    vis[r][c]=1;
                    return 1;
                }
                else 
                return 0; 
            }
            else 
            return 0;
        }
        int bt1(){
            if(r>=0 && r<rows && c+1>=0 && c+1<column){
                if((mat[r][c+1]=='1'|| mat[r][c+1]=='@') && vis[r][c+1]==1){
                    mat[r][c]=0;
                    r=r;
                    c=c+1;
                    return 1;
                }
                else 
                return 0; 
            }
            else 
            return 0;
        }
        int bt2(){
            if(r+1>=0 && r+1<rows && c>=0 && c<column){
                if((mat[r+1][c]=='1'|| mat[r+1][c]=='@') && vis[r+1][c]==1){
                    mat[r][c]=0;
                    r=r+1;
                    c=c;
                    return 1;
                }
                else 
                return 0; 
            }
            else 
            return 0;
        }
        int bt3(){
            if(r>=0 && r<rows && c-1>=0 && c-1<column){
                if((mat[r][c-1]=='1'|| mat[r][c-1]=='@') && vis[r][c-1]==1){
                    mat[r][c]=0;
                    r=r;
                    c=c-1;
                    return 1;
                }
                else 
                return 0; 
            }
            else 
            return 0;
        }
        int bt4(){
            if(r-1>=0 && r-1<rows && c>=0 && c<column){
                if((mat[r-1][c]=='1'|| mat[r-1][c]=='@') && vis[r-1][c]==1){
                    mat[r][c]=0;
                    r=r-1;
                    c=c;
                    return 1;
                }
                else 
                return 0; 
            }
            else 
            return 0;
        }
        void findpath(){
            while(mat[r][c]!='@'){
                if(di1()){
                    hops++;
                }
                else if(di2()){
                    hops++;
                }
                else if(di3()){
                    hops++;
                }
                else if(di4()){
                    hops++;
                }
                else if(bt1()){
                    hops--;
                }
                else if(bt2()){
                    hops--;
                }
                else if(bt3()){
                    hops--;
                }
                else if(bt4()){
                    hops--;
                }
            }
            cout<<hops<<endl;
        }
};
int main(){
    int rows;
    cin>>rows;
    int column;
    cin>>column;
    Matrix m1(rows,column);
    char **mat1;
    mat1=new char*[rows];
    for(int i=0;i<rows;i++){
        mat1[i]=new char[column];
    }
    char data;
    for(int i=0;i<rows;i++){
        for(int j=0;j<column;j++){
            cin>>data;
            mat1[i][j]=data;
        }
    }
    m1.insert(mat1);
    m1.findpath();
}