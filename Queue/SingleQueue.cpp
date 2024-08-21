#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
     int data;
     Node *next;

     // Constructor:::
     Node(int d)
     {
          this->data = d;
          this->next = NULL;
     }
};

// Insert the Queue::
// Note=>>>>>>>>>> Only insert from tail side not from both side:::

void Enqueue(Node *&head, Node *&tail, int d)
{
     if (head == NULL)
     {
          Node *temp = new Node(d);
          head = temp;
          tail = temp;

          // shwo what is in temp now
          cout <<"First Node "<< temp->data << endl;
     }
     // when Non-empty::
     else
     {
          Node *temp = new Node(d);
          temp->next = tail;
          // tail is now newly add node
          tail = temp;

          cout <<"After initial Node " << temp->data << endl;
          cout << "I am Tail " << tail << endl;
     }
}

// Delete the Node

// ===>>>Note::: Here in Queue System only head is delete as becuase head is the first element that is enter in the queue::

void Dequeue(Node* &head, Node* &tail)
{
     Node*traverser=tail;
     Node*prev=NULL;
     while(traverser->next!=NULL)
     {
          prev=traverser;
          traverser=traverser->next;
     }
     cout<<prev<<endl;
     cout<<traverser<<endl;
     head=prev;
     head->next=NULL;
     delete traverser;
}

void PrintQueue(Node* &head,Node* &tail)
{
     Node* traverser=tail;
     while(traverser!=NULL)
     {
          cout<<traverser->data<<"-> ";
          traverser=traverser->next;
     }
}
int main()
{

     Node *head = NULL;
     Node *tail = NULL;
     Enqueue(head, tail, 2);
     cout << "I am Head now  " << head << endl;
     cout << "I am tail now  " << tail << endl;
     Enqueue(head, tail, 5);
     cout << "I am Head now  " << head << endl;
     cout << "I am tail now  " << tail << endl;
     Enqueue(head, tail, 10);
     cout << "I am Head now  " << head << endl;
     cout << "I am tail now  " << tail << endl;

     Dequeue(head,tail);
     cout<<"Now head is "<<head<<endl;

     PrintQueue(head,tail);

     return 0;
}