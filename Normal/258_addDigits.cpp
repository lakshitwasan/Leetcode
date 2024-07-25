#include <bits/stdc++.h>
using namespace std;

int sum(int num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num = num / 10;
    }

    return sum;
}

int addDigits(int num)
{
    while (num / 10)
    {
        num = sum(num);
    }
    return num;
}

int main()
{

    int num = 38;

    int ans = addDigits(num);

    cout << ans << endl;

    return 0;
}