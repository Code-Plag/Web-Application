#include<iostream>
using namespace std;
class Node
{
    private:
        int data;
        Node *next;
    public:
        Node()
        {
            data=0;
            next=NULL;
        }
        Node(int data)
        {
            this->data=data;
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
class LinkList
{
    private:
        Node *head;
    public:
    LinkList()
    {
        head=NULL;
    }
    void insertbeg(int data)
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
    void insertend(int data)
    {
        Node *node=new Node(data);
        if(head==NULL)
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
    void insertafter(int tobe,int after)
    {
        Node *node=new Node(after);
        Node *temp=head;
        while(temp!=NULL && temp->getdata()!=tobe)
        {
            temp=temp->getnext();
        }
        if(temp==NULL)
        {
            cout<<"Data Not found" <<endl;
        }
        else
        {
            node->setnext(temp->getnext());
            temp->setnext(node);
        }
    }
    int insertbefore(int tobe,int before)
    {
        Node *node=new Node(before);
        Node *temp=head;
        Node *prev=head;
        while(temp->getdata()!=tobe)
        {
            prev=temp;
            temp=temp->getnext();
        }
        if(temp==NULL)
        {
            return 0;
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
    void deletenode(int data)
    {
        Node *temp=head;
        Node *prev=head;
        while(temp->getnext()!=NULL && temp->getdata()!=data)
        {
            prev=temp;
            temp=temp->getnext();
        }
            prev->setnext(temp->getnext());
            delete temp;
    }

    void deleteafter(int after)
    {
        Node *temp=head;
        Node *next=head;
        while(temp->getnext()!=NULL && temp->getdata()!=after)
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
    int deletebefore(int before)
    {
        Node *temp=head;
        Node *prev;
        if(temp->getdata()==before && temp!=NULL)
        {
            return 0;
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
            delete temp;
        }
    }
    void fancyprint()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->getdata() <<"->";
            temp=temp->getnext();
            if(temp->getnext()==NULL)
            {
            cout<<temp->getdata();
            break;
            }
        }
        cout<<endl;
    }
    void reverseprint()
    {
        Node *temp=head;
        Node *temp2=head;
        int count=1;
        while(temp->getnext()!=NULL)
        {
            temp=temp->getnext();
            count=count+1;
        }
        int *store;
        store=new int[count];
        for(int i=1;i<=count;i++)
        {
            store[i]=temp2->getdata();
            temp2=temp2->getnext();
        }
        for(int j=count;j>=1;j--)
        {
            cout<<store[j]<<" ";
        }
            cout<<endl;
    }

    void print()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->getdata() <<" ";
            temp=temp->getnext();
        }
        cout<<endl;
    }
    ~LinkList()
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
        LinkList l;
        string cmd;
        while(1)
        {
            cin>>cmd;
            if(cmd=="EXIT")
            {
                break;
            }
            else if(cmd=="AB")
            {
                int data;
                cin>>data;
                l.insertbeg(data);
            }
            else if(cmd=="AE")
            {
                int data;
                cin>>data;
                l.insertend(data);
            }
            else if(cmd=="AMA")
            {
                int tobe;
                int after;
                cin>>tobe;
                cin>>after;
                l.insertafter(tobe,after);
            }
            else if(cmd=="AMB")
            {
                int tobe;
                int before;
                cin>>tobe;
                cin>>before;
                l.insertbefore(tobe,before);
            }
            else if(cmd=="DN")
            {
                int data;
                cin>>data;
                l.deletenode(data);
            }
            else if(cmd=="DNA")
            {
                int data;
                cin>>data;
                l.deleteafter(data);
            }
            else if(cmd=="DNB")
            {
                int data;
                cin>>data;
                l.deletebefore(data);
            }
            else if(cmd=="FPR")
            {
                l.fancyprint();
            }
            else if(cmd=="RPR")
            {
                l.reverseprint();
            }
            else if(cmd=="PR")
            {
                l.print();
            }
        }
        return 0;
    }
