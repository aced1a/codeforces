#include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/50/A
//solved


using namespace std;

int main()
{
    int n = 0, m = 0, count = 0;
    cin >> n >> m;

    int* rows = new int[n];
    memset(rows, 0, n * sizeof(int));

    for(int i = 0;i<n;i++)
    {
        while(true) 
        {
            if(m-rows[i] >= 2)
                {rows[i] += 2; count ++;}
            else if(i != n-1 && m-rows[i] == 1 && rows[i+1] != m)
                {rows[i]++; rows[i+1]++; count++;}
            else 
                break;
        } 
    }
    cout << count;
    delete[] rows;
}