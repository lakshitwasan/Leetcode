#include <iostream>
using namespace std;

int calculateDifference(int n, int m)
{
    int num1 = 0; // Initialize num1 to store the sum of non-divisible numbers.
    int num2 = 0; // Initialize num2 to store the sum of divisible numbers.

    for (int i = 1; i <= n; i++)
    {
        if (i % m != 0)
        {
            num1 += i; // Add i to num1 if i is not divisible by m.
        }
        else
        {
            num2 += i; // Add i to num2 if i is divisible by m.
        }
    }

    return num1 - num2; // Return the difference between num1 and num2.
}

int main()
{
    int n, m;
    cin >> n >> m;

    int result = calculateDifference(n, m);
    cout << result << endl;

    return 0;
}
