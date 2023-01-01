//! Merge Sort
/*
* Merge Sort is suitable for problems which look for some pairs i, j
* such that i < j, and nums[i], nums[j] satisfy some constraints.

? We can find such pairs during merge sort. In each recursion, before we merge two sorted subarrays, 
? the i is in the left sorted subarray, and the j is in the right sorted subarray. So, we can just go 
? through both sorted subarray to find the valid i and j pairs. As long as this step is O(n), the 
* total time complexity would be O(n log n).
*/

    // [l, r) is the interval to be sorted
    int sort_count(iterator l, iterator r) {
        if (r - l <= 1) return; 
        // step 1. find the middle
        iterator m = l + (r - l) / 2;
        // step 2. sort left and right subarray
        int count = sort_count(l, m) + sort_count(m, r);
        /* step 3. write your code here for counting the pairs (i, j).*/
				
        // step 4. call inplace_merge to merge
        inplace_merge(l, m, r);
        return count;
    }

//* C++ provides built-ins for merge sort including:

//! merge(l1.begin(), l1.end(), l2.begin(), l2.end(), result.begin()); which stores the merged array in result
//* inplace_merge(l.begin(), l.middle, l.end()) where array [begin, middle) is merged with array [middle, end)

//? LeetCode 315. Count of Smaller Numbers After Self. Return the number of js such that i < j and nums[j] < nums[i].

    #define iterator vector<vector<int>>::iterator
    void sort_count(iterator l, iterator r, vector<int>& count) {
        if (r - l <= 1) return;
        iterator m = l + (r - l) / 2;
        sort_count(l, m, count);
        sort_count(m, r, count);
        for (iterator i = l, j = m; i < m; i++) {
            while (j < r && (*i)[0] > (*j)[0]) j++;
            count[(*i)[1]] += j - m; // add the number of valid "j"s to the indices of *i
        }
        inplace_merge(l, m, r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<vector<int>> hold;
        int n = nums.size();
        for (int i = 0; i < n; ++i) hold.push_back(vector<int>({nums[i], i})); // "zip" the nums with their indices
        vector<int> count(n, 0);
        sort_count(hold.begin(), hold.end(), count);
        return count;
    }



//? LeetCode 493. Reverse Pairs. Return the number of reverse pairs s.t. i < j and nums[i] > 2*nums[j].

    int sort_count(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1) return 0;
        vector<int>::iterator middle = begin + (end  - begin) / 2;
        int count = 0;
        if (begin < middle) count += sort_count(begin, middle);
        if (middle < end) count += sort_count(middle, end);
        vector<int>::iterator i, j;
        for (i = begin, j = middle; i < middle; ++i) { // double pointers trick
            while (j < end && *i > 2L * *j) {
                j++;
            }
            count += j - middle;
        }
        inplace_merge(begin, middle, end);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return sort_count(nums.begin(), nums.end());
    }


//? LeetCode 327. Count of Range Sum. Return the number of range sums that lie in [lower, upper] inclusive-inclusive. Let prefix-array sum be sums[0..n+1], the problem is to find pairs of i and j such that lower <= sums[j] - sums[i] <= upper.

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) sums[i + 1] = sums[i] + nums[i];
        return sort_count(sums, 0, n + 1, lower, upper);
    }
    
    int sort_count(vector<long>& sums, int l, int r, int lower, int upper) {
        if (r - l <= 1) return 0;
        int m = (l + r) / 2, i, j1, j2;
        int count = sort_count(sums, l, m, lower, upper) + sort_count(sums, m, r, lower, upper);
        for (i = l, j1 = j2 = m; i < m; ++i) { 
            // we have two j pointers now and one i pointer, but still linear time
            while (j1 < r && sums[j1] - sums[i] < lower) j1++; 
            while (j2 < r && sums[j2] - sums[i] <= upper) j2++;
            count += j2 - j1;
        }
        inplace_merge(sums.begin() + l, sums.begin() + m, sums.begin() + r);
        return count;
    }