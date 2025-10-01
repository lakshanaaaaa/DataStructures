#include<iostream>
using namespace std;
void Minimum_Groups_Flips_TO_Make_Same(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        if(arr[i]!=arr[i-1])
        {
            if(arr[i]!=arr[0])
            {
                cout<<"From "<<i<<" to ";
            }
            else
            {
                cout<<i-1<<"\n"; 
            }
        }
    }
    if(arr[size-1]!=arr[0])
        {
            cout<<(size-1);
        }
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    Minimum_Groups_Flips_TO_Make_Same(arr,size);
}