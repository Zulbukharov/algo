#include <stdio.h>
#include <stdlib.h>

int binary_search(int list[], int list_len, int item)
{
	int low;
	int high;
	int mid;
	int guess;
	int count;

	low = 0;
	count = 1;
	high = list_len - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		guess = list[mid];
		printf("[current index][%d]\n", mid);
		if (guess == item)
		{
			printf("[counter][%d]\n", count);
			return (mid);
		}
		else if (guess > item)
			high = mid - 1;
		else
			low = mid + 1;
		count++;
	}
	printf("[counter][%d]\n", count);
	return (0);
}

int main(void) {
	int list[] = {1, 3, 5, 7, 9};

	printf("%d\n", binary_search(list, 5, 3));
	return (0);
}
