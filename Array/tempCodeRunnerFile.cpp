void RotateRight(vector<int> &arr, int n, int k)
{
    Reverse(arr, n - k - 1, n);
    Reverse(arr, 0, k);
    Reverse(arr, 0, n);
}