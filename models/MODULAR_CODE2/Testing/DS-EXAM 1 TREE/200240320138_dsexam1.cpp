# include <iostream>
# include <bits/stdc++.h>
# include <vector>

using namespace std;

vector <int> levelPrint;

class Node
    {
        private:
            int data;
            Node* left;
            Node* right;
        public:
            Node()
                {
                    left = NULL;
                    right = NULL;
                }
            
            Node(int data)
                {
                    this->data = data;
                    left = NULL;
                    right = NULL;
                }
            
            int getData()
                {
                    return this->data;
                }
            
            void setLeft(Node* left)
                {
                    this->left = left;
                }
            
            void setRight(Node* right)
                {
                    this->right = right;
                }
            
            Node* getLeft()
                {
                    return left;
                }
            
            Node* getRight()
                {
                    return right;
                }
    };

class BST
    {
        private:
            Node *root;
        public:
            BST()
                {
                    root = NULL;
                }
            
            Node* getRoot()
                {
                    return root;
                }
            
            void insertData(int data)
                {
                    Node* newNode = new Node(data);
                    if(root == NULL)
                        root = newNode;
                    else
                    {
                        Node* temp1;
                        Node* temp2;
                        temp1 = root;
                        temp2 = root;
                        while(temp1 != NULL)
                            {
                                temp2 = temp1;
                                if(data<= temp1->getData())
                                    temp1 = temp1->getLeft();
                                else if(data > temp1->getData())
                                    temp1 = temp1->getRight();
                            }
                        if(data<= temp2->getData())
                                    temp2->setLeft(newNode);
                                else if(data > temp2->getData())
                                    temp2->setRight(newNode);
                    }
                }
            
            /*void inOrder(Node* root)
                {
                   if(root != NULL)
                    {
                        inOrder(root->getLeft());
                        cout<<root->getData()<<" ";
                        inOrder(root->getRight());
                    }
                    else
                        return;
                }*/
                
            int treeHeight(Node* root)
                {
                    if(root == NULL)
                        return 0;
                    else
                        {
                            int leftHeight = treeHeight(root->getLeft());
                            int rightHeight = treeHeight(root->getRight());
                            
                            if(leftHeight > rightHeight)
                                return (leftHeight +1);
                            else
                                return(rightHeight +1);
                        }    
                }
            
            void saveEachLevel(Node* root, int level)
                {
                    if(root == NULL)
                        return;
                    if(level == 1)
                        {
                            levelPrint.push_back(root->getData());
                            return;
                        }
                    else if(level > 1)
                        {
                            saveEachLevel(root->getLeft(), level-1);
                            saveEachLevel(root->getRight(), level-1);
                        }
                }
            
    };

int main()
    {
        BST b1;
        int cmd;
        while(cmd != -1)
            {
                cin>>cmd;
                if(cmd != -1)
                    b1.insertData(cmd);
            }
       // cout<<b1.treeHeight(b1.getRoot());
       // b1.inOrder(b1.getRoot());
        
        int treeHt = b1.treeHeight( b1.getRoot() );
        
        for(int i = 0; i<treeHt; i++)
            {
                b1.saveEachLevel( b1.getRoot(), i+1 );
                for(int j = 0; j < levelPrint.size(); j++)
                    {
                        if(j == (levelPrint.size() -1) )
                            cout<<levelPrint[j]<<endl;
                        else
                            cout<<levelPrint[j]<<" ";
                    }
                levelPrint.clear();
            }
        return 0;
    }