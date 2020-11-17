#include<iostream>
#include<queue>
using namespace std;
int arr[20];
int i =0;
class node
{
    private:
        int data;
        node *left;
        node *right;
    public:
       
       friend class BST;
};

class BST
{
    private:
        node *root;
         int level;
    public:
        BST()
          {
              level = 0;
              root = NULL;
          }
          node *getroot()
          {
              return root;
          }
         void InsertNode(int data)
           {
               node *newnode = new node;
               newnode->data = data;
               newnode->left = NULL;
               newnode->right = NULL;
               node *curr,*prev;
               curr  = prev = root;
               if(root == NULL)
                  root = newnode;
               else
                 {
                    while(curr != NULL) 
                      {
                          prev = curr;   
                           if (newnode->data > curr->data)
                              curr = curr->right;
                           else
                               curr = curr->left;
                      }
                          if (newnode->data > prev->data)
                              prev->right = newnode;
                          else
                                prev->left = newnode;
                 }      
           }
           void levelorder(node *temp)
            {
                if(temp == NULL)
                  return;
                queue<node *> q;
              // queue q;
               
                q.push(temp);
                while(!q.empty())
                 {
                     level = q.size();
                     while(level > 0)
                      {
                          node*temp1 = q.front();
                          cout<<temp1->data;
                           if(level > 1)
                           {
                              cout<<" ";
                           }
                           q.pop();
                           if(temp1->left != NULL)
                            {
                                q.push(temp1->left );
                            }
                           if(temp1->right != NULL)
                            {
                                q.push(temp1->right );
                            }
                            level--;
                            }
                            cout<<endl;
                      }
                 }
            
           
};
int main()
{
    BST b1;
    int value;
    while(1)
     {
         cin>>value;
            if(value == -1)
              break;
             else
           b1.InsertNode(value);
     }
     b1.levelorder(b1.getroot());
    
    return 0;
}