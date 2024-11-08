def knapsack(C, n, memo=None):
    if memo is None:
        memo = {}
        
    if (C, n) in memo:           # Check memo table
        return memo[(C, n)]
        
    if n < 0 or C <= 0:          # Base case
        return 0
        
    if wt[n] > C:                # Item weight is greater than remaining capacity
        result = knapsack(C, n - 1, memo)
    else:
        result = max(val[n] + knapsack(C - wt[n], n - 1, memo), knapsack(C, n - 1, memo))
        
    memo[(C, n)] = result        # Store result in memo
    return result

wt = [95, 4, 60, 32, 23, 72, 80, 62, 65, 46]  # Weight array
val = [55, 10, 47, 5, 4, 50, 8, 61, 85, 87]  # Value array
C = 269
n = len(val) - 1    # Start from the last index

print("Max Value is:", knapsack(C, n))
