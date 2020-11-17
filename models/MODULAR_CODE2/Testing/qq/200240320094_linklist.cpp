#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
class Node
{
    private:
       int data;
       Node *next;
    public:
       Node()
       {
           next=NULL;
       }
       Node(int data)
       {
          this->data=data;
          next=NULL;
       } 
      
       void setnext(Node *next)
        {
           this->next=next;
        }
      
        Node *getnext()
        {
          return next;
        }

        int getdata()
         {
          return data;
        }
};
  class LinkList
  {
      private:
         Node *head;
     public:
           LinkList()
           {
              head=NULL;
            }
            ~LinkList()
            {
            }
       
       void AB(int data)
        {
          Node *newnode=new Node(data);
          if(head==NULL)
          {
            head=newnode;
          }
          else
          {
             
              newnode->setnext(head);
              head=newnode;
          }
          
         }
        void AE(int data)
         {
           Node *newnode=new Node(data);
           if(head==NULL)
           {
             head = newnode;
           }     
           else
            {
              Node *temp;
              temp=head;
              while(temp->getnext()!=NULL)
              {
                   temp=temp->getnext();
              }       
                temp->setnext(newnode);
            }
         }
     
         int AMA(int pos,int data)
         {
           Node *newnode=new Node(data);
           Node *temp;
           temp=head;
           while(temp->getdata()!=pos)
           {
               temp=temp->getnext();
               if(temp== NULL)
               {
                 return 0;
               }
                
           }
             if(head->getdata()==pos)
             {
              newnode->setnext(head->getnext());
              head->setnext(newnode);
             }
             else
             {
               newnode->setnext(temp->getnext());
               temp->setnext(newnode);
             }
              
          }     

         int AMB(int pos,int data)
          {
            Node *newnode=new Node(data);
            Node *temp;
            Node *prev;
              temp=head;
             while(temp->getdata()!=pos)
             {
                 prev=temp;
                 temp=temp->getnext();
               if(temp==NULL)
               {
                 return 0;
               }
             }
              if(head->getdata()==pos)
             {
              newnode->setnext(head);
              head=newnode;
            }
            else
             {
               newnode->setnext(prev->getnext());
               prev->setnext(newnode);
             }
          
          
        }
        
        
        void RPR()
        {
            Node *temp;
            temp=head;
            reverse(temp);
            cout<<endl;
        
        }
         void reverse(Node *temp)
         {
             if(temp->getnext()!=NULL)
             {
                 reverse(temp->getnext());
             }
             cout<<temp->getdata()<<"";
         }

          
          int DN(int data)
           {
               Node *temp;
               Node *prev;
               prev=head;
               temp=head;
               while(temp->getdata()!=data)
               {
                   prev=temp;
                   temp=temp->getnext();
                   if(temp == NULL)
                   {
                       return 0;
                   }
                   
               }
               if(data==head->getdata())
               {
                head=head->getnext();
                delete temp;
               }    
               else if(temp!=NULL)
               {
                   prev->setnext(temp->getnext());
                   delete temp;
               }
            }
            int DNA(int data)
            {
                Node *temp;
                Node *prev;
                temp=prev=head;
                while(temp->getdata()!=data)
                {
                    
                    prev=temp;
                    temp=temp->getnext();
                    if(temp==NULL)
                    {
                        return 0;
                    }
                }
                prev=temp;
                temp=temp->getnext();
                if(temp!=NULL)
                 prev->setnext(temp->getnext());
                 delete temp;
                
            }
            
            int DNB(int data)
            {
                Node *temp;
                Node *prev;
                temp=head;
                prev=head;
                if(head->getdata()==data)
                {
                    return 0;
                }
                if(head->getnext()->getdata()==data)
                {
                    head=head->getnext();
                }
                else
                {
               
                while(temp->getnext()->getdata()!=data)
                {
                    prev=temp;
                    temp=temp->getnext();
                }
                prev->setnext(temp->getnext());
                delete temp;
                }
                  
            }
             
             void show()
             {
                 Node *temp;
                 temp=head;
                 while(temp->getnext()!=NULL)
                 {
                     cout<<temp->getdata()<<" ";
                     temp=temp->getnext();
                 }
                 cout<<temp->getdata()<<endl;
             }
             
             void FPR()
             {
                  Node *temp;
                  temp=head;
                 while(temp->getnext()!=NULL)
                 {
                     
                     
                     cout<<temp->getdata()<<"->";
                     temp=temp->getnext();
                 
                 }
                 cout<<temp->getdata()<<endl;
           }   
           
           
         
  };
  
  int main()
  {
      
      LinkList l1;
      int no,po;
      string str;
      while(1)
     {
       cin>>str;
      if(str=="AB")
      {
       cin>>no;
       l1.AB(no);
      }
      else if(str=="AE")
      {
        cin>>no;
        l1.AE(no);
      }
      else if(str=="AMB")
      {
        cin>>po>>no;
        l1.AMB(po,no);
      }
      else if(str=="DNA")
      {
        
        cin>>no;
        l1.DNA(no);
      }
      else if(str=="DNB")
       {
        cin>>po;
        l1.DNB(po);
      }
      else if(str=="AMA")
     {
      cin>>po>>no;
      l1.AMA(po,no);
     }
     else if(str=="FPR")
      {
       l1.FPR();
      }
      else if(str=="PR")
      {
       l1.show();
      }
      else if(str=="DN")
      {
         cin>>no;
       l1.DN(no);
      }
      else if(str=="RPR")
       {
           l1.RPR();
       }
      else if(str=="EXIT")
      {
        break;
      }
     }
     return 0;
  }