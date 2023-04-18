#include <iostream>
#include <vector>

using namespace std;

void printPrimes(int limit) {
    vector<bool> primes(limit+1, true);

    // 0 and 1 are not prime
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= limit; j += i) {
                primes[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            cout << i << endl;
        }
    }
}

int main() {
    printPrimes(100000000);
    return 0;
}
