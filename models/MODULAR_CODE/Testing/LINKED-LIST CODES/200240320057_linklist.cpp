#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
    class node
        {
             private:
                 int data;
                 node *next;
             public:
                 node(int data)
                    {
                         this->data=data;
                         next=NULL;
                     }
                     ~node()
                     {}
                 
                 int getdata()
                    {
                        return data;
                    }
                 
                 void setdata(int data)
                    {
                        this->data=data;
                    }
              
                 void setnext(node *next)
                    {
                      this->next=next;
                    }

                 node *getnext()
                    {
                      return next; 
                    }
        
};

      class linklist
          {
               private:
                    node *head;
               public:
                    linklist()
                       {
                           head=NULL;
                       }
                       ~linklist()
                       {}
    
                     void AB(int data)
                       {
                            node *n=new node(data);
                            if(head==NULL)
                                {
                                  head=n;
                                }
                            else
                                {
                                   n->setnext(head);
                                   head=n;
                                 }
                      }
                      
                      void AE(int data)
                         {
                              node *n=new node(data);
                              node *temp=head;
                              if(head==NULL)
                                 {
                                     head=n;
                                 }
                                 else
                                 {
                               while(temp->getnext()!=NULL)
                                    {
                                           temp=temp->getnext();
                                    }
                                    temp->setnext(n);
                                    n->setnext(NULL);
                                 }  
                         }   

                      int AMA(int after,int data)
                         {
                              node *n=new node(data);
                              node *temp=head;
                              while( temp->getdata()!=after)
                                   {
                                       temp=temp->getnext();
                                       if(temp==NULL)
                                         {
                                           return 0;
                                          }
                                   } 
                                    if(head->getdata()==after)
                                     {
                                        n->setnext(temp->getnext());
                                       temp->setnext(n);
                                     }
                                     else
                                     {
                                         n->setnext(temp->getnext());
                                         temp->setnext(n);
                                     }
                         }
                         
                         int  AMB(int before, int tobe)
                           {
                               node *n=new node(tobe);
                               node *temp=head;
                               node *prev=temp;
                               
                               while(temp->getdata()!=before)
                                   {
                                       prev=temp;
                                       temp=temp->getnext();
                                      if(temp==NULL)
                                        {
                                            return 0;
                                        }
                                   }
                                   if (head->getdata()==before)
                                      {
                                          n->setnext(head);
                                          head=n;
                                      }
                                else
                                   {
                                       n->setnext(prev->getnext());
                                       prev->setnext(n);
                                   }
                                      
                           }
                           
                           int DN(int data)
                               {
                                   node *temp=head;
                                   node *prev=temp;
                                   while( temp->getdata()!=data)
                                   {
                                       prev=temp;
                                       temp=temp->getnext();
                                       if(temp==NULL)
                                         {
                                             return 0;
                                         }
                                   }
                                   if(head->getdata()==data)
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
                               
                            int DNA(int data)
                                {
                                    node *temp=head;
                                    node *prev=head;
                                    
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
                                      node *temp=head;
                                      node *prev=head;
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
                                         while(  temp->getnext()->getdata()!=data)
                                          {
                                                prev=temp;
                                                temp=temp->getnext();
                                          }
                                          prev->setnext(temp->getnext());
                                          delete temp;
                                         }
                                  }
                             
                     void PR()
                         {
                             node *temp=head;
                             while(temp!=NULL)
                                  {
                                     cout<<temp->getdata()<<" ";
                                     temp=temp->getnext();
                                  }
                                  cout<<endl;
                          }
                            
                     void FPR()
                          {
                             node *temp=head;
                             while(temp->getnext()!=NULL)
                                  {
                                     cout<<temp->getdata()<<"->";
                                     temp=temp->getnext();
                                  }
                                  cout<<temp->getdata();
                                  cout<<endl;
                          }
                          
                        void reverse()
                           {
                               node *temp;
                               temp=head;
                               RPR(temp);
                               cout<<endl;
                               
                           }
                          
                    void RPR(node *temp)
                          {
                              if(temp==NULL)
                                 return ;
                                 RPR(temp->getnext());
                                 cout<<temp->getdata()<<" ";
                          }
                          
                          
};

int main()
      {
           int a,d;
        linklist s1;
         string cmd;
          while(1)
              {
                 cin>>cmd;
                   if(cmd=="EXIT")
                      {
                        exit(0);
                       }
                   if(cmd=="AB")
                        {
                           
                             cin>>a;
                            s1.AB(a);
                        }
                        
                    if (cmd=="AE")
                        {
                             cin>>a;
                             s1.AE(a);
                        }
                        
                   if(cmd=="AMA")
                       {
                          //int d;
                          cin>>a;
                          cin>>d;
                          s1.AMA(a,d);
                       }
                          
                   if(cmd=="AMB")
                       {
                          //int d;
                          cin>>a;
                          cin>>d;
                          s1.AMB(a,d);
                       }
                       
                    if (cmd=="DN")
                       {
                           cin>>a;
                           s1.DN(a);
                       }
                     if(cmd=="DNA")
                        {
                            cin>>a;
                            s1.DNA(a);
                        }
                        if (cmd=="DNB")
                          {
                              cin>>a;
                              s1.DNB(a);
                          }
                    if(cmd=="PR")
                        {
                             s1.PR();
                        }
                        
                    if (cmd=="FPR")
                        {
                            s1.FPR();
                        }
                        
                    if(cmd=="RPR")
                       {
                           s1.reverse();
                       }
              }
        return 0;
      }