
# Stack and mergeSort template
### Stack
  	1. Next Smaller of an Element
 ```cpp
 void nextGreatertoRight(vi &arr){
    stack<int>stk;
    for(int i=arr.size()-1;i>=0;i--){
      while(stk.empty()==false && arr[i]>=stk.top())stk.pop();
      int greater=!stk.empty()?stk.top():-1;
      stk.push(arr[i]),arr[i]=greater;
    }
}
 ```
### mergeSort template
	1. Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
 ```cpp
 #define iterator vector<vector<int>>::iterator
class Solution {
    void sort_count(iterator left, iterator right, vector<int>& count) {
        if (right- left <=1) return;
        iterator mid = left + (right - left) / 2;
        sort_count(left, mid, count);
        sort_count(mid, right, count);

        for (iterator i = left, j=mid; i < mid; i++) {
            //iterator j=mid;
            while (j < right && (*i)[0] > (*j)[0]) j++;
            count[(*i)[1]] += j - mid; // add the number of valid "j"s to the indices of *i
        }

        inplace_merge(left, mid, right);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> hold;
        int n = nums.size();
        for (int i = 0; i < n; ++i) hold.push_back(vector<int>({nums[i], i})); // "zip" the nums with their indices
        vector<int> count(n, 0);
        sort_count(hold.begin(), hold.end(), count);
        return count;
    }
};
```
---
#  Recursion, Divide & Conquor, DP, Backtracking
# Recursion
### When problems required to take some valid decision and on the result futher similar decision need to be taken then the problem is recursive in nature.
>_When Leaf or end result is required solution to problem then it is a **Simple Recursive Problem**._

>_But when decisions *[ Paths ]* becomes the solution then the problem is of **Backtracking Nature**_.

```java
void floodfill(int arr[][], boolean visited[][], int i, int j,vString ans)
{

    if (i < 0 || j < 0 || i >= arr.length || j >= arr[0].length || arr[i][j] == 1 || visited[i][j] == 1) return;

    if (i == n - 1 && j == m - 1)
    {
        cout << ans << " ";
        return;
    }
    visited[i][j] = true;

    floodfill(arr, visited, i, j + 1, n, m, "r" + ans);
    floodfill(arr, visited, i, j - 1, n, m, "l" + ans);
    floodfill(arr, visited, i - 1, j, n, m, "u" + ans);
    floodfill(arr, visited, i + 1, j, n, m, "d" + ans);

    visited[i][j] = false;
}
```

>_When decision is taken on the smallest solvable unit of problem then the problem is of  **Divide & Conquor**._

    1. Merge Sort
 ```cpp
 void merge(int arr[], int l, int m, int r)
    {
        vector<int> temp;
        int left = l,right = m + 1;
        while(left <= m && right <=r){
            if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }
        while(left<=m) temp.push_back(arr[left++]);
        while(right<=r) temp.push_back(arr[right++]);
        arr=temp;
    }

    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
 ```

>In *Simple Recursive Problem* when there is repeating subproblems then the problems is of **DP** nature.


    1. 0/1-knapsack
```cpp

#define vi vector<int>
int knapSack(int capacity, int weight[], int profit[], int n)
{
    vector<vi> dp(n + 1, vi(capacity + 1));

    for (int obj = 0; obj <= n; obj++)
        for (int wt = 0; wt <= capacity; wt++)
        {
            if (obj == 0 || wt == 0) dp[obj][wt] = 0;
            else if (weight[obj] <= wt)
                dp[obj][wt] = max(profit[obj] + dp[obj - 1][wt - weight[obj]], dp[obj - 1][wt]);
            else dp[obj][wt] = dp[obj - 1][wt];
        }
    pmatrix(dp, n + 1, capacity + 1);

    return dp[n][capacity];
}
```

# Two-pointer approach

 ### 1. Sorted array.  
 	1. Bag of Tokens
```cpp
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l=0,r=tokens.size()-1,score=0,res=0;
        sort(all(tokens));
        while(l<=r){
            int flag=0;
            if(power>=tokens[l])score++,power-=tokens[l++],res=max(res,score);
            else if(score>=1)score--,power+=tokens[r--];
            else break;
        }
        return res;
    }
```
 ### 2. Unsorted array
 	1. Container with maximum water
```cpp
    int maxArea(vector<int>& height) {
        int res=0,i=0,j=height.size()-1;
        while(i<j){
            res=max(res,min(height[i],height[j])*(j-i));
            if(height[i]<=height[j])i++;
            else j--;
        }
        return res;
    }
```

<br>

# Sliding Window

 ### 1. Fixed sized window
  	1. maximum sum subarray of size k
```cpp
    long maximumSumSubarray(vector<int> &arr , int k){
        long sum=0,res=0;
        for(int i=0;i<arr.size();i++){
            if(i<k)sum+=arr[i];
            else{
                res=max(res,sum);
                sum+=arr[i];
                sum-=arr[i-k];
            }
        }
        return max(res,sum);
    }
```

 ### 2. Variable sized window 
 	1. longest subarray with sum equals to target
	2. smallest subarray having all distinct char of string str
  	3. Hashmap -> **count** of subarray having all distinct char of string str.
>**a. keep Acquiring the val till [codition] is not met.<br>
    b. Collect [required ans] when [condition] is met<br>
    c. keep Releasing the val till [condition] is voilated**

**Q. Given a string s, find the length of the longest 
substring
 without repeating characters.**
```java
 public int lengthOfLongestSubstring(String s) {
        int i=-1,j=-1,cnt=0,n=s.length()-1;
        Map<Character,Integer>map=new HashMap<>();
        while(j<n){
            while(j<n){
                char ch=s.charAt(++j);
                map.put(ch,map.getOrDefault(ch,0)+1);
                if(map.get(ch)==2) break;
                cnt=Math.max(cnt,j-i);
            }
            while(i<j){
                char ch=s.charAt(++i);
                map.put(ch,map.get(ch)-1);
                if(map.get(ch)==1) break;
            }
        }
        return cnt;
    }
```

# Merge Interval vs prefixSum
### PrefixSum

 	1. Car pooling
```java
  public boolean carPooling(int[][] trips, int capacity) {
        int res[]=new int[1001];
        for(var trip:trips){
            res[trip[1]]+=trip[0];
            res[trip[2]]-=trip[0];
        }
        for(int i=0;i<1000;i++){
            res[i+1]+=res[i];
            if(res[i]>capacity)return false;
        }
        
        return true;
    }
```
### Merge Interval
 	1. Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
```java
public int[][] merge(int[][] intervals) {
        List<int []> res=new ArrayList<>();
        Arrays.sort(intervals,(int a[],int b[])->a[0]-b[0]);
        int prev[]=intervals[0],n=intervals.length;
        for(int i=1;i<n;i++){
            if(prev[1]<intervals[i][0]){
                res.add(prev);
                prev=intervals[i];
            }
            else{
                prev[0]=Math.min(prev[0],intervals[i][0]);
                prev[1]=Math.max(prev[1],intervals[i][1]);
            }
        }  
        res.add(prev);
        return res.toArray(new int[res.size()][]);
    }
```

# Points to keep in mind

#### _a. When you feel like recursion then think of stacks_
#### _b. When you feel like Longest Increasing Subseq. then think of include and exclude technique not the inclusion-exclusion principle_

## Tips
> **(2i + 1) % ( n|1 )** => _It gives set of odd numbers followed by even numbers_<br>
_loop i 0 to n step 1_
