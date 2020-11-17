#include<iostream>
#include<cstdlib>
using namespace std;
class Node
{
    private:
        int data;
        Node *left;
        Node *right;
    public:
        Node(int data)
            {
                this->data=data;
                left=NULL;
                right=NULL;
            }
        ~Node()
            {
                delete left,right;
            }
        Node *getLeft()
            {
                return left;
            }
        Node *getRight()
            {
                return right;
            }
        void setLeft(Node *left)
            {
                this->left=left;
            }
        void setRight(Node *right)
            {
                this->right=right;
            }
        int getData()
            {
                return data;
            }
};

class Bst
{
    private:
        Node *root;
        int *arr;
        int i;
    public:
        Bst()
            {
                root=NULL;
                this->arr=arr;
                arr=new int[50];
                i=0;
                
            }
        Node *getroot()
            {
                return root;
            }
            void Size(int size)
            {
                i=0;
                arr=new int[size];
            }
      /* void cleararray()
            {
                for(int i=0;i<15;i++)
                    {
                        arr[i]=-1;
                    }
            }*/
        void insert(int data)
            { 
                
                Node*node=new Node(data);
                if(root==NULL)
                    {
                        root=node;
                    }
                else
                    {
                        Node*temp=root;
                        Node*prev=root;
                        while(temp!=NULL)
                            {
                                prev=temp;
                                if(data<=temp->getData())
                                    {
                                        temp=temp->getLeft();
                                    }
                                else
                                    {
                                        temp=temp->getRight();
                                    }
                            }
                        if(prev->getData()>=data)
                            {
                                prev->setLeft(node);
                            }
                        else
                            {
                                prev->setRight(node);
                            }
                    }//size++;
            }
        void levelprint(Node *root,int lvl)
            {
                if(root==NULL)
                    {
                        return ;
                    }
                    else if(lvl>1)
                    {
                        levelprint(root->getLeft(),lvl-1);
                        levelprint(root->getRight(),lvl-1);
                    }
                else if(lvl==1)
                    {
                        arr[i]=root->getData();
                        i++;
                    }
                
            }
        int height(Node *root)
            {   
                int h=0;
                if(root==NULL)
                    {
                        return 0;
                    }
                else
                    {
                        int l=height(root->getLeft());
                        int r=height(root->getRight());
                        if(l>r)
                            {
                                h=l+1;
                            }
                        else
                            {
                                h=r+1;
                            }
                        return h;
                    }
                    
            }
            void print(Node *temp)
                {
                      int hgt=height(root);
                for(int j=1;j<=hgt;j++)
                     {
                         levelprint(root,j);
                         arr[i]=-1;
                         i++;
                        //cleararray();
                    }
                }
            void arrprint(int count)
                {
                    print(root);
                    //cout<<size<<endl;
                    int val;
                    val=0;
                         while(val<i)
                            {
                                
                                if(arr[val+1]==-1)
                                    {
                                        cout<<arr[val]<<endl;
                                        val=val+2;
                                    }
                                else
                                    {
                                        cout<<arr[val]<<" ";
                                        val++;
                                    }
                            }
                }
};

int main()
{
 Bst b1;
 int data;
 int count=0;
 while(1)
    {
        cin>>data;
        if(data==-1)
            {
                break;
            }
        b1.insert(data);
        count++;
    }
    /*int hgt=b1.height(b1.getroot());
    for(int i=1;i<=hgt;i++)
        {
            b1.levelprint(b1.getroot(),i);
            //cout<<b1.levelprint(b1.getroot,i);
            cout<<endl;
        }*/ int h=((count)+(count/2));
        b1.Size(h);
     //  b1.print(b1.getroot());
        b1.arrprint(h);
        return 0;
}