#include <iostream>
//https://codeforces.com/problemset/problem/231/A
//solved

using namespace std;


int main(){
    int n = 0, k = 0, count = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        k = 0;
        for(int j=0,l=0;j<3;j++) {cin >> l; k+=l;}
        if(k>=2) count++;
    }
    cout << count;
}