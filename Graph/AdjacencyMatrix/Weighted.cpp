#include<iostream>
#include<string>
using namespace std;

class Weighted{
    private:
    int arr[10][10];

    public:
    void Initialize(int size)
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0; j<size; j++)
            {
                arr[i][j]=0;
            }
        }
    }

    void Print(int size)
    {
        for(int i=0; i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void AddEdge(int i, int j, int weight,int size)
    {
        if((i>=0 && i< size) && (j>=0 && j<size))
        {
            arr[i][j]=weight;
            arr[j][i]=weight;
        }
        else{
            cout<<"Not correctly Add Nodes (Vertices)"<<endl;
        }
    }
};

int main()
{
    cout<<"Enter the Size of Matrix (Please must be less then 10 )"<<endl;
    int size;
    cin>>size;

Weighted first;
first.Initialize(size);
    for(int i=0; i<=size; i++)
    {
        cout<<"Enter the Vertices (As it is Undirected so Please first(1st) and then Second(2nd) )"<<endl;
        int h,a,s;
        cout<<"Enter the vertices"<<endl;
        cin>>h>>a;
        cout<<"Enter the Weight "<<endl;
        cin>>s;
first.AddEdge(h,a,s,size);
    }
    for(int i=0; i<=size; i++)
    {
        cout<<"Enter the Vertices (As it is Undirected so Please Second(2nd) and then First(1st) )"<<endl;
        int h,a,s;
        cout<<"Enter the vertices"<<endl;
        cin>>a>>h;
        cout<<"Enter the Weight "<<endl;
        cin>>s;
first.AddEdge(a,h,s,size);
    }

    first.Print(size);

     return 0;
}