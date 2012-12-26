#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define checkMemory(A, M)	{if (!A) {printf("ERROR: " M "\n"); exit(EXIT_FAILURE);}}

static node *createNode(void *data);
static void destroyNode(node *old, destroyDataFunc destroyData);
static int isEmpty(list *input);


static node *createNode(void *data)
{
	node *new = malloc(sizeof(node));
	checkMemory(new, "A list node could not be allocated.");
	new->data = data;
	new->next = NULL;
	return new;
}

list *createList(destroyDataFunc destroyData)
{
	list *new = malloc(sizeof(list));
	checkMemory(new, "A list could not be allocated.");
	new->head = NULL;
	new->destroyData = destroyData;
	return new;
}

static void destroyNode(node *old, destroyDataFunc destroyData)
{
	old->next = NULL;
	if (old->data) destroyData(old->data);
	if (old) free(old);
}

static int isEmpty(list *input)
{
	return (input->head)?0:1;
}

node *enlist(list *inputList, void *data)
{
	node *new = createNode(data);
	new->next = inputList->head;
	inputList->head = new;
	return new;
}

node *delist(list *inputList)
{
	node *old = inputList->head;
	inputList->head = old->next;
	destroyNode(old, inputList->destroyData);
	return inputList->head;	
}

void destroyList(list *old)
{
	while (!isEmpty(old)) {
		delist(old);
	}
	if (old) free(old);
}