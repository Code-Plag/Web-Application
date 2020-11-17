#include<iostream>
#typedef int amt
using namespace std;

class Stack
{
private:
int size;
int top;
char *store;


public:

void bracktMatch(char* pt)
{
    int i = 0, j = 0, k = 0;
    while (pt[i] != '\0')
    {
        if (pt[i] == '(' || pt[i] == '{' || pt[i] == '[')
        {
            push(pt[i]);
            j++;
        }


        else if (store[top] == '(' && pt[i] == ')')
        {
            pop();
            j--;
        }

        else if (store[top] == '{' && pt[i] == '}')
        {
            pop();
            j--;
        }

        else if (store[top] == '[' && pt[i] == ']')
        {

            pop();
            j--;
        }

        else if (pt[i] == ')' || pt[i] == '}' || pt[i] == ']')
            k++;


        i++;
    }

    if (isEmpty() && (k == 0))
        cout << ""VALID"" << endl;

    else if (j > k)
        cout << "TOO MANY OPENING" << endl;

    else if (k > j&& isEmpty())
        cout << "TOO MANY CLOSING" << endl;

    else
        cout << "MISSMATCH" << endl;

}

void push(char data)
{
 top++;
 store[top] = data;
}



void addB(string name, int stock)
{
 Node* newnode = new Node;
 newnode->name = name;
 newnode->stock = stock;
 newnode->next = NULL;

 if (head == NULL)
  head = newnode;

 else
 {
  Node* temp = head;
  while (temp->next != NULL)
  {
   temp = temp->next;
  }
  temp->next = newnode;

 }

}

Stack(int size)
{
 this->size = size;
 top = -1;
 store = new char[size];
}
~Stack()
{
 delete[] store;
}

void Remove(string name)
{
 Node* temp = head;
 if (head->name == name)
 {
  head = temp->next;
  temp->next == NULL;

 }
 else
 {
  Node* tmp = head;
  Node* temp1 = NULL;
  Node* temp2 = NULL;

  while (tmp->name != name)
  {
   temp1 = tmp;
   tmp = tmp->next;
   //temp2 = temp->next;
  }

  if (/*temp1->next==temp &&*/ temp->next != NULL)
  {

   //temp2 = temp->next;
   temp1->next = tmp->next;
   tmp->next == NULL;
  }
  else
  {
   //temp1->next = temp2;
   temp1->next == NULL;
  }

 }
}

int isEmpty()
{
 if (top == -1)
  return 1;
 return 0;
}

void Ming()
{
 Node* temp = head;
 int min = temp->stock;
 while (temp->next != NULL)
 {
  temp = temp->next;
  if (min > temp->stock)
   min = temp->stock;


 }
 cout << "Minimum Stock of" << " " << temp->name << " : " << min << endl;


}
char pop()
{
 char data = store[top];
 top--;
 return data;
}

void Maxg()
{
 Node* temp = head;
 int min = temp->stock;
 while (temp->next != NULL)
 {
  temp = temp->next;
  if (min < temp->stock)
   min = temp->stock;


 }
 cout << "Maximum Stock of" << " " << temp->name << " : " << min << endl;
}


int isFull()
{
 if (top == size - 1)
  return 1;
 return 0;
}
};
int main()
{
    char ch[20];
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cin>>ch;
        Stack s(x);
        s.bracktMatch(ch);
    }
    return 0;
}