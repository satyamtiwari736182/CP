// 1. You are given N number of words.
// 2. You are given M puzzles in the form of M strings.
// 3. For a given puzzle, a word is valid if both the following conditions are confirmed - 
//     Condition 1 -> Word contains the first letter of puzzle.
//     Condition 2 -> For each letter in word, that letter should be present in puzzle.
// 4. You have to print the number of valid words corresponding to a puzzle.



#include "../header.h"

vi findNumOfValidWords(auto &words, auto &puzzles)
{
    map<char, vi> hashmap;

    for (string word : words)
    {
        int mask = 0;
        for (char ch : word)
        {
            int bit = ch - 'a';
            mask = mask | (1 << bit);
        }

        set<char> unique;
        for (char ch : word)
        {
            if (unique.find(ch) != unique.end())
                continue;
            hashmap[ch].pb(mask);
            unique.insert(ch);
        }
    }

    vi res;
    for (string puzzle : puzzles)
    {
        int pmask = 0;
        for (char ch : puzzle)
        {
            int bit = ch - 'a';
            pmask = pmask | (1 << bit);
        }
        char ftch = puzzle[0];

        vi wordsToCheck;
        if (hashmap.find(ftch) != hashmap.end())
            wordsToCheck = hashmap[ftch];
        int count = 0;

        for (int wmask : wordsToCheck)
            if ((wmask & pmask) == wmask)
                count++;

        res.pb(count);
    }

    return res;
}

int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    vs words;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.pb(word);
    }

    int m;
    cin >> m;
    vs puzzles;
    for (int i = 0; i < m; i++)
    {
        string puz;
        cin >> puz;
        puzzles.pb(puz);
    }

    cout << "\n========================================\n";
    vi ans = findNumOfValidWords(words, puzzles);
    for (int i = 0; i < ans.size(); i++)
        cout << puzzles[i] << " -> " << ans[i] << endl;

    cout << "\n========================================\n";
    return 0;
}

// 7
// aaaa asas able ability actt actor access
// 6
// aboveyz abrodyz abslute absoryz actresz gaswxyz