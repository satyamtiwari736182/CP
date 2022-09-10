#include "../header.h"

int main()
{
    int temp = 60;
    string str = "satyam";

    auto samp = [=](int sam) mutable throw()->string
    {
        temp = 90;
        cout << "\nSample proramming " << temp << endl;
        return str;
    };
    string val = samp(30);

    cout << str << "  " << temp << endl;
    cout << "\nHello!\n"
         << val;
    return 0;
}