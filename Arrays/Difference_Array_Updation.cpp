#include<iostream>
using namespace std;
int main()
{
    int size;
    cin>>size;
    int queries;
    cin>>queries;
    int difference_array[size+1]{0};
    while(queries--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        difference_array[l]+=k;
        difference_array[r+1]-=k;
    }
    for(int i=1;i<size;i++)
    {
        difference_array[i]=difference_array[i-1]+difference_array[i];
    }
    for(int i=0;i<size;i++)
    {
        cout<<difference_array[i]<<" ";
    }
}