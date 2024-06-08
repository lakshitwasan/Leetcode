#include <iostream>
#include <vector>
using namespace std;

int findSingleNumber(vector<int> arr, int n)
{
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ arr[i];
    }

    return XOR;
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 2, 5, 5, 6, 6, 7, 8, 9, 8, 9};

    int n = arr.size();

    int ans = findSingleNumber(arr, n);

    cout << ans << endl;

    return 0;
}