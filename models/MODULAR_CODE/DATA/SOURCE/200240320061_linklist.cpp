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

    Node* getnext()
    {
        return next;
    }

    void setnext(Node *next)
    {
        this->next=next;
    }
};

class List
{
private:
    Node *head;
public:
    List()
    {
        head=NULL;
    }

    void AB(int data)
    {
        Node *add;
        add=new Node(data);
        add->setnext(head);
        head=add;
    }

    void AE(int data)
    {
        Node *add;
        add=new Node(data);
        Node *temp;
        temp=head;
        if(head==NULL)
        head=add;
        else
        {
            while(temp->getnext()!=NULL)
            {
                temp=temp->getnext();
            }
            temp->setnext(add);
        }
    }

    void AMA(int after, int data)
    {
        Node *add;
        add=new Node(data);
        Node *temp=head;
        while(temp!=NULL)
        {
            if(temp->getdata()==after)
            {
                add->setnext(temp->getnext());
                temp->setnext(add);
                break;
            }
            temp=temp->getnext();
        }
    }

    void AMB(int before, int data)
    {
        Node *add;
        add=new Node(data);
        Node *temp=head;
        Node *temp1=head;
        while(temp!=NULL)
        {
            if(temp->getdata()==before)
            {
                if(head->getdata()==before)
                {
                    add->setnext(temp);
                    head=add;
                }
                else
                {
                    add->setnext(temp);
                    temp1->setnext(add);
                    break;
                }
            }
            temp1=temp;
            temp=temp->getnext();
        }
    }

    void DN(int data)
    {
        Node *temp=head;
        Node *temp1=head;
        while(temp!=NULL)
        {
            if(temp->getdata()==data)
            {
                if(temp==head)
                {
                    head=temp;
                    delete [] temp;
                }
                else
                {
                    temp1->setnext(temp->getnext());
                    delete [] temp;
                    break;
                }
            }
            temp1=temp;
            temp=temp->getnext();
        }
    }
    /*
    void DNA(int data)
    {
        Node *temp=head;
        Node *temp1=temp->getnext();
        while(temp1->getnext()!=NULL)
        {
            if(temp1->getdata()==data)
            {
                break;
            }
            if(temp->getdata()==data && temp==head)
            {
                temp->setnext(temp->getnext()->getnext());
                break;
            }
            if(temp->getdata()==data)
            {
                temp->setnext(temp1->getnext());
                break;
            }
            temp=temp->getnext();
            temp1=temp->getnext();
        }
    }
    */
    void DNA(int data)
    {
        Node *temp=head;
        Node *temp1=head;
        while(temp->getnext()!=NULL)
        {
            if((temp1->getnext()==NULL) && (temp1->getdata()==data))
            {
                break;
            }
            if(temp->getdata()==data && temp==head)
            {
                temp->setnext(temp->getnext()->getnext());
                break;
            }
            if(temp->getdata()==data)
            {
                temp->setnext(temp1->getnext());
                break;
            }
            temp=temp->getnext();
            temp1=temp->getnext();
        }
    }
    /*
    void DNB(int data)
    {
        Node *temp=head->getnext();
        Node *temp1=temp;
        Node *temp2=head;
        while(temp!=NULL)
        {
            if(temp->getdata()==data)
            {
                if(temp1==head)
                {
                    head=temp;
                    temp1->setnext(NULL);
                    delete [] temp1;
                }
                else
                {
                    temp2->setnext(temp);
                    delete [] temp1;
                    break;
                }
            }
            temp2=temp1;
            temp1=temp;
            temp=temp->getnext();
        }
    }
    */
    void DNB(int data)
    {
        Node *temp=head;
        Node *temp1=head;
        Node *temp2=head;
        while(temp!=NULL)
        {
            if(temp->getdata()==data)
            {
                if(temp==head)
                {
                    break;
                }
                if(temp1==head)
                {
                    head=temp;
                    //temp1->setnext(NULL);
                    delete [] temp1;
                }
                else
                {
                    temp2->setnext(temp);
                    delete [] temp1;
                    break;
                }
            }
            temp2=temp1;
            temp1=temp;
            temp=temp->getnext();
        }
    }

    void PR()
    {
        Node *temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->getdata();
            if(temp->getnext()!=NULL)
            cout<<" ";
            temp=temp->getnext();
        }
        cout<<endl;
    }

    void FPR()
    {

        Node *temp;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->getdata();
            if(temp->getnext()!=NULL)
            cout<<"->";
            temp=temp->getnext();
        }
        cout<<endl;
    }

    void RPR()
    {
        Node *temp;
        //temp=head;
        //int *store;
        int count=0;

        for(temp=head;temp!=NULL;temp=temp->getnext())
        count++;

        /*while(temp!=NULL)
        {
            count++;
            temp=temp->getnext();
        }
        */
        temp=head;
        int store[count];
        //store=new int[count];
        for(int i=0;i<count;i++)
        {
            store[i]=temp->getdata();
            temp=temp->getnext();
        }
        for(int i=count-1;i>=0;i--)
        {
            cout<<store[i];
            if(i>0)
                cout<<" ";
        }
        cout<<endl;
    }

    ~List()
    {
        while(head!=NULL)
        {
            Node *temp;
            temp=head;
            head=head->getnext();
            delete [] temp;
        }
    }
};

int main()
{
    List obj;
    string str;
    int d;
    do
    {
        cin>>str;
        if(str=="AB")
        {
            cin>>d;
            obj.AB(d);
        }

        if(str=="AE")
        {
            cin>>d;
            obj.AE(d);
        }

        if(str=="AMA")
        {
            int after;
            cin>>after>>d;
            obj.AMA(after,d);
        }

        if(str=="AMB")
        {
            int before;
            cin>>before>>d;
            obj.AMB(before,d);
        }

        if(str=="DN")
        {
            cin>>d;
            obj.DN(d);
        }

        if(str=="DNA")
        {
            cin>>d;
            obj.DNA(d);
        }

        if(str=="DNB")
        {
            cin>>d;
            obj.DNB(d);
        }

        if(str=="PR")
        {
            obj.PR();
        }

        if(str=="FPR")
        {
            obj.FPR();
        }

        if(str=="RPR")
        {
            obj.RPR();
        }

    }while(str!="EXIT");
    return 0;
}
