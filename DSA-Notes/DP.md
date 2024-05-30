#    # *Keep your mind open and think realistic, cunning and clever ways 😊😁.* Be selfish to find best solution 🤩🤣
# Dyanamic Programming
    [1] Largest square matrix.
    [2] Print paths with minimum jumps.
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
### 4. Catalan Number -> Number of BST
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
    [14] Count distinct palindromic subsequences

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


# DP with bitmasking
> **LeetCode - 464**

    In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.Also the players cannot re-use integers. 
    Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.
>**1. DP Without Bitmasking** -> gives **TLE**
```java
class Solution {
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

> **LeetCode-847**

    You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge. Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
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
# LeetCode - 600. Non-negative Integers without Consecutive Ones
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
### <hr>

> Given an array of digits which is sorted in non-decreasing order. You can write numbers using each digits[i] as many times as we want. For example, if digits = ['1','3','5'], we may write numbers such as '13', '551', and '1351315'.
 <br>Return the number of positive integers that can be generated that are less than or equal to a given integer n.

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

## Tips
> 1. Set bits of Binary number from 0 to n can denotes all the possible subsets