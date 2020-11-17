#include<iostream>
#include<cstring>
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
                Node* getNext()
                {
                    return next;
                }
                void setNext(Node *next)
                {
                    this->next=next;
                }
                int getData()
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
                    head=node;
                    else
                    {
                        Node *temp;
                        temp=head;
                        while(temp->getNext()!=NULL)
                        {
                            temp=temp->getNext();
                        }
                        temp->setNext(node);
                    }
                }
                void AMA(int after,int data)
                {
                    Node *node=new Node(data);
                        Node *temp;
                        temp=head;
                    if(head==NULL)
                        head=node;
                    else
                    {
                        while(temp->getNext()!=NULL && temp->getData()!=after)
                        {
                            temp=temp->getNext();
                        }
                        if(temp==NULL)
                        {
                          return;
                        }
                        else
                        {
                            node->setNext(temp->getNext());
                            temp->setNext(node);
                        }
                    }
                    
                }
                void AMB(int before,int data)
                { 
                  Node *node=new Node(data);
                        Node *temp;
                        Node *prev;
                        temp=head;
                        prev=head;
                    if(head==NULL)
                        head=node;
                    if(head->getData()==before)
                    {
                        node->setNext(head);
                        head=node;
                    }
                    else
                    {
                        while(temp->getNext()!=NULL && temp->getData()!=before)
                        {
                            prev=temp;
                            temp=temp->getNext();
                        }
                        if(temp==NULL)
                        {
                            return;
                        }
                        else
                        {
                            node->setNext(temp);
                            prev->setNext(node);
                        }
                    }
                }
                void DN(int data)
                {
                    Node *temp=head;
                    
                    if(head->getData()==data)
                    {
                        head=head->getNext();
                        
                    }
                    else
                    {
                        while(temp!=NULL && (temp->getNext())->getData()!=data)
                        {
                            temp=temp->getNext();
                        }
                        if(temp==NULL)
                        {
                            cout<<"Data not found";
                        }
                        else if(temp->getNext()==NULL)
                        {
                            delete temp;
                        }
                        else
                        {
                            temp->setNext((temp->getNext())->getNext());
                        }
                    }                
                }
                void DNA(int data)
                {
                    Node *temp;
                    temp=head;
                    while(temp!=NULL && temp->getData()!=data)
                    {
                        temp=temp->getNext();
                    }
                
                    if(temp==NULL)
                    {
                        return;
                    }
                    else if(temp->getNext()==NULL)
                    {
                        return;                    
                    }
                    else
                    {
                        temp->setNext((temp->getNext())->getNext());
                    }
                }
                
                
                void DNB(int data)
                {
                    Node *temp;
                    Node *prev;
                    temp=head;
                    prev=head;
                    if(head->getData()==data)
                    {
                        return;
                    }
                    else
                    {
                    while(temp!=NULL && (temp->getNext())->getData()!=data)
                    {
                        prev=temp;
                        temp=temp->getNext();
                    }
                    if(temp==NULL)
                    {
                        return;
                    }
                    if(head->getNext()->getData()==data)
                    {
                        head=head->getNext();
                    }
                    else
                    {
                        prev->setNext(temp->getNext());
                        delete temp;
                    }
                    }  
            }
                void FPR()
                {
                    Node *temp;
                    temp=head;
                    Node *prev;
                    prev=head;
                    while(temp->getNext()!=NULL)
                    {
                        prev=temp;
                        cout<<prev->getData()<<"->";
                        temp=temp->getNext();
                    }
                    cout<<temp->getData()<<endl;
                }
                
                Node * getHead()
                {
                    return head;
                }
                void RPR(Node *rev)
                {   
                    if(rev==NULL)
                    {
                        return;
                    }
                    else
                    {
                        RPR(rev->getNext());
                        cout<<rev->getData()<<" ";
                    }
                    
                    
                }
                void PR()
                {
                    Node *temp;
                    temp=head;
                    while(temp!= NULL)
                    {
                        cout<<temp->getData()<<" ";
                        temp=temp->getNext();
                    }
                    cout<<endl;
                }
};

int main()
{
    LinkList l1;
    string cmd;
    
    int data;
    while(1)
    {   
        
        cin>>cmd;
        if(cmd=="AB")
        {
            cin>>data;
            l1.AB(data);
        }
        if(cmd=="PR")
        {
            l1.PR();
        }
        if(cmd=="AE")
        {
            cin>>data;
            l1.AE(data);
        }
        if(cmd=="AMA")
        {
          
            int after;
         
            cin>>after;
            cin>>data;
            l1.AMA(after,data);
        }
        if(cmd=="AMB")
        {
            int before;
            cin>>before;
            cin>>data;
            l1.AMB(before,data);
        }
        if(cmd=="DN")
        {
            
            cin>>data;
            l1.DN(data);
        }    
        if(cmd=="DNA")
        {
            
            cin>>data;
            l1.DNA(data);
        }  
         if(cmd=="DNB")
        {
            
            cin>>data;
            l1.DNB(data);
        }    
         if(cmd=="FPR")
        {
            l1.FPR();
        }
        if(cmd=="RPR")
        {
            l1.RPR(l1.getHead());
            cout<<endl;
        }
        if(cmd == "EXIT")
        {
            break;
        }
        
        
    }
    return 0;
    
}