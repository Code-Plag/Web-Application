#include<iostream>
#include<cstring>

using namespace std;

class Node
{
    private:
      int data;
      Node* left;
      Node* right;
      public:
      Node(int data)
      {
          this->data = data;
          left=NULL;
          right=NULL;
      }
      int getdata()
      {
          return data;
      }
        Node* getleft()
      {
          return left;
      }
      Node* getright()
      {
          return right;
      }
      void setright(Node* right)
      {
      this->right=right;
      }
      void setleft(Node* left)
      {
          this->left=left;
      }
};
template<class T>
class queue
{
    private:
    T * store;
    T data;
    int front;
    int rear;
    int size;
    int count;
    public:
    queue(int size)
    {
        this->size=size;
        count = 0;
        front=-1;
        rear=-1;
        store=new T[size];
    }
    ~queue()
    {
        delete[] store;
    }
    int isEmpty()
    {
        if(rear==front)
        {
            
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if(rear==size-1)
        {
            
            return 1;
        }
        return 0;
    }
    
    int getSize(){
        return count;
    }
    
        void enqueue(T data)
        {
            if(!isFull())
            {
                rear++;
                store[rear]=data;
                count++;
            }
        }
        T dequeue()
        {
            if(!isEmpty())
            {
                T data;
                front++;
                data=store[front];
                count--;
                return data;
            }
        }
    };
class Tree
{
    private:
    Node *root;
    public:
    Tree()
    {
        root=NULL;
    }
    Node *getroot()
    {
        return this->root;
    }
    void insert(int data)
    {
        Node *node=new Node(data);
        Node *temp=root;
        Node *prev=root;
        if(root==NULL)
        {
            root=node;
        }
        else
        {
           while(temp!=NULL)
           {
               prev=temp;
               if(data<=temp->getdata())
               {
                   temp=temp->getleft();
               }
               else
                    temp=temp->getright();
           }
           if(data<=prev->getdata())
                prev->setleft(node);
            else
                prev->setright(node);
        }
        
    }

    void inorder(Node *temp)
    {
        if(temp==NULL)
            return;
        inorder(temp->getleft());
        cout<<temp->getdata()<<" ";
        inorder(temp->getright());
    }
    
    void BFT(Node* root){
        queue<Node*> q(30);
        if(root == NULL)
            return;
     q.enqueue(root);
     while(!q.isEmpty())
     {
       int a = 0;
         a = q.getSize();
         while(a>0)
         {
              Node * node=q.dequeue();
              cout<<node->getdata();
              if(a>1){
                  cout<<" ";
              }
              if(node->getleft()!=NULL)
                q.enqueue(node->getleft());
             if(node->getright()!=NULL)
                q.enqueue(node->getright());
          a--;
       }
        cout<<endl;
    }
    }
  
};


int main(){
    Tree t1;
    int a;
    while(a != -1){
        cin>>a;
        if(a != -1)
            t1.insert(a);
    }
    
    
    t1.BFT(t1.getroot());
    
}
