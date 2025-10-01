#include<iostream>
using namespace std;
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int largest=arr[0];
    int Second_Largest=-1;
    for(int i=1;i<size;i++)
    {
        if(largest<arr[i])
        {
            Second_Largest=largest;
            largest=arr[i];
        }
        else if (largest!=arr[i])
        {
            if(Second_Largest==-1 || Second_Largest<arr[i])
            {
                Second_Largest=arr[i];
            }
        }
    }
    cout<<Second_Largest;
}