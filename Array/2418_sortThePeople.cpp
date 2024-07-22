#include <bits/stdc++.h>
using namespace std;

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{

    vector<pair<string, int>> v;

    for (int i = 0; i < names.size(); i++)
    {
        v.push_back({names[i], heights[i]});
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b)
         { return a.second > b.second; });

    vector<string> ans;

    for (auto i : v)
    {
        ans.push_back(i.first);
    }

    return ans;
}

int main()
{

    vector<string> names = {"Mary", "John", "Emma"};
    vector<int> heights = {180, 165, 170};

    vector<string> ans = sortPeople(names, heights);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}