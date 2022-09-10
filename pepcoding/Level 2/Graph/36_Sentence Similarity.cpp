// Given two sentences sentence1 and sentence2 each represented as a string array and given a 2d array of string pairs where each row contains two words {x,y} indicating that the word x and y are similar.
// Return true if sentence1 and sentence2 are similar, or false if they are not similar. Two sentences are similar if they have the same length and sentence1[i] and sentences2[i] are similar.

// Note: Similarity relation is transitive.

#include "../header.h"

unordered_map<string, string> parent;
unordered_map<string, int> ranks;

string findParents(string x)
{
    if (parent.count(x) == false)
        parent[x] = x, ranks[x] = 1;
    if (parent[x] == x)
        return x;
    string temp = findParents(parent[x]);
    parent[x] = temp;
    return temp;
}

bool Union(string x, string y)
{
    string lx = findParents(x);
    string ly = findParents(y);
    if (lx != ly)
    {
        if (ranks[lx] > ranks[ly])
            parent[ly] = lx;
        else if (ranks[ly] > ranks[lx])
            parent[lx] = ly;
        else
            parent[lx] = ly, ranks[ly]++;
        return true;
    }
    return false;
}

bool areSentenceSimilar(vs sent1, vs sent2, vector<pair<string, string>> &similar)
{
    if (sent1.size() != sent2.size())
        return false;

    for (auto pr : similar)
        Union(pr.fs, pr.se);

    for (int i = 0; i < sent1.size(); i++)
    {
        string word1 = sent1[i], word2 = sent2[i];
        if (word1 != word2 && findParents(word1) != findParents(word2))
            return false;
    }

    return true;
}

int main()
{
    cout << "\nHello world!" << endl;

    int n;
    cin >> n;
    vs str1(n), str2(n);
    rarr(str1, 0, n);
    rarr(str2, 0, n);
    cin >> n;

    vector<pair<string, string>> similar(n);
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        similar[i] = {s1, s2};
    }

    cout << "\n==========================================\n";
    cout << areSentenceSimilar(str1, str2, similar);
    cout << "\n==========================================\n";
    return 0;
}

/*

3
treat fight miss
like train lost
4
treat catch
train fight
like catch
miss lost

*/