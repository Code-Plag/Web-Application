#include<iostream>

using namespace std;

class Node
{
    private:
            int data;
            Node* next;
    public:
            Node()
            {
                next = NULL;
                //data = 0;
            }
        
            Node(int data)
            {
                this->data=data;
                this->next=NULL;
            }
    
            int getData()
            {
                return data;
            }

            Node* getNext()
            {
                return next;
            }
            void setNext(Node* next)
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
            head = NULL;
        }
      
                void AE(int data)
                {   
                    Node *node = new Node(data);
                    if(head == NULL)
                    {
                        head = node;
                    }

                    else
                    {
                        Node *temp = head;
                        while(temp->getNext() != NULL)
                        {
                            temp = temp->getNext();
                        }
                             temp->setNext(node);    
                    }    
                }


                void AB(int data)
                {
                    Node *node = new Node(data);
                    if(head == NULL)
                    {
                        head = node;
                    }
                    else
                    {
                        node->setNext(head);
                        head = node;
                    }
                }
            
               
                int AMA(int after , int d)
                {
                    Node *node = new Node(d);
                    Node *temp = head;
        
                    while(temp != NULL && temp->getData() != after)
                    {
                        temp = temp->getNext();
                    
                     if(temp == NULL)
                    {
                        return 0;
                    }
                    }
                    if(head->getData()==after)
                    {
                        node->setNext(head->getNext());
                        head->setNext(node);
                    }
                    else
                    {
                        node->setNext(temp->getNext());
                        temp->setNext(node);
        
                    }
            }
                
                
                 int AMB(int before , int d)
                {
                    Node *node = new Node(d);
                    Node *temp = head;
                    Node *prev = head;
                    while(temp->getData() != before)
                    {
                        prev=temp;
                        temp = temp->getNext();
                    }
                    if(temp == NULL)
                    {
                        return 0;
                    }
                     if(head->getData()==before)
                     {
                           node->setNext(head);
                           head=node;
                     }
                     else
                     {
                         node->setNext(prev->getNext());
                         prev->setNext(node);
                     }   
        
                }
                
                
                
                
                
                void DN(int data)
                {
                    Node *temp = head;
                    Node *prev = head;
                   // temp = head;
                    while(temp != NULL && temp->getData() != data)
                    {
                       // prev = temp;
                        temp = temp->getNext();
                    }
                    //temp = prev->getNext();
                    while(prev->getNext() != temp)
                    {
                        prev=prev->getNext();
                    }
                    prev->setNext(temp->getNext());
                }
                   
                
                 void *DNA( int after)
                {
                    Node *temp = head;
                    Node *prev = head;
                        
                    while(temp->getNext() != NULL)
                    {
                        if(temp->getData()==after)
                    {
                        temp->setNext(temp->getNext()->getNext());
                        break;
                    }
                    else
                    {
                        temp = temp->getNext();
                    }
                    }
                }
                  
                
                    int *DNB(int before)
                    {
                        Node *temp = head;
                        Node *prev=NULL;
                        if(head->getData() == before)
                        {
                            return 0;
                        }
                        
                         
                       while(temp->getNext()->getData() != before)  
                         {
                            prev = temp;
                            temp = temp->getNext();
                                                            
                         }
                         if(temp == head)
                         {
                             head= temp->getNext();
                             delete temp;
                         }
                        else
                        {
                            prev->setNext(temp->getNext());
                            delete temp;
                        }
                        
                    }
                    
                    
                    void FPR()
                     {
                         Node *temp = head;
                         while(temp->getNext() != NULL)
                     {
                        cout<<temp->getData()<<"->";
                        temp=temp->getNext();
                     }
                        cout<<temp->getData();
                        cout<<endl;
                     }
                
                
               
                void PR()
                {
                    Node *temp = head;
                    while(temp != NULL)
                {
                        cout<<temp->getData()<<" ";
                        temp=temp->getNext();
                }
                    cout<<endl;

                }
                
                void RPR(LinkList m)
                {
                
                    Node *temp;
                    temp = head;
                    int top = 0;
                    int *store;
                    int count=0;
                
                while(temp!=NULL)
                {
                    count++;
                    temp=temp->getNext();
                }
                     temp=head;
                     store=new int[count];
                     for(int i=0;i<count;i++)
                    {
                        store[i]=temp->getData();
                        temp=temp->getNext();
                    }
                
                        for(int i=count-1;i>=0;i--)
                        {
                            cout<<store[i];
                            if(i>0)
                            cout<<" ";
                        }
                        cout<<endl;
                 }
};
                             int main()
                            {
                            string cmd;
                            LinkList l,m;
                            while(1)
                            {
                                cin>>cmd;
                            if(cmd == "EXIT")
                            {
                                break;
                            }
                            if(cmd == "AB")
                            {
                                int data;
                                cin>>data;
                                l.AB(data);
                                
                            }
                                                
                            if(cmd == "AE")
                            {
                                int data;
                                cin>>data;
                                 l.AE(data);
                        
                            }   
                            if(cmd=="AMA")
                            {
                                int data,x;
                                cin>>data;
                                cin>>x;
                                 l.AMA(data,x);
                            }
                            
                             if(cmd=="AMB")
                            {
                                int data,x;
                                cin>>data;
                                cin>>x;
                                 l.AMB(data,x);
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
                            
                            if(cmd == "FPR")
                            {
                                int data;
                                
                                l.FPR();
                             
                            }
                        
                             if(cmd == "PR")
                            {
                                l.PR();
                        
                            }  
                            
                            if(cmd == "RPR")
                            {
                                
                                l.RPR(m);
                        
                            }
                            
            
 
                       } 
                        
                       
 return 0;
                        
                


}