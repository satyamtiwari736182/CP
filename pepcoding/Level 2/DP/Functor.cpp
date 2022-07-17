#include "./header.h"

// function object <- Functor;
//--------------------------------
struct Object
{
    int operator()(int i) const
    {
        return i;
    }
};

int foo(int i) { return i; }
//----------------------------------
struct addFunctor
{
    addFunctor(int x) : m_x(x) {}
    int m_x;
    int operator()(int y)
    {
        return m_x + y;
    }
};
int Add(int x, int y) { return x + y; }
//----------------------------------
void doSomething(int x, int y, string ch)
{
    // does somethig
}
struct DoSomethingFunctor
{
    DoSomethingFunctor(int x, int y, string ch) : x(x), y(y), ch(ch) {}
    int x, y;
    string ch;
    int operator()(int z)
    {
        doSomething(x, y, ch);
        cout << ch << " ";
        return x + y + z;
    }
};

//------------------------------------
struct Dog
{
    Dog(int age, int wt) : m_age(age), m_wt(wt) {}
    bool operator<(Dog const &other) const
    {
        return this->m_age < other.m_age;
    }
    int m_age, m_wt;
};

bool cmp(Dog first, Dog scnd)
{
    return first.m_wt < scnd.m_wt;
}

struct SortByWt
{
    bool operator()(Dog const &lhs, Dog const &rhs) const
    {
        return lhs.m_wt > rhs.m_wt;
    }
};

struct FindByWtFunctor
{
    FindByWtFunctor(int wt) : m_wt(wt) {}
    bool operator()(Dog const &dog) { return m_wt == dog.m_wt; }
    int m_wt;
};

int main()
{
    /*int i = 1, j = 2;
    addFunctor o(3);
    cout << o(i) << "  " << o(j) << endl;*/

    // cout << DoSomethingFunctor(10);
    /*
    DoSomethingFunctor obj(10, 20, "satyam");
    cout << obj(20) << endl;
    */

    vector<Dog> v = {Dog(3, 50), Dog(1, 70), Dog(5, 30), Dog(2, 60), Dog(4, 20)};

    sort(all(v)); // by default sort based on age
    for (auto dog : v)
        cout << dog.m_age << " ";
    cout << endl;

    sort(all(v), cmp); // by default sort based on cmp comparator
    for (auto dog : v)
        cout << dog.m_wt << " ";
    cout << endl;

    sort(all(v), SortByWt()); // by default sort based on functor comparator
    for (auto dog : v)
        cout << dog.m_age << " " << dog.m_wt << ", ";
    cout << endl;

    cout << find_if(all(v), FindByWtFunctor(50))->m_age;

    return 0;
}
