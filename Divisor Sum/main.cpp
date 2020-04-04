#include <bits/stdc++.h>
using namespace std;
bitset <10000> b;
vector<int> primes;

class Sieve
{
public:
    void sieve(int n) {
        b.set();
        b[0] = b[1] = 0;
        primes.push_back(2);
        for (int i = 3; i * i <= n; i += 2) {
            if (b[i]) {
                for (int j = i * i; j <= n; j += i) {
                    b[j] = 0;
                }
            }
            primes.push_back(i);
        }
    }
};

class DivisorCount
{
public:
    int divisor = 1;
    int divisorCount (int n) {
        for (unsigned int i = 0; i < primes.size(); ++i) {
            int count = 1;
            if (n % primes[i] == 0) {
                while (n % primes[i] == 0) {
                    n = n / primes[i];
                    count++;
                }
                divisor *= count;
            }
        }
        return divisor;
    }
};

class DivisorSum
{
public:
     int sum = 1;
    int divisorSum (int n) {
        for (unsigned int i = 0; i < primes.size(); ++i) {
            int count = 1;
            if (n % primes[i] == 0) {
                while (n % primes[i] == 0) {
                    n = n / primes[i];
                    count++;
                }
                sum *= (pow(primes[i], count) - 1) / (primes[i] - 1);
            }
        }
        return sum;
    }
};

int main()
{
    int n;
    cin >> n;

    Sieve prime;
    prime.sieve(n);
    for (it : primes) {
        cout << it << " ";
    }
    cout << "\n";

    DivisorCount div;
    cout << "Number of divisors: " << div.divisorCount(n) << endl;

    DivisorSum sum;
    cout << "Sum is: " << sum.divisorSum(n) << endl;

    return 0;
}
