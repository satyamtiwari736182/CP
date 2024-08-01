# Binary Search
```md
# LeetCode - 34
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
```
```cpp
#define all(x) begin(x),end(x)
vector<int> searchRange(vector<int>& nums, int target) {
    int left=-1,right=-1,lo=0,hi=nums.size()-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]==target)
            left=mid,hi=mid-1;
        else if(target<nums[mid]) hi=mid-1;
        else lo=mid+1;
    }
    lo=0,hi=nums.size()-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(nums[mid]==target)
            right=mid,lo=mid+1;
        else if(target<nums[mid]) hi=mid-1;
        else lo=mid+1;
    }
    return {left,right};
    
}
```
---
```md
# LeetCode - 81
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
```
```cpp
bool search(vector<int>& nums, int target) {
    int lo=0,hi=nums.size()-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(nums[mid]==target)return true;
        else if(nums[lo]==nums[mid] && nums[mid]==nums[hi])lo++,hi--;
        else if(nums[lo]<=nums[mid]){
            if(target>=nums[lo] && target<nums[mid])hi=mid-1;
            else lo=mid+1;
        }
        else if(nums[mid]<=nums[hi]){
            if(target>nums[mid] && target<=nums[hi])lo=lo=mid+1;
            else hi=mid-1;
        }
    }
    return false;
}
```
---
```md
# LeetCode - 410
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.
```
```cpp
#define all(x) begin(x),end(x)
int solve(vector<int>& nums, int val){
    int cnt=1,sum=0;
    for(int num:nums){
        sum+=num;
        if(sum>val) sum=num,cnt++;
    }
    return cnt;
}
int splitArray(vector<int>& nums, int k) {
    int lo=*max_element(all(nums)),hi=accumulate(all(nums),0),res=hi;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int numOfSubarray=solve(nums,mid);
        if(numOfSubarray<=k)res=mid,hi=mid-1;
        else if(numOfSubarray>k) lo=mid+1;
    }
    return res;
}
```
# QickSelect
```md
# LeetCode - 215
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?
```
```cpp
int partition(vector<int>&arr, int left, int right, int pivot)
{
    int i = left, j = left;
    while (j <= right){
        if (arr[j] < pivot) j++;
        else swap(arr[i], arr[j]), i++, j++;
    }
    return i - 1;
}

int quickSelect(vector<int>&arr, int left, int right, int k)
{
        int val=-1,pivot = arr[right];
        int pivot_idx = partition(arr, left, right, pivot);

        if (pivot_idx == k) return arr[k];
        else if (k > pivot_idx) val=quickSelect(arr, pivot_idx + 1, right, k);
        else val=quickSelect(arr, left, pivot_idx - 1, k);
    
    return val;
}
    
int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums,0,nums.size()-1,k-1);
}
```
---

# Partition 
```md
# LeetCode - 763
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.
```
```cpp
vector<int> partitionLabels(string str) {
    unordered_map<char,int>map;int n=str.length();
    for(int i=0;i<n;i++)map[str[i]]=i;
    vector<int>res;
    int i=0;
    while(i<n){
        int idx=map[str[i]],strtIdx=i;
        while(i<n && idx>i)idx=max(idx,map[str[i++]]);i++;
        res.push_back(idx-strtIdx+1);
    }
    return res;
}
```
---
```md
# LeetCode - 768
You are given an integer array arr.
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.
```
```cpp
int maxChunksToSorted(vector<int>& arr) {
    int j=0,n=arr.size(),cnt=0;
    while(j<n){
        int i=j,leftMax=arr[j],greater=leftMax,idx=j;
        while(++i<n){
            if(arr[i]<leftMax)idx=i,leftMax=greater;
            else if(arr[i]>=leftMax) greater=max(greater,arr[i]);
        }
        j=idx+1,cnt++;
    }
    return cnt;
}
```
# Moore Voting
```md
# LeetCode - 229
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
```
```cpp
vector<int> majorityElement(vector<int>& nums) {
    int n=nums.size(),val1 = INT_MAX, val2 = INT_MAX, cnt2 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {

        if (nums[i] == val1) cnt1++;
        else if (nums[i] == val2) cnt2++;
        else
        {
            if (cnt1 == 0) val1 = nums[i], cnt1++;
            else if (cnt2 == 0) val2 = nums[i], cnt2++;
            else cnt1--, cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for (int ele : nums)
    {
        if (val1 == ele) cnt1++;
        if (val2 == ele)cnt2++;
    }

    vector<int> res;
    int v=floor(n / 3);
    if (cnt1 > v) res.push_back(val1);
    if (cnt2 > v) res.push_back(val2);

    return res;
}
```
---

# Priority Queue
```md
# LeetCode - 632
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
```

```cpp
typedef vector<int>::iterator itrType;

vector<int> smallestRange(vector<vector<int>>& nums) {
    const auto cmp=[&](auto a,auto b){return *a.first>=*b.first;};
    priority_queue<pair<itrType,itrType>, vector<pair<itrType,itrType>>, decltype(cmp)> pq(cmp);
    int maxi=INT_MIN,mini=INT_MIN;
    for (auto &vec : nums)pq.push({vec.begin(),vec.end()}),maxi=max(maxi,vec[0]);
    if(!pq.empty())mini=*pq.top().first;

    int left=mini,right=maxi;
    while(!pq.empty()){
        auto itr=pq.top();pq.pop();
        mini=*itr.first;
        if(maxi-mini<right-left)right=maxi,left=mini;
        if(itr.first+1!=itr.second)pq.push({itr.first+1,itr.second}),maxi=max(maxi,*(itr.first+1));
        else break;
    }
    return {left,right};
}
```
---

