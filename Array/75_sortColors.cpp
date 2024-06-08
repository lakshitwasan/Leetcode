#include <iostream>
#include <vector>
using namespace std;

int sortColorDNF(vector<int> &arr, int n)
{

    // THIS IS DUTCH NATION FLAG ALGORITHM

    int low = 0, mid = 0, high = n - 1;

    while (mid < high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    int n = arr.size();

    sortColorDNF(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}