/*
 ============================================================================
 Name        : hello.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct key {
       char *word;
       int count;
   } keytab[] = {
		   {"auto", 0},
		   {"break", 0},
		   {"case", 0},
   };

#define NKEYS (sizeof keytab / sizeof (struct key))

int main(void) {
	struct key *p;
	p=&keytab[0];
	//char *text1="asd;lkj;lkj;lkjasdfasdffasdf";
	//printf("%p %s size is %ld %d\n", text1, text1, sizeof(text1), (int) strlen(text1));
	printf("Size of keytab is %ld\n", sizeof(keytab));
	printf("Size of keytab[0] is %ld\n", sizeof(keytab[0]));
	printf("Size of pointer is %ld\n", sizeof(keytab[0].word));
	printf("Size of int is %ld\n", sizeof(keytab[0].count));
	printf("Size of struct key is %ld\n", sizeof(struct key));

	int i;
	for (i=0; i<NKEYS; i++, p++)
		//printf("%p\t%s\t%d\n", &keytab[i], keytab[i].word, keytab[i].count);
		printf("%p\t%p:%s\t%p:%d\n", p, &(p->word), p->word,&(p->count),p->count);

	return EXIT_SUCCESS;
}
