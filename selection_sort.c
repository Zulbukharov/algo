#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void	print_arr(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d\n", arr[i]);
}

int	return_lowest(int list[], int len)
{
	int min;
	int index;

	index = 0;
	for (int i = 0; i < len; i++)
	{
		if (list[i] != INT_MAX)
		{
			min = list[i];
			index = i;
			break ;
		}
	}
	printf("[]%d\n", min);
	for (int i = 0; i < len; i++)
	{
		if (list[i] == INT_MAX)
			continue ;
		if (min > list[i])
		{
			min = list[i];
			index = i;
		}
		printf("[list[i]][%d][min][%d]\n", list[i], min);
	}
	printf("min, %d\n", min);
	return (index);
}

int	*selection_sort(int list[], int len)
{
	int *arr;
	int cur;

	arr = (int*)(malloc(sizeof(int) * len));
	cur = 0;
	for (int i = 0; i < len; i++)
	{
		arr[cur] = list[return_lowest(list, len)];
		list[return_lowest(list, len)] = INT_MAX;
		cur++;	
	}
	return (arr);
}

int	main(void)
{
	int list[] = {1, 2, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int list_len = sizeof(list) / sizeof(list[0]);

	print_arr(selection_sort(list, list_len), list_len);
}
