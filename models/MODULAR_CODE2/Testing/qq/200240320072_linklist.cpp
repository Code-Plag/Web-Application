#include<iostream>
using namespace std;
class Node
{
private:
        string name;
        int age;
        Node *next;
public:
        friend class Manipulation;
};

class Manipulation
{
private:
        Node *head;
public:
        Manipulation()
        {
            head=NULL;
        }
        
        void Insert(string na,int data)
        {
            Node *trav;
            Node *trav2;
            Node *newnode;
            trav=head;
            trav2=head;
            
            newnode=new Node;
            newnode->name=na;
            newnode->age=data;
            if(head==NULL)
            {
                head=newnode;
            }
            else
            {
             while((trav->next !=NULL) && (trav->age<=data))
               {
                   trav2=trav;
                   trav=trav->next;
               }
           
            
            if(trav==head)
            {
                if(trav->age<=data)
                {
                    trav2->next=newnode;
                    newnode->next=NULL;
                    trav=NULL;
                }
                
                else
                {
                    newnode->next=head;
                    head=newnode;
                    
                }
            }
            
            else if(trav->next==NULL)
            {
                if(trav->age<=data)
                {
                    trav->next=newnode;
                     newnode->next=NULL;
                }
                
                else
                {
                    newnode->next=trav;
                    trav2->next=newnode;
                    trav2 = NULL;
                    trav = NULL;
                    
                }
            }
            
            else if(trav->next !=NULL)
            {
                //trav->next=newnode;
                newnode->next=trav;
                trav2->next=newnode;
                trav=trav2=NULL;
            } 
                
            }
        }
        
        int Length()
        {
            int count=0;
            Node *trav;
            trav=NULL;
            while(trav !=NULL)
            {
                count++;
                trav=trav->next;
            }
            return count;
        }
        
        void Remove(int loc)
        {
            Node *trav;
            Node *trav2;
            trav=head;
            trav2=NULL;
            int i=1;
            
          
            if(loc==1)
            {
                head=trav->next;
                trav->next=NULL;
            }
            
            else
            {
                while(i<loc-1)
                {
                    trav=trav->next;
                    i++;
                }
                trav2=trav->next;
                
                trav->next=trav2->next;
                trav2->next=NULL;
            }
            
        }
        
        void Print(int loc)
        {
            Node *trav;
            trav=head;
            int i=1;
            
            while(i<loc)
            {
                trav=trav->next;
                i++;
            }
            cout<<trav->name<<" "<<trav->age<<endl;
            
        }
    
    
};

int main()
{
    Manipulation m;
    
    string cmd;
    while(1)
    {
        cin>>cmd;
        if(cmd=="insert")
        {
            int data;
            string na;
            cin>>na;
             cin>>data;
             m.Insert(na,data);
        }
        
        if(cmd=="print")
        {
            int loc;
            cin>>loc;
            m.Print(loc);
        }
        
        if(cmd=="remove")
        {
            int loc;
            cin>>loc;
            m.Remove(loc);
        }
        
        if(cmd=="stop")
        {
            break;
        }
           
        
    }
    
        
}