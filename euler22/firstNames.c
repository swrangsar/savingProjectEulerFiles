#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "firstNames.h"

static char *getFirstName(FILE *fp)
{
	char firstname[NAMELEN], *name;
	int i, c, length, state;
	i = c = length = 0;
	state = OUT;
	
	while ((c = getc(fp)) != EOF) {
		if (state == OUT) {
			if (c == '\"') 
				state = IN;
			else
				continue;
		} else {
			if (c == '\"') break;
			if (i < NAMELEN-1)
				firstname[i++] = c;
			else {
				printf("ERROR: Firstname overflow!\n");
				exit(1);
			}
		}
	}
	if (c == EOF) return NULL;
	length = i;
	firstname[i] = '\0';
	name = malloc(sizeof(char)*(length+1));
	strcpy(name, firstname);
	return name;	
}

int readFirstNames(char *firstnames[])
{
	int i;
	char *name;
	i = 0;
	FILE *fp;
	fp = fopen("names.txt", "r");
	while ((name = getFirstName(fp)) != NULL) {
		firstnames[i++] = name;
	}
	firstnames[i] = NULL;
	fclose(fp);
	return i;
}

static void swap(char *names[], int i, int j)
{
	char *temp;
	temp = names[i];
	names[i] = names[j];
	names[j] = temp;
}

void sortFirstNames(char *names[], int left, int right)
{
	/* using quicksort algorithm */
	int i, divider;
	
	if (left >= right) return;
	swap(names, left, ((left+right)/2));
	divider = left;
	i = left;
	while (++i <= right) {
		if (strcmp(names[i], names[left]) < 0)
			swap(names, ++divider, i);		
	}
	swap(names, left, divider);
	sortFirstNames(names, left, divider-1);
	sortFirstNames(names, divider+1, right);
}

void showFirstNames(char *names[])
{
	int i;
	i = 0;
	printf("... printing first names ...\n");
	while (names[i]) 
		printf("%s\n", names[i++]);
	printf("... printing job done :) ...\n");
}

int alphaValue(char name[])
{
	int sum, i;
	sum = i = 0;
	while (name[i])
		sum += (name[i++]-'A') + 1;
	return sum;
}