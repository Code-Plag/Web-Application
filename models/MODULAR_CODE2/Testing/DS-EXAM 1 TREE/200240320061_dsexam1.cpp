#include<iostream>
#include<queue>
using namespace std;

class Node{
    
private:
        int data;
        Node *right;
        Node *left;
public:
        friend class BinarySearchTree;
};

class BinarySearchTree{
    
private:
        Node *root;
        Node *DELIMITER;
public:
       BinarySearchTree(){
           
           root=NULL;
           //DELIMITER=nullptr;
           // DELIMITER=1;
           DELIMITER=NULL;
       } 
       
       Node *getRoot(){
           
           return root;
       }
       
       void addNode(int data){
           
           Node *newnode;
           newnode = new Node;
           
           newnode->data=data;
           newnode->left=NULL;
           newnode->right=NULL;
           
           if(root==NULL){
              
              root=newnode;
           }
           else{
               
               Node *current;
               Node *prev;
               current=root;
               prev=root;
               
               while(current !=NULL){
                   
                   prev=current;
                   
                   if(newnode->data > current->data){
                       
                       current=current->right;
                   }
                   else{
                       
                        current=current->left;
                   }
               }
               
               if(newnode->data > prev->data){
                   
                   prev->right=newnode;
               }
               else{
                   
                   prev->left=newnode;
               }
               
           }
           
       }
       
       /*void inorder(Node *temp){
           
           if(temp==NULL){
               return;
           }
           
           inorder(temp->left);
           cout<<temp->data<<" ";
           inorder(temp->right);
       }*/
       
       void printTreeLevelByLevel(Node *temp){
           
           if(temp == NULL){
               
               return;
           }
           
           queue<Node*> qu;
           int count=0;
           qu.push(temp);
          // qu.push(DELIMITER);
           
           while(!qu.empty()){
               
               count=qu.size();
               while(count > 0){
                                      
                    Node *curr=qu.front();
                    cout<<curr->data;
                    if(count > 1){
                        
                        cout<<" ";
                    }
                         
               qu.pop();
               
               //if(curr !=DELIMITER){
                   
                   //cout<<curr->data<<" ";
                   if(curr->left !=NULL){
                       
                       qu.push(curr->left);
                   }
                   if(curr->right !=NULL){
                       
                        qu.push(curr->right);
                   }
                   
                   count--;
               }
               
               cout<<endl;
              
           }
       }
       
       
       
    
};

int main(){
    
    BinarySearchTree t;
    int data;
    while(1){
        
        cin>>data;
        if(data==-1){
            break;
        }
        else{
            
            t.addNode(data);
        }
    }
    
    //t.inorder(t.getRoot());
    t.printTreeLevelByLevel(t.getRoot());
}