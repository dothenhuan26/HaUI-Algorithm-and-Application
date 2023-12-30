#include <bits/stdc++.h>
using namespace std;

void bai1()
{
    int n, i;
    cin >> n;
    char a[n + 1]{'a'};
    for (int i = 1; i <= n; i++)
        a[i] = 'a';
    do
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        i = n;
        while (i >= 1 && a[i] == 'b')
        {
            a[i] = 'a';
            i--;
        }
        if (i >= 1)
        {
            a[i] = 'b';
        }

        cout << endl;
    } while (i >= 1);
}

void bai2()
{
    int i, n = 6, k = 4;
    string str[6 + 1] = {"", "tam", "toan", "trang", "cong", "trung", "tu"};
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        a[i] = i;

    do
    {
        for (int i = 1; i <= k; i++)
            cout << str[a[i]] << " ";
        i = k;
        while (i >= 1 && a[i] == n - k + i)
            i--;
        if (i >= 1)
        {
            a[i]++;
            i++;
            while (i <= k)
            {
                a[i] = a[i - 1] + 1;
                i++;
            }
        }
        cout << endl;
    } while (i >= 1);
}

void bai3()
{
    int n = 6, i;
    string str[6 + 1] = {"", "tam", "toan", "trang", "cong", "trung", "tu"};
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    do
    {
        for (int i = 1; i <= n; i++)
            cout << str[a[i]] << " ";

        i = n - 1;
        while (i >= 1 && a[i] > a[i + 1])
            i--;

        if (i >= 1)
        {
            int j = n;
            while (a[i] > a[j])
                j--;
            swap(a[i], a[j]);
            i++;
            int r = n;
            while (i < r)
            {
                swap(a[i], a[r]);
                i++;
                r--;
            }
        }
        cout << endl;
    } while (i >= 1);
}

int main()
{
    // bai1();
    // bai2();
    bai3();

    return 0;
}