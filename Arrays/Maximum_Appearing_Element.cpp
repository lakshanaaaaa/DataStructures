#include<iostream>
using namespace std;
int brute_Force(int left[],int right[],int size)
{
    int freq[100]={0}; //maximum ending element considered as below 100
    for(int i=0;i<size;i++)
    {
        for(int j=left[i];j<=right[i];j++)
        {
            freq[j]++;
        }
    }
    int res=0;
    for(int i=1;i<100;i++)
    {
        if(freq[res]<freq[i])
        {
            res=i;
        }
    }
    return res;
}

int Efficient(int left[],int right[],int size)
{
    int freq[100]={0};
    for(int i=0;i<size;i++)
    {
        freq[left[i]]+=1;
        freq[right[i]+1]-=1;
    }
    int res=0;
    for(int i=1;i<size;i++)
    {
        freq[i]+=freq[i-1];
        if(freq[i]>freq[res])
        {
            return freq[i];
        }
    }
    return -1;
}
int main()
{
    int size;
    cin>>size;
    int left[size];
    int right[size];
    for(int i=0;i<size;i++)
    {
        cin>>left[i];
    }
    for(int i=0;i<size;i++)
    {
        cin>>right[i];
    }
    cout<<brute_Force(left,right,size);
}