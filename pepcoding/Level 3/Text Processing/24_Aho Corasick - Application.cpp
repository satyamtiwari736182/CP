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
{                           // will use bfs to set links
  root->suffix_link = root; // root represents empty string
  queue<node *> qu;

  for (auto rc : root->child)
  {
    qu.push(rc.se);
    root->child[rc.fs]->suffix_link = root; // root's children suffixlink will point to root only
  }

  while (qu.size() > 0)
  {
    node *curState = qu.front();
    qu.pop();

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
      qu.push(cchild);
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

void search(node *root, string s, vector<vi> &res)
{

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
}

int main()
{

  int n;
  cin >> n;
  vs patterns(n);
  for (int i = 0; i < n; i++)
    cin >> patterns[i];
  string txt;
  cin >> txt;
  // getline(cin, txt);
  node *root = new node();
  build_trie(root, patterns);
  build_suffix_and_output_links(root);

  vector<vi> res(n);

  search(root, txt, res);
  for (int i = 0; i < n; i++)
  {
    if (res[i].size() == 0)
      cout << (-1);
    for (int ep : res[i])
      cout << (ep - patterns[i].length() + 1) << " ";
    cout << endl;
  }
}

// #include "../header.h"

// class Node
// {
// public:
//     map<char, Node *> child;
//     Node *suffix_link;
//     Node *output_link;
//     int pattern_idx;
//     Node()
//     {
//         suffix_link = nullptr; // failure Link
//         output_link = nullptr;
//         pattern_idx = -1;
//     }
// };

// void build_trie(Node *root, vs patterns)
// {
//     for (int i = 0; i < patterns.size(); i++)
//     {
//         Node *curr = root;
//         for (int j = 0; j < patterns[i].length(); j++)
//         {
//             char ch = patterns[i][j];
//             if (curr->child.count(ch) != 0)
//                 curr = curr->child[ch];
//             else
//             {
//                 Node *newNode = new Node();
//                 curr->child[ch] = newNode;
//                 curr = newNode;
//             }
//         }
//         curr->pattern_idx = i;
//     }
// }

// void build_suffix_and_output_links(Node *root)
// {
//     root->suffix_link = root;
//     queue<Node *> que;

//     for (auto chld : root->child)
//     {
//         que.push(chld.se);
//         chld.se->suffix_link = root;
//     }

//     while (!que.empty())
//     {
//         Node *currState = que.front();
//         que.pop();

//         for (auto curr_child_pr : currState->child)
//         {
//             Node *curr_child = curr_child_pr.se;
//             Node *temp = currState->suffix_link;

//             while (!temp->child.count(curr_child_pr.fs) && temp != root)
//                 temp = temp->suffix_link;

//             if (temp->child.count(curr_child_pr.fs))
//                 curr_child->suffix_link = temp->child[curr_child_pr.fs];

//             else
//                 curr_child->suffix_link = root;

//             que.push(curr_child);
//         }

//         if (currState->suffix_link->pattern_idx >= 0)
//             currState->output_link = currState->suffix_link;

//         else
//             currState->output_link = currState->suffix_link->output_link;
//     }
// }

// void search(Node *root, string word, vector<vi> &res)
// {
//     cout << word << endl;

//     Node *parent = root;
//     for (int i = 0; i < word.length(); i++)
//     {
//         char ch = word[ch];

//         if (parent->child.count(ch))
//         {
//             parent = parent->child[ch];

//             if (parent->pattern_idx >= 0)
//                 res[parent->pattern_idx].pb(i);

//             Node *output = parent->output_link;

//             while (output)
//             {
//                 res[output->pattern_idx].pb(i);
//                 output = output->output_link;
//             }
//         }

//         else
//         {
//             // cout << "h1 ";
//             while (parent != root && !parent->child.count(ch))
//                 parent = parent->suffix_link;

//             if (parent->child.count(ch))
//                 i--;
//         }
//     }
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     vs patt(n);
//     for (int i = 0; i < n; i++)
//         cin >> patt[i];
//     string str;
//     cin >> str;

//     Node *root = new Node();
//     build_trie(root, patt);
//     build_suffix_and_output_links(root);

//     vector<vi> res;
//     res.resize(n);

//     search(root, str, res);
//     cout << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << i << " -> ";
//         if (res[i].size() == 0)
//             cout << "-1 ";
//         for (auto val : res[i])
//             cout << (val - patt[i].size() + 1) << " ";
//         cout << endl;
//     }
// }

// int main()
// {
//     cout << "\nHello world!" << endl;
//     int t = 1;
//     // cin >> t;
//     test(t)
//     {
//         solve();
//         cout << "\n------------------------------\n";
//     }

//     return 0;
// }

// 6
// ACC
// ATC
// CAT
// GCG
// C
// T
// GCATCG
