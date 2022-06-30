//https://codeforces.com/contest/27/problem/C
//solved
#include <bits/stdc++.h>

using namespace std;
int* a;

void solve(int n)
{
    if(n < 3) { cout << 0 << endl; return; }
    int max = 0, min = 0, last = 0;
    for(int i=0;i<n;i++){
        if(a[max] != a[min])
        {
            if(max > min ? a[i] < a[max] : a[i] > a[min]) {
                last = i;
                break;
            }
        }
        if(a[i] > a[max])
            max = i;
        else if(a[i] < a[min])
            min = i;
    }
    if(last == 0) 
        cout << 0 << endl;
    else {
        cout << 3 << endl;
        cout << (min < max ? min : max) + 1 << " " << (max > min ? max : min) + 1 << " " << last + 1 << endl;
    }
}

int main(){
    int n = 0;
    cin >> n;
    a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    solve(n);
    delete[] a;
    return 0;
}