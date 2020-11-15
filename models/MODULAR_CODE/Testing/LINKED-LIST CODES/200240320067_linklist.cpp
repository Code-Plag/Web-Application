#include<iostream>
#include<stdlib.h>

using namespace std;

class Node{
    private:
        int data;
        Node *next;
    public:
        Node()
        {
        data=0;
        this->next=NULL;
        }
        Node(int data)
        {
        this->data=data;
        next=NULL;
        }
        ~Node()
        {
            next=NULL;
        }
        int getdata()
        {
        return data;
        } 
        Node *getnext()
        {
        return next;
        }
        void setnext(Node *next)
        {
        this->next=next;
        }
    };
    
    
class linklist
    {
        private:
            Node*head;
        public:
            linklist()
        {
        head=NULL;
        }
    
    void AE(int data)
    {
        Node *node=new Node(data);
        if (head==NULL)
        {
            head=node;
        }
        else
        {
            Node *temp=head;
            while(temp->getnext()!=NULL)
            {
                temp=temp->getnext();
            }
            temp->setnext(node);
        }     
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
    node->setnext(head);
    head=node;
    }
}


int AMB(int tobe,int before)
{
Node*node=new Node(before);
Node*temp=head;
Node *prev=head;
while(temp->getdata()!=tobe)
{
    prev=temp;
    temp=temp->getnext();
    if(temp==NULL)
    {
        return 0;
    }
}
if(head->getdata()==tobe)
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


void AMA(int tobe,int after)
{
    Node *node=new Node(after);
    Node *temp=head;
    while(temp!=NULL && temp->getdata()!=tobe)
    {
        temp=temp->getnext();
        if(temp==NULL)
        {
            return ;
        }
    }
   if(head->getdata()==tobe)
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
          
int DN(int data)
{
    Node*temp=head;
    Node*prev=head;
    while(temp->getnext()!=NULL && temp->getdata()!=data)
    {
        prev=temp;
        temp=temp->getnext();
    }
        prev->setnext(temp->getnext());
        delete temp;
}


Node *DNA(int after)
{
        Node *temp=head;
        Node *next=head;
        while(temp->getdata()!=after && temp->getnext()!=NULL)
        {
                temp=temp->getnext();
                next=temp->getnext();
        }
        while(1)
        {
            if(temp->getnext()==NULL)
            {
                    break;
            }
            else if(next->getnext()==NULL)
            {
                temp->setnext(NULL);
                delete next;
            }
            else if(temp->getdata()==after)
            {
                next=temp->getnext();
                Node *temp1=next->getnext();
                temp->setnext(temp1);
                delete next;
            }
            break;
        }
}


Node *DNB (int before)
{
    Node *temp=head;
    Node *prev=head;
    while(1)
    {
        if(temp->getdata()==before && temp!=NULL)
        {
            break;
        }
        while(temp->getnext()->getdata()!=before)
        {
            prev=temp;
            temp=temp->getnext();
        }
        if(temp==head)
        {
            head=temp->getnext();
            delete temp;
        }
        else
        {
            prev->setnext(temp->getnext());
        }
        break;
    }
}
    void RPR()
    {
    int count=1;
    Node *temp=head;
    Node *temp1=head;
    while(temp->getnext()!=NULL)
    {
    temp=temp->getnext();
    count=count+1;
    }
    int *store;
    store=new int[count];
    
    for(int i=1;i<=count;i++)
    {
            store[i]=temp1->getdata();
            temp1=temp1->getnext();
    }
    for(int j=count;j>=1;j--)
    {
        cout<<store[j]<<"  ";
    }
    cout<<endl;
}
 void PR()
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
         if(temp->getnext()==NULL)
         {
         cout<<temp->getdata();
         break;
         }
           cout<<endl;
     }
}
        
         ~linklist()
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
    linklist l;
    string cmd;
    do
    {
        cin>>cmd;
        if(cmd=="AB")
        {
            int data;
            cin>>data;
            l.AB(data);
        }

        if(cmd=="AE")
        {
            int data;
            cin>>data;
            l.AE(data);
        }

        if(cmd=="AMB")
        {
            int data,before;
            cin>>data;
            cin>>before;
            l.AMB(data,before);
        }

        if(cmd=="AMA")
        {
            int data,after;
            cin>>data;
            cin>>after;
            l.AMA(data,after);
        }
 
        if(cmd=="DN")
        {
            int data;
            cin>>data;
            l.DN(data);
        }

        if(cmd=="DNA")
        {
            int data;
            cin>>data;
            l.DNA(data);
        }
 
        if(cmd=="DNB")
        {
            int data;
            cin>>data;
            l.DNB(data);
        }

        if(cmd=="RPR")
        {
            l.RPR();
        }
    
        if(cmd=="PR")
        {
            l.PR();
        }
    
        if(cmd=="FPR")
        {
            l.FPR();
        }
    }
    while(cmd !="EXIT");
    return 0;
}
