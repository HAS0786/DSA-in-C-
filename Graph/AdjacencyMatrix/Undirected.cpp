#include <iostream>
#include <string>
using namespace std;
class Undirected
{
private:
    int arr[10][10];

public:
    // ::::::::: size is my own method and it is work good :::::::

    // THis initialize the matrix to 0 (all elements to 0)
    void initialize(int size)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = 1; j < size; j++)
            {
                arr[i][j] = 0;
            }
        }
    }

    // This Print the values

    void Print(int size)
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = 1; j < size; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    // set the values of Nodes by calling this functon::

    void AddEdge(int i, int j, int &size)
    {
        if ((i >= 1 && i < size) && (j >= 1 && j < size))
        {
            arr[i][j] = 1;
            arr[j][i] = 1;
        }
        else{
            cout<<"Invalid Pair of Edges"<<endl;
        }
    }
};

int main()
{
    int size;
    cout << "Enter the Size of Matrix you want (Less then 10 )" << endl;
    cin >> size;

    Undirected first;

    first.initialize(size);

    // now add the nodes which are connected:

    // :::::::::::::::::::: Book Methods ::::::::::::::

    // first.AddEdge(1,4);
    // first.AddEdge(2,4);
    // first.AddEdge(2,5);
    // first.AddEdge(3,5);
    // first.AddEdge(4,1);
    // first.AddEdge(4,2);
    // first.AddEdge(4,6);
    // first.AddEdge(5,2);
    // first.AddEdge(5,3);
    // first.AddEdge(5,4);

    // :::::::::::::::: My Own Method ::::::::::::::::::

    // loop for First Directed Nodes
    for (int i = 1; i < size; i++)
    {
        int h, a;
        cout << "Enter the Values {first node then 2nd Node}" << endl;
        cin >> h >> a;
        // :::::::: size is given so it print according to that :::::::::

        first.AddEdge(h, a, size);
    }

    // loop for Second Directed Nodes

    for (int i = 1; i < size; i++)
    {
        int h, a;
        cout << "Enter the Values {Second node then First Node}" << endl;
        cin >> a >> h;
        // :::::::: size is given so it print according to that :::::::::

        first.AddEdge(a, h, size);
    }

    // :::::::: size is given so it print according to that :::::::::

    // now print:

    first.Print(size);
    return 0;
}