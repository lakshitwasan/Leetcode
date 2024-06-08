#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveOnes(vector<int> arr, int n)
{

    int count = 0, maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            if (maxCount < count)
            {
                maxCount = count;
            }
        }
        else if (arr[i] == 0)
        {
            count = 0;
        }
    }

    return maxCount;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0};

    int n = arr.size();

    int ans = maxConsecutiveOnes(arr, n);

    cout << ans;

    return 0;
}