#include <bits/stdc++.h>
using namespace std;

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(nullptr);

     int t;
     if (!(cin >> t))
          return 0;
     while (t--)
     {
          long long n;
          cin >> n;
          int res;
          cout << "mul 9\n"
               << flush;
          cin >> res;
          cout << "digit\n"
               << flush;
          cin >> res;
          cout << "digit\n"
               << flush;
          cin >> res;
          cout << "add " << n - 9 << '\n'
               << flush;
          cin >> res;
          cout << "!\n"
               << flush;
          cin >> res;
     }
     return 0;
}
