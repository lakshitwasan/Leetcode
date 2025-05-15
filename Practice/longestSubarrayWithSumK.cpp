#include<bits/stdc++.h>
using namespace std;

int subarray_bf1(vector<int> &arr, int k)
{

    // TIME COMPLEXITY: O(N^3) & SPACE COMPLEXITY: O (1)

    int n = arr.size();
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int w = i; w <= j; w++)
            {
                sum += arr[w];
            }
            if (sum == k)
            {
                length = max(length, j-i+1);
            }
            
        }
        
    }
    return length;
}

int subarray_bf2(vector<int> &arr, int k)
{

    // TIME COMPLEXITY: O(N^2) & SPACE COMPLEXITY: O (1)

    int n = arr.size();
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
        
            sum += arr[j];
            if (sum == k)
            {
                length = max(length, j-i+1);
            }
            if (sum >k)
            {
                break;
            }
            
        }
        
    }
    return length;
}

int subarray_hashMap(vector<int> &arr, int k)
{

    // ORDERED MAP: TIME COMPLEXITY: O(N x LOGN)& SPACE O(N)
    // UNORDERED MAP: TIME COMPLEXITY: [BEST] O(N x 1) [WORST] O(N x N) & SPACE O(N)

    // THIS IS BEST FOR +VE AND -VE BUT NOT FOR POSITIVE AND ZEROES

    int n = arr.size();
    int maxLength = 0;
    int sum = 0;
    unordered_map<int,int> prefixSum;
    
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLength = max(maxLength, i+1);
        }
        int rem = sum - k;

        if (prefixSum.find(rem) != prefixSum.end())
        {
            int length = i - prefixSum[rem];
            maxLength = max(maxLength, length);
        }
        else if(prefixSum.find(rem) == prefixSum.end())
        {
            prefixSum[sum] = i;
        }
    }

    return maxLength;
}

int subarray_SW(vector<int> &arr, int k)
{

    //  TIME COMPLEXITY: O(N + N) & SPACER COMPLEXITY : O(1)

    // THIS SOLUTION IS BEST FOR POSITIVES AND ZEROES BUT NOT FOR POSITIVES AND NEGATIVES

    int n = arr.size();
    int length = 0;
    int left = 0;
    int right = 0;
    int sum = 0; 

    while (right<n)
    {
        sum+= arr[right];

        while (left<=right && sum >k)
        {
            sum -= arr[left];
            left++;
        }

        if(sum == k)
        {
            length = max(length, right - left + 1);
        }

        right++;
    }
    

    return length;
}


int main()
{
    vector<int> arr= {1,2,3,1,1,1,1,3,3};
    int k = 6;

    int ans1 = subarray_bf1(arr,k);
    int ans2 = subarray_bf2(arr,k);
    int ans3 = subarray_hashMap(arr,k);
    int ans4 = subarray_hashMap(arr,k);
    
    cout << "Answer with BF1: " << ans1 << endl;
    cout << "Answer with BF2: " << ans2 << endl;
    cout << "Answer with hashmap: " << ans3 << endl;
    cout << "Answer with sliding window: " << ans4 << endl;
    return 0;
}