# include <iostream>
# include <bits/stdc++.h>
# include <queue>
# define d 100
using namespace std;
int MAZEROW;
int MAZECOL;
class EachPoint
    {
        private:
            int rowPoint;
            int colPoint;
        public:
            EachPoint()
                {
                    rowPoint = 0;
                    colPoint = 0;
                }
           /* EachPoint( int i, int j)
                {
                    rowPoint = i;
                    colPoint = j;
                }*/
            int getRowPoint()
                {
                    return rowPoint;
                }
            int getColPoint()
                {
                    return colPoint;
                }
            void setRowPoint(int rowPoint)
                {
                    this->rowPoint = rowPoint;
                }
            void setColPoint(int colPoint)
                {
                    this->colPoint = colPoint;
                }
            void setPoint(EachPoint w1)
                {
                    this->rowPoint = w1.getRowPoint();
                    this->colPoint = w1.getColPoint();
                }
    };

class ElementMaze
    {
        private:
            EachPoint pt;
            int distance;
        public:
            ElementMaze()
                {
                    
                    distance = 0;
                }
                void setEle( ElementMaze m1)
                    {
                        distance = m1.getDistance();
                        pt.setPoint(m1.getPt());
                    }
            int getDistance()
                {
                    return distance;
                }
            void setDistance(int distance)
                {
                    this->distance = distance;
                }
            void setPt(EachPoint w1)
                {
                    pt.setRowPoint(w1.getRowPoint());
                    pt.setColPoint(w1.getColPoint());
                }
            EachPoint getPt()
                {
                    return pt;
                }
    };
    
bool isPointValid(int row, int col)
    {
        return (row>=0) && (row<MAZEROW) && (col>=0) && (col< MAZECOL);
    }
    
int adjrowNUM[] = {-1, 0, 0, 1};
int adjcolNUM[] = { 0, -1, 1, 0};

int shortestPATH(int actualmazeArr[][d], EachPoint start, EachPoint end)
    {
        int tempactualmazeArr[MAZEROW][MAZECOL];
        for(int i = 0; i<MAZEROW; i++)
            for(int j = 0; j<MAZECOL; j++)
                tempactualmazeArr[i][j] = actualmazeArr[i][j];
       /* for(int i = 0; i<MAZEROW; i++)
            {
            for(int j = 0; j<MAZECOL; j++)
                cout<<tempactualmazeArr[i][j];
                cout<<endl;
            }
                return 0;*/
        
        int isPointVisited[MAZEROW][MAZECOL];
        for(int i = 0; i<MAZEROW; i++)
            {
            for(int j = 0; j<MAZECOL; j++)
             {
                isPointVisited[i][j] = 0;
             }
            }
        isPointVisited[start.getRowPoint()][start.getColPoint()] = 1;
       /*for(int i = 0; i<MAZEROW; i++)
            {
            for(int j = 0; j<MAZECOL; j++)
             {
                cout<<isPointVisited[i][j];
             }
             cout<<endl;
            }*/
        
        //cout<<isPointVisited[start.getRowPoint()][start.getColPoint()];
        queue <ElementMaze> q;
        
        ElementMaze s;
        s.setPt(start);
        s.setDistance(0);
        
        q.push(s);
        EachPoint temp;
        temp.setPoint(s.getPt());
       // cout<<temp.getRowPoint();
        while(!q.empty())
            {
               //cout<<"q";
               ElementMaze curr;
                curr.setEle(q.front());
                EachPoint pr;
                pr.setPoint(curr.getPt());
                if(pr.getRowPoint() == end.getRowPoint() && pr.getColPoint() == end.getColPoint() )
                    {
                        //cout<<curr.getDistance();
                        return curr.getDistance();
                    }
                q.pop();
                
                for(int i = 0; i<4; i++)
                    {
                        //cout<<"qqq"<<endl;
                        //cout<<"k";
                        int row = pr.getRowPoint() + adjrowNUM[i];
                        int col = pr.getColPoint() + adjcolNUM[i];
                       // cout<<row<<col<<" ";
                        //cout<<row<<" "<<col;
                        if(isPointValid(row, col) && tempactualmazeArr[row][col] && (!isPointVisited[row][col]))
                            {
                               // cout<<"e";
                                isPointVisited[row][col] = 1;
                                ElementMaze adjcellno;
                                EachPoint w1;
                                w1.setRowPoint(row);
                                w1.setColPoint(col);
                                adjcellno.setPt(w1);
                               // cout<<curr.getDistance();
                                adjcellno.setDistance(curr.getDistance() + 1);
                                q.push(adjcellno);
                            }
                    }
            }
        return -1;
    }
int main()
    {
        
        cin>>MAZEROW>>MAZECOL;
        //MAZECOLGLOBAL = MAZECOL;
        char mazeArr[MAZEROW][MAZECOL];
        
        for(int i = 0; i<MAZEROW; i++)
            for(int j = 0; j<MAZECOL; j++)
                cin>>mazeArr[i][j];
        
        /*for(int i = 0; i<MAZEROW; i++)
            {
            for(int j = 0; j<MAZECOL; j++)
                cout<<mazeArr[i][j];
                cout<<endl;
            } */
            
            //start location
            int startPt_i = 0;
            int startPt_j = 0;
        for(int i= 0;  i < MAZEROW; i++)      //find start pt
            {
                for(int j = 0; j < MAZECOL; j++)
                    {
                        if(mazeArr[i][j] == '#')
                            {
                                startPt_i = i;
                                startPt_j = j;
                                
                            }
                    }
            }
        int startLocation[] = {startPt_i, startPt_j};
       // cout<<startPt_i<<startPt_j;
        //cout<<startLocation[0]<<" "<<startLocation[1];
        
        
        //end location
        int endPt_i = 0;
            int endPt_j = 0;
        for(int i= 0; i < MAZEROW; i++)      //find end pt
            {
                for(int j = 0; j < MAZECOL; j++)
                    {
                        if(mazeArr[i][j] == '@')
                        {
                            endPt_i = i;
                            endPt_j = j;
                        }
                    }
            }
        int endLocation[] = {endPt_i, endPt_j};
        //cout<<endPt_i<<endPt_j;
        
        //cout<<startLocation[0]<<" "<<startLocation[1];
        //cout<<endLocation[0]<<" "<<endLocation[1];
        
        
        
        int actualmazeArr[d][d];
        
        for(int i = 0; i<d; i++)
        {
            for(int j = 0; j<d; j++)
                {
                        actualmazeArr[i][j] = 0;
                        
                }
        }
        //char to int
        for(int i = 0; i<MAZEROW; i++)
        {
            for(int j = 0; j<MAZECOL; j++)
                {
                        if(mazeArr[i][j] == '0')
                            actualmazeArr[i][j] = 0;
                        else
                            actualmazeArr[i][j] = 1;
                        
                }
        }
        
        
        
       /* for(int i = 0; i<MAZEROW; i++)
            {
            for(int j = 0; j<MAZECOL; j++)
                cout<<actualmazeArr[i][j];
                cout<<endl;
            } */
            
        EachPoint start;
        EachPoint end;
        
        start.setRowPoint(startLocation[0]);
        //cout<<start.getRowPoint();
        start.setColPoint(startLocation[1]);
        end.setRowPoint(endLocation[0]);
        end.setColPoint(endLocation[1]);

         //cout<<start.getRowPoint()<<start.getColPoint()<<endl;
        //cout<<end.getRowPoint()<<end.getColPoint()<<endl;
        
        int dist = shortestPATH(actualmazeArr, start, end);
        
        cout<<dist<<endl;
        

return 0;
    }