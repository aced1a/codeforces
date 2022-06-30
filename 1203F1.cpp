//http://codeforces.com/problemset/problem/1203/F1
//solved
#include <bits/stdc++.h>
using namespace std;

#define PII pair<int,int>
#define st first
#define nd second

int n = 0;
int r = 0;

vector<PII> pos;
vector<PII> neg;


void input()
{
    cin >> n >> r;
    PII temp;
    for(int i=0;i<n;i++)
    {
        cin >> temp.st >> temp.nd;

        if(temp.nd >= 0)
            pos.push_back(temp);
        else {
            temp.st = max(temp.st, abs(temp.nd));
            neg.push_back(temp);
        }
    }
}

bool cmp(const PII& a, const PII& b)
{
    return (a.st + a.nd) > (b.st + b.nd);
}

bool solveForPos()
{
    for(auto e: pos)
    {
        if(r >= e.st) {
            r += e.nd;
        } else {
            return false;
        }
    }
    return true;
}

bool solveForNeg()
{
    for(auto e: neg)
    {
        if(r >= e.st && r + e.nd >= 0) {
            r += e.nd;
        } else {
            return false;
        }
    }
    return true;
}

int main()
{
    input();

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), cmp);



    if(solveForPos() && solveForNeg())
    {
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;
    }
    return 0;
}