from lis import *
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


def s(stacks):
	for stack in stacks:
		if stack:
			print("s")
			stack.insert(1, stack.pop(0))
			print(stack)

def p(src, dest):
	if src:
		print("p")
		dest.insert(0, src.pop(0))
		print(src)

def rr(stacks):
	for stack in stacks:
		if stack:
			print("rr")
			stack.insert(0, stack.pop(-1))
			print(stack)

def r(stacks):
	for stack in stacks:
		if stack:
			print("r")
			stack.append(stack.pop(0))
			print(stack)
	

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
			#used to be a[-1]
			if a.index(num) == 1 and a[0] < a[1]:
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

def num_after_insert_target(num, a, sortedarr):
	return(sortedarr[sortedarr.index(num) + 1])

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
		# if a[a.index(num) - 1] != num_before_insert_target:
		p(a, b)
		print("b: ", b)
		path.append("pb")
		while a[-1] != num_before_insert_target:
			path.append("ra")
			r([a])
			print("b: ", b)
		p(b, a)
		print("b: ", b)
		path.append("pa")
		
		print(path)
		print(a)
		return(path)
		 


def sort_order(num, a, b, sortedarr):
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
	lis = longest(a)
	unsorted = sorted(list(filter(lambda elem: elem not in lis, a)))
	print("UNSORTED", unsorted)
	for num in unsorted:
		x = path_find(num, a, b, sortedarr);
	if (a.index(sortedarr[0]) != 0):
		x.extend(move_to_top(sortedarr[0], a, b, sortedarr))
	print("XXXXXX: ", x)


test = [3, 2 , 1]
arr = [10, 0, 1, 22, 9, 33, 21, 50, 41, 60]
arr2 =[22, 50, 41, 60, 10, 0, 1, 9, 33, 21]
# print(longest(arr2))
lis = longest(arr2)
unsorted = list(filter(lambda elem: elem not in lis, arr2))
print("unsorted", unsorted)
print("init: ", arr2)
print("lis", lis)
# # s([arr])
# print(arr)
# rr([arr])
# print(arr)
# p(arr, b)
# print("arr: ", arr)
# print ("b: ", b)
# r([arr])
# print(arr)

main(arr2)