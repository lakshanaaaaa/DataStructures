#include <iostream>
using namespace std;

void count_Frequency(int arr[], int size)
{
    int freq = 1;
    int i = 1;
    while (i < size)
    {
        while (i < size && arr[i] == arr[i - 1])
        {
            freq++;
            i++;
        }
        cout << arr[i-1] << " : " << freq<<"\n";
        i++;
        freq = 1;
    }
    if (size == 1 || arr[size - 1] != arr[size - 2])
    {
        cout << arr[size - 1] << " : " << 1;
    }
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    count_Frequency(arr,size);
}