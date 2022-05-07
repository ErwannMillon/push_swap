import copy
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
			stack.insert(1, stack.pop(0))
def p(src, dest):
	if src:
		dest.insert(0, src.pop(0))
def rr(stacks):
	for stack in stacks:
		if stack:
			stack.insert(0, stack.pop(-1))
def r(stacks):
	for stack in stacks:
		if stack:
			stack.insert(-1, stack.pop(0))

def sort_index(num, a, b, sortarr):
	num_index = a.index(num)
	distance_to_top = num_index
	distance_to_bottom = len(a) - num_index - 1
	# distance_to_target = 


def	main(a):
	sortedarr = sorted(a)
	b = []
	for num in a:
		sort_index(num, a, b);
	

b = [3, 2 , 1]
arr = [10, 0, 1, 22, 9, 33, 21, 50, 41, 60]
# print(lis(arr))
print(arr)
s([arr])
print(arr)
rr([arr])
print(arr)
p(arr, b)
print("arr: ", arr)
print ("b: ", b)
r([arr])
print(arr)

