#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int countStudents(vector<int> arr, int pages)
{
    int n = arr.size();

    int student = 1;
    int pageStudent = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageStudent + arr[i] <= pages)
        {
            pageStudent += arr[i];
        }
        else
        {
            student++;
            pageStudent = arr[i];
        }
    }
    return student;
}

int allocateBooks_Linear(vector<int> arr, int m)
{
    int n = arr.size();

    if (m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int i = low; i <= high; i++)
    {
        if (countStudents(arr, i) == m)
        {
            return i;
        }
    }

    return low;
}

int allocateBooks_BS(vector<int> arr, int m)
{
    int n = arr.size();

    if (m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (countStudents(arr, mid) <= m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{

    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;

    // int ans = allocateBooks_Linear(arr, m);
    int ans = allocateBooks_BS(arr, m);

    cout << ans;

    return 0;
}