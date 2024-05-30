
# Stack and mergeSort template
### Stack
  	1. Next Greater of an Element to right
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
### MergeSort template [O(n log n)]
	1. Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
>**CPP**<br>
**merge(l1.begin(), l1.end(), l2.begin(), l2.end(), result.begin())** which stores the merged array in result <br>
**inplace_merge(l.begin(), l.middle, l.end())** where array [begin, middle) is merged with array [middle, end)

 ```cpp
 #define iterator vector<vector<int>>::iterator
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

vector<int> countSmaller(vector<int>& nums) {
    vector<vector<int>> hold;
    int n = nums.size();
    for (int i = 0; i < n; ++i) hold.push_back(vector<int>({nums[i], i})); // "zip" the nums with their indices
    vector<int> count(n, 0);
    sort_count(hold.begin(), hold.end(), count);
    return count;
}
```
```md
> Merge Sort is suitable for problems which look for some pairs i, j. such that i < j, and nums[i], nums[j] satisfy some constraints.
We can find such pairs during merge sort. In each recursion, before we merge two sorted subarrays, the i is in the left sorted subarray, and the j is in the right sorted subarray. So, we can just go through both sorted subarray to find the valid i and j pairs. As long as this step is O(n), then total time complexity would be O(n log n).

# Build some linear relation for left and right sorted-array
Now you don't need to take care of the indexes for above type of problems.
# Focus only on countPair()
```

```md
# LeetCode - 493
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
```
```java
int countPair(int nums[],int l,int m,int r){
    int res=0,j=m+1;
    for(int i=l;i<=m;i++){
        while(j<=r && nums[i]> 2l*nums[j])j++;
        res+=j-(m+1);
    }
    return res;
}
void merge(int nums[],int l,int m,int r){
    int n=r-l+1, temp[]=new int[n],i=l,j=m+1,k=0;
    while(i<=m && j<=r){
        if(nums[i]>nums[j])temp[k++]=nums[j++];
        else temp[k++]=nums[i++];
    }
    while(i<=m)temp[k++]=nums[i++];
    while(j<=r)temp[k++]=nums[j++];
    k=0;i=l;
    while(i<=r)nums[i++]=temp[k++];
}
int mergeSort(int nums[],int l,int r){
    if(l>=r)return 0;
    int m=(l+r)/2,res=0;
    res+=mergeSort(nums,l,m);
    res+=mergeSort(nums,m+1,r);
    res+=countPair(nums,l,m,r);
    merge(nums,l,m,r);
    return res;
}
public int reversePairs(int[] nums) {
    return mergeSort(nums,0,nums.length-1);
}
```
```md
# LeetCode - 1512
Given an array of integers nums, return the number of good pairs.
A pair (i, j) is called good if nums[i] == nums[j] and i < j.
```

```java
int countPair(int nums[],int l,int m,int r){
    int res=0;
    int left[]=new int[101],right[]=new int[101];
    for(int i=l;i<=m;i++)left[nums[i]]++;
    for(int i=m+1;i<=r;i++)right[nums[i]]++;
    for(int i=0;i<101;i++)res+=left[i]*right[i];
    return res;
}
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
```md
# Merge Sort
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
```md
There will be some factor(property) which will control the window size of substring or subarray. Focus on that factor and use it for window check.
```

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

```md
# LeetCode - 3
Given a string s, find the length of the longest substring without repeating characters.
```
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
> **Alternate way to code**
```java
public int lengthOfLongestSubstring(String s) {
    int j=0,res=0,count[]=new int[206];
    for(int i=0;i<s.length();i++){
        count[s.charAt(i)]++;
        while(count[s.charAt(i)]>1)count[s.charAt(j++)]--;
        res=Math.max(res,i-j+1);
    }
    return res;
}
```

```md
# LeetCode - 1208
You are given two strings s and t of the same length and an integer maxCost.
You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.
```

```java
public int equalSubstring(String s, String t, int maxCost) {
    int cost=0,res=0,j=0,n=s.length();
    for(int i=0;i<n;i++){
        cost+=Math.abs(s.charAt(i)-t.charAt(i));
        while(j<=i && cost>maxCost){
            cost-=Math.abs(s.charAt(j)-t.charAt(j));
            j++;
        }
        res=Math.max(res,i-j+1);
    }
    return res;
}
```
```md
# LeetCode - 75
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
```
```java
public String minWindow(String s, String t) {
    int reqcount[]=new int[200],count[]=new int[200];
    for(int i=0;i<t.length();i++)reqcount[t.charAt(i)]++;
    int j=0,reqchar=0,start=0,end=0,res=Integer.MAX_VALUE;
    for(int i=0;i<s.length();i++){
        if(reqcount[s.charAt(i)]>0 && reqcount[s.charAt(i)]>count[s.charAt(i)]) reqchar++;
        count[s.charAt(i)]++;
        while(reqchar==t.length()) {
            if((i-j)<res){
                start=j;end=i;
                res=i-j;
            }
            if(reqcount[s.charAt(j)]>0 && reqcount[s.charAt(j)]==count[s.charAt(j)]) reqchar--;
            count[s.charAt(j++)]--;
        }
    }
    return res==Integer.MAX_VALUE?"":s.substring(start,end+1);
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


## 132_pattern subsequence
```cpp
bool find132pattern(vector<int>& nums) {
    int n=nums.size(),msf=INT_MAX;
    vector<int>leftMinimum(n);stack<int>stk;
    for(int i=0;i<n;i++)msf=min(msf,nums[i]),leftMinimum[i]=msf;
    for(int i=n-1;i>0;i--){
        while(!stk.empty()&& stk.top()<=leftMinimum[i])stk.pop();
        if(!stk.empty() && leftMinimum[i]<stk.top() && stk.top()<nums[i])return true;
        stk.push(nums[i]);
    }
    return false;
}
```

# Points to keep in mind

#### _a. When you feel like recursion then think of stacks_
#### _b. When you feel like Longest Increasing Subseq. then think of include and exclude technique not the inclusion-exclusion principle_
#### _c. When substring/subarray with some factor or conditions appears then think of sliding-window_ => **LeetCode - 1208**

## Tips
> **(2i + 1) % ( n|1 )** => _It gives set of odd numbers followed by even numbers_<br>
_loop **i 0 to n** step 1_

> _**cellNumber = curr_row * col + curr_col**_<br>
 **curr_row = cellNumber / col <br> curr_col = cellNumber % col**

>**int rightmost_set_bit = n & -n;**
