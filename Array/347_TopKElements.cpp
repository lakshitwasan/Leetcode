#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> topKFrequent(vector<int> &arr, int k)
{

    int n = arr.size();
    map<int, int> mp;
    vector<int> result;
    vector<pair<int, int>> newArr;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto &el : mp)
    {
        newArr.push_back(make_pair(el.second, el.first));
    }
    sort(newArr.rbegin(), newArr.rend());

    for (int i = 0; i < newArr.size() && k != 0; i++)
    {
        result.push_back(newArr[i].second);
        k--;
    }

    return result;
}

int main()
{

    vector<int> arr = {1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3};

    arr = topKFrequent(arr, 2);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}