#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;

class Node
{
  int data;
  Node* left;
  Node* right;
  friend class BSTree;
};

class BSTree
{
 private:
  
 Node* root;
    
    public:
        int getnodes(Node* temp)
        {
            if( temp != NULL)
            {
    n = 1 + getnodes(temp->left) + getnodes(temp->right);
             return n;
         }
         else
          return 0;
        }
    
        void inorder(Node* temp)
        {
            if( temp == NULL)
            return;
            inorder(temp->left);
            cout << temp->data << "" "";
            inorder(temp->right);
        }
        
        Node* getroot()
        {
            return root;
        }
        
        BSTree()
        {
            root = NULL;
        }
        
        void insert(int data)
        {
            Node* newnode;
            newnode = new Node;
            newnode->data = data;
            newnode->left = NULL;
            newnode->right = NULL;
            
            if(root == NULL)
                root = newnode;
            else
            {
                Node *temp1;
                Node *temp2;
                temp1 = root;
                while(temp1 != NULL)
                {
                    temp2 = temp1;
                    if(  data <= temp1->data )
                        temp1 = temp1->left;
                    else if(data > temp1->data )
                        temp1 = temp1->right;
                    
                }
                if(data <= temp2->data )
                {
                    temp2->left = newnode;
                }
                else if( data > temp2->data )
                {
                    temp2->right = newnode;
                }
                
            }    
        }      
};

int main()
{

    BSTree B;
    int input ;
  
    for(1;1;1)
    {
        cin >> input;
        if(input != -1)
         B.insert(input);
        else 
         break;
 } 
    
    cout << ""Total No. of Nodes in the BST = "" << B.getnodes(B.getroot());
    return 0;
}