import copy

def find_next(arr, currentlist, firstindex, index):
	listcopy = copy.deepcopy(currentlist)
	newnum = None
	# print(currentlist)
	for i in range(len(arr)):
		# print(firstindex, index, i)
		if index == len(arr):
			index = 0
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
	currentlist.append(newnum)
	if index == firstindex:
		return(currentlist)
	# print("-----")
	x = find_next(arr, currentlist, firstindex, (arr.index(newnum) + 1))
	y = find_next(arr, listcopy, firstindex, (arr.index(newnum) + 1))

	if x and y:
		return(max(x, y, key=len))
	return([])

def longest(arr):
	subsequences = []
	for num in arr:
		currentlist = [num]
		shouldsearch = True
		for elem in subsequences:
			if elem and num in elem:
				shouldsearch = False
		if shouldsearch:
			seq = find_next(arr, currentlist, arr.index(num), (arr.index(num) + 1))
		if seq:
			subsequences.append(seq)
	return(max(subsequences, key=len))

# arr = [70, 10, 0, 39, 1, 34, 22, 9, 33, 21, 50, 41, 60]
# # arr = [1, 2, 3, 4, 5, 0]
# longest(arr)