//https://codeforces.com/contest/1203/problem/B
//solved
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& sides) {
    int s = sides[0] * sides[sides.size()-1];
    for(int i=1;i<sides.size()/2;i++)
        if(sides[i]*sides[sides.size()-i-1] != s)
            return false;

    return true;
}

bool pairUp(vector<int>& a, int n, vector<int>& sides)
{
    for(int j=1;j<4*n;j+=2)
    {
        if(a[j] == a[j-1])
            sides.push_back(a[j]);
        else {
           return false;
        }
    }
    return true;
}

int main()
{
    int q = 0, n = 0;
    vector<string> ans;

    cin >> q;
    for(int i=0;i<q;i++)
    {
        vector<int> a;
        vector<int> sides;

        cin >> n;

        for(int j=0, temp;j<4*n;j++) { 
            cin >> temp;
            a.push_back(temp);
        }
        
        sort(a.begin(), a.end());

        
        if(pairUp(a, n, sides) && solve(sides)) {
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }

    }

    for(string s: ans)
            cout << s << endl;


    return 0;
}