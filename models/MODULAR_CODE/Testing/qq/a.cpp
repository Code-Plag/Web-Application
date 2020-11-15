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
    Node* root;
    
    public:
        BSTree()
        {
            root = NULL;
        }
        Node* getroot()
        {
            return root;
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
        int getnodes(Node* temp)
        {
            if( temp == NULL)
            return 0;
            n = 1 + getnodes(temp->left) + getnodes(temp->right);
            return n;
        }
        
};

int main()
{

    BSTree B;
    int input ;
  
    while(1)
    {
        cin >> input;
        if(input == -1)
         break;
        else 
         B.insert(input);
        
    } 
    
    cout << ""Total No. of Nodes in the BST = "" << B.getnodes(B.getroot());
    return 0;
}
