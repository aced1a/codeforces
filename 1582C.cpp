//https://codeforces.com/contest/1582/problem/C
//solved
#include <bits/stdc++.h>

using namespace std;

int solve(string s, int n)
{
    int counter = 0, a = 0, b = n-1, result = n;

    for(char c=0;c<26;c++){
        counter = 0, a = 0, b = n-1;
        while(a<b)
        {
            if(s[a] != s[b]){
                if(s[a] == ('a'+c)) {
                    a++; counter++;
                }
                else if(s[b] == ('a'+c)){
                    b--; counter++;
                } else {
                    counter = n; break;
                }
            } else{
                a++; b--;
            }
        }
        result = min(result, counter);
    }
    return result != n ? result :-1;
}

int main(){
    int t = 0, n = 0;
    string s;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        cin >> s;
        cout << solve(s,n) << endl;
    }
}