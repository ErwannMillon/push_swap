# Dynamic programming Python implementation of LIS problem

# lis returns length of the longest increasing subsequence
# in arr of size n

import random


def lis(arr):
    n = len(arr)

    # Declare the list (array) for LIS and initialize LIS
    # values for all indexes
    lis = [1]*n

    prev = [0]*n
    for i in range(0, n):
        prev[i] = i

    # Compute optimized LIS values in bottom up manner
    for i in range (1 , n):
        for j in range(0 , i):
            if arr[i] > arr[j] and lis[i]< lis[j] + 1:
                lis[i] = lis[j]+1
                prev[i] = j

    # Initialize maximum to 0 to get the maximum of all
    # LIS
    maximum = 0
    idx = 0

    # Pick maximum of all LIS values
    for i in range(n):
        if maximum < lis[i]:
            maximum = lis[i]
            idx = i

    seq = [arr[idx]]
    while idx != prev[idx]:
        idx = prev[idx]
        seq.append(arr[idx])

    return (list(reversed(seq)))

# # Driver program to test above function
arr = [50, 41, 60, 10, 22, 9, 33, 21]
print(lis(arr))
arr3 = random.sample(range(0, 80000), 500)

arr4  =[ 1968, 284, 287, 1395, 1234, 1427, 1375, 587, 1669, 483, 2158, 1823, 726, 175, 1609, 1803]

# This code is contributed by Nikhil Kumar Singh
# 		break
def longest(arr):
	subsequences = []
	for num in arr:
		fullarr = arr[arr.index(num) : ] + arr[0 : arr.index(num)]
		subsequences.append(lis(fullarr))
	print(subsequences)
	print(max(subsequences, key=len))
longest(arr3)