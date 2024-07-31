#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor:
    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }
};

// InsertAtHead:
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    cout << "Insert AT Head Run" << endl;
    cout << head << endl; // for understanding and verification only::

    // Point the temp now to head(whose address is comes)
    temp->next = head;

    // point the head at start(temp is now at start)
    head = temp;
    // Succesffly working:
    cout << temp->data << endl;
    cout << temp->next << endl;

    // Successfully head Point at Start::
    cout << head << endl;
    cout << "Exit from Head Run" << endl;
}

// Insert At Tail:::::::::::::
void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    cout << "Enter into Tail now" << endl;
    // to show the address of Tail;
    cout << tail << endl;

    // Now tail-next points to next;
    tail->next = temp;
    // Now temp is tail::
    tail = temp;

    cout << temp->data << endl;
    cout << temp->next << endl;

    // to show the address of Tail-Updated
    cout << tail << endl;
}

// Insert At Specific Position by Index (Generic Code=> As Add head , tail also according to Index)

void InsertAtSpecificID(Node *&head, Node *&tail, int Position, int d)
{

    Node *current = head;
    Node *temp = new Node(d);

    // For Adding at First
    if (Position == 1)
    {
        cout << "You Enter the Position -> 1 So it Add into Head" << endl;
        InsertAtHead(head, d);
        return;
    }
    else
    {
        int count = 1;
        while (count < Position)
        {
            current = current->next;
            count++;
        }

        if (current->next == NULL)
        {
            cout << "You Enter the Position =Tail So it Add into Tail" << endl;

            InsertAtTail(tail, d);
            return;
        }

        else
        {

            temp->next = current->next;
            current->next = temp;
            current = temp;
            cout << temp->data << endl;
            cout << temp->next << endl;
        }
    }
}

// Delete The Node:::;

void DeleteNode(Node *&head,Node* &tail, int Position)
{
    Node *temp; // for
    Node *prev = NULL;
    Node *current = head;

   if(Position==1)
   {
    temp=head;
    head=head->next;
    delete temp;
   }
   else{
    int counter=1;
    while(counter<Position)
    {
        prev=current;
        current=current->next;
        counter++;
    }
    // for tail
    if(current->next==NULL)
    {
        cout<<"Delete Tail"<<endl;
        temp=current;
        prev->next=NULL;
        tail=prev;
        delete temp;
        // cout<<"tail-newlocation"<<prev<<endl;
    }
    else{
        prev->next=current->next;
        temp=current;
        current=current->next;
        delete temp;
    }
   }
}

// Print the Linked List As a List::

void PrintList(Node *&head)
{
    Node *traverse = head;
    while (traverse != NULL)
    {
        cout << traverse->data << "->" << " ";
        traverse = traverse->next;
    }
}
int main()
{

    Node *temp = new Node(2);
    Node *head = temp;
    Node *tail = temp;
    cout << temp->data << endl;
    cout << temp->next << endl;
    InsertAtHead(head, 5); // inserting at Head works perfectly::::::;;
    // InsertAtHead(head,10);
    cout << head << endl;

    cout << "Now Insert At Tail" << endl;
    InsertAtTail(tail, 10);
    cout << tail << endl;

    cout << "Now Add at Position (Specifically)" << endl;
    // InsertAtSpecificID(head,tail,1,1); // for Add at Head
    InsertAtSpecificID(head, tail, 2, 9); // for Add at Specific Position
    // InsertAtSpecificID(head, tail, 3, 15); // for Add at Tail
    cout << head << endl;
    cout << tail << endl;

    // DeleteNode(head,tail, 1); work for Head
    // DeleteNode(head,tail, 3); // any specific term::
    DeleteNode(head,tail, 4);// here in my list at 4 is tail so it delete the tail and tail
    PrintList(head);
    cout<<tail<<endl;
   

    return 0;
}