//http://codeforces.com/problemset/problem/1051/C
//solved
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

#define SET(i, val) output[e.second[i]] = val

int bin(vector<int>& v, int k)
{
    int a = 0, b = v.size()-1, c = 0;
    while(a<=b)
    {
        c = (a+b)/2;

        if(v[c] == k) return c;

        if(v[c] <= k)
            a = c+1;
        else
            b = c-1;
    }
    return v[c] <= k ? c+1 : c;
}

void input(vector<int>& v)
{   
    int n = 0;
    int val = 0;

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> val;
        v.push_back(val);
    }
}

bool isNotRepeat(vector<int>& sets, int val)
{
    int k = bin(sets, val);
    return !((k > 0 && sets[k-1] == val) ||
            (k < sets.size()-1 && sets[k+1] == val)); 
}

bool canDistributeRepeats(map<int, vector<int>>& repeats, vector<char>& output, int a, int b)
{
    if(a != b && repeats.size() > 0) {
        for(auto& e: repeats) {
            if(e.second.size() == 2) {
                SET(0,'A');
                SET(1,'B');
            } else {
                char s = ' ';
                if(a == b) {
                    for(int i = 0; i < e.second.size(); i++) {
                        SET(i, 'A');
                    }
                    continue;
                }
                if(a > b) {
                    b++;
                    SET(0,'B');
                    s = 'A';
                } else {
                    a++;
                    SET(0, 'A');
                    s = 'B';
                }
                for(int i=1;i<e.second.size();i++)
                    SET(i, s);
            }

        }
    } else if(a == b) {
         for(auto& e: repeats) {
            for(int i: e.second) {
                output[i] = 'A';
            }
         }
    }
    return a == b;
}

void distributeBySets(vector<int>& sets, vector<int>& sortedSets)
{
    int a = 0, b = 0;
    int k = 0;
    vector<char> output(sets.size());
    map<int,vector<int>> repeats;

    for(int i=0;i<sets.size();i++){
        if(isNotRepeat(sortedSets, sets[i])){
            if(a > b){
                b++;
                output[i] = 'B';
            } else {
                a++;
                output[i] = 'A';
            }
        } else {
            repeats[sets[i]].push_back(i);
        }
    }
    if(canDistributeRepeats(repeats,output, a, b)){
        cout << "YES\n";
        for(char e: output) cout << e;
        cout << endl;
    } else {
        cout << "NO\n";
    }
}

int main()
{
    int n = 0;
    vector<int> sets;
    vector<int> sortedSets;

    input(sets);
    copy(sets.begin(), sets.end(), back_inserter(sortedSets));
    sort(sortedSets.begin(), sortedSets.end());
    distributeBySets(sets, sortedSets);

    return 0;
}