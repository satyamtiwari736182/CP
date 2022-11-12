#include "./header.h"
#define str_to_tok(str, deli, arr, val)         \
    {                                           \
                                                \
        stringstream strtokenize(str);          \
        string tok;                             \
        while (getline(strtokenize, tok, deli)) \
        {                                       \
            stringstream strm(tok);             \
            strm >> val;                        \
            arr.pb(val);                        \
        }                                       \
    }
class Pairs
{
public:
    int bi, ei, wi;
    Pairs(int bi, int ei, int wi) : bi(bi), ei(ei), wi(wi) {}
};

// int fun() {}
int main()
{
    cout << "hello!\n";
    string str;
    getline(cin, str);
    vi arr;
    int val;
    str_to_tok(str, ' ', arr, val);
    int x = arr[0], s = arr[1], r = arr[2], t = arr[3], n = arr[4];
    r = r - s;
    vector<Pairs> walkways;
    int i = 5, temp = n;

    while (temp-- > 0)
    {
        int bi = arr[i++];
        int ei = arr[i++];
        int wi = arr[i++];
        walkways.push_back(Pairs(bi, ei, wi + s));
    }

    sort(all(walkways), [=](Pairs p1, Pairs p2)
         { return p1.bi < p2.bi; });

    walkways.push_back(Pairs(0, walkways[0].bi, s));

    sort(all(walkways), [=](Pairs p1, Pairs p2)
         { return p1.bi < p2.bi; });

    cout << endl;

    double timeTaken = 0, dist = 0, idx = 0;

    while (dist < x)
    {
        if (dist > walkways[idx].ei)
            idx++;
        double remDist = x - dist;
        if (t-- > 0)
        {
            if (remDist < (walkways[idx].wi + r))
            {
                dist = x;
                timeTaken += (remDist * 1.0) / (walkways[idx].wi + r);
                break;
            }
            else
                dist += walkways[idx].wi + r;
        }
        else
        {
            if (remDist < (walkways[idx].wi))
            {
                dist = x;
                timeTaken += (remDist * 1.0) / (walkways[idx].wi);
                break;
            }
            else
                dist += walkways[idx].wi;
        }

        timeTaken++;
    }

    cout << timeTaken;

    return 0;
}

// 10 1 4 1 2 4 6 1 6 9 2

// 12 1 2 4 1 6 12 1