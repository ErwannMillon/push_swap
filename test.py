arr = [7, 0, 3, 1, 9, 2]
currentlist = [0, 3]
x = [0, 3, 9]
newnum = 9
firstindex = 2
for i in range(len(arr)):
	print("index: ", (arr.index(newnum) + i + 1) % len(arr))
	if (arr.index(newnum) + i + 1) % len(arr) == firstindex:
		break
	if arr[(arr.index(newnum) + i + 1) % len(arr)] not in x and arr[(arr.index(newnum) + i + 1) % len(arr)] > currentlist[-1]:
		print("index: ", (arr.index(newnum) + i + 1) % len(arr))
		shouldfork = True
		print(arr[(arr.index(newnum) + i + 1) % len(arr)])
		break
