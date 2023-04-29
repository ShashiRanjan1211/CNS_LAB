#include <iostream>
#include <string>
using namespace std;
string encrypt(string plaintext, string key) {
    string ciphertext = "";
    int keyIndex = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char k = key[keyIndex % key.length()];
            c = toupper(c);
            k = toupper(k);
            char encryptedChar = (((c + k - 2 * 'A') % 26) + 'A');
            if (islower(plaintext[i])) {
                encryptedChar = tolower(encryptedChar);
            }
            ciphertext += encryptedChar;
            keyIndex++;
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}
string decrypt(string ciphertext, string key) {
    string plaintext = "";
    int keyIndex = 0;
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char k = key[keyIndex % key.length()];
            c = toupper(c);
            k = toupper(k);
            char decryptedChar = (((c - k + 26) % 26) + 'A');
            if (islower(ciphertext[i])) {
                decryptedChar = tolower(decryptedChar);
            }
            plaintext += decryptedChar;
            keyIndex++;
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}
int main() {
    string plaintext,key;
    cout<<"Enter the plain text:";
    getline(cin,plaintext);
    cout<<"Enter the key:";
    cin>>key;
    string encrypted = encrypt(plaintext, key);
    cout << "Encrypted text: " << encrypted << endl;
    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted text: " << decrypted << endl;
    return 0;
}
