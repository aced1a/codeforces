//https://codeforces.com/contest/27/problem/B
//Solved
#include <bits/stdc++.h>

using namespace std;
int r[51][51];
int n;

void solve()
{
    int x = 0, y = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i != j && r[i][j] == 0){
                x = i; y = j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(r[x][i] * r[y][i] < 0){
            if(r[x][i] > r[y][i])
                cout << x << " " << y << endl;
            else
                cout << y << " " << x << endl;
            return;
        }
    }
    cout << x << " " << y << endl;
}

int main(){
    memset(r, 0, sizeof(int) * 51 * 51);
    int x = 0, y = 0;
    cin >> n;
    for(int i=0;i<n*(n-1)/2-1;i++){
        cin >> x >> y;
        r[x][y] = 1; r[y][x] = -1;
    }
    solve();
    return 0;
}