# import copy
# import random

# def find_next(arr, currentlist, firstindex, index):
# 	listcopy = copy.deepcopy(currentlist)
# 	newnum = None
# 	y = []
# 	x = []
# 	print("\n", currentlist)
# 	for i in range(len(arr)):
# 		if index == len(arr):
# 			index = 0
# 		print(f'firstindL {firstindex}, index: {index}, i: {i}, arr[index] {arr[index]}')
# 		if arr[index] > currentlist[-1]:
# 			newnum = arr[index]
# 			index += 1
# 			break
# 		if index == firstindex - 1 or index == firstindex:
# 			break
# 		index += 1
# 	if newnum is None:
# 		# print("NO NUM FOUND")
# 		return(currentlist)
# 	print("newnum", newnum)
# 	currentlist.append(newnum)
# 	if index == firstindex:
# 		return(currentlist)
# 	shouldfork = False
# 	x = find_next(arr, currentlist, firstindex, (arr.index(newnum) + 1))
# 	print("xfound", x)
# 	for i in range(len(arr)):
# 		if (arr.index(newnum) + i + 1) % len(arr) == firstindex:
# 			break
# 		if arr[(arr.index(newnum) + i + 1) % len(arr)] > listcopy[-1]:
# 			newnum = arr[(arr.index(newnum) + i + 1) % len(arr)]
# 			shouldfork = True
# 			break
# 	if shouldfork:
# 		print("YYYYy")
# 		y = find_next(arr, listcopy, firstindex, arr.index(newnum))
# 	if x or y:
# 		# if x:
# 			# print("X: ", x)
# 		# if y:
# 			# print("Y: ", y)
# 		return(max(x, y, key=len))
# 	return([])

# def longest(arr):
# 	subsequences = []
# 	for num in arr:
# 		currentlist = [num]
# 		shouldsearch = True
# 		for elem in subsequences:
# 			if elem and num in elem:
# 				shouldsearch = True
# 		if shouldsearch:
# 			seq = find_next(arr, currentlist, arr.index(num), (arr.index(num) + 1))
# 		if seq:
# 			subsequences.append(seq)
# 	return(max(subsequences, key=len))

# arr = [70, 10, 0, 39, 1, 34, 22, 9, 33, 21, 50, 41, 60]
# arr3 = random.sample(range(0, 2344), 100)
# arr4  =[ 1968, 284, 287, 1395, 1234, 1427, 1375, 587, 1669, 483, 2158, 1823, 726, 175, 1609, 1803]
# # lis = longest(arr)
# lis = longest(arr4)
# print(arr4)
# print(lis)
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
# print(lis(arr))
arr3 = random.sample(range(0, 80000), 500)

arr4  =[ 1968, 284, 287, 1395, 1234, 1277, 1375, 587, 1669, 483, 2158, 1823, 726, 175, 1609, 1803]

# This code is contributed by Nikhil Kumar Singh
# 		break
def longest(arr):
	subsequences = []
	for num in arr:
		fullarr = arr[arr.index(num) : ] + arr[0 : arr.index(num)]
		subsequences.append(lis(fullarr))
	# print(subsequences)
	return(max(subsequences, key=len))
longest(arr4)