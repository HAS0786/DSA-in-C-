#include<iostream>
#include<string>
using namespace std;
class Directed{

    private:
    int arr[10][10];
    public:

// :::::::: initialize the values :::::::::

    void Initialize(int size)
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                arr[i][j]=0;
            }
        }
    }

// ::::::::::::: Print ::::::::::::::::

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

// :::::: Set 1 to values :::::::::

void AddEdge(int i, int j, int size)
{
    if((i>=0 && i<size)&& (j>=0 && j<size))
    {
        arr[i][j]=1;
    }
    else{
        cout<<"Invalid Pair Of Edges "<<endl;
    }
}
};

int main()
{
    Directed first;

    cout<<"Enter the Size of Array you want (Please less then 10)"<<endl;
    int size;
    cin>>size;
first.Initialize(size);
    for(int i=0;i<size;i++){
        cout<<"Enter the Values (Directed so Only 1-times )"<<endl;
        int h,a;
        cin>>h>>a;
       first.AddEdge(h,a,size); 
    }
    first.Print(size);
    
     return 0;
}