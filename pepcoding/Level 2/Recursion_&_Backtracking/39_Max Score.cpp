// 1. You are given a list of words, a list of alphabets(might be repeating) and score of every alphabet
//      from a to z.
// 2. You have to find the maximum score of any valid set of words formed by using the given
//      alphabets.
// 3. A word can not be used more than one time.
// 4. Each alphabet can be used only once.
// 5. It is not necessary to use all the given alphabets.

// Note -> Check out the question video and write the recursive code as it is intended without
//                changing signature. The judge can't force you but intends you to teach a concept.

#include "../header.h"

int solution(vs &words, vi &freqArr, vi &score, int idx)
{
    // cout << idx << " ";
    if (idx >= words.size())
        return 0;
    int sno = 0 + solution(words, freqArr, score, idx + 1);
    int sword = 0;
    string word = words[idx];
    bool flag = true;

    for (char ch : word)
    {
        if (freqArr[ch - 'a'] == 0)
            flag = false;
        freqArr[ch - 'a']--;
        sword += score[ch - 'a'];
    }

    int syes = 0;
    if (flag)
        syes = sword + solution(words, freqArr, score, idx + 1);

    for (char ch : word)
        freqArr[ch - 'a']++;

    return max(sno, syes);
}

void solve()
{
    int nofWords, nofLetters;
    cin >> nofWords;

    vs words(nofWords);
    rarr(words, 0, nofWords);

    cin >> nofLetters;
    vector<char> letters(nofLetters);
    rarr(letters, 0, nofLetters);

    vi score(26), farr(26);
    rarr(score, 0, 26);

    for (char ch : letters)
        farr[ch - 'a']++;

    // parr(letters, letters.size());
    cout << solution(words, farr, score, 0);
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
4
dog cat dad good
9
a b c d d d g o o
1 0 9 5 0 0 3 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0
*/