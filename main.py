import copy
"""
Starting approach:
Check if optimal nums are those that are not in the LIS
Start with relative sort: sorting by order, pathfinding number to be adjacent to its neighbor in sorted

Principles:
if a[0] > b[0], push to b
if num_index = 1, decide between rotate and swap based on if a[-1] is higher or lower than a[0]


Functions:
move_above(x, y)
move_below(y, x)


"""
def lis(list):
	subsequences = []
	for i in range(len(list)):
		n = i;
		currentlist = [];
		while n < len(list):
			if n == i or list[n] > currentlist[-1]:
				currentlist.append(list[n]);
			n += 1;
		if currentlist:
			subsequences.append(currentlist)
	lisindexes = [list.index(x) for x in max(subsequences, key=len)]
	return (lisindexes)

def s(stacks):
	for stack in stacks:
		if stack:
			print("s")
			stack.insert(1, stack.pop(0))
def p(src, dest):
	if src:
		print("p")
		dest.insert(0, src.pop(0))
def rr(stacks):
	for stack in stacks:
		if stack:
			print("rr")
			stack.insert(0, stack.pop(-1))
def r(stacks):
	for stack in stacks:
		if stack:
			print("r")
			stack.append(stack.pop(0))

def move_to_top(num, a, b, sortedarr):
	num_index = a.index(num)
	num_after_insert_target = sortedarr[sortedarr.index(num) + 1]
	index_after_insert_target = a.index(sortedarr[sortedarr.index(num) + 1])
	num_before_insert_target = sortedarr[sortedarr.index(num) - 1]
	index_before_insert_target = a.index(sortedarr[sortedarr.index(num) - 1])
	distance_to_bottom = len(a) - num_index - 1
	distance_to_top = num_index
	path = []
	if distance_to_bottom + 1 < distance_to_top:
		print(f"{num} going to bottom")
		for i in range(distance_to_bottom + 1):
			if a.index(num) == 1 and a[0] < a[-1]:
				path.append("sa")
				s([a])
			else:
				path.append("rra")
				rr([a])
				print(a)
	else:
		print(f'{num} going to top')
		for i in range(distance_to_top):
			path.append("ra")
			r([a])
			print(a)
	print(f'path: {path}')
	return (path)

def	path_find(num, a, b, sortedarr):
	num_index = a.index(num)
	num_after_insert_target = sortedarr[sortedarr.index(num) + 1]
	index_after_insert_target = a.index(sortedarr[sortedarr.index(num) + 1])
	num_before_insert_target = sortedarr[sortedarr.index(num) - 1]
	index_before_insert_target = a.index(sortedarr[sortedarr.index(num) - 1])
	distance_to_bottom = len(a) - num_index - 1
	distance_to_top = num_index
	path = []
	# if num_index == index_after_insert_target or num_index == index_before_insert_target:
	if 1:
		path.extend(move_to_top(num, a, b, sortedarr))
		print(path)
		print(a)
		 


def sort_index(num, a, b, sortedarr):
	num_index = a.index(num)
	num_after_insert_target = sortedarr[sortedarr.index(num) + 1]
	distance_to_bottom = len(a) - num_index - 1
	distance_to_top = num_index
	
	# if a[a.index(num_after_insert_target)] < num and num != max(a):
	# 	sort_index(num_after_insert_target, a, b, sortedarr)
	# else:
		# path_find(num, a, b, sortedarr)
	path_find(num, a, b, sortedarr)


def	main(a):
	sortedarr = sorted(a)
	b = []
	# for num in a:
		# sort_index(num, a, b);
	sort_index(a[1], a, b, sortedarr)

test = [3, 2 , 1]
arr = [10, 0, 1, 22, 9, 33, 21, 50, 41, 60]
# print(arr)
# s([arr])
# print(arr)
# rr([arr])
# print(arr)
# p(arr, b)
# print("arr: ", arr)
# print ("b: ", b)
# r([arr])
# print(arr)

main(arr)