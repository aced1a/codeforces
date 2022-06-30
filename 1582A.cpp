//https://codeforces.com/contest/1582/problem/A
//solved
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t = 0, a = 0, b = 0, c = 0;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> a >> b >> c;
        cout << ((a+c) % 2) << endl;
    }
    return 0;
}