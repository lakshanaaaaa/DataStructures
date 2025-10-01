#include<iostream>
using namespace std;
int brute_force(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        int count=1;
        for(int j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
            
            {
                count++;
            }
        }
        if(count>size/2)
        {
            return arr[i];
        }
    }
    return -1;
}

int Moore(int arr[],int size)
{
    int res=1;
    for(int i=1;i<size;i++)
    {
        if(arr[res]==arr[i])
        {
            res++;
        }
        else
        {
            res--;
        }
        if(res==0)
        {
            res=1;
        }
    }
    return res;
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
    cout<<brute_force(arr,size);

}