#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int t;
    cin >> t;

    int lo = 0, hi = n - 1;
    int res = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == t)
        {
            res = mid;
            hi = mid - 1;
        }
        else if (arr[mid] < t)
        {
            if (arr[res] != t) res = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << res << endl;
}