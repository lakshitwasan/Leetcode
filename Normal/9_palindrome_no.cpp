#include <iostream>
using namespace std;

class solution
{
public:
    bool isPlalindrome(int x)
    {

        int temp = x;

        int reversed = 0;

        while (temp > 0)
        {
            reversed = reversed * 10 + temp % 10;
            temp = temp / 10;
        }

        if (reversed == x)
            return true;

        return false;
    }
};

int main()
{
    solution n;

    bool res = n.isPlalindrome(12321);

    cout << res;

    return 0;
}