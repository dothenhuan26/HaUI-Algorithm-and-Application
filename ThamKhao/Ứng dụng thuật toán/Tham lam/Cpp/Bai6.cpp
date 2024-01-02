#include <bits/stdc++.h>
using namespace std;

// 50 5 21 33 2 7 30 19 22 16 4 18

bool cmp(pair<double, double> a, pair<double, double> b)
{
    return a.first < b.first;
}

int main()
{
    int k, n;
    cin >> k >> n;
    pair<double, double> x[n];
    for (auto &i : x)
        cin >> i.first >> i.second;

    sort(x, x + n, cmp);

    double minWeight = 0;
    int i = 0;
    while (i < n)
    {
        if (k - x[i].second < 0)
        {
            ++i;
            continue;
        }
        minWeight += x[i].first;
        k -= x[i].second;
        ++i;
    }

    cout << minWeight << endl;

    return 0;
}