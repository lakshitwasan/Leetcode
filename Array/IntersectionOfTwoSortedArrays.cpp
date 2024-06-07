#include <iostream>
#include <vector>
using namespace std;

vector<int> Intersec(vector<int> arr1, vector<int> arr2)
{
    int i = 0;
    int j = 0;

    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> arr3;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else // if (arr1[i] == arr2[j])
        {
            if (arr3.empty() || arr3.back() != arr1[i])
            {
                arr3.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    return arr3;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 4, 4, 4, 4, 4, 5, 5, 44};
    vector<int> arr2 = {2, 3, 4, 4, 5, 69, 420};

    vector<int> arr3 = Intersec(arr1, arr2);

    for (auto &i : arr3)
    {
        cout << i << " ";
    }

    return 0;
}
