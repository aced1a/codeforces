#include <bits/stdc++.h>

using namespace std;

#define SIZE 400001

int n, a[SIZE], b[SIZE], c[SIZE];

int solve()
{
    int k = 0, top = n-1, l = 0, count = 1;
    for(int i=n;i>0;i--)
    {
        k = i + b[i];
        for(top;top>=(k-a[k]);top--)
        {
            c[top] = i;
        }
        if(top == i-1) return -1;
    }
    while(l != n) { a[count++] = l; l = c[l];}
    return count - 1;
}

int main()
{
    int k = 0, count = 1;
    cin >> n;

    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    k = solve();
    cout << k << endl;
    if(k != -1) {
        for(int i=k;i>0;i--)
            cout << a[i] << ' ';
    }

    return 0;
}