#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int minTaps(int n, vector<int> &ranges)
{
    int idxLeft, idxRight;

    int temp[n + 1];
    memset(temp, -1, sizeof(temp));

    for (int i = 0; i <= n; i++)
    {
        idxLeft = max(0, i - ranges[i]);
        idxRight = min(n, i + ranges[i]);
        temp[idxLeft] = max(idxRight, temp[idxLeft]);
    }

    int steps = temp[0];
    int maxReach = temp[0];
    int taps = 1;

    if (maxReach == 0)
        return -1;
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
            return taps;

        maxReach = max(maxReach, temp[i]);

        steps--;
        if (steps == 0)
        {
            if (maxReach <= i)
                return -1;
            taps++;

            steps = maxReach - i;
        }
    }

    return -1;
}