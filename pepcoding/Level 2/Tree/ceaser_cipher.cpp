#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char con = 'y', ele;
    char msg[100];
    int i, j, length, choice, key;
    do
    {
        cout << "Enter message: ";
        cin >> msg;
        cout << "\nEnter Key: ";
        cin >> key;
        int l = strlen(msg);
        cout << " \n1.Encryption \n2.Decryption " << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        { // for encryption char ch;
            for (int i = 0; msg[i] != '\0'; i++)
            {
                char ch = msg[i];
                if (ch >= 'a' && ch <= 'z')
                {
                    ch = ch + key;
                    if (ch > 'z' || ch < 'a')
                    {
                        ch = ch - 'z' + 'a' - 1;
                    }
                    msg[i] = ch;
                }
                else if (ch >= 'A' && ch <= 'Z')
                {
                    ch = ch + key;
                    if (ch > 'Z' || ch < 'A')
                    {
                        ch = ch - 'Z' + 'A' - 1;
                    }
                    msg[i] = ch;
                }
            }
            cout << "Encrypted Message: " << msg << endl;
        }
        else if (choice == 2)
        {
            char ch;
            for (int i = 0; msg[i] != '\0'; i++)
            {
                ch = msg[i];
                if (ch >= 'a' && ch <= 'z')
                {
                    ch = ch - key;
                    if (ch > 'z' || ch < 'a')
                    {
                        ch = ch + 'z' - 'a' + 1;
                    }
                    msg[i] = ch;
                }
                else if (ch >= 'A' && ch <= 'Z')
                {
                    ch = ch - key;
                    if (ch > 'Z' || ch < 'A')
                    {
                        ch = ch + 'Z' - 'A' + 1;
                    }
                    msg[i] = ch;
                }
            }
            cout << "Decrypted Message: " << msg << endl;
        }
        else
        {
            cout << "Enter Valid choice: " << endl;
        }
        cout << "\tDo you want to continue press 1 other wise 0: ";
        cin >> ele;
        con = ele;
    } while (con == '1');
}
