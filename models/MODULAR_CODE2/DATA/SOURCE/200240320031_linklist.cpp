#include<iostream>
#include<cstring>

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
          
        Node(int data)
          {
              this->data = data;
              this->next = NULL;
          }
          
        ~Node()
          {
              next = NULL;
          }
          
         Node* getNext()
          {
              return next;
          }
          
         void setNext( Node *next)
          {
              this->next = next;   
          }
          
         int getData()
          {
              return data;
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
    
    
        ~LinkList()
           {
              while(head != NULL)
                  {
                      Node *temp = head;
                      head = head->getNext();
                      delete temp;
                  }
           }
           
        Node* getHead()
          {
              return head;
          }
         
         
        void insertBegin(int data)
        
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
          
          
       void insertEnd(int data)
        
           {
                  Node *node = new Node(data);
                  if(head == NULL)
                       {
                           head = node;
                       }
                  else
                       {
                           Node *temp=head;
                           while( temp->getNext() != NULL)
                                {
                                    temp = temp->getNext();
                                }
                           temp->setNext(node);
                       }
           }
           
         
        void insertAfter(int after, int data)
           { 
                 Node *node = new Node(data);
                 Node *temp = head;
                 while( temp !=NULL && temp->getData()!= after)
                       {
                           temp = temp->getNext();
                       }
                 if(head == NULL)
                       {
                           return;
                       }
                 else if(temp == NULL)
                       {
                           //cout<<"Data not found";
                       }
                 else
                       {
                           node->setNext(temp->getNext());
                           temp->setNext(node);
                       }
           }
        
           
        void insertBefore(int before, int data)
           {
                /* Node *node = new Node(data);
                 Node *temp = head;
                 Node *pretemp = head;
                 while( temp !=NULL && temp->getData()!= before)
                       {
                           pretemp = temp;
                           temp= temp->getNext();
                       }
                 if(head==NULL)
                       {
                         return;
                       }
                       else if(temp == NULL)
                       {
                           //cout<<"Data not found";
                       }
                 else
                       {
                           node->setNext(temp);
                           pretemp->setNext(node);
                       } */
                       
                       
                Node* node= new Node(data);
                if(head == NULL)
                  {
                      
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
                         node->setNext(temp1);
                         this->head = node;
                     }
                     else if(temp1 != NULL)
                     {
                         node->setNext(temp1);
                         temp2->setNext(node);
                     }
                     else if(temp1 ==NULL)
                     {
                         
                     }
                      
                  }
           } 
         
         
        void deleteNode( int data)
           {
            /*   Node *temp, *pretemp, *postemp;
                 temp = head;
                 postemp = head;
                 pretemp = head;
                 if(head == NULL)
                 {
                     return;
                 }
                 
                 else
                   {
                 while((temp != NULL) && (temp->getData()!=data))
                    {
                           postemp = temp;
                           temp = pretemp;
                           pretemp =  pretemp->getNext();
                          
                    }
                
                if( temp == NULL)
                    {
                        temp->setNext(NULL);
                        postemp = NULL;
                        temp = NULL;
                    }
                else if( temp != NULL)
                    {
                        postemp->setNext(pretemp);
                        temp->setNext(NULL);
                 }   }    */
                 
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
                        temp2 = NULL;
                    }
          else if(temp1 != NULL)
                   {
                       temp2->setNext(temp1->getNext());
                       temp1->setNext(NULL);
                   }
           }
          
        void deleteBefore( int dBefore)
           {
               /*  Node *temp, *pretemp;
                 temp = head;
                 pretemp = head;
                 if(head==NULL)
                 {
                     return;
                 }
                 else
                 {
                 if(head->getData()==dBefore)
                 {
                     return;
                 }
                 
                  if(head->getNext()->getData()== dBefore)
                 {
                     head = head->getNext();
                     
                 }
                 
                 while(temp->getNext()->getData() !=dBefore)
                    {   
                       pretemp = temp;
                        temp = temp->getNext();
                    }
                    if(head->getNext()->getData()==dBefore)
                    {
                        head=head->getNext();
                    }
              
                 else   {  
                      pretemp->setNext(temp->getNext());
                 }
                                         
           }   */
           
           Node* temp1;
           Node* temp2;
           Node* temp3;
           temp1 = head;
           temp2 = head;
           temp3 = head;
         while((temp1 != NULL) && (temp1->getData() !=dBefore))
         {
               temp3 = temp2;
               temp2 = temp1;
               temp1 = temp1->getNext();
         }
         if(temp1 ==NULL)
                 {
                     temp3 = NULL;
                     temp2 =NULL;
                 }
        else if(temp1 == head)
                {
                   temp3 = NULL;
                     temp2 =NULL; 
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

       void deleteAfter(int aDelete)
           {
               
               Node* temp1;
               Node* temp3;
               temp1 = head;
               temp3 = NULL;
              while((temp1 != NULL) && (temp1->getData()!= aDelete))
              {
                  temp1 = temp1->getNext();
              }

               if(temp1== NULL)
               {
                   temp3 = NULL;
               }
               else if(temp1->getNext() == NULL)
               {
                   
               }
               else
               {
                   temp3 = temp1->getNext();
                   temp1->setNext(temp3->getNext());
                   temp3->setNext(NULL);
                   temp3 = NULL;
               }
               
             /*  Node* temp=head;
               if(head == NULL)
               {
                   return;
               }
               else{
               while(temp->getNext()!=NULL && temp->getData()!=aDelete)
               {
                   temp = temp->getNext();
               }
               if(temp == NULL)
               {
                   temp->setNext(NULL);
               }
               if(temp->getData()!= aDelete)
                {
                    return;
                }
                else
                {
                    temp->setNext(temp->getNext()->getNext());
                }
                */
                
                 /*Node *temp, *pretemp, *postemp;
                 temp = head->getNext();
                 postemp = temp->getNext();
                 pretemp = head;
                 
                 if( pretemp->getData() != aDelete )
                    {
                        
                       // cout<<"direct return"<<endl;
                        return;
                       
                    }
                 
                 while((pretemp->getNext() != NULL) && (pretemp->getData()!=aDelete))
                    {
                         pretemp = temp;
                         temp = temp->getNext();
                       postemp =  temp->getNext();
                    }
                     if(pretemp == NULL)
                     {
                     return;
                     }
                else if( temp != NULL)
                    {
                        pretemp->setNext(postemp->getNext());
                       
                    }*/  
         //  } 
           }
           
         void print()
           {    
               Node *temp;
               temp=head;
                while(temp!=NULL)
                    {
                        cout<<temp->getData()<<" ";
                        temp = temp->getNext();
                        
                    }
                    
                    cout<<endl;
           }
           
         void fancyPrint()
           {
               Node *temp;
               temp=head;
               //cout<<"hello";
                while(temp!=NULL)
                    {   
                        if(temp->getNext()!=NULL)
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
                    
                  //  cout<<endl;
           }
          
          void reverse()
          {
              Node* temp = head;
              if(head == NULL)
              {
                  
              }
              else
              {
              rev(temp);
              cout<<endl;
              }
          }
         void rev( Node* temp)
           {     
               if(head == NULL)
               {
                   
               }
               else if(temp->getNext()!= NULL)
                 {
                     rev(temp->getNext());
                 }
                 cout<<temp->getData()<<" ";
                  
           }
};

int main()
{
    LinkList l;
    while(1)
        {
            string exp;
            cin>>exp;
            if(exp == "EXIT")
                 {
                     break;
                 }
            else if(exp == "AB")
                 {      
                     int data;
                     cin>>data;
                     l.insertBegin(data);
                 }
            else if(exp =="PR")
                {
                    l.print();
                }
            else if(exp == "AE")
                {
                    int data;
                    cin>>data;
                    l.insertEnd(data);
                }
            else if(exp == "AMA")
               {
                   int data;
                   int after;
                   cin>>after>>data;
                   l.insertAfter(after , data);
               }
            else if(exp == "AMB")
              {
                  int data;
                  int before;
                  cin>>before>>data;
                  l.insertBefore(before, data);
              }
            else if(exp == "DN")
              {
                  int data;
                  cin>>data;
                  l.deleteNode(data);
              }
            else if(exp == "DNA")
              {
                  int data;
                  cin>>data;
                  l.deleteAfter(data);
              }
            else if(exp == "DNB")
              {
                  int data;
                  cin>>data;
                  l.deleteBefore(data);
              }
            else if(exp == "FPR")
              {
                  l.fancyPrint();
              }
            else if(exp == "RPR")
              {
                  l.reverse();
              }
            
        }
    
    
return 0;
}