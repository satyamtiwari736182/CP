//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<utility>
// using namespace std;
// int main(){
//	cout<<"hello!"<<endl;
//	int ar[]={1,1,2,2,2,0,30,20,10,10,20};
//	vector<int> vec={1,1,2,2,2,4,5,6};
//	cout<<*min_element(vec.begin()+3,vec.end())<<" "<<*min_element(ar,ar+4)<<endl;
//	cout<<*max_element(vec.begin()+3,vec.end())<<" "<<*max_element(ar,ar+4)<<endl;
//
//	pair<int,int> pr={20,56};
//
//	cout<<pr.first<<" "<<pr.second<<endl;
//	cout<<equal(ar,ar+6,vec.begin())<<endl;
//
//	pair<int*,vector<int>::iterator>range=mismatch(ar,ar+8,vec.begin());
//	cout<<*range.first<<" "<<*range.second<<endl;
//	return 0;
//}

//--------------------------------------------------------------------------------

#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    cout << "hello!" << endl;
    const int n = 12;
    //	cin>>n;
    bitset<n> bs(121);
    cout << bs << endl;
    bs.set(10, 5);
    cout << bs << endl;
    cout << bs.none() << endl;
    return 0;
}
/*
char str[100];
    vi arr;
    cin.getline(str, 100);
    // fflush(stdout);
    char *ch = strtok(str, " ");
    string tok;
    while (ch != NULL)
    {
        cout << ch << endl;
        ch = strtok(NULL, " ");
    }
*/

/*
string str;
    cin>>str;
    stringstream strm(str);
    int val;
    strm >> val;
    cout<<val*4<<endl;
*/

/*

#include <stdio.h>
int main()
{
    char character;
    char string[500];
    char sentence[500];
    scanf("%c", &character);
    scanf("%s", string);

    fflush(stdin);

    scanf("%[^\n]s", sentence);

    // fgets(sentence, 500, stdin);

    printf("Your character: %c\n", character);
    printf("Your string: %s\n", string);
    printf("Your sentence: %s\n", sentence);
}
*/