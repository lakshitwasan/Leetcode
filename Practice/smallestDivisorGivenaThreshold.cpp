#include <bits/stdc++.h>
using namespace std;

    int maxNo(vector<int> arr) {
        int max = INT32_MIN;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        return max;
    }

    int calculateDivisorSum(vector<int> arr, int divisor) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += ceil((double)arr[i] / (double)divisor);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int max = maxNo(nums);

        int low = 1;
        int high = max;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (calculateDivisorSum(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

int main()
{
    vector<int> arr = {8, 4,2,3};

    int t = 10;

    int ans = smallestDivisor(arr,t);

    cout << ans;

    return -1;
}