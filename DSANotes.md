
# 4. Array & Strings.
    [1] Prefix sum
    [2] Two Pointer Approach
    [3] Sliding window
    [4] Moore voting Algorithm
    [5] Partition labels , Qno. 12_Max Chunk_2
    [6] Qno. 31
    [7] Removing element from search space Qno. 40
    [8] Merge Intervals


# 6. Recursion & Backtracking
    [1] Permutation and Combination
    [2] Permutation and Combination with [conditional] check -> N-Queen problem.
    [4] Backtracking -> like Flood Fill Problem
    [5] N-Queen Branch-Bound technique.


> _**cellNumber = curr_row * col + curr_col**_<br>
 **curr_row = cellNumber / col <br> curr_col = cellNumber % col**
# 7. Stack & Queue
    [1] Next Greatest Elements
    [2] Largest Area Histogram - 2
    [3] Remove Outermost Parentheses
    [4] Score of Prarentheses
    [5] Basic Calculator III
    [7] remove duplicate letters
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

# 9. BitsManupulation
# 10. Tries
