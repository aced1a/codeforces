//http://codeforces.com/problemset/problem/1213/B
//solved
#include <bits/stdc++.h>
using namespace std;

void input(vector<vector<int>>& v)
{
    int n = 0, k = 0, temp = 0;
    cin >> n;
    v.resize(n);

    for(int i=0;i<n;i++) {
        cin >> k;
        for(int j=0;j<k;j++) {
            cin >> temp;
            v[i].push_back(temp);
            //cin >> v[i][j];
        }
    }
}

int getBadPricesCount(vector<int>& v)
{
    int count = 0, min = v[v.size()-1];
    for(int i=v.size()-2;i>=0;i--) {
        if(v[i] < min) 
            min = v[i];
        else if(v[i] > min)
            count++;
    }
    return count;
}

void processBadPrices(vector<vector<int>>& v) {
    for(auto& e: v) {
        cout << getBadPricesCount(e) << endl;
    }
}

int main()
{
    vector<vector<int>> v;
    input(v);
    processBadPrices(v);
    return 0;
}