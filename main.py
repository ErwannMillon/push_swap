from gettext import find
from select import kevent
from typing import final
from lis import *
import copy
import random
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
def make_moves(a, b, path):
	for instruction in path:
		if instruction == "ra":
			r([a])
		elif instruction == "rra":
			rr([a])
		elif instruction == "pb":
			p(a, b)
		elif instruction == "pa":
			p(b, a)
		elif instruction == "rr":
			r([a, b])
		elif instruction == "rrr":
			rr([a, b])
		elif instruction == "sa":
			s([a])
		elif instruction == "sb":
			s([b])
	print("MoveMade")
	print_stacks(a, b)

	# print("\n\n")
	# # print(arr)
	# # print(sortedarr)
	# if arr == sortedarr:
		# print("arr = sortedarr")

def s(stacks):
	for stack in stacks:
		if stack:
			# print("s")
			stack.insert(1, stack.pop(0))
			# print(stack)

def p(src, dest):
	if src:
		# print("p")
		dest.insert(0, src.pop(0))
		# print(src)

def rr(stacks):
	for stack in stacks:
		if stack:
			# print("rr")
			stack.insert(0, stack.pop(-1))
			# print(stack)

def r(stacks):
	for stack in stacks:
		if stack:
			# print("r")
			stack.append(stack.pop(0))
			# print(stack)
	
def dist_to_bottom(arr, num):
	num_index = arr.index(num)
	distance_to_bottom = len(arr) - num_index - 1
	return(distance_to_bottom)

def dist_to_top(arr, num):
	num_index = arr.index(num)
	return(num_index)

def move_to_top(num, a, b, sortedarr):
	num_index = a.index(num)
	num_after_insert_target = sortedarr[(sortedarr.index(num) + 1) % len(sortedarr)]
	# index_after_insert_target = a.index(sortedarr[(sortedarr.index(num) + 1) % len(sortedarr)])
	num_before_insert_target = sortedarr[sortedarr.index(num) - 1]
	# index_before_insert_target = a.index(sortedarr[sortedarr.index(num) - 1])
	distance_to_bottom = len(a) - num_index - 1
	distance_to_top = num_index
	path = []
	if distance_to_bottom + 1 < distance_to_top:
		# print(f"{num} going to bottom")
		for i in range(distance_to_bottom + 1):
			#used to be a[-1]
			if a.index(num) == 1 and a[0] < a[-1]:
				path.append("sa")
				s([a])
			else:
				"""ADD NUM AFTER"""
				if (num_before_insert_target in b and dist_to_bottom(b, num_before_insert_target) > dist_to_top(b, num_before_insert_target)):
					print("double rev rotate")
					path.append("rrr")
					rr([a, b])
				else:
					path.append("rra")
					rr([a])
				# # print(a)
	else:
		# print(f'{num} going to top')
		for i in range(distance_to_top):
			if (num_before_insert_target in b and dist_to_bottom(b, num_before_insert_target) > dist_to_top(b, num_before_insert_target)):
				print("double rotate")
				path.append("rr")
				r([a, b])
			path.append("ra")
			r([a])
			# # print(a)
	# print(f'path: {path}')
	return (path)

def num_after_insert_target(num, a, sortedarr):
	return(sortedarr[(sortedarr.index(num) + 1) % len(sortedarr)])

def	path_find(num, a, b, sortedarr):
	num_index = a.index(num)
	num_after_insert_target = sortedarr[(sortedarr.index(num) + 1) % len(sortedarr)]
	index_after_insert_target = a.index(sortedarr[(sortedarr.index(num) + 1) % len(sortedarr)])
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
		# print("b: ", b)
		path.append("pb")
		while a[-1] != num_before_insert_target:
			path.append("ra")
			r([a])
			# print("b: ", b)
		p(b, a)
		# print("b: ", b)
		path.append("pa")
		
		# print(path)
		# print(a)
		return(path)

def	path_find_from_b(num, acopy, bcopy, sortedarr):
	a = copy.deepcopy(acopy)
	b = copy.deepcopy(bcopy)
	num_index = b.index(num)
	num_after_insert_target = sortedarr[(sortedarr.index(num) + 1) % len(sortedarr)]
	num_before_insert_target = sortedarr[sortedarr.index(num) - 1]
	path = []
	num_dist_top = dist_to_top(b, num)
	num_dist_bottom = dist_to_bottom(b, num)
	# print("INIT")
	# print_stacks(a, b)
	if num_after_insert_target in a:
		target_index = a.index(num_after_insert_target)
		target_num = num_after_insert_target
		targ_dist_top = dist_to_top(a, target_num)
		targ_dist_bottom = dist_to_bottom(a, target_num)
		if num_dist_top < num_dist_bottom + 1:
			if targ_dist_top - num_dist_top > targ_dist_bottom + 1:
				for i in range(num_dist_top):
					path.append("rb")
					r([b])
				for i in range(targ_dist_bottom + 1):
					path.append("rra")
					rr([a])
				path.append("pa")
				p(b, a)
			else:
				for i in range(num_dist_top):
					if a.index(target_num) != 0:
						path.append("rr")
						r([a, b])
					else:
						path.append("rb")
						r([b])
				if a.index(target_num) != 0:
					for i in range(dist_to_top(a, target_num)):
						path.append("ra")
						r([a])
				path.append("pa")
				p(b, a)
		else:
			if targ_dist_bottom + 1 - num_dist_bottom > targ_dist_top:
				for i in range(num_dist_bottom + 1):
					path.append("rrb")
					rr([b])
				for i in range(targ_dist_top):
					path.append("ra")
					r([a])
			else:
				for i in range(num_dist_top):
					if a.index(target_num) != 0:
						path.append("rr")
						r([a, b])
					else:
						path.append("rrb")
						rr([b])
				if a.index(target_num) != 0:
					for i in range(dist_to_bottom(a, target_num) + 1):
						path.append("rra")
						rr([a])
			path.append("pa")
			p(b, a)

	elif num_before_insert_target in a:
		target_index = a.index(num_before_insert_target)
		target_num = num_before_insert_target
		targ_dist_top = dist_to_top(a, target_num)
		targ_dist_bottom = dist_to_bottom(a, target_num)
		if num_dist_top < num_dist_bottom:
			if targ_dist_top + 1 - num_dist_top > targ_dist_bottom:
				for i in range(num_dist_top):
					path.append("rb")
					r([b])
				for i in range(targ_dist_bottom):
					path.append("rra")
					rr([a])
			else:
				for i in range(num_dist_top):
					if a.index(target_num) != len(arr) - 1:
						path.append("rr")
						r([a, b])
					else:
						path.append("rb")
						r([b])
				if a.index(target_num) != len(arr) - 1:
					for i in range(dist_to_top(a, target_num) + 1):
						path.append("ra")
						r([a])
			path.append("pa")
			p(b, a)

		else:
			if targ_dist_bottom - num_dist_bottom + 1 > targ_dist_top:
				for i in range(num_dist_bottom + 1):
					path.append("rrb")
					rr([b])
				for i in range(dist_to_top(a, target_num) + 1):
					path.append("ra")
					r([a])
			else:
				for i in range(num_dist_bottom + 1):
					if a.index(target_num) != len(arr) - 1:
						path.append("rrr")
						rr([a, b])
					else:
						path.append("rrb")
						rr([b])
				if a.index(target_num) != len(arr) - 1:
					for i in range(dist_to_bottom(a, target_num)):
						path.append("rra")
						rr([a])
			path.append("pa")
			p(b, a)
	# print("PATH: ", path)
	# print("A: ", a)
	# print("B: ", b)
	# print("FINAL")
	# print_stacks(a, b)
	return(path)
		 

def print_stacks(a, b):
	print("A:", a)
	print("B:", b)

def reinsert_b(a, b, sortedarr):
	final_path = []
	while b:
		lengths = []
		for num in b:
			print()
			x = path_find_from_b(num, a, b, sortedarr)
			print(f"num: {num}, pathL: {x}")
			lengths.append(x)
		current_move = min(lengths, key=len)
		print(f"currentmove {current_move}")
		final_path.extend(current_move)
		make_moves(a, b, current_move)

	print("path", final_path, len(final_path))

def move_unsorted_to_b(a, b):
	sub = longest(a)
	sortedarr = sorted(a)
	unsorted = list(filter(lambda elem: elem not in sub, a))
	path = []
	print(unsorted)
	while (unsorted):
		if a[0] in unsorted:
			p(a, b)
			path.append("pb")
			unsorted.pop(0)
		else:
			for num in unsorted:
				if unsorted[0] == num or min(dist_to_bottom(a, num), dist_to_top(a, num)) < min_len:
					min_len = min(dist_to_bottom(a, num), dist_to_top(a, num))
					num_to_push = num
			path.extend(move_to_top(num_to_push, a, b , sortedarr))
			p(a, b)
			path.append("pb")
			if b and len(b) > 1 and b[0] < b [1]:
				s([b])
				path.append("sb")
			unsorted.pop(unsorted.index(num_to_push))
		print_stacks(a, b)
	print(path)
	
def	main(a):
	copied = copy.deepcopy(a)
	sortedarr = sorted(a)
	b = []
	listcopy = longest(a)

	unsorted = list(filter(lambda elem: elem not in listcopy, a))
	# print("UNSORTED", unsorted)
	# x = []
	# while unsorted:
	# 	# if unsorted and unsorted[0] == a[0]:
	# 	# 	unsorted.pop(0)
	# 	for num in unsorted:
	# 		previous_sorted_num = sortedarr[sortedarr.index(num) - 1]
	# 		if a[a.index(num) - 1] == previous_sorted_num:
	# 			continue
	# 		x.extend(path_find(num, a, b, sortedarr));
	# 	lis = longest(a)
	# 	unsorted = sorted(list(filter(lambda elem: elem not in lis, a)))
	# 	# print("LIS", lis)
	# 	# print("UNSORTED", unsorted)
	# 	# print("SORTED", sortedarr)
	# 	# print("\n\n")
	# if (a.index(sortedarr[0]) != 0):
	# 	x.extend(move_to_top(sortedarr[0], a, b, sortedarr))
	
	move_unsorted_to_b(a, b)
	reinsert_b(a, b, sortedarr)
	# print("\n init: ", copied)
	# print("lis: ", listcopy)
	# print("unsorte:", unsorted)
	# print("result: ", a)
	# print("Sorted: ", sortedarr)
	# print("resultLis: ", longest(a))
	# print("Path: ", x)
	# print("has been soirted?? :", a == sortedarr)
	# print("len: ", len(x))
	# return(x)

test = [1, 5, 2, 4, 3]
arr = [10, 0, 1, 22, 9, 33, 21, 50, 41, 60]
arr2 = [2173, 1159, 560, 2274, 726, 1278, 251, 893, 915, 2165]
arr3 = random.sample(range(0, 2344), 10)
checkcopy = copy.deepcopy(arr2)
# print(arr3)
# # print(longest(arr2))
lis = longest(arr2)
unsorted = list(filter(lambda elem: elem not in lis, arr2))
print("arr", arr2)
print("\nlis:", lis)
# # print("lis: ", findLIS(arr3))
# # print("unsorted", unsorted)
# # print("init: ", arr2)
# # print("lis", lis)
# # # s([arr])
# # # print(arr)
# rr([arr])
# # print(arr)
# p(arr, b)
# # print("arr: ", arr)
# # print ("b: ", b)
# r([arr])
# # print(arr)
main(arr2)
# path = main(arr3)
# # print("Path", path, "\n\n\n")
# # print("dic", dic)
# check(checkcopy, path)
