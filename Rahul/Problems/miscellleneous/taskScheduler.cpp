#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    char arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int h[26];
    for (int i = 0; i < n; i++)
        h[arr[i] - '0']++;

    sort(h, h + 26);

    int mx = h[25] - 1;
    int idle_time = mx * k;

    for (int i = 24; i >= 0; i--)
    {
        idle_time -= min(mx, h[i]);
    }

    cout << (idle_time > 0) ? n + idle_time : n;
}