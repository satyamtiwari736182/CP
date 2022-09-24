#include "../header.h"

bool sol(string binaryString)
{
    int oddcount = 0;
    int evencount = 0;
    for (int i = 0; i < binaryString.length(); ++i)
    {
        if ((binaryString[i] - '0'))
        {
            if (i % 2 == 0)
                evencount++;
            else
                oddcount++;
        }
    }
    if (abs(evencount - oddcount) % 11 == 0)
        return true;
    return false;
}
int main()
{
    cout << "\nHello world!" << endl;
    string binarystr;
    cin >> binarystr;
    cout << "\n========================================\n";
    cout << sol(binarystr);
    bitset<17> val(735);
    // cout<<val;
    cout << "\n========================================\n";
    return 0;
}
// 01011011111