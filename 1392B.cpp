#include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1392/B
//solved

using namespace std;

int main()
{
    int t = 0, n = 0;
    long long k = 0;

    cin >> t;

    int** arr = new int*[t];
    for(int i=0;i<t;i++) {
        cin >> n >> k;
        arr[i] = new int[n + 4];
        arr[i][0] = n; arr[i][1] = k % 2;
        int max = -1000000001, min = 1000000001;
        for(int j=4, t = 0;j<n+4;j++){
              cin >> t;
              if(t > max) {max = t;}
              if(t < min) {min = t;}
              arr[i][j] = t;
        }
        arr[i][2] = max;
        arr[i][3] = min;
    }

    for(int i=0;i<t;i++){
        long max = (arr[i][1] ? arr[i][2] : (arr[i][2] - arr[i][3]) - arr[i][2]);
        int f = (arr[i][1] ? 1: -1);

        for(int j=4;j<arr[i][0]+4;j++)
        {
            cout << max - f * arr[i][j] << ' ';
        }
        cout << endl;
    }

    for(int i=0;i<t;i++) delete[] arr[i];
    delete[] arr;
}