// ! NOT Req.

// Suffix Tree is implemented for you, you just have to write the code for DFS traversal and print all the suffixes in lexicographical order

// abca

// A C program to implement Ukkonen's Suffix Tree Construction
#include "../header.h"
#define MAX_CHAR 256

class SuffixTreeNode
{
public:
  struct SuffixTreeNode *children[MAX_CHAR];
  struct SuffixTreeNode *suffixLink;
  int start;
  int *end;
  int suffixIndex;
};

typedef struct SuffixTreeNode Node;

string text;       // Input string
Node *root = NULL; // Pointer to root node

Node *lastNewNode = NULL;
Node *activeNode = NULL;
static int count = 0;

int activeEdge = -1;
int activeLength = 0;

int remainingSuffixCount = 0;
int leafEnd = -1;
int *rootEnd = NULL;
int *splitEnd = NULL;
int size = -1; // Length of input string

Node *newNode(int start, int *end)
{
  ::count++;
  Node *node = (Node *)malloc(sizeof(Node));
  int i;
  for (i = 0; i < MAX_CHAR; i++)
    node->children[i] = NULL;

  node->suffixLink = root;
  node->start = start;
  node->end = end;

  node->suffixIndex = -1;
  return node;
}

int edgeLength(Node *n)
{
  return *(n->end) - (n->start) + 1;
}

int walkDown(Node *currNode)
{
  if (activeLength >= edgeLength(currNode))
  {
    activeEdge = (int)text[activeEdge + edgeLength(currNode)] - (int)' ';
    activeLength -= edgeLength(currNode);
    activeNode = currNode;
    return 1;
  }
  return 0;
}

void extendSuffixTree(int pos)
{
  leafEnd = pos;
  remainingSuffixCount++;

  lastNewNode = NULL;

  while (remainingSuffixCount > 0)
  {

    if (activeLength == 0)
      activeEdge = (int)text[pos] - (int)' ';

    if (activeNode->children[activeEdge] == NULL)
    {
      activeNode->children[activeEdge] = newNode(pos, &leafEnd);
      if (lastNewNode != NULL)
      {
        lastNewNode->suffixLink = activeNode;
        lastNewNode = NULL;
      }
    }

    else
    {

      Node *next = activeNode->children[activeEdge];
      if (walkDown(next)) // Do walkdown
        // Start from next node (the new activeNode)
        continue;

      if (text[next->start + activeLength] == text[pos])
      {
        if (lastNewNode != NULL && activeNode != root)
        {
          lastNewNode->suffixLink = activeNode;
          lastNewNode = NULL;
        }

        // APCFER3
        activeLength++;
        /*STOP all further processing in this phase
        and move on to next phase*/
        break;
      }

      splitEnd = (int *)malloc(sizeof(int));
      *splitEnd = next->start + activeLength - 1;

      // New internal node
      Node *split = newNode(next->start, splitEnd);
      activeNode->children[activeEdge] = split;

      // New leaf coming out of new internal node
      split->children[(int)text[pos] - (int)' '] = newNode(pos, &leafEnd);
      next->start += activeLength;
      split->children[activeEdge] = next;

      if (lastNewNode != NULL)
        lastNewNode->suffixLink = split;

      lastNewNode = split;
    }

    remainingSuffixCount--;
    if (activeNode == root && activeLength > 0) // APCFER2C1
    {
      activeLength--;
      activeEdge = (int)text[pos - remainingSuffixCount + 1] - (int)' ';
    }

    // APCFER2C2
    else if (activeNode != root)
      activeNode = activeNode->suffixLink;
  }
}

void print(int i, int j)
{
  int k;
  for (k = i; k <= j; k++)
    cout << text[k];
}

void setSuffixIndexByDFS(Node *n, int labelHeight)
{
  if (n == NULL)
    return;

  if (n->start != -1) // A non-root node
  {
    // Print the label on edge from parent to current node
    print(n->start, *(n->end));
  }
  int leaf = 1;
  int i;
  for (i = 0; i < MAX_CHAR; i++)
  {
    if (n->children[i] != NULL)
    {
      if (leaf == 1 && n->start != -1)
        cout << "  " << n->suffixIndex << endl;

      // Current node is not a leaf as it has outgoing
      // edges from it.
      leaf = 0;
      setSuffixIndexByDFS(n->children[i], labelHeight + edgeLength(n->children[i]));
    }
  }
  if (leaf == 1)
  {
    n->suffixIndex = ::size - labelHeight;
    cout << "  " << n->suffixIndex << endl;
  }
}

void freeSuffixTreeByPostOrder(Node *n)
{
  if (n == NULL)
    return;
  int i;

  for (i = 0; i < MAX_CHAR; i++)
    if (n->children[i] != NULL)
      freeSuffixTreeByPostOrder(n->children[i]);

  if (n->suffixIndex == -1)
    free(n->end);
  free(n);
}

void buildSuffixTree()
{
  ::size = text.length();
  int i;
  rootEnd = (int *)malloc(sizeof(int));
  *rootEnd = -1;

  root = newNode(-1, rootEnd);

  activeNode = root; // First activeNode will be root
  for (i = 0; i < ::size; i++)
    extendSuffixTree(i);
  int labelHeight = 0;
  setSuffixIndexByDFS(root, labelHeight);

  // Free the dynamically allocated memory
  freeSuffixTreeByPostOrder(root);
}

int main()
{
  // text = "abbc";
  text = "abca";
  buildSuffixTree();
  cout << "Number of nodes in suffix tree are: " << ::count;
  return 0;
}
