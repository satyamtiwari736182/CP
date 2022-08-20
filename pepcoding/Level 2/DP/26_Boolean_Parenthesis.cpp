#include "../header.h"
int main()
{
    int n;
    string str1, str2;
    cin >> str1 >> str2;
    n = str1.length();

    int truedp[N][N], falsedp[N][N];
    fill(*truedp, *truedp + n * n, 0);
    fill(*falsedp, *falsedp + n * n, 0);

    //-----------------------------------------------------
    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                if (str1[i] == 'T')
                {
                    truedp[i][j] = 1;
                    falsedp[i][j] = 0;
                }
                else
                {
                    truedp[i][j] = 0;
                    falsedp[i][j] = 1;
                }
            }
            else
                for (int k = 0; k < j; k++)
                {
                    char optr = str2[k];

                    int ltc = truedp[i][k];
                    int rtc = truedp[k + 1][j];

                    int lfc = falsedp[i][k];
                    int rfc = falsedp[k + 1][j];

                    if (optr == '&')
                    {
                        truedp[i][j] += ltc * rtc;
                        falsedp[i][j] += lfc * rtc + ltc * rfc + lfc * rfc;
                    }

                    else if (optr == '|')
                    {
                        truedp[i][j] += ltc * rtc + lfc * rtc + ltc * rfc;
                        falsedp[i][j] += lfc * rfc;
                    }
                    
                    else
                    { // ^
                        truedp[i][j] += ltc * rfc + lfc * rtc;
                        falsedp[i][j] += ltc * rtc + lfc * rfc;
                    }
                }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(truedp, n, n);
    cout << "\n***************************\n";
    pmatrix(falsedp, n, n);
    return 0;
}

// TFTF
// &|^
