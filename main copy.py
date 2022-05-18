from gettext import find
from math import floor
from select import kevent
from tabnanny import check
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
		elif instruction == "rb":
			r([b])
		elif instruction == "rrb":
			rr([b])
		elif instruction == "sa":
			s([a])
		elif instruction == "sb":
			s([b])
	# print("MoveMade")
	# print_stacks(a, b)

	# # print("\n\n")
	# # # print(arr)
	# # # print(sortedarr)
	# if arr == sortedarr:
		# # print("arr = sortedarr")

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

def move_to_top(num, arr):
	num_index = arr.index(num)
	distance_to_bottom = len(arr) - num_index - 1
	distance_to_top = num_index
	path = []
	if distance_to_bottom + 1 < distance_to_top:
		# print(f"{num} going to bottom")
		for i in range(distance_to_bottom + 1):
			#used to be a[-1]
			if arr.index(num) == 1 and arr[0] < arr[-1]:
				path.append("sa")
				s([arr])
			else:
				path.append("rra")
				rr([arr])
				# # print(a)
	else:
		# print(f'{num} going to top')
		for i in range(distance_to_top):
			r([arr])
			path.append("ra")
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

def reinsert_before_target(path, num, a, b, sortedarr):
	num_index = b.index(num)
	num_after_insert_target = sortedarr[(sortedarr.index(num) + 1) % len(sortedarr)]
	num_before_insert_target = sortedarr[sortedarr.index(num) - 1]
	num_dist_top = dist_to_top(b, num)
	num_dist_bottom = dist_to_bottom(b, num)

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
	return(a, b)

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
		# target_index = a.index(num_after_insert_target)
		# target_num = num_after_insert_target
		# targ_dist_top = dist_to_top(a, target_num)
		# targ_dist_bottom = dist_to_bottom(a, target_num)
		# if num_dist_top < num_dist_bottom + 1:
		# 	if targ_dist_top - num_dist_top > targ_dist_bottom + 1:
		# 		for i in range(num_dist_top):
		# 			path.append("rb")
		# 			r([b])
		# 		for i in range(targ_dist_bottom + 1):
		# 			path.append("rra")
		# 			rr([a])
		# 		path.append("pa")
		# 		p(b, a)
		# 	else:
		# 		for i in range(num_dist_top):
		# 			if a.index(target_num) != 0:
		# 				path.append("rr")
		# 				r([a, b])
		# 			else:
		# 				path.append("rb")
		# 				r([b])
		# 		if a.index(target_num) != 0:
		# 			for i in range(dist_to_top(a, target_num)):
		# 				path.append("ra")
		# 				r([a])
		# 		path.append("pa")
		# 		p(b, a)
		# else:
		# 	if targ_dist_bottom + 1 - num_dist_bottom > targ_dist_top:
		# 		for i in range(num_dist_bottom + 1):
		# 			path.append("rrb")
		# 			rr([b])
		# 		for i in range(targ_dist_top):
		# 			path.append("ra")
		# 			r([a])
		# 	else:
		# 		for i in range(num_dist_top):
		# 			if a.index(target_num) != 0:
		# 				path.append("rr")
		# 				r([a, b])
		# 			else:
		# 				path.append("rrb")
		# 				rr([b])
		# 		if a.index(target_num) != 0:
		# 			for i in range(dist_to_bottom(a, target_num) + 1):
		# 				path.append("rra")
		# 				rr([a])
		# 	path.append("pa")
		# 	p(b, a)
		a, b = reinsert_before_target(path, num, a, b, sortedarr)

	elif num_before_insert_target in a:
		# print(f"Inserting after previous num in sorted, target: {num_before_insert_target}, num{num}")
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
					if a.index(target_num) != len(a) - 1:
						path.append("rr")
						r([a, b])
					else:
						path.append("rb")
						r([b])
				if a.index(target_num) != len(a) - 1:
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
					if a.index(target_num) != len(a) - 1:
						path.append("rrr")
						rr([a, b])
					else:
						path.append("rrb")
						rr([b])
				if a.index(target_num) != len(a) - 1:
					for i in range(dist_to_bottom(a, target_num)):
						path.append("rra")
						rr([a])
			path.append("pa")
			p(b, a)
	else:
		min_index = a.index(min(a))
		for i in range (min_index, min_index + len(a)):
			if a[i % len(a)] > num:
				break
		
		target_index = i % len(a)
		target_num = a[target_index]
		if target_num < num:
			target_num = min(a)
			target_index = min_index
		targ_dist_top = dist_to_top(a, target_num)
		targ_dist_bottom = dist_to_bottom(a, target_num)
		# print("\n\n***************************")
		# print(f"new function, num {num}, target {a[target_index]}, neighborL {num_after_insert_target},")
		# print("A: ", a)
		# print("S:", sortedarr)
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
		# print("NO NEIGHBOR IN A")
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
			# print()
			x = path_find_from_b(num, a, b, sortedarr)
			# print(f"num: {num}, pathL: {x}")
			if x:
				# print_stacks(a, b)
				lengths.append(x)
		current_move = min(lengths, key=len)
		# print(f"currentmove {current_move}")
		# print_stacks(a, b)
		final_path.extend(current_move)
		make_moves(a, b, current_move)


	# print("reinsert path", final_path, len(final_path))
	return(final_path)

def move_unsorted_to_b(a, b):
	sub = longest(a)
	sortedarr = sorted(a)
	unsorted = list(filter(lambda elem: elem not in sub, a))
	path = []
	# print("A", a)
	# print("S", sortedarr)
	# first_half = [x for x in unsorted if x <= sortedarr[int(len(arr) / 2)]]
	# second_half = [x for x in unsorted if x >  sortedarr[int(len(arr) / 2)]]
	# print("\n\nhalf1", first_half)
	# print("half2", second_half)

	# # print(unsorted)
	# while (first_half):
	# 	for num in first_half:
	# 		if first_half[0] == num or min(dist_to_bottom(a, num), dist_to_top(a, num)) < min_len:
	# 			min_len = min(dist_to_bottom(a, num) + 1, dist_to_top(a, num))
	# 			num_to_push = num
	# 	path.extend(move_to_top(num_to_push, a))
	# 	p(a, b)
	# 	path.append("pb")
	# 	first_half.pop(first_half.index(num_to_push))
	# while (second_half):
	# 	for num in second_half:
	# 		if  second_half[0] == num or min(dist_to_bottom(a, num), dist_to_top(a, num)) < min_len:
	# 			min_len = min(dist_to_bottom(a, num) + 1, dist_to_top(a, num))
	# 			num_to_push = num
	# 	path.extend(move_to_top(num_to_push, a))
	# 	p(a, b)
	# 	path.append("pb")
	# 	second_half.pop(second_half.index(num_to_push))

	unsorted.sort()
	print("lis", sub)
	print("sorted list of unsorted elems in a", unsorted)
	if (len(a) > 200):
		while (unsorted):
			subarray = unsorted[0:int(len(arr) / 2)]
			for num in subarray:
				if unsorted[0] == num or min(dist_to_bottom(a, num), dist_to_top(a, num)) < min_len:
					min_len = min(dist_to_bottom(a, num) + 1, dist_to_top(a, num))
					num_to_push = num
			path.extend(move_to_top(num_to_push, a))
			p(a, b)
			path.append("pb")
			# if b and len(b) > 1 and b[0] < b [1]:
			# 	s([b])
			# 	path.append("sb")
			unsorted.pop(unsorted.index(num_to_push))
			print("NUM TO PUSH", num_to_push)
	else:
		while (unsorted):
			for num in unsorted:
				if unsorted[0] == num or min(dist_to_bottom(a, num), dist_to_top(a, num)) < min_len:
					min_len = min(dist_to_bottom(a, num) + 1, dist_to_top(a, num))
					num_to_push = num
			path.extend(move_to_top(num_to_push, a))
			p(a, b)
			path.append("pb")
			# if b and len(b) > 1 and b[0] < b [1]:
			# 	s([b])
			# 	path.append("sb")
			unsorted.pop(unsorted.index(num_to_push))
			print("NUM TO PUSH", num_to_push)
	print_stacks(a, b)
		# print(path)
	# print(unsorted)
		# print()
	print("MOVE UNSORTED TO B PATH", path, len(path))
	return(path)

def move_to_beginning(a, sortedarr):
	path = []
	target_index = a.index(sortedarr[0])
	if target_index != 0:
		if dist_to_bottom(a, sortedarr[0]) + 1 < dist_to_top(a, sortedarr[0]):
			for i in range (dist_to_bottom(a, sortedarr[0]) + 1):
				path.append("rra")
				rr([a])
		else:
			for i in range (dist_to_top(a, sortedarr[0])):
				path.append("ra")
				r([a])
	# print("A:", a)
	# print("MOVE TO BEGINNING PATH", path, len(path))
	return(path)

def tester():
	average = 0
	n = 30
	l = 500
	results = [0, 0, 0, 0]
	for i in range(n):  
		arr = random.sample(range(0, 505), l)
		errcopy = copy.deepcopy(arr)
		checkcopy = copy.deepcopy(arr)
		returnval = main(arr)
		print(i, " RETURNVAL\n\n\n\n", len(returnval[0]))
		make_moves(checkcopy, [], returnval[0])
		if checkcopy != sorted(checkcopy):
			print("ERRORRRR: Could not sort: ", errcopy)
			return()
		for i in range(4):
			results[i] += len(returnval[i])
	for i in range(4):
		results[i] /= n
	print("average: = ", results)
	print(str(average))
	with open("log.txt", "w") as log:
		log.write(str(average))
		log.close()

def	main(a):
	copied = copy.deepcopy(a)
	sortedarr = sorted(a)
	b = []
	listcopy = longest(a)
	final_path = []
	# print("arr", a)
	# print("\nlis:", listcopy)
	unsorted = list(filter(lambda elem: elem not in listcopy, a))
	# print("ASDJ")
	move_unsorted = move_unsorted_to_b(a, b)
	reinsert = reinsert_b(a, b, sortedarr)
	move_beginning = move_to_beginning(a, sortedarr)
	final_path.extend(move_unsorted)
	final_path.extend(reinsert)
	final_path.extend(move_beginning)

	# # final_path.extend(reinsert_b(a, b, sortedarr))
	# # final_path.extend(move_to_beginning(a, sortedarr))
	
	# print("FINALLLL PATH, ", final_path, len(final_path))
	return([final_path, move_unsorted, reinsert, move_beginning])
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

arr = [1523, 1983, 1702, 1104, 2119, 149, 1427, 1091, 1404, 1667, 194, 848, 954, 1639, 1337, 2143, 212, 1048, 879, 2221, 2052, 572, 166, 1450, 379, 816, 1867, 536, 1784, 225, 530, 2121, 1876, 1933, 2075, 240, 655, 1951, 1358, 2342, 415, 68, 523, 1792, 902, 1536, 1316, 1481, 1772, 1746, 585, 1036, 538, 1038, 1842, 339, 289, 2037, 1077, 2023, 18, 569, 1015, 2170, 2217, 2153, 2077, 47, 1277, 1910, 106, 355, 1462, 577, 360, 8, 1281, 202, 1617, 1589, 983, 729, 1445, 183, 679, 741, 252, 1806, 316, 208, 150, 178, 2242, 1422, 1221, 205, 216, 519, 1940, 1854]
arr2 = [8, 58, 86, 92, 110, 121, 136, 137, 138, 144, 152, 177, 183, 223, 241, 245, 260, 264, 292, 298, 322, 326, 343, 377, 390, 399, 408, 462, 487, 492, 516, 518, 536, 540, 548, 557, 566, 567, 601, 617, 655, 656, 658, 661, 667, 671, 677, 684, 694, 728, 737, 752, 753, 757, 763, 770, 784, 793, 798, 801, 804, 805, 806, 816, 838, 847, 854, 893, 897, 911, 913, 920, 924, 925, 935, 948, 951, 966, 975, 981, 996, 1005, 1010, 1036, 1040, 1047, 1067, 1072, 1074, 1089, 1101, 1114, 1129, 1136, 1193, 1232, 1238, 1285, 1293, 1308, 1312, 1324, 1331, 1049, 1335, 1338, 1367, 1372, 1374, 1391, 1450, 1462, 1465, 1469, 1486, 1495, 1513, 1526, 1547, 1563, 1052, 1058, 1064, 1622, 1653, 1158, 1171, 1174, 1181, 1187, 1659, 1668, 1671, 1675, 1688, 1701, 1719, 1726, 1731, 1732, 1738, 1747, 1758, 1766, 1777, 1782, 1792, 1794, 1800, 1814, 1815, 1817, 1826, 1829, 1845, 1847, 1857, 1888, 1895, 1902, 1908, 1922, 1944, 1946, 1956, 2013, 2022, 2032, 2044, 2045, 2046, 2054, 2063, 2070, 2075, 2076, 2087, 2089, 2137, 2141, 2147, 2161, 2169, 2172, 2192, 2193, 2202, 2207, 2208, 2213, 2214, 2239, 2267, 2268, 2269, 2271, 2276, 2300, 2309, 2334]
arr3 = random.sample(range(0, 101), 100)
arr4 = [1658, 249, 237, 2058, 649, 1400, 1962, 465, 2259, 94, 2310, 1507, 33, 1263, 1212, 1465, 486, 1033, 1038, 315, 1959, 1997, 672, 1925, 1994, 2056, 857, 2268, 2339, 1120, 168, 1826, 1113, 1556, 699, 953, 1431, 518, 1955, 2285, 861, 1451, 108, 34, 268, 2202, 944, 1117, 2018, 885, 2125, 924, 2203, 1388, 664, 1734, 1276, 1198, 1684, 104, 2283, 193, 2149, 487, 1416, 1434, 1965, 2028, 365, 152, 895, 1905, 1697, 421, 2318, 1854, 1469, 1024, 539, 1325, 131, 817, 525, 1246, 2127, 1058, 798, 891, 507, 1294, 2088, 832, 521, 2003, 2302, 1410, 1187, 273, 480, 1220, 1334, 774, 2017, 701, 637, 745, 1362, 949, 2307, 102, 1963, 978, 218, 504, 1103, 420, 2220, 1377, 1707, 463, 1640, 318, 2053, 1641, 1519, 1403, 1047, 1491, 677, 1466, 1792, 1322, 83, 1290, 1114, 867, 1380, 1614, 1971, 1189, 232, 68, 336, 522, 1291, 1975, 308, 1646, 27, 1390, 2294, 772, 1719, 440, 1340, 358, 2011, 279, 397, 1998, 938, 992, 1157, 1102, 326, 328, 1812, 1996, 1324, 837, 1487, 100, 592, 1819, 653, 197, 297, 1018, 1645, 743, 1701, 537, 1196, 746, 1945, 1181, 2114, 591, 2100, 1021, 1078, 287, 756, 1308, 1151, 1214, 997, 1670, 1051, 3]
arr5 = [1658, 249, 237, 2058, 649, 1400, 1962, 465, 2259, 94, 2310, 1507, 33, 1263, 1212, 1465, 486, 1033, 1038, 315, 1959, 1997, 672, 1925, 1994, 2056, 857, 2268, 2339, 1120, 168, 1826, 1113, 1556, 699, 953, 1431, 518, 1955, 2285, 861, 1451, 108, 34, 268, 2202, 944, 1117, 2018, 885, 2125, 924, 2203, 1388, 664, 1734, 1276, 1198, 1684, 104, 2283, 193, 2149, 487, 1416, 1434, 1965, 2028, 365, 152, 895, 1905, 1697, 421, 2318, 1854, 1469, 1024, 539, 1325, 131, 817, 525, 1246, 2127, 1058, 798, 891, 507, 1294, 2088, 832, 521, 2003, 2302, 1410, 1187, 273, 480, 1220, 1334, 774, 2017, 701, 637, 745, 1362, 949, 2307, 102, 1963, 978, 218, 504, 1103, 420, 2220, 1377, 1707, 463, 1640, 318, 2053, 1641, 1519, 1403, 1047, 1491, 677, 1466, 1792, 1322, 83, 1290, 1114, 867, 1380, 1614, 1971, 1189, 232, 68, 336, 522, 1291, 1975, 308, 1646, 27, 1390, 2294, 772, 1719, 440, 1340, 358, 2011, 279, 397, 1998, 938, 992, 1157, 1102, 326, 328, 1812, 1996, 1324, 837, 1487, 100, 592, 1819, 653, 197, 297, 1018, 1645, 743, 1701, 537, 1196, 746, 1945, 1181, 2114, 591, 2100, 1021, 1078, 287, 756, 1308, 1151, 1214, 997, 1670, 1051, 3]
test = arr3

checkcopy = copy.deepcopy(test)
# print(arr3)
# # print(longest(arr2))
faila = [1451, 1465, 1466, 1469, 1487, 1491, 1556, 1614, 1640, 1641, 1431, 1645, 1646, 1658, 1507, 1707, 1719, 1734, 1792, 1812, 1670, 1819, 1826, 1925, 1945, 1955, 1959, 1962, 1963, 1965, 1971, 1975, 1994, 1996, 1997, 1998, 2003, 2011, 2017, 2018, 2028, 2053, 2056, 2058, 2088, 2220, 2259, 2268, 2283, 2285, 2294, 2302, 2307, 2310, 2318, 2339, 3, 27, 33, 34, 68, 100, 102, 104, 108, 168, 193, 197, 218, 232, 336, 358, 365, 397, 420, 421, 440, 463, 537, 539, 774, 798, 817, 832, 837, 1047, 1051, 1058, 1078, 1102, 1103, 1187, 1189, 1196, 1214, 1220, 1246, 1322, 1324, 1325, 1334, 1340, 1362, 1377, 1380, 1388, 1390, 1400, 1403, 1410, 1416]
failb = [861, 518, 953, 699, 1113, 1120, 857, 672, 315, 1038, 1033, 486, 1212, 1263, 94, 2114, 465, 1181, 2100, 591, 1021, 287, 756, 1308, 1151, 997, 649, 237, 249, 746, 1701, 743, 1018, 297, 653, 592, 328, 326, 1157, 992, 938, 279, 772, 308, 1291, 522, 867, 1114, 1290, 83, 1519, 677, 318, 504, 978, 949, 745, 637, 701, 480, 273, 521, 1294, 507, 891, 2127, 525, 131, 1024, 1854, 1697, 1905, 895, 152, 1434, 487, 2149, 1684, 1198, 1276, 664, 2203, 924, 2125, 885, 1117, 944, 2202, 268]
path = main(test)[0]
make_moves(checkcopy, [], path)
tester()
if checkcopy == sorted(checkcopy): print("SORTED")
print ("A:", checkcopy)
print ("S:", sorted(checkcopy))
print("\n\n")
for i in range(len(checkcopy)):
	if checkcopy[i] != sorted(checkcopy)[i]:
		print("!!!", end="")
	print(checkcopy[i], ",", end=" ")