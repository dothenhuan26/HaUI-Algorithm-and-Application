#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double findMaxWeight(pair<string, double> cars[], int l, int r)
{
    if (l == r)
        return cars[l].second;
    int m = (l + r) / 2;
    double left = findMaxWeight(cars, l, m);
    double right = findMaxWeight(cars, m + 1, r);
    return max(left, right);
}

void merge(pair<string, double> cars[], int l, int m, int r)
{
    vector<pair<string, double>> x(cars + l, cars + m + 1);
    vector<pair<string, double>> y(cars + m + 1, cars + r + 1);
    int i = 0, j = 0;

    while (i < x.size() && j < y.size())
    {
        if (x[i].second <= y[j].second)
        {
            cars[l] = x[i];
            l++;
            i++;
        }
        else
        {
            cars[l] = y[j];
            l++;
            j++;
        }
    }

    while (i < x.size())
    {
        cars[l] = x[i];
        l++;
        i++;
    }
    while (j < y.size())
    {
        cars[l] = y[j];
        l++;
        j++;
    }
}

void mergeSort(pair<string, double> cars[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(cars, l, m);
    mergeSort(cars, m + 1, r);
    merge(cars, l, m, r);
}

int findIndexToInsert(pair<string, double> cars[], int l, int r, pair<string, double> car)
{
    if (l > r)
        return l;
    int m = (l + r) / 2;
    if (cars[m].second == car.second)
        return m;
    else if (cars[m].second > car.second)
    {
        return findIndexToInsert(cars, l, m - 1, car);
    }
    else
    {
        return findIndexToInsert(cars, m + 1, r, car);
    }
}

int main()
{
    pair<string, double> cars[7] = {
        {"0001", 5.6},
        {"0002", 7.8},
        {"0003", 2.3},
        {"0004", 11.5},
        {"0005", 1.8},
        {"0006", 9.11},
        {"0007", 4.7},
    };

    cout << "Xe co trong tai lon nhat: " << findMaxWeight(cars, 0, 6) << endl;
    mergeSort(cars, 0, 6);
    for (auto x : cars)
        cout << x.first << " " << x.second << endl;
    pair<string, double> car = {"0175", 5.1};
    cout << findIndexToInsert(cars, 0, 6, car) << endl;
    return 0;
}