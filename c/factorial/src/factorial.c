/*
 ============================================================================
 Name        : factorial.c
 Author      : William Meng
 Version     :
 Copyright   :
 Description : recursive factorial function
 ============================================================================
 */


#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#define	LIMIT	10

/* take list of numbers, run factorial function on each one
first arg is function name, rest is for each number */

struct result {
	int *r[LIMIT];
	int count;
};


struct result *callfunc(char *, ...);
int factorial(int);

/* calculate factorial of a number*/
int factorial(int n) {
	int f;
	if (n <= 1)
		return 1;
	f = n * factorial(n-1);
	return f;
}

//to return multiple values: put them in a struct result with integer array** and int count
struct result *callfunc(char *func_name, ...) {
	// compare input function name with a static string
	//return value
	int r;
	va_list ap;
	//can't declare values in a loop
	int ival;
	struct result *rr;

	rr = (struct result *) malloc(sizeof(struct result));
	rr->count = 0;

	r = strcmp(func_name, "factorial");
	if (r == 0) {
		va_start(ap, func_name);
		// dadada is useful for a list of stuff
		while ( (ival = va_arg(ap, int)) > 0 && rr->count <= LIMIT) {
			printf("%d\t", ival);
			printf("%d\n" ,factorial(ival));
			rr->r[rr->count] = (int *) malloc(sizeof(int));
			// rr.r[rr.count] is a single pointer
			*(rr->r[rr->count]) = factorial(ival);
			rr->count++;
		}
		va_end(ap); //clean up when done

	}
	return rr;

}

//int *[] callfunc(char *)

main() {
	struct result *dadada;
	dadada = callfunc("factorial", 1, 2, 3, 4);
//printout loop
	int i;
	for (i=0; i < dadada->count; i++) {
		printf("%d\n", *(dadada->r[i]));
	}

}
