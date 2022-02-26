
#include <bits/stdc++.h>
using namespace std;

string Cipher(string input, string oldAlphabet, string newAlphabet)
{
    string output = "";
    int inputLen = input.size();

    if (oldAlphabet.size() != newAlphabet.size())
        return "-1";

    for (int i = 0; i < inputLen; ++i)
    {
        int oldCharIndex = oldAlphabet.find(tolower(input[i]));

        if (oldCharIndex >= 0)
            output += isupper(input[i]) ? toupper(newAlphabet[oldCharIndex]) : newAlphabet[oldCharIndex];
        else
            output += input[i];
    }

    return output;
}

string Encipher(string input, string cipherAlphabet)
{
    string plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
    return Cipher(input, plainAlphabet, cipherAlphabet);
}

string Decipher(string input, string cipherAlphabet)
{
    string plainAlphabet = "abcdefghijklmnopqrstuvwxyz";
    return Cipher(input, cipherAlphabet, plainAlphabet);
}

int main()
{

    string cipherAlphabet = "yhkqgvxfoluapwmtzecjdbsnri";

    int ch = 0;
    do
    {
        cout << "Enter the text: ";
        string text;
        cin >> text;
        string encipherResult = Encipher(text, cipherAlphabet);
        string decipherResult = Decipher(encipherResult, cipherAlphabet);
        cout << "\nCipher text: " << encipherResult << endl
             << "Decrypted text: " << decipherResult << "\n\n";

        cout << "\tTo continue press 1 else 0 : ";
        cin >> ch;

    } while (ch);

    return 0;
}
