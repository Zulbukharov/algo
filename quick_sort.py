def quickSort(array):
	if len(array) < 2:
		return array
	else:
		pivot = array[0]
		less = [i for i in array[1:] if i <= pivot]
		more = [i for i in array[1:] if i > pivot]
		return quickSort(less) + [pivot] + quickSort(more)

print(quickSort([9, 8, 7, 6, 5, 4, 3, 2, 1]))
