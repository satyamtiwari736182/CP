// 1. You are given N strings which represents N different skills related to I.T field.
// 2. You are working on a project and you want to hire a team of software developers for that project.
// 3. There are N applicants. Every applicant has mentioned his/her skills in resume.
// 4. You have to select the minimum number of developers such that for every required skill, there is 
//      at least one person in the team who has that skill.
// 5. It is guaranteed that you can form a team which covers all the required skills.

// Note -> Check out the question video for details.


#include "../header.h"

vi ans;
void sol(auto &people, int nskills, int cp, vi onesol, int smask)
{
    if (cp == people.size())
    {
        if (smask == ((1 << nskills) - 1))
            if (ans.size() == 0 || onesol.size() < ans.size())
                ans = onesol;
        return;
    }
    sol(people, nskills, cp + 1, onesol, smask); // person not chosen

    onesol.pb(cp);
    sol(people, nskills, cp + 1, onesol, (smask | people[cp]));
    onesol.pop_back(); // helps in backtracking
}

int main()
{
    cout << "\nHello world!" << endl;
    // get skills and prepare the skill mapping
    int ns;
    cin >> ns;
    map<string, int> hashmap;
    for (int i = 0; i < ns; i++)
    {
        string skill;
        cin >> skill;
        hashmap.insert({skill, i});
    }

    int np;
    cin >> np;
    vi people;

    for (int i = 0; i < np; i++)
    {
        int person_skills_cnt;
        cin >> person_skills_cnt;
        people.pb(0);
        for (int j = 0; j < person_skills_cnt; j++)
        {
            string skill;
            cin >> skill;
            int skill_maps = hashmap[skill];
            people[i] = people[i] | (1 << skill_maps);
        }
    }
    cout << "\n========================================\n";
    vi s;
    sol(people, ns, 0, s, 0);
    for (auto prs : ans)
        cout << prs << " ";
    cout << "\n========================================\n";
    return 0;
}

// 3
// java nodejs reactjs
// 3
// 1 java
// 1 nodejs
// 2 nodejs reactjs