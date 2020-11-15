#include<iostream>
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
           int getdata()
           {
               return data;
           }
           void setnext(Node *next)
           {
               this->next=next;
           }
           Node *getnext()
           {
               return next;
           }
};

class Link
{
        private:
          Node *head;
          public:
                 Link()
                 {
                     head=NULL;
                 }
                 /*Node * gethead()
                 {
                     return head;
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
                           node->setnext(head);
                           head=node;
                       }
                      // cout<<node->getdata()<<endl;     
                 }
                 
                 int  AE(int data)
                 {
                     Node *node=new Node(data);
                     if(head==NULL)
                     {
                         head=node;
                         
                     }
                     else
                     {
                          Node *temp;
                          temp=head;
                          while(temp->getnext()!=NULL)
                          {
                              temp=temp->getnext();
                          }
                          temp->setnext(node);
                          //cout<<node->getdata()<<endl   
                     }
                 }  
                 
                    int AMA(int after,int data)
                     {
                         Node*node=new Node(data);
                         Node*temp=head;
                         while(temp->getdata()!=after)
                         {
                             temp=temp->getnext();
                             if(temp==NULL)
                             {
                                 return 0 ;
                             }
                         }
                         if(head->getdata()==after)
                         {
                             node->setnext(head->getnext());
                             head->setnext(node);
                         }
                         else
                         {
                             node->setnext(temp->getnext());
                             temp->setnext(node);
                         }
                     }
                     
                   
                                                                                                                                                                                                                                                                                                                                                                                                                                   
                   int  AMB(int before,int data)
                     {
                         Node *node=new Node(data);          
                             Node *prev;
                             Node *temp;
                             temp=head;
                             prev=head;
                             while(temp->getdata()!=before)
                             {
                                 prev=temp;
                                 temp=temp->getnext();
                                 if(temp==NULL)
                                 {
                                     return 0;
                                 }
                             }
                             if(head->getdata()==before)
                             {
                               node->setnext(head);
                                head=node;
                             }
                             else
                              {
                                 node->setnext(prev->getnext());
                                prev->setnext(node);
                             }       
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
                             if(temp==NULL)
                             {
                                 return 0;
                             }
                         }
                         if(data==head->getdata())
                         {
                             head=head->getnext();
                             delete temp;
                         }
                         else
                         {
                             prev->setnext(temp->getnext());
                             delete temp;
                         }
                     }
                   
                    int DNB(int data)
                      {
                       Node *temp=head;
                       Node *prev=head;
                       if(head->getdata()==data)
                       {
                           return 0;
                       }
                       if(head->getnext()->getdata()==data)
                       {
                           head=head->getnext();
                           
                       }
                       while(temp->getnext()->getdata()!=data)
                           {
                               prev=temp;
                               temp=temp->getnext();
                               
                           }
                           prev->setnext(temp->getnext());
                           delete temp;
                      }
                  
                      int DNA(int data)
                      {
                          Node *temp=head;
                         Node *prev=head;
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
                        {
                            prev->setnext(temp->getnext());
                        }
                        delete temp;
                        
                      }
                      
                          
                      
                     int PR()
                     {
                         Node *temp=head;
                         while(temp!=NULL)
                         {
                             cout<<temp->getdata()<<" ";
                             temp=temp->getnext();
                         }
                         cout<<endl;
                     }
                     void FPR()
                         {
                             Node *temp=head;
                             while(temp->getnext()!=NULL)
                             {
                                 cout<<temp->getdata()<<"->";
                                 temp=temp->getnext();
                             }
                             cout<<temp->getdata();
                             cout<<endl;
                             
                         }

                     void fun(Node *head)      
                     {
                         Node *temp=head;
                         if(temp==NULL)
                           return;
                         
                         fun(temp->getnext());
                         cout<<temp->getdata()<<" ";
                         
                     }
                     int RPR()
                     {
                         fun(head);
                         cout<<endl;
                         
                     }
                    
                 ~Link()
                  {
                      while(head!=NULL)
                      {
                          Node *temp=head;
                          head=head->getnext();
                          delete temp;
                      }
                  }
                            
};
int main()
{
    Link l;
  int data;
  int after;
  string cmd;
  
  while(1)
  {
      cin>>cmd;
      if(cmd=="AB")
      {
          cin>>data;
          l.AB(data);
      }
      if(cmd=="AE")
      {
          cin>>data;
          l.AE(data);
          
      }
      if(cmd=="AMA")
      {
          cin>>after>>data;
          l.AMA(after,data);
      }
      if(cmd=="PR")
      {
          
          l.PR();
      }
     if(cmd=="AMB")
      {
         
          cin>>after>>data;
          l.AMB(after,data);
          
      }
      if(cmd=="DN")
     {
       
       cin>>data;
       l.DN(data);
     }
     if(cmd=="FPR")
      {
          l.FPR();
      }
      if(cmd=="DNB")
      {
          
          cin>>data;
          l.DNB(data);
      }  
    if(cmd=="RPR")
      {
          l.RPR();
      }
      
      
     if(cmd=="DNA")
      {
          cin>>data;
          l.DNA(data);
      }
      if(cmd=="EXIT")
      {
          break;
      }
      
  }
 
      return 0;
  
}