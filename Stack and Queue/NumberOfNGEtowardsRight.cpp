#include <bits/stdc++.h>
using namespace std;

vector<int> noOfNGE(vector<int> arr, vector<int> indices)
{

    // TIME COMPLEXITY: O(Q x N) % SPACE COMPLEXITY: O(Q)

    // THIS IS THE BRUTE FORCE APPROACH I DO NOT KNOW HOW TO DO IT USING STACK RIGHT NOW

    int n = arr.size();
    int q = indices.size();
    vector<int> result(q, 0);

    for (int i = 0; i < q; i++)
    {
        int index = indices[i];

        for (int j = index + 1; j < n; j++)
        {
            if (arr[j] > arr[index])
            {
                result[i]++;
            }
        }
    }

    return result;
}

int main()
{

    return 0;
}