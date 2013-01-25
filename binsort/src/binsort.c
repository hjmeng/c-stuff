/*
 * binsort.c
 *
 *  Created on: Dec 29, 2012
 *      Author: wlmeng
 */


#include <stdio.h>
#include <stdlib.h>
#define	RLIMIT	1000
#define RRANGE	100

int table[RLIMIT];

struct node {
	int value;
	int counter; //number of occurences
	struct node *left, *right;
};

struct node * addtree(struct node *, int);
void treeprint(struct node *);

void main() {
	/* generate random numbers and put them in table[]*/
	srandom(1);
	int i;
	for (i=0; i < RLIMIT; i++) {
		table[i] = (int)  ( (double) random()/RAND_MAX * RRANGE);
		printf("%d\t", table[i]);
	}
	printf("\n");

	struct node * root = NULL;
/*
	struct node n1 = {1,1,NULL,NULL};
	struct node n2 = {2,1,NULL,NULL};
	struct node n3 = {3,1,NULL,NULL};

	n2.left = &n1;
	n2.right = &n3;

	root = &n2;

	treeprint(root);
*/


	for (i=0; i< RLIMIT; i++) {
		root = addtree(root, table[i]);
		//treeprint(root);
		//printf("\n");
	}
	treeprint(root);
}

struct node * addtree(struct node * p, int v) {
	//newnode is an instance of struct node

	int cond;
	if (p == NULL) {
		//point p to where the memory has just been allocated
		p = (struct node *) malloc(sizeof(struct node));
		// initialize integers as 0 and pointers to NULL
		p->value = v;
		p->counter = 1;
		p->left = NULL;
		p->right = NULL;
	}
	else if ((cond = v - p->value) == 0)
		p->counter++;
	else if (cond < 0)
		p->left = addtree(p->left, v);
	else
		p->right = addtree(p->right, v);
	return (p);

}

void treeprint(struct node *p/* parameter named in actual function, not declaration*/) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%d %d\t", p->value, p->counter);
		treeprint(p->right);
	};
}
