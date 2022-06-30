//https://codeforces.com/contest/1582/problem/B
//solved
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0, n = 0, ones = 0, zeros = 0;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        ones = 0, zeros = 0;
        cin >> n;
        for(int j=0,a=0;j<n;j++)
        {
            cin >> a;
            if(a == 0) zeros++;
            else if(a == 1) ones++;
        }
        cout << fixed << setprecision(0) << ones * pow(2,zeros) << endl;
    }
    return 0;
}