#include "../header.h"

void solve(string str)
{
    for (int i = 0; i < (1 << str.length()); i++)
    {
        string abbr = "";
        int count = 0;

        for (int j = 0; j < str.length(); j++)
        {
            int b = str.length() - 1 - j;
            if ((i & (i << b)) == 0)
            {
                if (count == 0)
                    abbr = abbr + str[j];
                else
                {
                    abbr = abbr + to_string(count) + str[j];
                    count = 0;
                }
            }
            else
                count++;
        }

        if (count > 0)
            abbr = abbr + to_string(count);
        cout << abbr << ", ";
    }
}

int main()
{
    cout << "\nHello world!" << endl;

    string str;
    cin >> str;
    cout << "\n========================================\n";
    solve(str);
    cout << "\n========================================\n";
    return 0;
}
// pep