#include <iostream>
using namespace std;
string encrypt(string text, int s)
{
	string result = "";
	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i]))
			result += char(int(text[i] + s - 65) % 26 + 65);
		 else if(islower(text[i]))
			result += char(int(text[i] + s - 97) % 26 + 97);
            else 
             result+=text[i];
	} 
	return result;
}
string decrypt(string encrypted_text, int s)
{
    string result = "";
    for (int i = 0; i < encrypted_text.length(); i++) {
        if (isupper(encrypted_text[i]))
            result += char((int(encrypted_text[i] - s - 65) + 26) % 26 + 65);
    else if(islower(encrypted_text[i]))
            result += char((int(encrypted_text[i] - s - 97) + 26) % 26 + 97);
            else 
            result+=encrypted_text[i];
    }
    return result;
}
int main()
{
	string text; 
    cout<<"Enter the plain text to be encrypted"<<endl;
    getline(cin,text);
    cout<<"Enter the shift number"<<endl;
	int s;
    cin>>s;
	cout << "\nCipher text: " ;
    string p=encrypt(text, s);
    cout<<p<<endl;
    cout<<"decrpyted test: "<<decrypt(p,s)<<endl;
	return 0;
}
