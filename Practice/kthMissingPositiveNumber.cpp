#include<bits/stdc++.h>
using namespace std;

int kthMissingNumber_BF(vector<int> arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else{
            break;
        }
    }
    return k;
}

int kthMissingNumber_BS(vector<int> arr, int k)
{

    // SOMEWHAT IDEA THIS TIME

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high)/2;

        int missing = arr[mid] - (mid+1);

        if (missing < k)
        {
            low = mid +1;
        }
        else
        {
            high = mid -1;
        }
    }
    return low +k ;

}

int main()
{

    vector<int> arr = {2,3,4,6};

    int k = 5;

    int ans1 = kthMissingNumber_BF(arr,k);
    int ans2 = kthMissingNumber_BS(arr,k);

    cout <<ans1 << endl;
    cout <<ans2 << endl;

    return -1;
}