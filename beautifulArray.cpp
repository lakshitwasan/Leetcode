// static int findBeauty(int[] arr) {
//         Map<Integer, Integer> hm = new HashMap<>();
//         for (int num : arr) {
//             hm.put(num, hm.getOrDefault(num, 0) + 1);
//         }

//         int maxf = 0;
//         for (int freq : hm.values()) {
//             maxf = Math.max(maxf, freq);
//         }

//         return maxf;
//     }

//     public static int findSubarrayBeauty(int[] arr, int arrbeauty) {
//         int min_sa_length = Integer.MAX_VALUE;
//         int start = 0;
//         Map<Integer, Integer> currentfreq = new HashMap<>();

//         for (int end = 0; end < arr.length; end++) {
//             int num = arr[end];
//             currentfreq.put(num, currentfreq.getOrDefault(num, 0) + 1);

//             while (hasMaxFrequency(currentfreq, arrbeauty)) {
//                 min_sa_length = Math.min(min_sa_length, end - start + 1);
//                 int start_ele = arr[start];
//                 currentfreq.put(start_ele, currentfreq.get(start_ele) - 1);
//                 if (currentfreq.get(start_ele) == 0) {
//                     currentfreq.remove(start_ele);
//                 }
//                 start++;
//             }
//         }

//         return min_sa_length;
//     }

//     public static boolean hasMaxFrequency(Map<Integer, Integer> currentfreq, int arrbeauty) {
//         for (int freq : currentfreq.values()) {
//             if (freq == arrbeauty) {
//                 return true;
//             }
//         }
//         return false;
//     }
// }

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findBeauty(vector<int> arr)
{
    map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            mp[arr[i]]++;
        }

        mp[arr[i]] = 0;
    }

    int maxf = 0;

    for (auto &el : mp)
    {
        maxf = max(maxf, el.second);
    }
}

int main()
{

    return 0;
}