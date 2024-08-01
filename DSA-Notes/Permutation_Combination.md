
# Permuation
**There are two ways to do permutation**

**1. taken an object/item, it can be placed at any available empty position and so on for next item**.

```cpp
void permute(int item,string str,vector<char>&res,unordered_map<char,int>&lastIndex){

    if(item==str.length()){
        for(int i=0;i<res.size();i++)cout<<res[i];
        cout<<", ";
        return;
    }
    int prevIndex=lastIndex[str[item]];
    for(int i=prevIndex+1;i<res.size();i++)if(res[i]=='\0'){
        res[i]=str[item],lastIndex[str[item]]=i;
        permute(item+1,str,res,lastIndex);
        res[i]='\0',lastIndex[str[item]]=prevIndex;
    }       
}
```
> Here we track the lastIndex of the character to avoid duplication(permutation) when again same character encountered.-> aa,aa

---
**2. consider a postion where any unplaced object can be placed and so on for next position**.

```cpp
void permute(int pos,vector<char>&res,map<char,int>&items){
    if(pos==res.size()){
        for(int i=0;i<res.size();i++)cout<<res[i];
        cout<<", ";
        return;
    }
    for(auto &item:items)if(item.second>0){
        res[pos]=item.first,item.second--;
        permute(pos+1,res,items);
        res[pos]='\0',item.second++;
    }   
}
```


# Combination

**There are two ways to select the required number of object**

**1. To select an object/item i-e either you accept the object or reject it following the condition make the solution**.

```cpp
void select(int item,int k,string asf,string str){
    if(item==str.length()){
        if(asf.length()==k)cout<<asf<<", ";
        return;
    }
    select(item+1,k,asf+str[item],str);
    select(item+1,k,asf,str);
}

abcd, abc, abd, ab, acd, ac, ad, a, bcd, bc, bd, b, cd, c, d, ,
```
---

**2. To select the required number of object make the combination of all without considering the same object for which choices has been made**.

```cpp
void select(int lastItemDecision,int k,string asf,string str){
    if(asf.length()==k){
        cout<<asf<<", ";
        return;
    }
    for(int item=lastItemDecision+1;item<str.length();item++) 
        select(item,k,asf+str[item],str);
}

, a, ab, abc, abcd, abd, ac, acd, ad, b, bc, bcd, bd, c, cd, d,
```


# Permutation and Combination

      Means select few items from many and also permute them
*In this case first we have to choose the required item and then permute them, thus combination technique is used*.

**1. By Using combiantion [1]: reject the item or select it and place it at any available empty position**

```cpp
void selectAndPermute(int item,int k,int ssf,vector<char> &position,string str){

    if(item==str.length())
    {
        if(ssf==k)
        {
            for(char itm:position)cout<<itm;
            cout<<", ";
        }
        return;
    }
    selectAndPermute(item+1,k,ssf,position,str);
    for(int i=0;i<position.size();i++)if(position[i]=='\0'){
        position[i]=str[item];
        selectAndPermute(item+1,k,ssf+1,position,str);
        position[i]='\0';
    }
}
```
---
**2. By Using combiantion [2]: make combination of items with permutation i-e even consider those item for which choices has been made except the current selected ones**.

```cpp
void selectAndPermute(int k,string asf,string str,unordered_set<char>&selected){
    if(asf.length()==k){
        cout<<asf<<", ";
        return;
    }

    for(int item=0;item<str.length();item++)
        if(selected.count(str[item])==false){
            selected.insert(str[item]);
            selectAndPermute(k,asf+str[item],str,selected);
            selected.erase(str[item]);
        }
}
```

# Partitioning

```cpp
// partition n elements in k subsets and print all such configurations.
int counter = 0;
void solution(int i, int n, int k, int nos, vvi &res)
{
    if (i > n)
    {
        if (nos == k) // no. of set
        {
            cout << counter++ << ". ";
            for (auto Set : res)
            {
                cout << "[";
                for (int j = 0; j < Set.size(); j++)
                    cout << Set[j] << (j != Set.size() - 1 ? "," : "");
                cout << "] ";
            }
            cout << endl;
        }
        return;
    }
    for (int Set = 0; Set < res.size(); Set++)
    {
        if (res[Set].size() > 0)
        {
            res[Set].pb(i);
            solution(i + 1, n, k, nos, res);
            res[Set].pop_back();
        }

        else
        {
            res[Set].pb(i);
            solution(i + 1, n, k, nos + 1, res);
            res[Set].pop_back();
            break;
        }
    }
}
```
---