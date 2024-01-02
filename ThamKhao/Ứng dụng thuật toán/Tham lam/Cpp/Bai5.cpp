#include <bits/stdc++.h>
using namespace std;

int k, n;
pair<int, int> x[100];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    cin >> k >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i].first >> x[i].second;
    }

    sort(x, x + n, cmp);
    int maxWeight = 0;
    int i = 0;
    while (i < n)
    {
        cout << i << " " << k << endl;
        if (k - x[i].second < 0)
            i++;
        else
        {
            maxWeight += x[i].first;
            k -= x[i].second;
            if (k == 0)
                break;
            i++;
        }
    }

    cout << "Khoi luong lon nhat co the dat duoc la: " << maxWeight << endl;

    return 0;
}