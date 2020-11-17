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
        Node()
        {
            next=NULL;
        }
        
        /*~Node()
        {
            next=NULL;
        }*/
        
        Node(int data)
        {
            this->data=data;
            this->next=NULL;
        }
        
        int getdata()
        {
            return data;
        }
        
        Node* getnext()
        {
            return next;
        }
        
        void setnext(Node* next)
        {
            this->next=next;
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
        
        void insertbegin(int data)
        {
            Node* node=new Node(data);
            if(head==NULL){
                head=node;
                }
            else{
                node->setnext(head);
                head=node;
                }
        }
        
        void print()
        {
            Node*temp=head;
            while(temp!=NULL)
            {
                cout<<temp->getdata()<<" ";
                temp=temp->getnext();
            }
            cout<<endl;
        }
        
        void insertend(int data)
        {
            Node* node=new Node(data);
            if(head==NULL){
                head=node;
            }
            else{
                Node* temp=head;
                while(temp->getnext()!=NULL)
                {
                    temp=temp->getnext();
                }
                    temp->setnext(node);
            }
        }
        
        void insertafter(int after,int data)
        {
            Node* node=new Node(data);
            Node* temp=head;
            while(temp!=NULL && temp->getdata()!=after)
            {
                temp=temp->getnext();
                if(temp==NULL){
                    cout<<"data not found"<<endl;
                }
            }
            if(head->getdata()==after)
            {
                node->setnext(head->getnext());
                head->setnext(node);
            }
            else{
                node->setnext(temp->getnext());
                temp->setnext(node);
            }
        }
        
        int insertbefore(int before, int data)
        {
            Node*node=new Node(data);
            Node* prev;
            Node* temp=head;
            while(temp->getdata() != before)
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
        
        /*void delfirst(int data)
        {
            Node* temp=head;
            
            if(head!=NULL){
             temp=head;
             head=temp->getnext();
             delete temp;
            }
            else{
                cout<<endl;
            }    
        }*/

        int dR(int data)
        {
            Node* temp;
            Node* prev;
            prev=temp=head;
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

        int delbefore(int data)
        {
            Node* temp;
            Node* prev;
            temp=prev=head;
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
        
        int delafter(int data)
        {
            Node* temp;
            Node* prev;
            temp=prev=head;
            while(temp->getdata() != data)
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
        
        void print_fancy()
        {
            Node*temp=head;
           while(temp->getnext()!=NULL)
            {
                cout<<temp->getdata()<<"->";
                temp=temp->getnext();
            }
            cout<<temp->getdata()<<endl; 
        }
        
        void RV()
        {
            Node* temp;
            temp=head;
            R(temp);
            cout<<endl;
        }
        
        void R(Node* temp)
        {
            if(temp->getnext()!=NULL)
            {
                R(temp->getnext());
            }
            cout<<temp->getdata()<<" ";
        }
};

int main()
{
    Linklist ll;
    int data;
    int position;
    string cmd;
   
   while(1)
   { 
       cin>>cmd;
        
        if(cmd=="AB")
        {
            cin>>data;
           ll.insertbegin(data);
           
        }
        
        if(cmd=="PR")
        {
            ll.print();
        }
        
        if(cmd=="AE")
        {
            cin>>data;
            ll.insertend(data);    
        }
        
        if(cmd=="AMA")
        {
            cin>>position;
            cin>>data;
            ll.insertafter(position,data);    
        }
        
        if(cmd=="AMB")
        {
            cin>>position;
            cin>>data;
            ll.insertbefore(position,data);
        }

        if(cmd=="DN")
        {
            cin>>position;
            //ll.delfirst(N);
            ll.dR(position);
        }
        
        if(cmd=="DNA")
        {
            cin>>position;
            ll.delafter(position);
        }
        
        if(cmd=="DNB")
        {
            cin>>position;
            ll.delbefore(position);
            //ll.print();
        }
        
        
        if(cmd=="FPR")
        {
            ll.print_fancy();
        }
        
        if(cmd=="RPR")
        {
            ll.RV();
            //ll.print_fancy();
        }
        
        if(cmd=="EXIT")
        {
            exit (0);
        }
   }
   return 0;
}