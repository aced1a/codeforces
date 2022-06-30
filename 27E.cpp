//solved
#include <bits/stdc++.h>

using namespace std;

int prime[] = {0,1,2,3,5,7,11,13,17,19, 23, 29};
long double num[1001][11];


long double f(int n, int k) 
{
    if(num[n][k]) return num[n][k];

    int i = 1;
    long double number = 0, min = 0;

    while(i < n){
        if(n%(i+1)==0){
            number = num[n/(i+1)][k-1] * pow(prime[k],i);
            if((number < min && number) || min==0) {
                min = number;
            }
        }
        i++;
    }
    num[n][k] = min;
    return min;
}

long double getMin(int n)
{
    int i = 2;
    long double min = num[n][i++];
    while(true)
    {
        if(num[n][i] == 0) break;
        if(num[n][i] < min) 
            min = num[n][i];
        i++;
    }
    return min;
}

long double Solve(int n) 
{
    long double current = 0, last = 0;
    for(int i=2;i<=n;i++)
    {
        current = 0, last = 0;
        for(int j=2;j<=11;j++)
        {
            last = current;
            current = f(i,j);
            if(current == 0 || (last && current > last)) break;
        }
    }
    return n==1 ? 1 : getMin(n);
}

int main()
{
    memset(num, 0, sizeof(long) * 1001 * 11);
    num[1][1] = 1;
    int n = 0;
    cin >> n;
    cout << fixed << setprecision(0) << Solve(n);
}