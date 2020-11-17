#include<iostream>
using namespace std;

class node
{
    
        int data;
        node *next;
    public:
        friend class linklist;
};
class linklist
{
    private:
        node *head;
    public :
        linklist()
        {
            head = NULL;
        }
        node* gethead()
       {
         return head;
       }
       ~linklist()
       {
           while(head != NULL)
           {
               node *temp = head;
               head = head -> next;
               delete temp;
           }
       }

    void AddFirst(int d)
    {
        node *newnode;
        int data;
        newnode = new node;
        newnode -> data = d;
        newnode -> next = NULL;
        
        if (head == NULL)
        {
            head = newnode;
        }
        else
            {
             newnode-> next = head;
             head = newnode;
            }
    }
    
     void AddLast(int d)
    {
        node *newnode;
        int data;
        newnode = new node;
        newnode -> data = d;
        newnode -> next = NULL;
            if(head==NULL)
            {
                  head = newnode;
            }
            else
            {
                 node *temp;
                 temp=head;
                while(temp->next != NULL)
                {   
                    temp = temp->next;
                }
                temp->next = newnode;
            }
    }
    
    void AddNodeAfter(int after, int d)
    {
       node*newnode;
       newnode = new (node);
        newnode -> data = d;
        newnode -> next = NULL;
        node *temp;
        temp = head;
            while(temp != NULL && temp -> data != after)
            {
                temp = temp -> next;
            }
            if (temp==NULL)
            {
                
            }
            else
            {
                newnode -> next = temp-> next;
                temp-> next = newnode;
            }
    }
    
    void AddNodeBefore(int before, int d)
    {
            
        node *newnode;
        int data;
        newnode = new node;
        newnode -> data = d;
        newnode -> next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else 
        {
            node *t1;
            node *t2;
            t1 =t2 = head;
            
        while (t1 != NULL && t1->data != before)
        {
            t2 =t1;
            t1 = t1->next;
        }
        if (t1 == head)
        {
             newnode -> next= t1;
               head = newnode;
        }
        else if (t1 != NULL)
        {
           newnode-> next =t1;
           t2->next= newnode;
        }
        else if(t1==NULL)
        {
            
        }
        
        }
    }

void DelNode(int after)
    {
        node *t1;
        node *t2;
        t1 =t2 = head;
        while (t1->data != after)
        {
            t2 =t1;
            t1 = t1-> next;
        }
        t2-> next = t1-> next;
        t1-> next = NULL;
        delete [] t1;
        
    }
  void Rev(node *temp)

    {
        
        if(temp == NULL)
            return ;
        
      Rev(temp->next);
        cout<<temp->data<<" ";
    }
    void print()
    {
        node *trav;
        trav = head;
        while(trav != NULL)
            {
                cout<<trav->data<<" ";
                trav = trav -> next;
            }
        cout<<endl;
    }
void delafter(int after)
    {
        node * temp;
        node *t2;
        temp = head;
        t2 = NULL;
        while ( (temp != NULL) && (temp->data != after) )
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            t2 == NULL;
        }
       else if(temp->next == NULL)
        {
            return;
        }
        else
        {
            t2 = temp->next;
             temp->next =  t2->next;    
             t2 ->next =NULL;
            //t3 = NULL;
            delete [] t2;

        }


    }
void delbefore(int before)
     {
         node * t1;
         node * t2;
        node *t3;
        t1 = head;
        t2 = head;
        t3 = head;
    while( (t1 != NULL) && (t1->data != before) )
        {
            t3 = t2;
            t2 = t1;
            t1 = t1->next;
        }
    if (t1 == NULL)
        {
            t3 = NULL;
            t2 = NULL;
        }
      if (t1 == head)
        {
            t3 = NULL;
            t2 = NULL;
        }
     else if(t2 == head && t3 == head)
        {
           this-> head = t1;
            t2->next = NULL;
             t3 = NULL;
            t2 = NULL;
        }
     else if (t1 != NULL)
        {
            t3->next = t1;
            t2->next = NULL;
             t3 = NULL;
            t2 = NULL;
        }
    

    }

    void fancy()
    {
        node*temp = head;
        while(temp != NULL)
        {
            if (temp->next != NULL)
            {
                cout<<temp->data<<"->";
                temp = temp->next;    
            }
        else if (temp->next == NULL)
            {
                 cout<<temp->data<<endl;
                  temp = temp->next;   
            }
        }

    }
};

int main()
{
    linklist l1;
    int data1;
  
    string s;
    while (1)
    {
        cin>>s;
        if (s=="AB")
         {
             cin>>data1;
             l1.AddFirst(data1);
         }
          if (s=="AE")
         {
             cin>>data1;
             l1.AddLast(data1);
         }
          if (s=="PR")
         {
             l1.print();
         }
         
        if(s=="EXIT")
         {
             break;
         }
         if(s=="AMA")
         {
               int d;
             cin>>d;
             cin>>data1;
             l1.AddNodeAfter(d,data1);
         }
          if(s=="AMB")
         {
               int d;
             cin>>d;
             cin>>data1;
             l1.AddNodeBefore(d,data1);
         }
         if (s=="DN")
         {
             int d;
             cin>>d;
             l1.DelNode(d);
         }
        if(s=="RPR")
        {
            
             l1.Rev(l1.gethead());
        }
         if(s=="FPR")
        {
            
             l1.fancy();
        }
        if(s=="DNA")
        {
            int after;
            cin>>after;
            l1.delafter(after);
        }
        if(s=="DNB")
        {
            int af;
            cin>>af;
            l1.delbefore(af);
        }
        
        
    }
    return 0;
}