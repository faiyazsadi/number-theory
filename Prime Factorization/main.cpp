#include <bits/stdc++.h>
#define ll long long
using namespace std;
bitset<100000> b;
vector<int> prime, primeFactors;

void print(vector<int> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

void sieve(int N)
{
    b.set();
    b[0] = b[1] = 0;
    prime.push_back(2);
    for (ll i = 3; i <= N; i += 2) {
        if (b[i]) {
            for (ll j = i * i; j <= N; j += i) {
                b[j] = 0;
            }
            prime.push_back(i);
        }
    }
}

void primeFactorization(int n) {
    for (int i = 0; prime[i] * prime[i] <= n; ++i) {
        if (n % prime[i] == 0) {
            while (n % prime[i] == 0) {
                n = n / prime[i];
                primeFactors.push_back(prime[i]);
            }
        }
    }
    if (n > 1) {
            primeFactors.push_back(n);
    }
}

int main()
{
    sieve(100000);
    int n;
    cin >> n;
    primeFactorization(n);
    for (unsigned int i = 0; i < primeFactors.size(); ++i) {
        cout << primeFactors[i] << " ";
    }
    cout << "\n";
    return 0;
}
