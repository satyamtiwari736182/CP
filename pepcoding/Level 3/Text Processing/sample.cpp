// // Given an integer n indicating the number of patterns.Then follow n lines, each containing non empty strings, representing patterns.
// // Then comes a non empty string representing text.
// // Output n lines where ith line contains the positions of all occurances of the ith pattern in text.

#include "../header.h"

// import jdk.internal.org.jline.terminal.impl.CursorSupport;
// import jdk.internal.org.jline.utils.Curses;

class node
{
public:
  map<char, node *> child;
  node *suffix_link;
  node *output_link;
  int pattern_ind;

  node()
  {
    suffix_link = nullptr;
    output_link = nullptr;
    pattern_ind = -1;
  }
};

void build_trie(node *root, vs patterns)
{
  for (int i = 0; i < patterns.size(); i++)
  {
    node *curr = root;
    for (int j = 0; j < patterns[i].length(); j++)
    {
      char c = patterns[i][j];
      if (curr->child.count(c))
        curr = curr->child[c];
      else
      {
        node *nn = new node();
        curr->child[c] = nn;
        curr = nn;
      }
    }
    curr->pattern_ind = i;
  }
}

void build_suffix_and_output_links(node *root)
{
  root->suffix_link = root; // root represents empty string
  queue<node *> que;        // will use bfs to set links

  for (auto rc : root->child)
  {
    que.push(rc.se);
    root->child[rc.fs]->suffix_link = root; // root's children suffixlink will point to root only
  }

  while (que.size() > 0)
  {
    node *curState = que.front();
    que.pop();

    for (auto cc : curState->child)
    {
      node *cchild = curState->child[cc.fs]; // jiske liye suffix link dhund rhe hein
      node *tmp = curState->suffix_link;     // parent suffix link
      while (!tmp->child.count(cc.fs) && tmp != root)
        tmp = tmp->suffix_link; // finding lps

      if (tmp->child.count(cc.fs))
        cchild->suffix_link = tmp->child[cc.fs];
      else
        cchild->suffix_link = root;
      que.push(cchild);
    }

    // setting output link

    if (curState->suffix_link->pattern_ind >= 0)
      curState->output_link = curState->suffix_link;
    else
      curState->output_link = curState->suffix_link->output_link;
  }
}

void search2(node *root, string text, vector<vi> &searchResults)
{
  node *parent = root;

  for (int i = 0; i < text.length(); i++)
  {
    char c = text[i];
    if (parent->child.count(c))
    { // if parent has a child node in trie, travel it
      parent = parent->child[c];
      if (parent->pattern_ind >= 0)
      {
        searchResults[parent->pattern_ind].pb(i); // reached a output node
      }

      node *myOutput = parent->output_link;
      while (myOutput != nullptr)
      {
        searchResults[myOutput->pattern_ind].pb(i);
        myOutput = myOutput->output_link;
      }
    }
    else
    {
      while (parent != root && !parent->child.count(c))
        parent = parent->suffix_link;
      if (parent->child.count(c))
        i--; // hold i and start traversing in next iteration
    }
  }
}

vector<vi> search(node *root, string s)
{
  vector<vi> res(s.length());

  node *parent = root;

  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];
    if (parent->child.count(c))
    {
      parent = parent->child[c];
      if (parent->pattern_ind >= 0)
        res[parent->pattern_ind].pb(i);
      node *myOutput = parent->output_link;
      while (myOutput != nullptr)
      {
        res[myOutput->pattern_ind].pb(i);
        myOutput = myOutput->output_link;
      }
    }
    else
    {
      while (parent != root && !parent->child.count(c))
        parent = parent->suffix_link;
      if (parent->child.count(c))
        i--;
    }
  }
  return res;
}

void solve()
{
  int n;
  cin >> n;
  vs patterns(n);
  rarr(patterns, 0, n);

  string txt;
  cin >> txt;

  node *root = new node();

  build_trie(root, patterns);
  build_suffix_and_output_links(root);

  vector<vi> res = search(root, txt);

  cout << "\n----------------------------\n";

  for (int i = 0; i < n; i++)
  {
    cout << patterns[i] << " -> ";
    if (res[i].size() == 0)
      cout << (-1);
    for (int ep : res[i])
      cout << (ep - patterns[i].length() + 1) << " ";
    cout << endl;
  }
}

int main()
{
  cout << "\nhello world!\n";
  int t = 1;
  // cin >> t;
  test(t)
  {
    solve();
    cout << "----------------------------\n";
  }
}

// 6
// ACC
// ATC
// CAT
// GCG
// C
// T
// GCATCG
