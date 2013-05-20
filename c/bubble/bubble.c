#include <stdio.h>

int main () {
	int list[6] = {5,2,1,4,6,3};
	int i;
	int p; //placeholder

	printf("%d\t", list[0]);
	printf("%d\t", list[1]);
	printf("%d\t", list[2]);
	printf("%d\t", list[3]);
	printf("%d\t", list[4]);
	printf("%d\n", list[5]);

	for(i = 0; i < 5; i++) {
		if (list[i] > list[i+1]) {
			p = list[i];
			list[i] = list[i+1];
			list[i+1] = p;
		}
		printf("%d\t", list[0]);
		printf("%d\t", list[1]);
		printf("%d\t", list[2]);
		printf("%d\t", list[3]);
		printf("%d\t", list[4]);
		printf("%d\n", list[5]);
	}

	printf("%d\t", list[0]);
	printf("%d\t", list[1]);
	printf("%d\t", list[2]);
	printf("%d\t", list[3]);
	printf("%d\t", list[4]);
	printf("%d\n", list[5]);

	return(0);
}
