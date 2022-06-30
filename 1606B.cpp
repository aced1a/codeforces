#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t = 0, n = 0, k = 0, now = 0, count = 0;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n >> k;
        now = 1; count = 0;
        while (now < k)
        {
            now *= 2;
            count++;
        }
        count += n > now ? (n - now + k - 1) / k : 0;
        cout << count << endl;
    }
    return 0;
}
