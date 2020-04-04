#include <bits/stdc++.h>

using namespace std;

class DivisorCount
{
public:
    int divisorCount(int n) {
        int divisor = 0;
        for (int i = 1; i * i <= n; ++i) {
            if (i * i == n) {
                divisor++;
                cout << i << "\n";
            }
            else if (n % i == 0) {
                /// if "i" divides "n" then "n / i" also divides "n".
                /// so we increase the count by 2.
                divisor += 2;
                cout << i << " " << n / i << "\n";
            }
        }
        return divisor;
    }
};

int main()
{
    DivisorCount d;
    int n;
    cin >> n;
    cout << "\n" << "Divisor count is: " << "\n" << d.divisorCount(n) << endl;
    return 0;
}
