// 1. A complex number can be represented as a string on the form "Real + Imaginary i" where:
//     1.1 Real is the real part and is an integer in the range [-100, 100].
//     1.2 Imaginary is the imaginary part and is an integer in the range [-100, 100].
//     1.3 i^2 == -1.
// 2. Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.


#include "../header.h"

string complexProduct(string num1, string num2)
{
    string::size_type idx1 = num1.find("+", 0);
    if (idx1 == (string::npos))
        idx1 = num1.find("-", 1);

    int a = stoi(Substr(num1, 0, idx1));
    int b = stoi(Substr(num1, idx1, num1.length() - 1));

    size_t idx2 = num2.find("+", 0);
    if (idx2 == (string::npos))
        idx2 = num2.find("-", 1);

    int x = stoi(Substr(num2, 0, idx2));
    int y = stoi(Substr(num2, idx2, num2.length() - 1));

    // cout << a << " " << b << endl;
    // cout << x << " " << y << endl;

    int real = a * x - b * y, img = a * y + b * x;
    string ans = to_string(real);
    if (img >= 0)
        ans += "+";
    ans += to_string(img) + "i";

    return ans;
}

void solve()
{
    string num1, num2, num3 = "";
    // cin >> num1 >> num2;
    //     num1 -> a+bi
    //     num2 -> x+yi
    //   res -> (ax - by) + (y * a + x * b) i

    fflush(stdin);
    getline(cin, num1);
    fflush(stdin);
    getline(cin, num2);
    num1.erase(remove_if(all(num1), [=](auto ch)
                         { return ch == ' '; }),
               end(num1));

    num2.erase(remove_if(all(num2), [=](auto ch)
                         { return ch == ' '; }),
               end(num2));

    num3 = complexProduct(num1, num2);

    cout << num1 << " * " << num2 << " = " << num3 << endl;
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*

1+1i
1+1i


-5-6i
2+7i

*/
