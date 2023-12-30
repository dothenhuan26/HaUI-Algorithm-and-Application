#include <bits/stdc++.h>
using namespace std;

void stn(int n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    cout << n << " ";
    stn(n - 1);
}

long long giaiThua(int n)
{
    if (n == 0)
        return 1;
    return n * giaiThua(n - 1);
}

int ucln(int a, int b)
{
    if (a % b == 0)
        return b;
    return ucln(b, a % b);
}

long long fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long toHop(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;
    return toHop(n - 1, k - 1) + toHop(n - 1, k);
}

long long tongN(int n)
{
    if (n == 0)
        return 0;
    return n + tongN(n - 1);
}

long long result(int n)
{
    if (n == 0)
        return 1;
    else
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + pow(n - i, 2) * result(i);
        }
        return sum;
    }
}

long long ackermann(int x, int y)
{
    if (x == 0 && y >= 0)
        return 1;
    if (x == 1 && y == 0)
        return 2;
    if (x >= 0 && y == 0)
        return x + 2;
    return ackermann(ackermann(x - 1, y), y - 1);
}

void chuyen(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << "=>" << c << endl;
        return;
    }
    chuyen(n - 1, a, c, b);
    chuyen(1, a, b, c);
    chuyen(n - 1, b, a, c);
}

int main()
{
    // stn(5);

    // cout << giaiThua(5) << endl;

    // cout << ucln(45, 27) << endl;

    // cout << fibonacci(20) << endl;

    // cout << toHop(5, 3) << endl;

    // cout << result(3);

    chuyen(3, 'A', 'B', 'C');

    return 0;
}