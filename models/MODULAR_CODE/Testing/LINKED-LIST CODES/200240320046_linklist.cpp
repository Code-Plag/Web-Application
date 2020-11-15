#include<iostream>
using namespace std;

class Node
{
    private:
        int age;
        string name;
        Node *next;
        friend class linklist;
};
class linklist
{
    private:
        Node *head;
    public:
        linklist()
        {
            head=NULL;
        }
        void addNode(string nam,int data)
        {
            Node *temp,*temp1;
            temp1=head;
            temp=head;
            Node *newnode=new Node;
            newnode->age=data;
            newnode->name=nam;
            newnode->next=NULL;

            if(head==NULL)

                head=newnode;

            else
            {

                while((temp->next != NULL)&&(temp->age <= data))
                {
                    temp1=temp;
                    temp=temp->next;
                }
                if(temp==head)
                {
                    if(temp->age <= data)
                    {
                        temp1->next=newnode;
                        newnode->next=NULL;
                    }
                    else
                    {
                       newnode->next=head;
                       head=newnode;
                    }
                }

                else if(temp->next == NULL)
                {
                    if(temp->age <= data)
                    {
                        temp->next=newnode;
                        newnode->next=NULL;
                    }
                    else
                    {
                        newnode->next=temp;
                        temp1->next=newnode;
                    }
                }
                else if(temp->next != NULL)
                {
                    newnode->next=temp;
                    temp1->next=newnode;
                }
             }
        }

        void deleteNode(int data)
        {
            int i=1;
            Node *temp,*temp1,*temp2;
            temp1 = temp = head;
            if(data == 1)
            {
                head=head->next;
                temp=NULL;
                temp1=NULL;
            }
            else
            {
                while(i < data-1)
                {
                    temp=temp->next;
                    i++;
                }
                temp1=temp->next;
                temp->next=temp1->next;
                temp1->next=NULL;
                temp1=NULL;
            }
        }
        void printLL(int manip)
        {
            int i = 1;
            Node *temp;
            temp=head;
            while(i<manip)
            {
                i++;
                temp = temp->next;
            }
            cout<<temp->name<<" "<<temp->age<<endl;
        }
};
int main()
{
    linklist m;
    while(1)
    {
        string input;
        cin>>input;
        if(input == "insert")
            {
                int data;
                string name;
                cin>>name;
                cin>>data;
                m.addNode(name,data);
            }
            if(input =="remove")
            {
                int data;
                cin>>data;
                m.deleteNode(data);
            }
            if(input =="print")
            {
                int manip;
                cin>>manip;
                m.printLL(manip);
            }
            if(input =="stop")
            {
                break;
            }
    }
 return 0;
}
