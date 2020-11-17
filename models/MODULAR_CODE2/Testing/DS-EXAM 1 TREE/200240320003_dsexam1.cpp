#include<iostream>
#include<queue>
using namespace std;
class Node
{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int d)
        {
            data=d;
            left=right=NULL;
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
        void setleft(Node* l)
        {
            left=l;
        }
        void setright(Node* r)
        {
            right=r;
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
        void insertBST(int d)
        {
            Node* nd=new Node(d);
            if(nd==NULL)
            {
                return;
            }
            if(root==NULL)
            {
                root=nd;
            }
            else{
                    Node* temp=root;
                    while(1)
                    {
                        if(temp->getdata()>=d)
                        {
                            if(temp->getleft()==NULL)
                            {
                                temp->setleft(nd);
                                break;
                            }
                            temp=temp->getleft();
                            continue;
                        }
                        else{
                                if(temp->getright()==NULL)
                                {
                                    temp->setright(nd);
                                    break;
                                }
                                temp=temp->getright();
                                continue;
                        }
                    }
            }
        }

       Node* getroot()
       {
           return root;
       }
	void BFS(Node* temp)
	{
		if(temp==NULL)
		{
			return;
		}
		queue<Node*> Q;
		int level=0;
		Q.push(temp);
		while(!Q.empty())
		{
			level=Q.size();
			while(level>0)
			{
				Node* temp1=Q.front();
				cout<<temp1->getdata();
				if(level>1)
				{
					cout<<" ";
				}
				Q.pop();
				if(temp1->getleft()!=NULL)
				{
					Q.push(temp1->getleft());
				}
				if(temp1->getright()!=NULL)
				{
					Q.push(temp1->getright());
				}
				level--;
				}
			cout<<endl;
		}
	}

};

int main()
{
    Tree T;
    int d;
    while(1)
    {
        cin>>d;
        if(d==-1)
        {
           break;
        }
        T.insertBST(d);
    }

    if(T.getroot()==NULL)
    {
        return 0;
    }
    T.BFS(T.getroot());
    return 0;
}
