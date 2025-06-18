#include<bits/stdc++.h>
using namespace std;

int maxNo(vector<int> arr)
{
    int max = INT32_MIN;

    for(int i = 0; i < arr.size(); i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    
    return max;
}

int sumOfArray(vector<int> arr)
{
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

int calculateDays(vector<int> loads, int capacity)
{
    int load = 0;
    int day = 1;
    for (int i = 0; i < loads.size(); i++)
    {
        
        if ((load + loads[i]) > capacity )
        {
            load = loads[i];
            day += 1;
        }
        else
        {
            load +=loads[i];
        }
    }

    return day;
    
}

int  minCapacity(vector<int>loads, int days)
{
    int low = maxNo(loads);
    int high = sumOfArray(loads);

    while (low <=high)
    {
        int mid = (low + high)/2;

        if (calculateDays(loads, mid) <= days)
        {
            high = mid -1;
        }
        else
        {
            low = mid +1;
        }
        
    }
    return low;

}

int main()
{

    vector<int> loads = {5,4,5,2,3,4,5,6};

    int days = 5;

    int ans = minCapacity(loads, days);

    cout <<ans;


    return -1;
}