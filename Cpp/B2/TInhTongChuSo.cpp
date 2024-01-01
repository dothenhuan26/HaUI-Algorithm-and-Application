#include <bits/stdc++.h>
using namespace std;

int tongChuSo(int n)
{
    if (n / 10 == 0)
        return n;
    return n % 10 + tongChuSo(n / 10);
}

int tongChuSoLoop(int n)
{
    int sum = 0;
    while (n / 10 != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    sum += n;
    return sum;
}

int main()
{
    cout << tongChuSo(2) << endl;
    cout << tongChuSoLoop(2) << endl;

    return 0;
}