#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0, k = 0;;
    int max = 0;
    string s;

    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> s;
        k = 0; max = 0;
        while(k < s.size())
        {
            if(s[k] < s[max]) max = k;
            k++;
        }
        cout << s[max] << ' ' << s.substr(0, max) + s.substr(max+1, s.size() - max) << endl;
    }
    return 0;
}