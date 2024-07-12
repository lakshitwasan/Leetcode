#include <bits/stdc++.h>
using namespace std;

bool containDuplicate_bruteForce(vector<int> arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }

    return false;
}

bool containDuplicates_Better(vector<int> arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return true;
        }
    }

    return false;
}

bool containDuplicate_Best(vector<int> arr)
{
    unordered_map<int, int> mp;

    for (auto &num : arr)
    {
        if (mp[num] > 0)
        {
            return true;
        }
        mp[num]++;
    }

    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Using Brute Force Method: " << (containDuplicate_bruteForce(arr) ? "Duplicates Found" : "No Duplicates") << endl;
    cout << "Using Better Method: " << (containDuplicates_Better(arr) ? "Duplicates Found" : "No Duplicates") << endl;
    cout << "Using Best Method: " << (containDuplicate_Best(arr) ? "Duplicates Found" : "No Duplicates") << endl;

    return 0;
}