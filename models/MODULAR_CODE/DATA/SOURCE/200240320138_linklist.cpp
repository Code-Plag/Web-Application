# include <iostream>

using namespace std;

class Node
    {
            private:
                    int data;
                    Node *next;
            public:
                    Node()
                        {
                            next = NULL;
                        }
                    Node( int data)
                        {
                            this->data = data;
                            this-> next = NULL;
                        }
                    ~Node()
                        {
                            next = NULL;
                        }
                    Node* getNext()
                    {
                        return next;
                    }
                    int getData()
                    {
                        return data;
                    }
                    void setNext(Node *next)
                    {
                        this->next = next;
                    }
    };
    
class Linklist
    {
            private:
                    Node *head;
            public:
                    Node* getHead()
                        {
                            return head;
                        }
                    Linklist()
                        {
                            head = NULL;         
                        }
                    ~Linklist()
                        {
                           while( head != NULL)
                                {
                                    Node *temp = head;
                                    head = head->getNext();
                                    delete temp;
                                }
                        }
                    
                    void RevPrint( Node* head)
                        {
                             Node *temp;
                            temp = head;
                            
                            if(temp== NULL)
                            {
                                //cout<<endl;
                                return;
                            }
                            RevPrint(temp->getNext());
                                cout<<temp->getData()<<" ";
                                
                        }
                    void print()
                        {
                            Node *temp = head;
                            while( temp!=NULL)
                                {
                                    cout<<temp->getData()<<" ";
                                    temp = temp->getNext();
                                }
                            cout<<endl;
                        }
                    void fancyPrint()
                        {
                            Node *temp = head;
                            while( temp!=NULL)
                                {
                                    if(temp->getNext() != NULL)
                                    {
                                        cout<<temp->getData()<<"->";
                                        temp = temp->getNext();
                                    }
                                    else if(temp->getNext() == NULL)
                                    {
                                        cout<<temp->getData()<<endl;
                                        temp = temp->getNext();
                                    }
                                }
                            
                        }
                    void addatB( int data)
                        {
                            Node* newnode;
                            newnode = new Node(data);
                            newnode->setNext(head);
                            head = newnode;
                        }
                    
                      void addatE( int data)
                        {
                            Node* newnode;
                            newnode = new Node(data);
                            if(head ==NULL)
                                {
                                    head = newnode; 
                                }
                            else
                                {
                                    Node* temp;
                                    temp = head;
                                    while(temp->getNext() !=NULL)
                                        {
                                            temp = temp->getNext();
                                        }
                                    temp->setNext(newnode);
                                }
                        }
                    
                    void addatMA(int after, int data)
                        {
                            Node* newnode;
                            newnode = new Node(data);
                            if(head ==NULL)
                                {
                                  //  head = newnode; 
                                }
                            else
                                {
                                    Node* temp;
                                    temp = head;
                                    while((temp != NULL) && (temp->getData() != after))
                                        {
                                            temp = temp->getNext();
                                        }
                                    if(temp == NULL)
                                        {
                                            //cout<<"Data NOT FOUND"<<endl;
                                        }
                                    else
                                        {
                                            newnode->setNext(temp->getNext());
                                            temp->setNext(newnode);
                                        }
                                } 
                        }
                        
                    void addatMB( int before, int data)
                        {
                            Node* newnode;
                            newnode = new Node(data);
                            if(head ==NULL)
                                {
                                   // head = newnode; 
                                }
                            else
                                {
                                    Node* temp1;
                                    Node* temp2;
                                    temp1 = head;
                                    temp2 = head;
                                    while((temp1 != NULL) && (temp1->getData() != before))
                                        {
                                            temp2 = temp1;
                                            temp1 = temp1->getNext();
                                        }
                                  if(temp1 == head)
                                  {
                                       newnode->setNext(temp1);
                                       this->head = newnode;
                                  }
                                   else if(temp1 != NULL)
                                        {
                                            newnode->setNext(temp1);
                                            temp2->setNext(newnode);
                                        }
                                    else if (temp1 == NULL)
                                        {
                                            //Data Not Found
                                        }
                                } 
                        }
                        
                        void delN( int data)
                            {
                                    Node* temp1;
                                    Node* temp2;
                                    temp1 = head;
                                    temp2 = head;
                                    while((temp1 != NULL) && (temp1->getData() != data))
                                        {
                                            temp2 = temp1;
                                            temp1 = temp1->getNext();
                                        }
                                    if(temp1 == this->head)
                                        {
                                           this->head = temp1->getNext();
                                            temp1 = NULL;
                                            temp2 = NULL;
                                        }
                                    else if(temp1 == NULL)
                                        {
                                      //  cout<<"Data NOT FOUND"<<endl;
                                        temp2 = NULL;
                                        }
                                    else if(temp1 != NULL)
                                        {
                                            temp2->setNext(temp1->getNext());
                                            temp1->setNext(NULL);
                                        }
                            }
                        
                        void delAN( int data)
                            {
                                Node* temp1;
                                Node* temp3;
                                    temp1 = head;
                                    temp3 = NULL;
                                
                                    while((temp1 != NULL) && (temp1->getData() != data))
                                        {
                                            temp1 = temp1->getNext();
                                        }
                                    
                                     if(temp1 == NULL)
                                        {
                                    //    cout<<"Data NOT FOUND"<<endl;
                                        temp3 = NULL;
                                        } 
                                    else if(temp1->getNext() ==NULL)
                                        {
                                            //cout<<"No data present after tail"<<endl;
                                           // temp3 = NULL;
                                        }
                                    else
                                        {
                                            
                                           temp3 = temp1->getNext();
                                           temp1->setNext(temp3->getNext());
                                           temp3->setNext(NULL);
                                           temp3 = NULL;
                                        }
                            } 
                            
                        void delBN( int data)
                            {
                                Node* temp1;
                                Node* temp2;
                                Node* temp3;
                                temp1 = head;
                                temp2 = head;
                                temp3 = head;
                                
                                
                                    while((temp1 != NULL) && (temp1->getData() != data))
                                        {
                                            temp3 = temp2;
                                            temp2 = temp1;
                                            temp1 = temp1->getNext();
                                        }
                                    
                                     if(temp1 == NULL)
                                        {
                                       // cout<<"Data NOT FOUND"<<endl;
                                        temp3 = NULL;
                                        temp2 = NULL;
                                        }
                                    else if(temp1 == head)
                                        {
                                           // cout<<"No data present before head"<<endl;
                                            temp3 = NULL;
                                            temp2 = NULL;
                                        }
                                    else if(temp2 == head && temp3 == head)
                                        {
                                            this->head = temp1;
                                            temp2->setNext(NULL);
                                            temp3 = NULL;
                                            temp2 = NULL;
                                        }
                                    else if(temp1 != NULL)
                                        {
                                            
                                           temp3->setNext(temp1);
                                           temp2->setNext(NULL);
                                           temp3 = NULL;
                                           temp2 = NULL;
                                        }
                            } 
                            
    };

int main()
    {
        Linklist p;
           while(1)
            {
                string cmd;
                cin>>cmd;                
             //  p.addatB(30);
             //    p.print();
                
                if(cmd == "EXIT")
                    {
                        //cout<<"e"<<endl;
                        break;
                     }
               else if(cmd == "AB")
                    {
                        int val;
                        cin>>val;
                        p.addatB(val);
                        //continue;
                    }
                 else if(cmd == "PR")
                    {
                        p.print();
                        //continue;
                    }
                else if(cmd == "FPR")
                    {
                        p.fancyPrint();
                        //continue;
                    }
                else if(cmd == "AE")
                    {
                        int val;
                        cin>>val;
                        p.addatE(val);
                    }
                else if(cmd == "AMA")
                    {
                        int data, after;
                        cin>>after>>data;
                        p.addatMA(after, data);
                    }
                else if(cmd == "AMB")
                    {
                        int data, before;
                        cin>>before>>data;
                        p.addatMB(before, data);
                    }
                else if(cmd == "DN")
                    {
                        int data;
                        cin>>data;
                        p.delN(data);
                    }
                else if(cmd == "DNA")
                    {
                        int data;
                        cin>>data;
                        p.delAN(data);
                    }
                else if(cmd == "DNB")
                    {
                        int data;
                        cin>>data;
                        p.delBN(data);
                    }
                else if(cmd == "RPR")
                    {
                        
                        p.RevPrint(p.getHead());
                        cout<<endl;
                    }
            }   
                
            
        return 0;
    }