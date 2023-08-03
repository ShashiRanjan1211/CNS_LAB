#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
        {
            return x;
        }
    }
    return -1;
}

int modExp(int base, int exp, int mod)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    int p, q, n, phi, e, d;
    cout << "Enter a prime number for p: ";
    cin >> p;
    while (!isPrime(p))
    {
        cout << "p must be a prime number. Please enter another value for p: ";
        cin >> p;
    }
    cout << "Enter a prime number for q: ";
    cin >> q;
    while (!isPrime(q))
    {
        cout << "q must be a prime number. Please enter another value for q: ";
        cin >> q;
    }
    n = p * q;
    phi = (p - 1) * (q - 1);
    cout << "phi = " << phi << endl;
    cout << "Choose a value for e such that 1 < e < phi and gcd(e, phi) = 1: ";
    cin >> e;
    while (e <= 1 || e >= phi || gcd(e, phi) != 1)
    {
        cout << "Enter correct value of e:" << endl;
        cin >> e;
    }
    d = modInverse(e, phi);
    cout << "Public key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private key (d, n): (" << d << ", " << n << ")" << endl;

    string plaintext;
    cout << "Enter the plaintext to be encrypted: ";
    cin.ignore();
    getline(cin, plaintext);
    cout << "Encrypted message: ";
    vector<int> encryptedText;
    for (char ch : plaintext)
    {
        int charValue = static_cast<int>(ch) - 'a';
        int encryptedCharValue = modExp(charValue, e, n);
        encryptedText.push_back(encryptedCharValue);
        cout << encryptedCharValue << " ";
    }
    cout << "Decrypted message: ";
    string decryptedText;
    for (size_t i = 0; i < encryptedText.size(); i++)
    {
        int decryptedCharValue = modExp(encryptedText[i], d, n);
        decryptedCharValue = (decryptedCharValue + 26) % 26;
        decryptedCharValue = (decryptedCharValue + 'a');
        decryptedText += static_cast<char>(decryptedCharValue);
    }
    cout << decryptedText << endl;
    return 0;
}
