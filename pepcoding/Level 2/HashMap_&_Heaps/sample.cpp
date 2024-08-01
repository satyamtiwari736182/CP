#include <bits/stdc++.h>
using namespace std;
#define MAX 500005
const int Lgn = 19;

struct Node
{
    int cnt;
    Node *L, *R;
    Node():L(nullptr),R(nullptr),cnt(0){}
};

int Q, N;
vector<int> V;
Node *Root[MAX];

int count(Node *l, Node *r, bool right)
{
    int ret = 0;
    if (right)
    {
        if (r != NULL && r->R != NULL) ret = r->R->cnt;
        if (l != NULL && l->R != NULL) ret -= l->R->cnt;
    }
    else
    {
        if (r != NULL && r->L != NULL) ret = r->L->cnt;
        if (l != NULL && l->L != NULL) ret -= l->L->cnt;
    }
    return ret;
}

void add(int num, Node *rootl, Node *rootr)
{
    rootr->cnt = rootl->cnt + 1;
    for (int i = Lgn; i >= 0; i--)
    {
        int tp = (num & (1 << i)) ? 1 : 0;
        if (tp)
        {
            rootr->R = new Node;
            if (rootl != NULL) rootr->L = rootl->L;
        }
        else
        {
            rootr->L = new Node;
            if (rootl != NULL) rootr->R = rootl->R;
        }
        rootr = (tp) ? rootr->R : rootr->L;
        if (rootl != NULL) rootl = (tp) ? rootl->R : rootl->L;
        rootr->cnt = 1;
        if (rootl != NULL) rootr->cnt += rootl->cnt;
    }
}

void del(int num, Node *root)
{
    root->cnt--;
    for (int i = Lgn; i >= 0; i--)
    {
        int tp = (num & (1 << i)) ? 1 : 0;
        root = (tp) ? root->R : root->L;
        if (root != NULL) root->cnt--;
    }
}

int Xor(int num, Node *rootl, Node *rootr)
{
    int ret = 0;
    for (int i = Lgn; i >= 0; i--)
    {
        int tp = (num & (1 << i)) ? 0 : 1;
        if (tp > 0 && count(rootl, rootr, true) > 0)
        {
            rootr = rootr->R;
            if (rootl != NULL) rootl = rootl->R;
            ret |= (1 << i);
        }
        else if (tp > 0)
        {
            rootr = rootr->L;
            if (rootl != NULL) rootl = rootl->L;
        }
        if (tp == 0 && count(rootl, rootr, false) > 0)
        {
            rootr = rootr->L;
            if (rootl != NULL) rootl = rootl->L;
        }
        else if (tp == 0)
        {
            rootr = rootr->R;
            if (rootl != NULL) rootl = rootl->R;
            ret |= (1 << i);
        }
    }
    return ret;
}

int smaller(int num, Node *rootl, Node *rootr)
{
    int ret = 0;
    for (int i = Lgn; i >= 0; i--)
    {
        int tp = (num & (1 << i)) ? 1 : 0;
        if (tp > 0 && rootr->L != NULL) ret += count(rootl, rootr, false);
        if (tp > 0 && rootr->R == NULL) return ret;
        if (tp == 0 && rootr->L == NULL) return ret;
        rootr = (tp) ? rootr->R : rootr->L;
        if (rootl != NULL) rootl = (tp) ? rootl->R : rootl->L;
    }
    if (rootr != NULL) ret += rootr->cnt;
    if (rootl != NULL) ret -= rootl->cnt;
    return ret;
}

int Kth(int K, Node *rootl, Node *rootr)
{
    int ret = 0;
    for (int i = Lgn; i >= 0; i--)
    {
        int p = count(rootl, rootr, false);
        if (p >= K)
        {
            rootr = rootr->L;
            if (rootl != NULL) rootl = rootl->L;
        }
        else
        {
            K -= p;
            ret |= (1 << i);
            rootr = rootr->R;
            if (rootl != NULL) rootl = rootl->R;
        }
    }
    return ret;
}

void main_()
{
    Root[0] = new Node;
    cin >> Q;
    while (Q--)
    {
        int tp;
        cin >> tp;
        // add number
        if (tp == 0)
        {
            int x;
            cin >> x;
            Root[++N] = new Node;
            add(x, Root[N - 1], Root[N]);
            V.push_back(x);
        }
        if (tp == 1)
        {
            int x, l, r;
            cin >> l >> r >> x;
            cout << Xor(x, Root[l - 1], Root[r]) << endl;
        }
        if (tp == 2)
        {
            int k;
            cin >> k;
            while (k--)
            {
                del(V.back(), Root[N--]);
                V.pop_back();
            }
        }
        if (tp == 3)
        {
            int x, l, r;
            cin >> l >> r >> x;
            cout << smaller(x, Root[l - 1], Root[r]) << endl;
        }
        if (tp == 4)
        {
            int k, l, r;
            cin >> l >> r >> k;
            cout << Kth(k, Root[l - 1], Root[r]) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;

    while (t--)
        main_();

    return 0;
}
/*
10
0 8
4 1 1 1
0 2
1 2 2 7
1 2 2 7
0 1
3 2 2 2
1 1 2 3
3 1 3 5
0 6
*/