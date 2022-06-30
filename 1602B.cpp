//https://codeforces.com/problemset/problem/1602/B
//solved
#include <bits/stdc++.h>

using namespace std;

int a[13][2000];
int c[13][2001];
int n = 0, l = 0;

void solve()
{
    for(int i=1;i<=l;i++)
    {
        for(int j=0,t = 0;j<n;j++)
        {
            t = a[i-1][j];
            if(c[i-1][t] != t){
                a[i][j] = c[i-1][t];
                c[i][c[i-1][t]]++; 
                
            } else {
                a[i][j] = t;
                c[i][t]++;
            }
        }
    }
}

int main()
{
    memset(a, 0, sizeof(int) * 13 * 2000);
    int t = 0, q = 0, x = 0, k = 0;
    cin >> t;
    for(int i=0;i<t;i++)
    {   
        memset(c, 0, sizeof(int) * 13 * 2001);
        cin >> n; l = int(ceil(log2(n))) + 1;
        for(int j=0;j<n;j++)
        {
            cin >> a[0][j];
            c[0][a[0][j]]++;
        }
        solve();
        cin >> q;
        for(int j=0;j<q;j++)
        {
            cin >> x >> k;
            k = k > l ? l : k;
            cout << a[k][x-1] << endl;
        }
    }
    return 0;
}