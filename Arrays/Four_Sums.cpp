#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Four_sums(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < size; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;
            int lo = j + 1;
            int hi = size - 1;
            while (lo < hi)
            {
                long long sum = arr[i] + arr[j] + arr[lo] + arr[hi];
                if (sum == target)
                {
                    res.push_back({arr[i], arr[j], arr[lo], arr[hi]});
                    lo++;
                    hi--;
                    while (lo < hi && arr[lo] == arr[lo - 1])
                        lo++;
                    while (lo < hi && arr[hi] == arr[hi + 1])
                        hi--;
                }
                else if (sum < target)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
            }
        }
    }
    return res;
}

vector<vector<int>> Four_sum_method_2(vector<int> arr, int target)
{
    int size = arr.size();
    set<vector<int>> res;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            set<int> hashset;
            for (int k = j + 1; k < size; k++)
            {
                int third = target - (arr[i] + arr[j] + arr[k]);
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], third};
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}
int main()
{
    int size, sum;
    cin >> size >> sum;
    vector<int> v(size);
    for (int i = 0; i < size; i++)
        cin >> v[i];
    vector<vector<int>> ans = Four_sums(v, sum);
    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << "\n";
    }
}