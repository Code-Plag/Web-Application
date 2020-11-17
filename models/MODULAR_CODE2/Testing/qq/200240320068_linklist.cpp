#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class Node
{
    private:
            int data;
            Node* next;
    public:
            Node(int data)
            {
                this->data=data;
                next=NULL;
            }
            ~Node()
            {
                
            }
            int getData()
            {
                return data;
            }
            void setNext(Node* next)
            {
                this->next=next;
            }
            Node* getNext()
            {
                return next;
            }
            
};

class Linklist
{
    private:
            Node* head;
    public:
            Linklist()
            {
                head=NULL;
            }
            ~Linklist()
            {
                
            }
            void insertB(int data)
            {
                Node* node=new Node(data);
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
            void insertE(int data)
            {
                Node* node=new Node(data);
                if(head==NULL)
                {
                    head=node;
                }
                else
                {
                    Node* temp=head;
                    while(temp->getNext()!=NULL)
                    {
                        temp=temp->getNext();
                    }
                    temp->setNext(node);
                }
            }
            
            int insertAfter(int after,int data)
            {
                Node* node=new Node(data);
                Node* temp=head;
                while(temp->getData()!=after)
                {
                    temp=temp->getNext();
                    if(temp==NULL)
                    {
                        return 0;
                    }
                }
                if(head->getData()==after)
                {
                    node->setNext(temp->getNext());
                    head->setNext(node);
                }
                else
                {
                    node->setNext(temp->getNext());
                    temp->setNext(node);
                }
            }
            
            int insertBefore(int before,int data)
            {
                Node* node=new Node(data);
                Node* temp=head;
                Node* prev=temp;
                while(temp->getData()!=before)
                {
                    prev=temp;
                    temp=temp->getNext();
                    if(temp==NULL)
                    {
                        return 0;
                    }
                }
                if(head->getData()==before)
                {
                    node->setNext(head);
                    head=node;;
                }
                else
                {
                    node->setNext(prev->getNext());
                    prev->setNext(node);
                }
            }
            
            int deleteMid(int data)
            {
                Node* temp=head;
                Node* prev=temp;
                while(temp->getData()!=data)
                {
                    prev=temp;
                    temp=temp->getNext();
                    if(temp==NULL)
                    {
                        return 0;
                    }
                }
                if(head->getData()==data)
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
            
            int deleteBefore(int data)
            {
                Node* temp=head;
                Node* prev=head;
                if(head->getData()==data)
                {
                    return 0;
                }
                if(head->getNext()->getData()==data)
                {
                    head=head->getNext();
                }
                else
                {
                    while(temp->getNext()->getData()!=data)
                    {
                        prev=temp;
                        temp=temp->getNext();
                    }
                    prev->setNext(temp->getNext());
                    delete temp;
                    
                }
            }
            
            int deleteAfter(int data)
            {
                Node* temp=head;
                Node* prev=head;
                while(temp->getData()!=data)
                {
                    prev=temp;
                    temp=temp->getNext();
                    if(temp==NULL)
                    {
                        return 0;
                    }
                }
                prev=temp;
                temp=temp->getNext();
                if(temp!=NULL)
                    prev->setNext(temp->getNext());
                    delete temp;
            }
            
            void reverse1(Node* temp)
            {
                if(temp->getNext()!=NULL)
                {
                    reverse1(temp->getNext());
                }
                cout<<temp->getData()<<" ";
            }
            
            void reverse()
            {
                Node* temp;
                temp=head;
                reverse1(temp);
                cout<<endl;
            }
            
            void Fancy()
            {
                Node* temp=head;
                while(temp->getNext()!=NULL)
                {
                    cout<<temp->getData()<<"->";
                    temp=temp->getNext();
                }
                cout<<temp->getData()<<endl;
            }
            
            void show()
            {
                Node* temp=head;
                while(temp->getNext()!=NULL)
                {
                    cout<<temp->getData()<<" ";
                    temp=temp->getNext();
                }
                cout<<temp->getData()<<endl;
            }
};

int main()
{
    Linklist ll;
    string cmd;
    int data,before,after;
    while(1)
    {
        cin>>cmd;
        if(cmd=="AB")
        {
            cin>>data;
            ll.insertB(data);
        }
        if(cmd=="AE")
        {
            cin>>data;
            ll.insertE(data);
        }
        if(cmd=="AMA")
        {
            cin>>after>>data;
            ll.insertAfter(after,data);
        }
        if(cmd=="AMB")
        {
            cin>>before>>data;
            ll.insertBefore(before,data);
        }
        if(cmd=="DN")
        {
            cin>>data;
            ll.deleteMid(data);
        }
        if(cmd=="DNA")
        {
            cin>>data;
            ll.deleteAfter(data);
        }
        if(cmd=="DNB")
        {
            cin>>data;
            ll.deleteBefore(data);
        }
        if(cmd=="RPR")
        {
            ll.reverse();
        }
        if(cmd=="PR")
        {
            ll.show();
        }
        if(cmd=="FPR")
        {
            ll.Fancy();
        }
        if(cmd=="EXIT")
        {
            exit(0);
        }
    }
    return 0;
}