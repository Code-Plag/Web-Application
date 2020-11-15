#include<iostream>
using namespace std;
class Node
{
    private:
        int data;
        Node *next;
    public:
        Node(int a)
        {
            data=a;
            next=NULL;
            
        }
    
        int getData()
        {
            return data;
        }
        Node* getNext()
        {
            return next; 
        }
        void setNext(Node* n)
        {
            next=n;
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
            
        void insertB(int d)
        {  
            Node* nd=new Node(d);

            if(head==NULL)
                {
                    head=nd;
                }
            else{
                    nd->setNext(head);
                    head=nd;
                }
        }
        
        void insertE(int d)
        {
            Node* nd=new Node(d);
            Node* temp=head;
            
            if(head==NULL)
            {
                head=nd;
            }
            else{
                    while(temp->getNext()!=NULL)
                    {
                        temp=temp->getNext();
                    }
                        temp->setNext(nd);
            }
        }
        
        int insertMA(int d, int a)
        {
            Node* nd=new Node(a);
            
            if(nd==NULL)
            {
                return 0;
            }
            
            if(head==NULL)
            {
                head=nd;
            }
            else{    
                    if(head->getData()==d)
                    {
                        if(head->getNext()==NULL)
                        {
                            head->setNext(nd);
                        }
                        else{
                                nd->setNext(head->getNext());
                                head->setNext(nd);
                            }
                    }  
                 else{
                            Node* temp=head;
                            temp=temp->getNext();                    
                            
                            while(temp->getData()!=d)
                            {
                                if(temp->getNext()==NULL)
                                {
                                    return 0;
                                }
                                temp=temp->getNext();
                            }
                                nd->setNext(temp->getNext());
                                temp->setNext(nd);
                           
                        }  
            }  
            
        }
        
    int insertMB(int d,int b)
    {
        Node* nd=new Node(b);
        if(nd==NULL)
        {
            return 0;
        }
        
        if(head==NULL)
        {
            head=nd;
        }
        else{
                if(head->getData()==d)
                {
                    nd->setNext(head);
                    head=nd;
                }
                else{
                    
                        Node* temp=head;
                        Node* prev;
                        while(temp->getData()!=d)
                        {
                            if(temp->getNext()==NULL)
                            {
                                return 0;
                            }
                                prev=temp;
                                temp=temp->getNext();
                        }
                        nd->setNext(temp);
                        prev->setNext(nd);
                }                
        }
        
    }
    
    int Delete(int d)
    {
        Node* temp=head;
        Node* prev=temp;
        if(head==NULL)
        {
            return 0;
        }
        
        if(head->getData()==d)
        {  
            if(head->getNext()==NULL)
            {
                delete temp;
                head=NULL;
                return 0;
            }
            head=head->getNext();
            delete temp;
        }
        else{
                temp=temp->getNext();
                while(temp->getData()!=d)
                {
                    if(temp->getNext()==NULL)
                    {
                        return 0;
                    }
                        prev=temp;
                        temp=temp->getNext();                        
                }
                if(temp->getNext()==NULL)
                {
                    prev->setNext(NULL);
                    delete temp;
                    return 0;
                }
                    prev->setNext(temp->getNext());
                    delete temp;
            }
    }
    
    int deleteA(int d)
    {
        Node* temp=head;
        Node* prev=temp;
        if(head==NULL)
        {
            return 0;
        }
        
        if(head->getData()==d)
        {   
            if(head->getNext()==NULL)
            {   
                return 0;
            }
        else{
                temp=temp->getNext();
                prev->setNext(temp->getNext());
                delete temp;
            }
        }
        else{
                temp=temp->getNext();
                prev=temp;
                while(temp->getData()!=d)
                {
                    if(temp->getNext()==NULL)
                    {
                        return 0;
                    }
                
                prev=temp;
                temp=temp->getNext();
                }
                
                if(temp->getNext()==NULL)
                {
                    return 0;
                }
                else{
                        prev=temp;
                        temp=temp->getNext();
                        
                        if(temp->getNext()==NULL)
                        {
                            prev->setNext(NULL);
                            delete temp;
                        }
                        else{
                                prev->setNext(temp->getNext());
                                delete temp;
                            }
                }
        }
    
    }
    
    int deleteB(int d)
    {
        Node* temp=head;
        Node* prev=temp;
        
        if(head==NULL)
        {
            return 0;
        }
        
        if(head->getData()==d)
        {
            return 0;
        }
        else{
                temp=temp->getNext();
                
                if(temp->getData()==d)
                {
                    head=temp;
                    delete prev;
                    return 0;
                }
                
                while(temp->getNext()->getData()!=d)
                {
                    if(temp->getNext()->getNext()==NULL)
                    {
                        return 0;
                    }
                        prev=temp;
                        temp=temp->getNext();                        
                }
                
                prev->setNext(temp->getNext());
                delete temp;
        }
    }   
    
     void print()
     {
         Node *temp=head;
        if(head==NULL)
        {
            return;
        }
        else{    
                while(temp->getNext()!=NULL)
                {
                     cout<<temp->getData()<<" ";
                     temp=temp->getNext();
                    
                }   
                    cout<<temp->getData()<<endl;
             }
        }
            
     void Fprint()
     {
         Node *temp=head;
    
        if(head==NULL)
        {
            return;   
        }
        else{    
                while(temp->getNext()!=NULL)
                {   
        
                     cout<<temp->getData()<<"->";
                     temp=temp->getNext();
                }   
                    cout<<temp->getData()<<endl;
            }
     }
     
        
    void Rprint(Node* h)
    {
       if(h==NULL)
        return;
        
        Rprint(h->getNext());
        cout<<h->getData()<<" ";
        
    } 
    
    Node* gethead()
    {
        return head;
    }
            
};

int main()
{
    Linklist l;
    int c=0;
    
    while(1)
    {
        string cmd;
        char s[20];
        int d;
        cin>>cmd;
        
        if(cmd=="AB")
        {  
            c++;
            cin>>d;            
            l.insertB(d);
            continue;
        }
        
        if(cmd=="AE")
           {  
                c++;
                cin>>d;
                l.insertE(d);
                continue;
            }
        if(cmd=="AMA")
            {   int a;
                c++;
                cin>>d>>a;
                l.insertMA(d,a);
                continue;
            }
        if(cmd=="AMB")
            {   
                c++;
                int a;
                cin>>d>>a;
                l.insertMB(d,a);
                continue;
            }
        if(cmd=="DN")
            {
                cin>>d;
                l.Delete(d);
            }
        if(cmd=="DNA")
            {
                cin>>d;
                l.deleteA(d);
                continue;
            }
        if(cmd=="DNB")
            {
                cin>>d;
                l.deleteB(d);
                continue;
                
            }  
         if(cmd=="PR")
           {
                l.print();
                continue;
            }
        if(cmd=="FPR")
            {
                l.Fprint();
                continue;
            }
        if(cmd=="RPR")
            {
                l.Rprint(l.gethead());
                cout<<endl;
                continue;
            }  

        if(cmd=="EXIT")
            {
                break;
            }
    }   
        return 0;
}