// 1. You are given number N and 2*N number of strings that represent a list of N tickets(source and destination).
// 2. You have to find the itinerary in order using the given list of tickets.

// Assumption -> The input list of tickets is not cyclic and there is one ticket from every city except the final destination.

#include "../header.h"

void findRoute(map<string, string> &hashmap)
{
    map<string, bool> cities;
    string start = "";
    for (auto ticket : hashmap)
    {
        string src = ticket.fs;
        string dest = ticket.se;
        cities[dest] = false;
        if (cities.find(src) == cities.end())
            cities[src] = true;
        else
            cities[src] = false;
    }

    for (auto place : cities)
    {
        string city = place.fs;
        if (place.se)
        {
            start = city;
            cities[city] = false;
        }
    }

    int cnt = cities.size();
    string city = start;
    while (cnt-- > 0)
    {
        if (cities[city] == false)
            cout << " --> " << city;
        cities[city] = true;
        city = hashmap[city];
    }
}

int main()
{

    cout << "\nHello world!" << endl;
    int n,i;
    cin >> n;
    map<string, string> hashmap;
    REP(i,0, n - 1)
    {
        string src, dest; // ticket
        cin >> src >> dest;
        hashmap.insert({src, dest});
    }
    cout << "\n============================================\n";
    findRoute(hashmap);
    cout << "\n============================================\n";
    return 0;
}

// 4
// Chennai Banglore
// Bombay Delhi
// Goa Chennai
// Delhi Goa