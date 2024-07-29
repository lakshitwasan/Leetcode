#include <bits/stdc++.h>
using namespace std;

int numTeams(vector<int> &rating)
{
    int n = rating.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = i; k < n; k++)
            {
                if (((rating[i] < rating[j]) && (rating[j] < rating[k])) || ((rating[i] > rating[j]) && (rating[j] > rating[k])))
                {
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}