#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
    private:
       int data;
       Node *next;
    public:
            Node(int data)
             {
                this->data=data;
                next=NULL;
             }
           /* ~Node()
            {
                
             }*/
    
       int getdata()
       {
           return data;
      }

       Node *getNext()
       {
           return next;
      }
     
      void setNext(Node* next)
      {
          this->next=next;
      }
};

class Linklist
{
    private:
             Node *head;
           
    public:
           Linklist()
           {
               head=NULL;
               
           }
          /*  ~Linklist()
         {
        
         }*/
           
            void AB(int data)
            {
                Node *node=new Node(data);
                if(head==NULL)
                {
                 head=node;
                }
                else
                {
                 node->setNext(head);
                  head=node;
                 }
            }

        
    
    void AE(int data)
    {
        Node *node=new Node(data);
        if(head==NULL)
        {
            head=node;
        }    
        else
        {    
            Node *temp=head;
            while(temp->getNext()!=NULL)
            {
              temp=temp->getNext();
            }  
                temp->setNext(node);
            
        }
    }
    int DN(int data)
    {
        Node *temp=head;
        Node *prev=head;
        while(temp->getdata()!=data)
        {
            prev=temp;
            temp=temp->getNext();
            if(temp==NULL)
            {
                return 0;
            }
        }
        if(head->getdata()==data)
        {
       
        head=head->getNext();
        delete temp;
        }
        else
        {
            
         prev->setNext(temp->getNext());
        delete temp;
        }
        
    }
        
    int DNA(int data)
    {
        Node *temp=head;
        Node *prev=head;
        while( temp->getdata()!=data)
        {
            if(temp->getdata()!=data)
            {
           prev=temp;
           temp=temp->getNext();
           if(temp==NULL)
           {
               return 0;
           }
          }
        }
        prev=temp;
        temp=temp->getNext();
        if(temp!=NULL)
        {
            prev->setNext(temp->getNext());
        }
        delete temp;
    }
    int DNB(int data)
    {
        Node *temp=head;
        Node *prev=head;
         
        if(head->getdata()==data)
        {
            return 0;
        }
        if(head->getNext()->getdata()==data)
        {
            head=head->getNext();
        }
        
            while(temp->getNext()->getdata()!=data)
            {
                prev=temp;
                temp=temp->getNext();
            }
           
            prev->setNext(temp->getNext());
            delete temp;
            
        //if(head->getNext()->getdata()==data)
        //{
          //  head=head->getNext();
        
        
    }
    
    int AMA(int aft,int data)
    {
        Node *node=new Node(data);
        Node *temp=head;
            while(temp->getdata()!=aft)
            {  
                temp=temp->getNext();
                if(temp==NULL)
                {
                    return 0;
                }
            }
            if(head->getdata()==aft)
            {
               node-> setNext(head->getNext());
               head->setNext(node);
            }
            else
            {
                node->setNext(temp->getNext());
                temp->setNext(node);
            }
       }    
    
    int AMB(int bef,int data)
     {
         Node *newnode=new Node(data);
           Node*temp=head;
           Node*prev=head;
             while( temp->getdata()!=bef)
             {
                prev=temp;
                temp=temp->getNext();
                if(temp==NULL)
                {
                    return 0;
                }
             }
             if(head->getdata()==bef)
             {
                 newnode->setNext(head);
                 head=newnode;
                 
             }
             else
             {
                // newnode->setNext(prev->getNext());
                // prev->setNext(newnode);
                newnode->setNext(prev->getNext());
               prev->setNext(newnode);
                
             }           
     }
      
      void PR()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->getdata()<<" ";
            temp=temp->getNext();
        }
        cout<<endl;
        
    }
     void FPR()
     {
         Node *temp=head;
         //while(1)
         //{
             while(temp->getNext()!=NULL)
             {
                 cout<<temp->getdata()<<"->";
                  temp=temp->getNext();
             }
             cout<<temp->getdata()<<endl;
            
         //}
        // cout<<endl;
     }
     void RPR()
     {
         Node *temp;
         temp=head;
         Reverse(temp);
         cout<<endl;
     }
     void Reverse(Node*temp)
     {
         if(temp->getNext()!=NULL)
         {
             Reverse(temp->getNext());
         }
         cout<<temp->getdata()<<" ";
     }
     /*void RPR(Linklist L1)
     {
         Node* temp;
         while(temp!=NULL)
         {
             L1.AB(temp->getdata());
             temp=temp->getNext();
         }
         L1.PR();
     }*/
    
  
  };
    
    int main()
    {
        string cmd;
        Linklist l2;
        int data,a;
        while(1)
        {
            cin>>cmd;
            
            if(cmd=="AB")
            {
                  cin>>data;
                  l2.AB(data);
            }
            if(cmd=="AE")
            {
                
                cin>>data;
                l2.AE(data);
            }
            
            if(cmd=="PR")
            {
                
                l2.PR();
            }
            if(cmd=="FPR")
            {
                l2.FPR();
            }
            if(cmd=="RPR")
            {
                l2.RPR();
            }
            
            if(cmd=="DN")
            {
                cin>>data;
                l2.DN(data);
            }
            if(cmd=="DNA")
            {
               cin>>data;
                l2.DNA(data);
            }
            if(cmd=="DNB")
            {
                cin>>data;
                l2.DNB(data);
            }
            if(cmd=="AMA")
            {
                
                cin>>a>>data;
                l2.AMA(a,data);
            }
            if(cmd=="AMB")
            {
                 cin>>a>>data;
                 l2.AMB(a,data);
            }
            if(cmd=="EXIT")
            {
                exit(0);
            }
            
        }
        return 0;
    }