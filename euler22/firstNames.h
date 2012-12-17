#ifndef FIRSTNAMES_H
#define FIRSTNAMES_H

#define NAMELEN	20
#define IN	1
#define OUT 0

int readFirstNames(char *firstnames[]);
void sortFirstNames(char *names[], int left, int right);
void showFirstNames(char *names[]);
int alphaValue(char name[]);

#endif