#include<iostream>
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
        int getdata()
        {
            return data;
        }
        void setleft(Node *left)
        {
            this->left=left;
        }
        void setright(Node *right)
        {
            this->right=right;
        }
        Node *getleft()
        {
            return left;
        }
        Node *getright()
        {
            return right;
        }
        void print()
        {
            cout<<data <<" ";
        }
};
class BST
{
    private:
        Node *root;
        int *a;
        int x;
    public:
        BST()
        {
            root=NULL;
        }
        Node *getroot()
        {
            return root;
        }
        void asize(int size)
        {
            x=0;
            a=new int[size];
        }
        void insert(int data)
        {
            Node *node=new Node(data);
            Node *temp=root;
            Node *prev=NULL;
            if(root==NULL)
            {
                root=node;
            }
            else
            {
                while(temp!=NULL)
                {
                    prev=temp;
                    if(data <=temp->getdata())
                    {
                        temp=temp->getleft();
                    }
                    else
                    {
                        temp=temp->getright();
                    }
                }
                if(data <=prev->getdata())
                {
                    prev->setleft(node);
                }
                else
                {
                    prev->setright(node);
                }
            }
        }

        int height(Node *root)
        {
            if(root==NULL)
            {
                return 0;
            }
            else
            {
                int L=height(root->getleft());
                int R=height(root->getright());
                if(L>R)
                {
                    return (L+1);
                }
                else
                {
                    return(R+1);
                }
            }
        }
        void level(Node *root,int l)
        {
            if(root==NULL)
            {
                return;
            }
            else if(l>1)
            {
                level(root->getleft(),l-1);
                level(root->getright(),l-1);
            }
            else if(l==1)
            {
                a[x]=root->getdata();
                x++;
            }
        }
        void print(Node *root)
        {
            int h=height(root);
            for(int i=1;i<=h;i++)
            {
                level(root,i);
                a[x]=-1;
                x++;
            }
        }
        void aprint(int size)
        {
            print(root);
            int i=0;
            while(i<=x-2)
            {
                if(a[i+1]==-1)
                {
                    cout<<a[i]<<endl;
                    i=i+2;
                }
                else
                {
                    cout<<a[i]<<" ";
                    i++;
                }
            }
        }
};
int main()
{
    BST bst;
    int a,b=0,c;
    while(1)
    {
        cin>>a;
        if(a==-1)
        {
            break;
        }
        bst.insert(a);
        b++;
    }
        c=b+(b/2);
        bst.asize(c);
        bst.aprint(c);
        return 0;
}
