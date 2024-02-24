#include <bits/stdc++.h>
using namespace std;

// Chuyen n dia tu A sang C voi B la trung gian
// Chuyen n-1 dia tu A sang B
// Chuyen 1 dia tu A sang C
// Chuyen n-1 dia tu B sang A

void chuyen(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Chuyen 1 dia tu: " << a << " => " << c << endl;
        return;
    }
    chuyen(n - 1, a, c, b);
    chuyen(1, a, b, c);
    chuyen(n - 1, b, a, c);
}

int main()
{
    chuyen(3, 'A', 'B', 'C');
    return 0;
}