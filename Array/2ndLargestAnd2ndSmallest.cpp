#include <iostream>
#include <vector>
using namespace std;

int secMax(vector<int> arr)
{

    if (arr.size() < 2)
    {
        return -1;
    }
    else
    {
        int max = INT32_MIN;
        int secMax = INT32_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            if (max < arr[i])
            {
                secMax = max;
                max = arr[i];
            }
            else if (secMax < arr[i] && arr[i] != max)
            {
                secMax = arr[i];
            }
        }
        return secMax;
    }
}

int secMin(vector<int> arr)
{

    if (arr.size() < 2)
    {
        return -1;
    }
    else
    {
        int min = INT32_MAX;
        int secMin = INT32_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            if (min > arr[i])
            {
                secMin = min;
                min = arr[i];
            }
            else if (secMin > arr[i] && arr[i] != min)
            {
                secMin = arr[i];
            }
        }
        return secMin;
    }
}

int main()
{
    vector<int> arr = {-1, -1, 5, -3, -1, -2, 3};

    cout << "Second Max: " << secMax(arr) << endl;
    cout << "Second Min: " << secMin(arr) << endl;

    return 0;
}