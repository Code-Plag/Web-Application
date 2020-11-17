#include<iostream>
using namespace std;
class Node
{
    private: 
            int data;
            Node* next;
    public: 
            Node(int data)
            {
                this->data = data;
                next = NULL;                
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
                this->next = next;
            }
};

class list
{
    private: Node* head;
    
    public :
            list()
            {
                head = NULL;
            }
            void AB(int data)
            {
                Node* node = new Node(data);
               
                if(head == NULL)
                {
                    head = node;
                }
                else
                {   
                        node->setnext(head);
                        head = node;
                 }
                    
            }
            
            void AE(int data)
            {
                Node* node = new Node(data);
                Node* temp = head;
                if(head == NULL)
                {
                    head = node;
                }
                else
                {   
                    while(temp->getnext()!=NULL)
                    {
                        temp = temp->getnext();
                    }
                    temp->setnext(node);
                    
                }
            }
            
            void AMA(int AFTER,int A)
            {
                Node* node = new Node(A);
                Node* temp = head;
                if(head == NULL)
                {
                    head = node;
                }
                /*else if(head->getdata() == A) 
                {
                    A->setnext(head);
                     head = A;
                    
                }else{*/
                    while(temp->getdata()!=AFTER && temp!=NULL)
                    {
                        temp = temp->getnext();
                    }
                    node->setnext(temp->getnext());
                    temp->setnext(node);
                
                
            }
            
            void AMB(int BEFORE,int B)
            {
                Node* node=new Node(B);
                Node* temp=head;
                Node* prev=head;
                if(head->getdata() == BEFORE)
                {
                    node->setnext(head);
                    head = node;
                }
                else if(head!=NULL)
                {
                    while(temp!=NULL && temp->getdata()!=BEFORE)
                    {       
                        prev = temp;
                        temp = temp->getnext();
                    }
                    node->setnext(prev->getnext());
                    prev->setnext(node);
                }
                
            }
               
               void DN(int data)
            {
                Node* temp = head;
                Node* prev = head;
               if(head == NULL)
               {
                  
               } if(head->getdata()!=data)
                        {
                            while(temp!=NULL && temp->getdata()!=data)
                            {   
                                prev = temp;
                                temp=temp->getnext();
                            }    
                            prev->setnext(temp->getnext());
                            delete temp;
                        }
                    else if(head->getdata() == data)
                    {
                         prev = head;    
                         head = head->getnext();
                         delete prev;
                         
                    }
            }   
            
                int DNA(int data)
             {
                Node* temp = head;
                Node* after = head;
                Node* temp2=head; 
                while(temp2->getnext()!=NULL)
                {
                        temp2=temp2->getnext();
                }
                if(temp2->getdata()==data)
                {
                    return 0;
                }
                
                    while(temp->getdata()!=data)
                        {
                            temp = temp->getnext();
                            if(temp==NULL)
                            {
                                return  0;
                            }
                        }
                    after = temp->getnext();
                    temp->setnext(after->getnext());    
                    delete after;                                           
                
            }
            
            int DNB(int data)
            {
               
                Node* prev = head;
                Node* temp = head;
                if(head->getdata() == data)
                {
                    return 0;
                }
                else if(head->getnext()->getdata() == data)
                    {
                        head = head->getnext();   
                    }
                    else
                    {    
                    while(temp!=NULL && temp->getnext()->getdata()!=data)
                    {
                        prev = temp;
                        temp = temp->getnext();
                    
                    }
                prev->setnext(temp->getnext());
                delete temp;
                }
            }
            
             int REVERSE(Node* temp)
            {
                
                if(temp->getnext()!=NULL)
                    {
                        REVERSE(temp->getnext());
                    }                    
                        cout<<temp->getdata()<<" ";
            }
            
            void RPR()
            {
                Node* temp = head;
                REVERSE(temp);
                cout<<endl;
            }
            
             void FPR()
            {
                Node* temp = head;
                while(temp->getnext()!=NULL)
                { 
                    cout<<temp->getdata()<<"->";
                    temp = temp->getnext();
                }
                    cout<<temp->getdata()<<endl;
            }
              
            void PR()
            {
                Node* temp = head;
                while(temp!=NULL)
                { 
                    cout<<temp->getdata()<<" ";
                    temp = temp->getnext();
                }
                cout<<endl;
            }
                
};

int main()
{
    list L;
    
    int data;
    string s;
   
     while(1)
{
     cin>>s;
    if(s == "AB")
    {
        cin>>data;
        L.AB(data);
    }
    if(s == "AE")
    {
        cin>>data;
        L.AE(data);
    }
     if(s == "AMA")
    {
        int after;
        cin>>after;
        cin>>data;
        L.AMA(after,data);
    }
     if(s == "AMB")
    {
        int before;
        cin>>before;
        cin>>data;
        L.AMB(before,data);
    }
     if(s == "DN")
    {
        cin>>data;
        L.DN(data);
    }
    if(s == "DNA")
    {
        int d;
        cin>>d;
        L.DNA(d);
    }
    
     if(s == "DNB")
    {
        int d;
        cin>>d;
        L.DNB(d);
    }
    
     if(s == "FPR")
    {
        L.FPR();
    }
    
     if(s == "RPR")
    {
       L.RPR();
    }
    
     if(s == "PR")
    {
        L.PR();
    }
    if(s == "EXIT")
    {
        break;
    }
}
    
    return 0;
}