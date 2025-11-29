// 1. Given two non-negative integers num1 and num2 represented as strings.
// 2. Return the product of num1 and num2, also represented as a string.
// 3. Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include "../header.h"

string multiplyStrings(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int n1 = num1.size(), n2 = num2.size();
    vector<int> result(n1 + n2, 0);

    // Multiply each digit and add to result
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i]-'0') * (num2[j]-'0');
            int sum = mul + result[i+j+1];
            result[i+j+1] = sum % 10;
            result[i+j] += sum / 10;
        }
    }

    // Convert result vector to string
    string product = "";
    int i = 0;
    while (i < result.size() && result[i] == 0) i++; // Skip leading zeros
    while (i < result.size()) product += to_string(result[i++]);

    return product;
}
int main() {
    string num1 = "123456789";
    string num2 = "987654321";
    cout << multiplyStrings(num1, num2) << endl;
    return 0;
}

/*

123 456

*/
