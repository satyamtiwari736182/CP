Types of Problems:

- [1] Permutation and Combination
- [2] Permutation and Combination with [conditional] check -> N-Queen problem.
- [3] Partitioning Qno.35
- [4] Backtracking -> like Flood Fill Problem
- [*] Others
  N-Queen Branch-Bound technique.

- cellNumber = (curr_row-1) * col + curr_col
  curr_row = cellNumber / col
  curr_col = cellNumber % col
