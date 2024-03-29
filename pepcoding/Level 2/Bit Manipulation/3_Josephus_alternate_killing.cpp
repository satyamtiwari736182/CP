// 1. You are given an integer N which represents the total number of soldiers standing in a circle 
//      having position marked from 1 to N.
// 2. A cruel king wants to execute them but in a different way.
// 3. He starts executing soldiers from 1st position and proceeds around the circle in clockwise 
//      direction.
// 4. In each step, every second soldier is executed.
// 5. The elimination proceeds around the circle (which is becoming smaller and smaller as the 
//      executed soldiers are removed), until only the last soldier remains, who is given freedom.
// 6. You have to find the position of that lucky soldier.

#include "../header.h"

int powerof_2(int n)
{
    int i = 1;
    while (i * 2 <= n)
        i = i * 2;
    return i;
}

int sol(int n)
{
    // Epress n like -> n=2^i+l
    int hp2 = powerof_2(n); // highest power of two;
    int l = n - hp2;
    return 2 * l + 1; // request ans, who will saved at last.
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;

    cout << "\n========================================\n";
    cout << sol(n);

    cout << "\n========================================\n";
    return 0;
}
