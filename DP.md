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