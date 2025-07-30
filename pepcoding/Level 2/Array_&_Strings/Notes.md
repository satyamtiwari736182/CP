Types of problems

- [1] Prefix sum
- [2] Two Pointer Approach
- [3] Sliding window
- [4] Moore voting Algorithm
- [5] Partition labels , Qno. 12_Max Chunk_2
- [6] Qno. 31
- [7] Removing element from search space Qno. 40
- [8] Merge Intervals
- [*] Others
  [9] Where will the ball fall
```cpp
struct Congruence {
    long long a, m;
};

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}
```

<!-- With those two coefficients we can define a solution -->

For all N = a * b
where a >= sqrt(N)  and b <= sqrt(N)

Here the sum is over all positive divisors  
d  of  
n .

If 
a
≡
b
(
m
o
d
m
)
a≡b(modm), then 
a
n
≡
b
n
(
m
o
d
m
)
a 
n
 ≡b 
n
 (modm) for any positive integer 
n
n.

A 
n
 modm≡A 
(nmod(m−1))
 modm