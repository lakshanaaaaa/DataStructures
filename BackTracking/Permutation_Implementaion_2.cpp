#include<iostream>
using namespace std;

void permutate_method_2(string str,int index,int size)
{
    if(index==size)
    {
        cout<<str<<"\n";
    }
    else{
        for(int choice=index;choice<size;choice++)
        {
            swap(str[index],str[choice]);
            permutate_method_2(str,index+1,size);
            swap(str[index],str[choice]);
        }
    }
}


int main()
{
    string str;
    cin>>str;
    permutate_method_2(str,0,str.size());
}