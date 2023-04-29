#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int power(int a, int b, int mod) {
    int res = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    return res;
}
int generatePublicKey(int base, int private_key, int prime) {
    return power(base, private_key, prime);
}
int calculateSharedSecret(int public_key, int private_key, int prime) {
    return power(public_key, private_key, prime);
}
int main() {
    int base, prime, alice_private_key, bob_private_key;
    cout << "Enter a prime number: ";
    cin >> prime;
    if (!isPrime(prime)) {
        cout << "Error: " << prime << " is not a prime number." << endl;
        return 1;
    }
    cout << "Enter a base (must be less than the prime number): ";
    cin >> base;
    if (base >= prime || base <= 1) {
        cout << "Error: " << base << " is not a valid base." << endl;
        return 1;
    }
    cout << "Enter Alice's private key: ";
    cin >> alice_private_key;
    cout << "Enter Bob's private key: ";
    cin >> bob_private_key;
    int alice_public_key = generatePublicKey(base, alice_private_key, prime);
    cout << "Alice's public key: " << alice_public_key << endl;
    int bob_public_key = generatePublicKey(base, bob_private_key, prime);
    cout << "Bob's public key: " << bob_public_key << endl;
    int alice_shared_secret = calculateSharedSecret(bob_public_key, alice_private_key, prime);
    cout << "Alice's shared secret key: " << alice_shared_secret << endl;
    int bob_shared_secret = calculateSharedSecret(alice_public_key, bob_private_key, prime);
    cout << "Bob's shared secret key: " << bob_shared_secret << endl;
    return 0;
}
