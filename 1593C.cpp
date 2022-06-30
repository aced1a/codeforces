#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0, n = 0, k = 0, used = 0, count = 0;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n >> k;
        vector<int> v(k);
        for(int j=0;j<k;j++)
        {
            cin >> v[j];
        }
        sort(v.rbegin(),v.rend());
        count = 0;
        used = 0;
        
        while (count < k && used + (n - v[count]) < n)
        {
            used += n - v[count];
            count++;
        }
        cout << count << endl;
    }
}