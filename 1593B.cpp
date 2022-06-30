//https://codeforces.com/problemset/problem/1593/B
//solved
#include <bits/stdc++.h>

using namespace std;

int search(string& s, char c, int i){
    while(i >= 0){
        if(s[i] == c) break;
        i--;
    }
    return i;
}

int solve(string s){
    int n = s.size(), res = 0;
   
    int zero = search(s, '0', n-1), five = search(s,'5',n-1);

    res = max(
        max(search(s,'0',zero-1),search(s,'5',zero-1)),
        max(search(s,'2',five-1),search(s,'7',five-1))
        );

    return n - res - 2;
}

int main()
{
    int t = 0;
    string s;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> s;
        cout << solve(s) << endl;
    }
}