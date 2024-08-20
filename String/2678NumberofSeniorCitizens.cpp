#include <bits/stdc++.h>
using namespace std;

int countSeniors(vector<string> arr)
{
    int n = arr.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int age = (arr[i][11] - '0') * 10 + (arr[i][12] - '0');
        if (age > 60)
        {
            count++;
        }
    }

    return count;
}

int main()
{

    vector<string> arr;
    arr.push_back("7868190130M7522");
    arr.push_back("5303914400F9211");
    arr.push_back("9273338290F4010");
    int ans = countSeniors(arr);
    cout << ans << endl;

    return 0;
}