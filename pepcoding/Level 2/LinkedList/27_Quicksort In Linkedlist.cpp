// 1. Given the head of a linked list, return the list after sorting it in increasing order.
// 2. You must apply quick sort.
// 3. Time Complexity : O(nlogn)
// 4. Space Complexity : constant space

// 4
// 0
// 6
// 7
// 5

class Node
{
public:
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
    Node() : data(0), next(nullptr) {}
};

Node *makeList()
{
    int n;
    cin >> n;
    Node *dummy = new Node(-1);
    Node *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new Node(val);
        prev = prev->next;
    }

    return dummy->next;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *getTail(Node *head)
{
    Node *curr = head, *pivot = nullptr;

    while (curr)
        pivot = curr, curr = curr->next;
    return pivot;
}

int getSize(Node *head)
{
    if (head == nullptr)
        return 0;
    Node *node = head;
    int cnt = 0;
    while (node->next != nullptr)
        node = node->next, cnt++;
    return cnt;
}

vector<Node *> segregate(Node *head, int pivotIdx)
{

    Node *pivot = head;
    while (pivotIdx-- > 0)
        pivot = pivot->next;

    Node *dmyl = new Node(-1), *dmyg = new Node(-1);
    Node *pl = dmyl, *pg = dmyg;
    Node *curr = head;

    while (curr)
    {
        if (curr != pivot)
        {
            if (curr->data <= pivot->data)
                pl->next = curr, pl = pl->next;

            else
                pg->next = curr, pg = pg->next;
        }
        // else
        //     pivot = pivot;
        curr = curr->next;
    }

    pl->next = nullptr;
    pg->next = nullptr;
    pivot->next = nullptr;
    return {dmyl->next, pivot, dmyg->next};
    // return pl;
}

vector<Node *> mergeSortedLists(vector<Node *> &leftSortedList, Node *pivotNode, vector<Node *> &rightSortedList)
{
    Node *head = nullptr, *tail = nullptr;

    if (leftSortedList[0] && rightSortedList[0])
    {
        leftSortedList[1]->next = pivotNode;
        pivotNode->next = rightSortedList[0];
        head = leftSortedList[0];
        tail = rightSortedList[1];
    }

    else if (leftSortedList[0])
    {
        head = leftSortedList[0];
        leftSortedList[1]->next = pivotNode;
        tail = pivotNode;
    }

    else if (rightSortedList[0])
    {
        head = pivotNode;
        pivotNode->next = rightSortedList[0];
        tail = rightSortedList[1];
    }

    else
        head = tail = pivotNode;

    return {head, tail};
}

vector<Node *> quickSort_(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return {head, head};

    int lenth = getSize(head);
    int pivotIdx = lenth / 2;

    vector<Node *> segregatedLists = segregate(head, pivotIdx);

    vector<Node *> leftSortedList = quickSort_(segregatedLists[0]);
    vector<Node *> rightSortedList = quickSort_(segregatedLists[2]);

    return mergeSortedLists(leftSortedList, segregatedLists[1], rightSortedList);
}

Node *quickSort(Node *head)
{
    return quickSort_(head)[0];
}

void solve()
{
    Node *lst1 = makeList();
    // Node *lst2 = makeList();
    int pivotIdx;
    // cin >> pivotIdx;
    lst1 = quickSort(lst1);
    cout << "\n***********\n";

    display(lst1);
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

12
1 5 2 9 5 14 11 1 10 10 1 3

*/