#include <bits/stdc++.h>
using namespace std;

// 5
// 8 9 10 11 12
// 8.5 11 11.5 12.5 13

bool cmp(pair<double, double> a, pair<double, double> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    pair<double, double> x[n];
    int flag[n]{0};
    for (auto &x : x)
        cin >> x.first;
    for (auto &x : x)
        cin >> x.second;

    sort(x, x + n, cmp);

    for (auto i : x)
        cout << i.first << " ";
    cout << endl;
    for (auto i : x)
        cout << i.second << " ";
    cout << endl;

    int cnt = 1, i = 0;
    flag[i] = 1;

    for (int j = 1; j < n; j++)
    {
        if (x[j].first >= x[i].second)
        {
            cnt++;
            i = j;
            flag[i] = 1;
        }
    }

    for (auto k : flag)
        cout << k << " ";

    return 0;
}