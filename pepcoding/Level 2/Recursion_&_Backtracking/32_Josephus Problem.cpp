// 1. You are given two numbers N and K.
// 2. N represents the total number of soldiers standing in a circle having position marked from 0 to N-1.
// 3. A cruel king wants to execute them but in a different way.
// 4. He starts executing soldiers from 0th position and proceeds around the circle in clockwise direction.
// 5. In each step, k-1 soldiers are skipped and the k-th soldier is executed.
// 6. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed soldiers are removed), until only the last soldier remains, who is given freedom.
// 7. You have to find the position of that lucky soldier.

// Note -> Check out the question video and write the recursive code as it is intended without  changing signature. The judge can't force you but intends you to teach a concept.


#include "../header.h"

int solution(int n, int k)
{
    if (n == 1)
        return 0;
    int x = solution(n - 1, k);
    int y = (x + k) % n;
    return y;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = solution(n, k);
    cout << ans << endl;
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
4 2
*/
