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

// // Add at First Position::
void InsertAtStart(Node *&head, Node *&tail, int d)
{
    cout << "Insert At Start" << endl;
    cout << head << endl;

    Node *temp = new Node(d); // Create a new node with the given data.
    if (head == NULL)         // If the list is empty
    {
        head = temp;       // Set head to the new node.
        tail = temp;       // Set tail to the new node.
        head->next = head; // Point head's next to itself, making it circular.
        head->prev = head; // Point head's prev to itself, making it circular.
    }
    else
    {
        temp->next = head; // Point new node's next to the current head.
        head->prev = temp; // Point current head's prev to the new node.
                           // for showing only (verfication)
        cout << "temp-next" << temp->next << endl;

        head = temp; // Update head to be the new node.
                     // for showing only (verfication)
        cout << "Here Iam head-Prev" << head->prev << endl;

        head->prev = tail; // Point new head's prev to the tail.
                           // for showing only (verfication)
        cout << "Here Iam head-Prev" << head->prev << endl;

        tail->next = head; // Point tail's next to the new head, completing the circular link.

        // for showing only (verfication)
        cout << temp->data << endl;
        cout << "After Update" << head << endl;
        cout << "Exit from Start" << endl;
    }
}

// // Insert At Tail:::
void InsertAtTail(Node *&head, Node *&tail, int d)
{
    cout << "Insert At Tail" << endl;

    cout << tail << endl;
    Node *temp = new Node(d);
    if (tail == NULL) // If the list is empty
    {
        head = temp;
        tail = temp;
        head->next = head;
        head->prev = head;
    }
    else
    {
        temp->prev = tail;
        cout << temp->data << endl;
        cout << "temp-prev" << temp->prev << endl;
        tail->next = temp;
        tail = temp;
        cout << "I am tail-next" << tail->next << endl;

        tail->next = head;
        head->prev = tail;
        cout << "I am tail-next" << tail->next << endl;
        cout << "After Update" << tail << endl;
        cout << "Exit from Tail" << endl;
    }
}

// // InsertAt Any Point:::
void InsertAtPoint(Node *&head, Node *&tail, int value, int d)
{
    Node *temp = new Node(d);
    Node *current = head;
    if (value == head->data)
    {
        cout << "Enter into head-Section" << endl;

        InsertAtStart(head, tail, d);
        return;
    }
    else
    {
        while (value != current->data)
        {
            current = current->next;
        }
        if (current->next == head)
        {
            cout << "Enter into Tail-Section" << endl;

            InsertAtTail(head, tail, d);
            return;
        }
        else
        {
            cout << "Enter into Random Place Insertion" << endl;

            temp->next = current;
            current->prev->next = temp;
            temp->prev = current->prev;
            current->prev = temp;

            cout << current->data << endl;
            cout << "After Update" << current << endl;
            cout << "Exit from Random" << endl;
        }
    }
}

// // Delete the Nodes::
void DeleteNodes(Node *&head, Node *&tail, int value)
{
    cout << "Enter into Delete Section" << endl;

    Node *temp;
    Node *current = head;
    if (value == head->data)
    {
        cout << "Here delete First Node" << endl;

        temp = current;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
    else
    {
        while (value != current->data)
        {
            current = current->next;
        }
        if (current == tail)
        {
            cout << "Delete the tail" << endl;

            temp = current;
            tail = current->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
        else
        {
            cout << "Delete the Random Node" << endl;

            current->prev->next = current->next;
            current->next->prev = current->prev;
            //  delete current;
            temp = current;
            current = current->next;
            delete temp;
        }
    }
}

// Print all Nodes::
void PrintNodes(Node *&head)
{
    if (head != NULL)
    {
        Node *traverse = head;
        do
        {
            cout << traverse->data << " <-> ";
            traverse = traverse->next;
        } while (traverse != head);
        cout << endl;
    }
}

int main()
{
    Node *temp = new Node(2);
    Node *head = temp;
    Node *tail = temp;
    //     Node *head = NULL;
    //     Node *tail = NULL;

    InsertAtStart(head, tail, 5);
    InsertAtTail(head, tail, 10);
    InsertAtPoint(head, tail, 5, 20);

    PrintNodes(head);

    cout << "Now delete the Nodes" << endl;
    DeleteNodes(head, tail, 2);

    PrintNodes(head);

    return 0;
}
