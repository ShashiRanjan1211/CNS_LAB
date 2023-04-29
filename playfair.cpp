#include<bits/stdc++.h>
using namespace std;
const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
string clean_text(string text) {
    string cleaned_text = "";
    for (char c : text) {
        if (isalpha(c)) {
            cleaned_text += tolower(c);
        }
    }
    return cleaned_text;
}
vector<vector<char>> build_matrix(string key) {
    string unique_chars = "";
    for (char c : key) {
        if (unique_chars.find(c) == string::npos) {
            unique_chars += c;
        }
    }
    vector<vector<char>> matrix(5, vector<char>(5));
    int row = 0;
    int col = 0;
    for (char c : unique_chars) {
        matrix[row][col] = c;
        col++;
        if (col == 5) {
            row++;
            col = 0;
        }
    }
    for (char c : ALPHABET) {
        if (c == 'j') {
            continue;
        }
        if (unique_chars.find(c) == string::npos) {
            matrix[row][col] = c;
            col++;
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }
    return matrix;
}
void find_char_in_matrix(char c, vector<vector<char>> matrix, int& row, int& col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c) {
                row = i;
                col = j;
                return;
            }
        }
    }
}
string encrypt(string plaintext, string key) {
    string cleaned_text = clean_text(plaintext);
    key=clean_text(key);
    vector<vector<char>> matrix = build_matrix(key);
    if (cleaned_text.length() % 2 == 1) {
        cleaned_text += 'z';
    }
    string ciphertext = "";
    for (int i = 0; i < cleaned_text.length(); i += 2) {
        char c4 = cleaned_text[i];
        char c5 = cleaned_text[i+1];
        int r1, c1, r2, c2;
        find_char_in_matrix(c4, matrix, r1, c1);
        find_char_in_matrix(c5, matrix, r2, c2);
        if (r1 == r2) {
            c1 = (c1 + 1) % 5;
            c2 = (c2 + 1) % 5;
        }
        else if (c1 == c2) {
            r1 = (r1 + 1) % 5;
            r2 = (r2 + 1) % 5;
        }
        else {
            swap(c1,c2);
        }
        ciphertext += matrix[r1][c1];
        ciphertext += matrix[r2][c2];
    }

    return ciphertext;
}
string decrypt(string ciphertext, string key) {
     key=clean_text(key);
    vector<vector<char>> matrix = build_matrix(key);
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i += 2) {
        char c4 = ciphertext[i];
        char c5 = ciphertext[i+1];
        int r1, c1, r2, c2;
        find_char_in_matrix(c4, matrix, r1, c1);
        find_char_in_matrix(c5, matrix, r2, c2);
        if (r1 == r2) {
            c1 = (c1 +4) % 5;
            c2 = (c2 +4) % 5;
        }
        else if (c1 == c2) {
            r1 = (r1 +4) % 5;
            r2 = (r2 +4) % 5;
        }
        else {
           swap(c1,c2);
        }
        plaintext += matrix[r1][c1];
        plaintext += matrix[r2][c2];
    }
    return plaintext;
}
int main() {
    string plaintext, key;
cout << "Enter the plaintext message: ";
    getline(cin, plaintext);
    cout << "Enter the encryption key: ";
    getline(cin, key);
    string ciphertext = encrypt(plaintext, key);
    cout << "Encrypted message: " << ciphertext << endl;
    string decrpyt_text=decrypt(ciphertext,key);
    cout << "Decrypted message: " <<decrpyt_text  << endl;
    return 0;
}