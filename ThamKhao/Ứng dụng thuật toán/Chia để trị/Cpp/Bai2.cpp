#include <bits/stdc++.h>
using namespace std;

void merge(double a[], int l, int m, int r)
{
    vector<double> x(a + l, a + m + 1);
    vector<double> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size())
    {
        if (x[i] <= y[j])
        {
            a[l] = x[i];
            l++;
            i++;
        }
        else
        {
            a[l] = y[j];
            l++;
            j++;
        }
    }
    while (i < x.size())
    {
        a[l] = x[i];
        l++;
        i++;
    }
    while (j < y.size())
    {
        a[l] = y[j];
        l++;
        j++;
    }
}

void mergeSort(double a[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main()
{
    double a[15] = {5.4, 11.2, 49.12, 28.64, 11.4, 4.9, 8.112, 9.1001, 41.23, 19.41, 2.15, 12.13, 52.1, 55.9, 6.8};

    mergeSort(a, 0, 14);

    for (auto x : a)
        cout << x << " ";

    return 0;
}