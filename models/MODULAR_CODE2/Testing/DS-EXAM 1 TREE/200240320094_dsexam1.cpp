#include<iostream>
using namespace std;
  class queue
 {
  private:
      int count;
      int front;
      int size;
      int rare;
      int *store;
  public:
      queue(int size)
      {
          count=0;
          this->size=size;
          front=rare=-1;
          store=new int[size];
      }
      ~queue()
      {
          delete []store;
      }
      int getNoe()
      {
          return count;
      }
      void clearfn()
      {
           count=0,rare=front=-1;
      }
      int isEmpty()
      {
          if(front==rare)
              return 1;
          else          
             return 0;
      }
      int isFull()
      {
          if(rare==(size-1))
             return 1;
          else
            return 0; 
      }
      void enqueue(int data)
      {
          rare++;
          count++;
          store[rare]=data;
        
      }
      int dequeue()
      {
          front++;
          int data=store[front];
          if(front==rare)
          {
              front=rare=-1;
          }
          return data;
      }
      int display(int c)
      {
          return store[c];
      }
 };
  queue q1(10000);
 class Node
 {
    private:
       int data;
       Node* right;
       Node* left;
    public:
       Node()
       {
           left=right=NULL;
       }
       Node(int data)
       {
           this->data=data;
           left=right=NULL;
       }
       void setleft(Node* left)
       {
           this->left=left;
       }
       void display()
       {
           cout<<data<<" ";
       }
       void setData(int data)
       {
           this->data=data;
           left=right=NULL;
       }
       void setright(Node* right)
       {
           this->right=right;
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
 };
 
  class Tree
  {
      private:
          Node* root;
      public:
          Tree()
          {
              root=NULL;
          }
          Node* getroot()
          {
              return root;
          }
           
          void insertdata(int data)
          {
              Node* newnode=new Node(data);
              if(root==NULL)
              {
                  root=newnode;
              }
              else
              {
                  Node* temp1;
                  Node*pre;
                  temp1=root;
                  pre=root;
                  while(temp1!=NULL)
                  {
                      pre=temp1;
                      if(data<=temp1->getdata())
                      {
                          temp1=temp1->getleft();
                      }
                      else if(data>temp1->getdata())
                      {
                          temp1=temp1->getright();
                      }
                
                  }
                  if(data<=pre->getdata())
                      pre->setleft(newnode);
                  else if(data>pre->getdata())
                      pre->setright(newnode);
              }
          }
          
          int height(Node* node)
          {
              if(node==NULL)
                  return 0;
              else
              {
                 int lheight=height(node->getleft());
                 int rheight=height(node->getright());
                 
                 if(lheight >rheight)
                    return(lheight+1);
                  else 
                    return(rheight+1);
              }
          }
        void Level(Node* root, int level)
          {
              if(root==NULL)
               return;
              if(level==1)
              {
                 q1.enqueue(root->getdata());
                 return;
              }
              else if(level>1)
              {
               Level(root->getleft(),level-1);
               Level(root->getright(),level-1);
              }
          }
  };
 
  
  int main()
  {
      Tree t1;
      int num=-5;
          while(num!=-1)
          {
              cin>>num;
              if(num!=-1)
                  t1.insertdata(num);
          }
     
      int h=t1.height(t1.getroot());
     // int flag=1;
      for(int i=0;i<h;i++)
      {
          
          t1.Level(t1.getroot(),i+1);
         // cout<<q1.getNoe()<<endl;
          for(int j=0;j<q1.getNoe();j++)
          {
              if(j==(q1.getNoe()-1))
              {
                  cout<<q1.display(j)<<endl;
              }
              else 
              {    
                  
                  cout<<q1.display(j)<<" ";
              }
          }
          q1.clearfn();
      }
     return 0;
  }