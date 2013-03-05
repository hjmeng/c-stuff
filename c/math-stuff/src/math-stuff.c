/*
 ============================================================================
 Name        : math-stuff.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define	PI	atan(1)*4
#define	IN	1 /* inside a word */
#define OUT	0 /* outside a word */
#define	FIRST	2 /* beginning of sentence */

/* calculate radians value of input */
double d2r(int n) {
	 double x;
		 x = (double) (n*(PI/180));
	 return x;
}

/* calculate factorial of a number*/
int factorial(int n) {
	int f;
	if (n <= 1)
		return 1;
	f = n * factorial(n-1);
	return f;
}

/* filecopy:  copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
	int c;
    while ((c = getc(ifp)) != EOF)
    	putc(c, ofp);
}

void allcaps(char *file_name) {
	FILE *fp;
	int c;
	if ((fp = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "error opening file %s", file_name);
		exit(1);
	}
	while ( (c = (getc(fp))) != EOF) {
		if ( (islower(c)) == 0)
			printf("%c", c);
		else {
			c = toupper(c);
			printf("%c", c);
		}
	}
}

void wordcap(char *file_name) {
	FILE *fp;
	int c, state;

	state = OUT;

	if ((fp = fopen(file_name, "r")) == NULL) {
			fprintf(stderr, "error opening file %s", file_name);
			exit(1);
		}
	//filecopy(fp, stdout);
	while ( (c = (getc(fp))) != EOF) {
		if ( (c == ' ') || (c == '\n') || (c == '\t') || (c == '\n')) {
			state = OUT;
			printf("%c", c);
		}
		else if (state == OUT) {
			c = toupper(c);
			printf("%c", c);
			state = IN;
		}
		else if (state == IN) {
			printf("%c", c);
		}
	}
}

void sentencecap(char *file_name) {
	FILE *fp;
	int c, state;

	state = FIRST;

	if ((fp = fopen(file_name, "r")) == NULL) {
				fprintf(stderr, "error opening file %s", file_name);
				exit(1);
			}
	//filecopy(fp, stdout);
	while ( (c = (getc(fp))) != EOF) {
		if ( (c == ' ') || (c == '\n') || (c == '\t') || (c == '\n')) {
			state = OUT;
			printf("%c", c);
		}
		else if (state == OUT) {
			c = toupper(c);
			printf("%c", c);
			state = IN;
		}
		else if (state == IN) {
			printf("%c", c);
		}
	}
}

void main(int argc, char *argv[]) {
	#define LINESZ 1024

	FILE *fp;
	int funcval;
	char *func_name;
	char *file_name;
	char buff[LINESZ];

	func_name = (char *) malloc(sizeof(char)* LINESZ);

	if (argc == 1) {
		printf("Usage: %s [FILE]\n", argv[0]);
		exit(1);
	}

	file_name = argv[1];

	if ((fp = fopen("/home/wlmeng/workspace/c-stuff/math-stuff/src/text", "r")) == NULL) {
		fprintf(stderr, "error opening file %s", file_name);
		exit(1);
	}
//	filecopy(fp, stdout);

	while ( fgets (buff, LINESZ, fp)) {
		if (sscanf(buff, "%s %d\n", func_name, &funcval) == 2) {
			//call function that is spelled out in funcname
			if ((strcmp(func_name, "factorial")) == 0)
				printf("Factorial of %d is %d\n", funcval, factorial(funcval));
			if ((strcmp(func_name, "sin")) == 0)
				printf("Sin of %d is %f\n", funcval, sin(d2r(funcval)));
		}
	}
	fclose(fp);
	//allcaps("/home/wlmeng/workspace/c-stuff/text/test");
	wordcap("/home/wlmeng/workspace/c-stuff/text/ipsum");
}
