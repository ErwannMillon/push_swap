import copy
import random

def find_next(arr, currentlist, firstindex, index):
	listcopy = copy.deepcopy(currentlist)
	newnum = None
	y = []
	x = []
	print("\n", currentlist)
	for i in range(len(arr)):
		if index == len(arr):
			index = 0
		print(f'firstindL {firstindex}, index: {index}, i: {i}, arr[index] {arr[index]}')
		if arr[index] > currentlist[-1]:
			newnum = arr[index]
			index += 1
			break
		if index == firstindex - 1 or index == firstindex:
			break
		index += 1
	if newnum is None:
		# print("NO NUM FOUND")
		return(currentlist)
	print("newnum", newnum)
	currentlist.append(newnum)
	if index == firstindex:
		return(currentlist)
	shouldfork = False
	x = find_next(arr, currentlist, firstindex, (arr.index(newnum) + 1))
	print("xfound", x)
	for i in range(len(arr)):
		if (arr.index(newnum) + i + 1) % len(arr) == firstindex:
			break
		if arr[(arr.index(newnum) + i + 1) % len(arr)] > listcopy[-1]:
			newnum = arr[(arr.index(newnum) + i + 1) % len(arr)]
			shouldfork = True
			break
	if shouldfork:
		print("YYYYy")
		y = find_next(arr, listcopy, firstindex, arr.index(newnum))
	if x or y:
		# if x:
			# print("X: ", x)
		# if y:
			# print("Y: ", y)
		return(max(x, y, key=len))
	return([])

def longest(arr):
	subsequences = []
	for num in arr:
		currentlist = [num]
		shouldsearch = True
		for elem in subsequences:
			if elem and num in elem:
				shouldsearch = True
		if shouldsearch:
			seq = find_next(arr, currentlist, arr.index(num), (arr.index(num) + 1))
		if seq:
			subsequences.append(seq)
	return(max(subsequences, key=len))

arr = [70, 10, 0, 39, 1, 34, 22, 9, 33, 21, 50, 41, 60]
arr3 = random.sample(range(0, 2344), 100)
arr4  =[ 1968, 284, 287, 1395, 1234, 1427, 1375, 587, 1669, 483, 2158, 1823, 726, 175, 1609, 1803]
# lis = longest(arr)
lis = longest(arr4)
print(arr4)
print(lis)