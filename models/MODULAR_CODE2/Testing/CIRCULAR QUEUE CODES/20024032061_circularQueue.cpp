#include<iostream>

using namespace std;

class cQueue
{
    private:
            int size;
            int no;
            int front;
            int rear;
            int *store;
    public:
            cQueue(int size)
            {
                this->size=size;
                no = 0;
                front = -1;
                rear = -1;
                store = new int(size);
            }
            ~cQueue()
            {
                delete[] store;
            }
            int isEmpty()
            {
                if(no == 0)
                return 1;
                return 0;
            }
            int isFull()
            {
                if(no == size)
                return 1;
                return 0;
            }
            
            void enQueue(int data)
            {
                rear = (rear+1) %size;
                no++;
                store[rear]=data;
            }
            int deQueue()
            {
                int data;
                front = (front + 1)%size;
                no--;
                data=store[front];
                
                if(front == rear)
                {
                    front = rear - 1;
                }
                return data;
            }
};
            
            int main()
            {
                int size;
                cin>>size;
                
                cQueue e1(size);
                string cmd;
                while(1)
                {
                    cin>>cmd;
                    if(cmd == "exit")
                    {
                        break;
                    }
                    
                    if(cmd == "enque")
                    {
                        if(!e1.isFull())
                        {
                            int d;
                            cin>>d;
                            e1.enQueue(d);
                        }
                        else if(e1.isFull())
                        {
                            cout<<"FULL"<<endl;
                        }
                    }
                    
                    
                    if(cmd == "deque")
                    {
                        if(e1.isEmpty())
                        {
                            cout<<"EMPTY"<<endl;
                        }
                        else
                        {
                        cout<<e1.deQueue()<<endl;
                    
                        }
                }
                }
                        return 0;
                    }