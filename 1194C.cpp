//https://codeforces.com/problemset/problem/1194/C
//solved
#include <bits/stdc++.h>
using namespace std;

int bin(string& s, char ch)
{
    int a = 0, b = s.size()-1, c = 0;
    while(a<=b)
    {
        c = (a+b)/2;

        if(s[c] == ch) return c;

        if(s[c] < ch)
            a = c+1;
        else
            b = c-1;
    }
    return -1;
}

bool solve(string& s, string& t, string& p)
{
    int count = 0;
    for(int i=0, j=0, k=-1; j<t.size();i++, j++)
    {
        if(s.size() < i || s[i] != t[j])
        {
            k = bin(p, t[j]);
            if(k == -1)
            {
                return false;
            } 
            p.erase(k, 1);
            i--; count++;
        }
    }
    return s.size() + count == t.size();
}

int main()
{
    int n = 0;
    string s = "", t = "", p = "";
    vector<string> ans;

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s >> t >> p;

        //sort(s.begin(), s.end()); sort(t.begin(),t.end());
        sort(p.begin(),p.end());

        if(solve(s, t, p)) {
            ans.push_back("YES"); 
        } else {
            ans.push_back("NO");
        }
    }

    for(string a: ans)
        cout << a << endl;
    return 0;
}