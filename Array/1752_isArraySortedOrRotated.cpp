#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> arr)
{
    int count = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            count++;
        }
    }

    if (arr[0] < arr[arr.size() - 1])
    {
        count++;
    }

    return count <= 1;
}

int main()
{
    vector<int> arr = {2, 1, 3, 4};

    bool ans = isSorted(arr);

    cout << (ans ? "True" : "False");

    return 0;
}