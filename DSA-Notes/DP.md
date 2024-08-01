#    # *Keep your mind open and think realistic, cunning and clever ways 😊😁.* Be selfish to find best solution 🤩🤣
# Dyanamic Programming
    [1] Largest square matrix.
### 2. Print paths with minimum jumps.
```md
# LeetCode - 45
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
    0 <= j <= nums[i] and
    i + j < n
```
```cpp
class Pair
{
public:
    int i, j, s;
    string psf;
    Pair(int i, int j, int s, string psf)
    {
        this->i = i;
        this->j = j;
        this->s = s;
        this->psf = psf;
    }
};

void solve(vector<int> arr){
    int n=arr.size(), dp[n];
    fill(dp, dp + n, -1);

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1) dp[i] = 0;
        if (arr[i] > 0)
        {
            int val = INT_MAX;
            for (int j = 1; j <= arr[i]; j++)
                if ((i + j) < n && dp[i + j] != -1)
                    val = min(dp[i + j], val);
            
            dp[i] = val + 1;
        }
    }

    queue<Pair> que;
    que.push(Pair(0, arr[0], dp[0], "0"));
    cout << dp[0] << endl;
    while (!que.empty())
    {
        Pair temp = que.front();
        if (temp.s == 0)
            cout << temp.psf << "." << endl;
        for (int i = 1; i <= temp.j; i++)
            if ((temp.i + i) < n && dp[temp.i + i] != -1 && dp[temp.i + i] == temp.s - 1)
                que.push(Pair(temp.i + i, arr[temp.i + i], dp[temp.i + i], temp.psf + " -> " + to_string(temp.i + i)));
        que.pop();
    }
}
```
### 3. Longest Increasing Subsequence. 
```cpp
int lengthOfLIS(vector<int>& nums) {
    int n=nums.size(),ans=1,dp[n+1];
    fill(dp,dp+n+1,0);
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        int cnt=0;
        for(int j=i-1;j>=0;j--)if(nums[j]<nums[i])cnt=max(cnt,dp[j]);
        dp[i]=cnt+1;
        ans=max(ans,dp[i]);
    }
    return ans;
}
```
---
```md
# LeetCode - 368
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
```
```java
public List<Integer> largestDivisibleSubset(int[] nums) {
    int n=nums.length, dp[]=new int[n],maxlen=0,pos=-1,parent[]=new int[n];
    Arrays.sort(nums);Arrays.fill(parent,-1);Arrays.fill(dp,1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++) if(nums[j]%nums[i]==0 && dp[j]<dp[i]+1){
            dp[j]=dp[i]+1;
            parent[j]=i;
        }
        if(maxlen<dp[i]){
            maxlen=dp[i];
            pos=i;
        }
    }
    List<Integer> res=new ArrayList<>();
    while(pos!=-1){
        res.add(nums[pos]);
        pos=parent[pos];
    }
    return res;
}
```
### 4. Catalan Number
```md
# LeetCode - 96
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
```
```cpp
int dp[21];
int nomOfBST(int n){
    if(n<=1)return 1;
    int res=0;
    if(dp[n])return dp[n];
    for(int i=0;i<n;i++) res+=nomOfBST(i)*solve(n-i-1);
    return dp[n]=res;
}
```
### 5. Matrix Chain Multiplication

```cpp
int matrixMultiplication(int n, int arr[])
{
    int dp[105][105],mod=1e9+7;
    for(int g=0;g<n;g++)for(int i=0,j=g;j<n;i++,j++){
        if(g==0)dp[i][j]=0;
        else if(g==1)dp[i][j]=arr[i]*arr[i+1]*arr[j+1];
        else{
            int ans=INT_MAX;
            for(int k=i;k<j;k++)ans= min(ans,(dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1])%mod);
            dp[i][j]=ans;
        }
    }
    return dp[0][n-2];
}
```
### 6. Rod Cutting maxProfit
```cpp
int cutRod(int price[], int n) {
    int dp[1001]={0};
    for(int i=0;i<n;i++)dp[i+1]=price[i];
    for(int i=0;i<=n;i++)for(int j=0;j<=i/2;j++)dp[i]=max(dp[i],dp[j]+dp[i-j]);
    return dp[n];
}
```
### 7. Longest Common Subsequences
```cpp
int dp[1001][1001];
string str1="",str2="";
int solve(int m,int n){
    for(int i=m;i>=0;i--) for(int j=n;j>=0;j--){
        if(i==m || j==n) continue;
        else if(str1[i]==str2[j]) dp[i][j]=1+dp[i+1][j+1];
        else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
    }
    return dp[0][0];
}

int longestCommonSubsequence(string text1, string text2) {
    str1=text1,str2=text2;
    return solve(str1.length(),str2.length());
}
```
### 8. Longest Common SubString
```java
int longestCommonSubstr(String s1, String s2){
    
    int dp[][] = new int[s1.length()+1][s2.length()+1];
    int maxLength = Integer.MIN_VALUE;
    for(int i=0;i<=s1.length();i++) {
        for(int j=0;j<=s2.length();j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1.charAt(i-1)==s2.charAt(j-1))  dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = 0;
            maxLength = Math.max(maxLength, dp[i][j]);
        }
    }
    return (maxLength==Integer.MIN_VALUE)?0:maxLength;
}
```

### 9. WildCard pattern matching
```md
# LeetCode - 44
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
```
```cpp
bool isMatch(string str, string patt) {
    int n=patt.length(),m=str.length(),dp[2005][2005];
    fill(&dp[0][0],&dp[n+1][m+1],0);
    dp[n+1][m+1]=true;
    for(int i=n;i>=0;i--)for(int j=m;j>=0;j--){
        if(patt[i]==str[j] || patt[i]=='?')dp[i][j]=dp[i+1][j+1];
        else if(patt[i]=='*' && j==m)dp[i][j]=dp[i+1][j];
        else if(patt[i]=='*') dp[i][j] = dp[i+1][j] || dp[i][j+1];
        else dp[i][j]=false;
    }
    
    return dp[0][0];
}
```
### 10. Regular expression matching
```md
# LeetCode - 10
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
```
```cpp
bool isMatch(string str, string pattern) {
    str=" "+str,pattern=" "+pattern;
    int n=pattern.length(),m=str.length(),dp[30][30];
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
    {
        if (i == 0 && j == 0) dp[i][j] = true;
        else if (j == 0) {if (pattern[i] == '*') dp[i][j] = dp[i - 2][j];}
        else if (pattern[i] == '*')
        {
            dp[i][j] = dp[i - 2][j];
            if (pattern[i - 1] == str[j] || pattern[i - 1] == '.') dp[i][j] |= dp[i][j - 1];
        }
        else if (pattern[i] == str[j] || pattern[i] == '.') dp[i][j] = dp[i - 1][j - 1];
        else dp[i][j] = false;
        
    }

    return dp[n-1][m-1];
}

// mississippi m*s*i.*p*i
```
### 11. Edit distance.
```md
# LeetCode - 72
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
    Insert a character
    Delete a character
    Replace a character
```
```cpp
int dp[501][501];
int minDistance(string str1, string str2) {      
    int n = str1.size(),m=str2.size();
    for(int i=0;i<n+1;i++)for(int j=0;j<m+1;j++){
        if(i==0)dp[i][j] = j;
        else if(j==0)dp[i][j] = i;
        else if(str1[i-1]==str2[j-1])dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = 1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
    }
    return dp[n][m];  
}
```
### 12. Kadane's Algorithms
```cpp
int maxSumSubArray(vector<int>& nums) {
    int max_so_far=INT_MIN;
    int max_ending_here=0;
    for(int i=0;i<nums.size();i++){
        max_ending_here += nums[i];
        if(max_so_far < max_ending_here) 
            max_so_far = max_ending_here;
        if(max_ending_here < 0) max_ending_here = 0;
    }
    return max_so_far;
    
}
```


### 13. Egg Drop (Game strategies)
```md
# LeetCode - 887
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.
You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.
Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.
Return the minimum number of moves that you need to determine with certainty what the value of f is.
```
```cpp
int superEggDrop(int k, int n) {
    int dp[105][10005];
    fill(&dp[0][0],&dp[k+1][n+1],0);
    for(int e=0;e<=k;e++)for(int f=0;f<=n;f++){
        if(e==0)dp[e][f]=0;
        else if(f==0||f==1)dp[e][f]=f;
        else if(e==1)dp[e][f]=f;
        else{
            int ans=INT_MAX,lo=1,hi=f;
            while(lo<=hi){
                int midFloor=(lo+hi)/2;
                int belowCriticalFloorAttempts=dp[e-1][midFloor-1];
                int aboveCriticalFloorAttempts=dp[e][f-midFloor];
                int maximumAttempts=1+max(belowCriticalFloorAttempts,aboveCriticalFloorAttempts);
                
                if(belowCriticalFloorAttempts < aboveCriticalFloorAttempts) lo=midFloor+1;
                else hi=midFloor-1;

                ans=min(ans,maximumAttempts);
            }

            // for(int rthFloor=1;rthFloor<f;rthFloor++) {
            //     int maximumAttemps=1+max(dp[e][rthFloor-1],dp[e-1][f-rthFloor]);
            //     ans=min(ans,maximumAttemps);
            // }
            dp[e][f]=ans;
        }
    }
    return dp[k][n];
}
```
### 14. Count distinct palindromic subsequences
```md
# LeetCode - 730
Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.
A subsequence of a string is obtained by deleting zero or more characters from the string.
A sequence is palindromic if it is equal to the sequence reversed.
Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.
```
```cpp
int mod=1e9+7;
long long int dp[1001][1001];
int countPalindromicSubsequences(string str) {
    int n=str.length();
    int rightNext[1001],leftNext[1001];
    map<char,int>occurrence;
    for(int i=0;i<n;i++){
        char ch=str[i];
        if(occurrence.find(ch)==occurrence.end()) leftNext[i]=-1;
        else leftNext[i]=occurrence[ch];
        occurrence[ch]=i;
    }
    occurrence.clear();
    for(int i=n-1;i>=0;i--){
        char ch=str[i];
        if(occurrence.find(ch)==occurrence.end()) rightNext[i]=-1;
        else rightNext[i]=occurrence[ch];   
        occurrence[ch]=i;
    }

    for(int g=0;g<n;g++)for(int i=0,j=g;j<n;j++,i++){
        if(g==0)dp[i][j]=1;
        else if(str[i]!=str[j])dp[i][j]=(dp[i+1][j]+dp[i][j-1]- dp[i+1][j-1]+mod)%mod;
        else {
            int right=rightNext[i],left=leftNext[j];
            if(right==j && left==i) dp[i][j]=(2*dp[i+1][j-1]+2)%mod;     //if(right==j && left==i)
            else if(right==left)dp[i][j]=(2*dp[i+1][j-1]+1)%mod;
            else if(right<left)dp[i][j]=(2*dp[i+1][j-1]-dp[right+1][left-1]+mod)%mod;
        }
    }
    
    return dp[0][n-1];
}
```

### 15. 0-1 Knapsack
```cpp
int main(int n, int cap,int wt[],int prof[])
{
    int dp[n + 1][cap + 1];
    fill(*dp, *dp + (n + 1) * (cap + 1), 0);

    for (int obj = 0; obj <= n; obj++)for (int currCapacity = 0; currCapacity <= cap; currCapacity++){
            if (obj == 0 || currCapacity == 0) dp[obj][currCapacity] = 0;
            else if (currCapacity < wt[obj]) dp[obj][currCapacity] = dp[obj - 1][currCapacity];
            else dp[obj][currCapacity] = max(dp[obj - 1][currCapacity], prof[obj] + dp[obj - 1][currCapacity - wt[obj]]);
    }
    return dp[n][cap];
}
```
### Greedy
```md
# LeetCode - 502
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.
```
```java
public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
    int n=profits.length,projects[][]=new int[n][2],res=w,i=0;
    for(int j=0;j<n;j++){
        projects[j][0]=capital[j];
        projects[j][1]=profits[j];
    }
    Arrays.sort(projects,(a,b)->a[0]-b[0]);
    PriorityQueue<int[]>que=new PriorityQueue<>((a,b)->b[1]-a[1]);
    while(i<n && projects[i][0]<=w)que.add(projects[i++]);
    while(!que.isEmpty() && k>0){
        int temp[]=que.poll();
        res+=temp[1];
        k--;
        while(i<n && projects[i][0]<=res)que.add(projects[i++]);
    }
    return res;
}
```


# DP with bitmasking
```md
# LeetCode - 464
In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.Also the players cannot re-use integers. 
Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.
```
>**1. DP Without Bitmasking** -> gives **TLE**
```java
boolean canIWinFrom(int maxChoosableInteger, int desiredTotal, boolean[] used,Map<String,Boolean>dp) {
    if (desiredTotal <= 0) return false; 
    String key=Arrays.toString(used);
    if(dp.containsKey(key)) return dp.get(key);
    for (int i = 1; i <= maxChoosableInteger; i++) {
        if (used[i]) continue;
        used[i] = true;
        if (canIWinFrom(maxChoosableInteger, desiredTotal - i, used,dp)==false) {// current player's opponents fails so i won
            used[i] = false;
            dp.put(key,true);
            return true;
        }
        used[i] = false;
    }
    dp.put(key,false);
    return false;
}

```
>**2. DP With Bitmasking**

```java
boolean canIWinFrom(int maxChoosableInteger, int desiredTotal, int used,Boolean dp[]) {
    if (desiredTotal <= 0) return false;
    if(dp[used]!=null)return dp[used];
    for (int i = 1; i <= maxChoosableInteger; i++) {
        if ((used & (1<<i))!=0) continue;
        used ^= (1<<i);
        if (canIWinFrom(maxChoosableInteger, desiredTotal - i, used,dp)==false) {
            used ^= (1<<i);
            return dp[used]=true;
        }
        used ^= (1<<i);
    }
    return dp[used]=false;
}
```
---
```md
# LeetCode - 847
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge. Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
```
```java
public int shortestPathLength(int[][] graph) {
    int res=Integer.MAX_VALUE,allVisited=(1<<graph.length)-1;
    Deque<int[]>que=new LinkedList<>();
    Set<Integer> visitedState=new HashSet<>();
    
    for(int i=0;i<graph.length;i++){// Simultaneously BFS
        que.addFirst(new int[]{1<<i,i,0});//visited node set,src,path(dist);
        visitedState.add((1<<i)*16+i);
    }
    
    while(!que.isEmpty()){
        int temp[]=que.removeFirst();
        if(temp[0]==allVisited) return temp[2];
        for(int nbr:graph[temp[1]]){
            int state=(temp[0] | (1<<nbr))*16+nbr;
            if(!visitedState.contains(state)){
                que.addLast(new int[]{temp[0] | (1<<nbr),nbr,temp[2]+1});
                visitedState.add(state);
            }
        }
    }
    return -1;
}
    
```

# Digit DP
> In this solve problem from **left to right** i-e **MSB to LSB** on a given number;

```md
# LeetCode - 600
Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.
```
>1. Without digit dp simple dp fails -> TLE
```java
public int findIntegers(int n,int len,int i,int prev,int asf) {
    if(asf>n)return 0;
    if(i>len) return asf<=n?1:0;
    int res=0;
    if(prev==1)res+=findIntegers(n,len,i+1,0,asf);
    else res+=findIntegers(n,len,i+1,0,asf)+findIntegers(n,len,i+1,1,asf|(1<<i));
    return res;
}
public int findIntegers(int n) {
    int len=(int)(Math.log(n)/Math.log(2));
    return findIntegers(n,len,0,0,0);
}
```

>2. With Digit DP
```java
public int findIntegers(int n,int i,int tight,int prev,Integer dp[][][]) {
    if(i==32) return 1;
    int res=0,limit=tight==1?(n>>(31-i))&1:1;

    if(dp[i][tight][prev]!=null) return dp[i][tight][prev];
    for(int k=0;k<=limit;k++){
        if(k==1 && prev==1)continue;
        res+=findIntegers(n,i+1,(tight & (k==limit?1:0)),k==1?1:0,dp);
    }
    return dp[i][tight][prev]=res;
}
public int findIntegers(int n) {
    Integer dp[][][]=new Integer[33][2][2];
    return findIntegers(n,0,1,0,dp);
}
```
```md
So basically tight here determines if the particular bit is tight or not i-e is it the upper limit of the number that can be generated 
If the tight if false the it will be false always in the next calls as the number will always be smaller than the upper limit given 
If the upper limit is true then it is true again if the bit taken is again the upper limit at that position but if the bit taken at that 
positon is not the upper one then tight will become false....
Agar pichla banda upperlimit h to agalr banda tight hoga warna nahi hoga.....
```
---
```md
# LeetCode - 902
Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
Return the number of positive integers that can be generated that are less than or equal to a given integer n.
```
```java
Integer dp[][];
public int atMostNGivenDigitSet(String[] digits, String num,int i,int tight) {
    if(i==num.length())return 1;
    int limit=tight==1?(int)(num.charAt(i)-'0'):10;
    int res=0;
    if(dp[i][tight]!=null) return dp[i][tight];
    for(int k=0;k<digits.length && Integer.parseInt(digits[k])<=limit;k++)
        res+=atMostNGivenDigitSet(digits,num,i+1,(tight==1 && Integer.parseInt(digits[k])==limit)?1:0 );
    return dp[i][tight]=res;
}
public int atMostNGivenDigitSet(String[] digits, int n) {
    dp=new Integer[12][2];
    int res=atMostNGivenDigitSet(digits,n+"",0,1);
    for(int i=1;i<(n+"").length();i++)
        res+=atMostNGivenDigitSet(digits,n+"",i,0);
    return res;
}
```
# DP + Alpha (Tricks/DS) [ something ending at index i ]
```md
# LeetCode - 413
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.
A subarray is a contiguous subsequence of the array.
```

```java
public int numberOfArithmeticSlices(int[] nums) {
    int dp[]=new int[nums.length],res=0;
    for(int i=2;i<nums.length;i++) if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
        dp[i]=dp[i-1]+1;
        res+=dp[i];
    }
    return res;
}
```
```md
# LeetCode - 446
Given an integer array nums, return the number of all the arithmetic subsequences of nums.
A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.
```
```java
public int numberOfArithmeticSlices(int[] nums) {
    int n=nums.length,res=0;
    Map<Integer,Integer> dp[]=new Map[n]; // List<int[]>lst[]=new List[n]; in java
    for(int i=0;i<n;i++)dp[i]=new HashMap<>();

    for(int i=1;i<n;i++) for(int j=0;j<i;j++){
        long cdiff=(long)nums[i]-nums[j];
        if(cdiff<=Integer.MIN_VALUE || cdiff>=Integer.MAX_VALUE)continue;
        int diff=(int)cdiff;
        dp[i].put(diff,dp[i].getOrDefault(diff,0)+dp[j].getOrDefault(diff,0)+1);
        res+=dp[j].getOrDefault(diff,0);
    }
    return res;
}
```
```cpp
// The element dp[i][d] represents the number of arithmetic subsequences ending at index i with a common difference d
int numberOfArithmeticSlices(std::vector<int>& nums) {
    int n = nums.size(),total_count = 0;
    unordered_map<int, int>dp[n];
    for (int i = 1; i < n; ++i) for (int j = 0; j < i; ++j) {
        long long diff = static_cast<long long>(nums[i]) - nums[j]; 
        if (diff > INT_MAX || diff < INT_MIN) continue; 
        int diff_int = static_cast<int>(diff);
        dp[i][diff_int] += 1 + dp[j][diff_int]; //  dp[i][diff_int]=it has no. of element >= 2
        total_count += dp[j][diff_int]; // since dp[j][diff_int] has no. of element >= 3 so it will contribute in ans.
        
    }

    return total_count;
}
```


# Attentions
```md
# LeetCode - 1423
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
```
#### a. with DP approach it fails
```java
Integer dp[][];
int dfs(int[] cardPoints,int i,int j,int k){
    if(k==0) return 0;
    if(i>=cardPoints.length || j<i) return Integer.MIN_VALUE;
    if(dp[i][j]!=null) return dp[i][j];
    return dp[i][j]=Math.max(cardPoints[i]+dfs(cardPoints,i+1,j,k-1),cardPoints[j]+dfs(cardPoints,i,j-1,k-1));
}
public int maxScore(int[] cardPoints, int k) {
    dp=new Integer[cardPoints.length][cardPoints.length];
    return dfs(cardPoints,0,cardPoints.length-1,k);
}
```

#### b. with prefixSum and suffixSum it get accepted
```java
public int maxScore(int[] cardPoints, int k) {
    int n=cardPoints.length, suffixSum[]=new int[k+1],prefixSum[]=new int[k+1],res=0;
    for(int i=0;i<k;i++){
        prefixSum[i+1]=prefixSum[i]+cardPoints[i];
        suffixSum[i+1]=suffixSum[i]+cardPoints[n-1-i];        
    }
    for(int i=0;i<=k;i++)res=Math.max(res,prefixSum[i]+suffixSum[k-i]);
    return res;   
}
```
#### c. Another approach => removing ( n-k ) sized window's SubArraySum from totalSum

# Simultaneouly running two DFS.
```md
# LeetCode - 741
You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
    0 means the cell is empty, so you can pass through,
    1 means the cell contains a cherry that you can pick up and pass through, or
    -1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:

Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
```

```java
Integer dp[][][][];
public int cherryPickup(int[][] grid,int i,int j,int r,int c) {
    
    if(i==grid.length || j==grid[0].length || r==grid.length || c==grid[0].length || grid[i][j]==-1 || grid[r][c]==-1) return Integer.MIN_VALUE;
    if(i==grid.length-1 && j==grid[0].length-1) return grid[i][j];

    if(dp[i][j][r][c]!=null) return dp[i][j][r][c];
    // vv, hh, hv, vh
    int res=Math.max(Math.max(cherryPickup(grid,i+1,j,r+1,c),cherryPickup(grid,i,j+1,r,c+1)),
                    Math.max(cherryPickup(grid,i,j+1,r+1,c),cherryPickup(grid,i+1,j,r,c+1)));
    
    if(i==r && j==c)res+=grid[i][j]; // pick once
    else res+=grid[i][j]+grid[r][c];
    
    return dp[i][j][r][c]=res;
}
public int cherryPickup(int[][] grid) {
    int n=grid.length;
    dp=new Integer[n][n][n][n];
    int res=cherryPickup(grid,0,0,0,0);
    return res<0?0:res;
}
```


## Tips
> 1. Set bits of Binary number from 0 to n can denotes all the possible subsets