#include <stdio.h>

#define SIZE 6

void printlist (int list[], int highlight) {
	int i;
	for (i = 0; i < SIZE; i++) {
		if (i == highlight)
			printf("[%d]\t", list[i]);
		else
			printf(" %d\t", list[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main () {
	//int list[SIZE] = {5,2,1,4,6,3};
	int list[SIZE] = {6,5,4,3,2,1};
	int i, j;
	int sorted=0;

	printlist(list, SIZE);

	for(i = 0; i < SIZE - 1; i++) {
		//printf("i loop %d\n", i);
		for (j=0; j < SIZE - 1; j++) {
			//printf("j loop %d\n", j);
			if (list[j] > list[j+1]) {
				swap(&list[j], &list[j+1]);
			}
			printlist(list, j+1);
		}
	}

	return(0);
}
