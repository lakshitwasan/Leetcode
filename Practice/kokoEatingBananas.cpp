#include<bits/stdc++.h>
using namespace std;

int biggestPile(vector<int> arr) {
    int max = INT32_MIN;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

long long totalHours(vector<int> piles, int hour) {
    long long totalHours = 0;

    for (int i = 0; i < piles.size(); i++) {
        totalHours += (ceil((double)piles[i] / (double)hour));
    }

    return totalHours;
}

int kokoEatingBanana_BS(vector<int> piles, int hours)
{
    int maxPile = biggestPile(piles);

    int low = 1;
    int high = maxPile;

    while (low <=high)
    {
        int mid = (low+high)/2;

        long long reqTime = totalHours(piles, mid);

        if (reqTime <= hours)
        {
            high = mid -1 ;
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

    // vector<int> arr = {7,15,6,3};
    vector<int> arr = {805306368,805306368,805306368};
    int h = 1000000000;

    int ans = kokoEatingBanana_BS(arr, h);

    cout << ans;

    return -1;
}