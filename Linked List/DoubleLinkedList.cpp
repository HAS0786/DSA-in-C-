#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor::
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Add at First Position::
void InsertAtStart(Node *&head, int d)
{
    cout << "Insert At Start" << endl;
    cout << head << endl;
    Node *temp = new Node(d);
    temp->next = head;
    cout << "temp-next" << temp->next << endl;
    head->prev = temp;
    head = temp;
    cout << temp->data << endl;
    cout << "After Update" << head << endl;
    cout << "Exit from Start" << endl;
}

// Insert At Tail:::

void InsertAtTail(Node *&tail, int d)
{
    cout << "Insert At Tail" << endl;
    cout << tail << endl;
    Node *temp = new Node(d);
    temp->prev = tail;
    tail->next = temp;
    cout << temp->data << endl;
    cout << "temp-prev" << temp->prev << endl;

    tail = temp;
    cout << "After Update" << tail << endl;
    cout << "Exit from Tail" << endl;
}

// InsertAt Any Point:::

void InsertAtPoint(Node *&head, Node *&tail, int value, int d)
{
    Node *temp = new Node(d);
    Node *current = head;
    if (value == head->data)
    {
        cout << "Enter into head-Section" << endl;

        InsertAtStart(head, d);
        return;
    }
    else
    {
        // int counter=1;
        while (value != current->data)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "Enter into Tail-Section" << endl;
            InsertAtTail(tail, d);
            return;
        }
        else
        {
            cout<<"Enter into Random Place Insertion"<<endl;
            temp->next = current;
            current->prev->next = temp;
            temp->prev = current->prev;
            current->prev = temp;
            current = temp;
            cout<<current->data<<endl;
            cout << "After Update" << current << endl;
            cout << "Exit from Random" << endl;
        }
    }
}


// Delete the Nodes::
void DeleteNodes(Node* &head, Node* &tail, int value)
{
    cout<<"Enter into Delete Section"<<endl;
    Node* temp;
    Node* current=head;
    if(value==head->data)
    {
        cout<<"Here delete First Node"<<endl;
        temp=current;
        current=current->next;
        head=head->next;
        head->prev=NULL;
        delete temp;
    
    }

    else{

        while(value!=current->data)
        {
            current=current->next;
        }
        if(current->next==NULL)
        {
            cout<<"Delete the tail"<<endl;
            temp=current;
            tail=current->prev;
            current=current->prev; // current=temp;
            current->next=NULL;
            delete temp;
        }
        else{
          
             cout << "Delete the Random Node" << endl;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            temp = current;
            current=current->next;
            delete temp;
            
        }
    }
}

// print all Nodes::
void PrintNodes(Node* &head)
{
    Node *traverse = head;
    while (traverse != NULL)
    {
        cout << traverse->data << " <-> ";
        traverse = traverse->next;
    }


}
int main()
{

    Node *temp = new Node(2);
    Node *head = temp;
    Node *tail = temp;

    cout << temp->data << endl;
    cout << temp->prev << endl;
    cout << temp->next << endl;

    InsertAtStart(head, 5);
    cout << head << endl;

    InsertAtTail(tail, 10);
    cout << tail << endl;

    InsertAtPoint(head, tail, 2, 20);

    PrintNodes(head);

cout<<"Now delete the Nodes"<<endl;
  //  DeleteNodes(head,tail,5); // successfuly delte the Head::
  DeleteNodes(head,tail,2);

    PrintNodes(head);

    return 0;
}