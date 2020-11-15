#include <iostream>
#include <cstring>

using namespace std;

class Node
{
    private:
        int data;
        Node *next;

    public:
        Node()
        {
            next = NULL;
        }

        Node(int data)
        {
            this->data = data;
            next = NULL;
        }

        int getData()
        {
            return data;
        }

        void setData(int data)
        {
            this->data = data;
        }

        Node * getNext()
        {
            return next;
        }

        void setNext(Node * n)
        {
            next = n;
        }
};

class LinkedList
{
    private:
        Node * head;

    public:
        LinkedList()
        {
            head = NULL;
        }

        void insertB(int data)
        {
            Node *n = new Node(data);

            if(head == NULL)
                head = n;

            else
            {
                n->setNext(head);
                head = n;
            }
        }

        void insertE(int data)
        {
            Node *n = new Node(data);

            if(head == NULL)
                head = n;
            else
            {
                Node *temp = head;
                while(temp->getNext() != NULL)
                {
                    temp = temp->getNext();
                }
                temp->setNext(n);
            }
        }

        void insertMB(int pos, int data)
        {

            if(head->getData() == pos)
            {
                insertB(data);
            }
            else
            {

                Node *temp = head;
                Node *prev = NULL;
                while(temp->getData() != pos)
                {
                    if(temp->getNext() == NULL)
                    {
                        break;
                    }
                    prev = temp;
                    temp = temp->getNext();
                }
                if(temp->getData() == pos)
                {
                    Node *n = new Node(data);
                    n->setNext(prev->getNext());
                    prev->setNext(n);
                }
                else
                    cout << "NODE NOT FOUND" << endl;
            }
        }

        void insertMA(int pos, int data)
        {
            Node * temp = head;
            while(temp->getData() != pos)
            {
                if(temp->getNext() == NULL)
                    break;
                temp = temp->getNext();
            }
            if(temp->getData() == pos)
            {
                Node *n = new Node(data);
                n->setNext(temp->getNext());
                temp->setNext(n);
            }
            else
                cout << "NODE NOT FOUND" << endl;
        }

        void deleteN(int pos)
        {
            Node *temp = head;
            if(head == NULL)
                cout << "EMPTY" << endl;
            else if(head->getData() == pos)
            {
                head = head->getNext();
                delete temp;
            }
            else
            {
                Node *prev = NULL;
                while(temp->getData() != pos)
                {
                    if(temp->getNext() == NULL)
                        break;
                    prev = temp;
                    temp = temp->getNext();
                }
                if(temp->getData() == pos)
                {
                    prev->setNext(temp->getNext());
                    delete temp;
                }
                else
                    cout << "NODE NOT FOUND" << endl;
            }
        }

        void deleteNA(int pos)
        {

            Node *temp = head;
            if(head == NULL)
                cout << "EMPTY" << endl;
            else if(head->getData() == pos)
            {
                temp = head->getNext();
                head->setNext(temp->getNext());
                delete temp;
            }
            else
            {
                Node *prev = NULL;
                while(temp->getData() != pos)
                {
                    if(temp->getNext() == NULL)
                        break;
                    prev = temp;
                    temp = temp->getNext();
                }
                if(temp->getData() == pos)
                {
                    if(temp->getNext() != NULL)
                    {
                        prev = temp;
                        temp = temp->getNext();
                        prev->setNext(temp->getNext());
                        delete temp;
                    }
                 //   else
                      //  cout << "NODE NOT FOUND" << endl;
                }
              //  else
                   // cout << "NODE NOT FOUND" << endl;
            }
        }

        void deleteNB(int pos)
        {
            Node *temp = head;
            if(head == NULL)
                cout << "EMPTY" << endl;
            else if(head->getData() == pos)
            {
              //  cout << "NODE NOT FOUND" << endl;
            }
            else if(temp->getNext()->getData() == pos)
            {
                head = head->getNext();
                delete temp;
            }
            else
            {
                Node *prev = NULL;
                while(temp->getNext()->getData() != pos)
                {
                    if(temp->getNext()->getNext() == NULL)
                        break;
                    prev = temp;
                    temp = temp->getNext();
                }
                if(temp->getNext()->getData() == pos)
                {
                    prev->setNext(temp->getNext());
                    delete temp;
                }
              //  else
                 //   cout << "NODE NOT FOUND" << endl;
            }
        }

        void fancyDisplay()
        {
            Node *temp = head;

            while(true)
            {
                if(temp->getNext() == NULL)
                {
                    cout << temp->getData() << endl;
                    break;
                }
                cout << temp->getData() << "->";
                temp = temp->getNext();
            }
        }

        void revInit()
        {
            if(head == NULL)
                {}
            else
            {
                Node *temp = head;
                reverse(temp);
                cout << endl;
            }
        }

        int reverse(Node *temp)
        {
            if(temp->getNext() == NULL)
                cout << temp->getData() << " ";
            else
            {
                reverse(temp->getNext());
                cout << temp->getData() << " ";
            }
        }

        void display()
        {
            Node *temp = head;

            while(true)
            {
                if(temp->getNext() == NULL)
                {
                    cout << temp->getData() << endl;
                    break;
                }
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
        }

        ~LinkedList()
        {
            Node *temp;

            while(head->getNext() != NULL)
            {
                temp = head;
                head = head->getNext();
                delete temp;
            }
            delete head;
            //cout << "DESTRUCTOR CALLED!" << endl;
        }
};

int main()
{
    LinkedList l;
    string cmd;
    int data, pos;

    while(true)
    {
        cin >> cmd;
        if(cmd == "AB")
        {
            cin >> data;
            l.insertB(data);
        }

        else if(cmd == "PR")
        {
            l.display();
        }

        else if(cmd == "AE")
        {
            cin >> data;
            l.insertE(data);
        }

        else if(cmd == "AMA")
        {
            cin >> pos >> data;
            l.insertMA(pos, data);
        }

        else if(cmd == "AMB")
        {
            cin >> pos >> data;
            l.insertMB(pos, data);
        }

        else if(cmd == "DN")
        {
            cin >> pos;
            l.deleteN(pos);
        }

        else if(cmd == "DNA")
        {
            cin >> pos;
            l.deleteNA(pos);
        }

        else if(cmd == "DNB")
        {
            cin >> pos;
            l.deleteNB(pos);
        }

        else if(cmd == "FPR")
        {
            l.fancyDisplay();
        }

        else if(cmd == "RPR")
        {
            l.revInit();
        }

        else if(cmd == "EXIT")
            break;
    }

    return 0;

}
