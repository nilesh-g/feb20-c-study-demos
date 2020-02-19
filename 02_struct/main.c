/*
 * main.c
 *
 *  Created on: 16-Feb-2020
 *      Author: nilesh
 */

#include <stdio.h>

#pragma pack(1)

struct emp
{
	int id;
	char name[40];
	double sal;
};

void print_emps(struct emp *a, int n);
int main()
{
	//struct emp arr[3] = { {1, "A", 100.0}, {2, "B", 200.0}, {3, "C", 300.0} };
	struct emp arr[3];
	int i;
	for(i=0; i<3; i++)
	{
		printf("enter id, name & sal: ");
		scanf("%d%s%lf", &arr[i].id, arr[i].name, &arr[i].sal);
	}
	print_emps(arr, 3);
	
	return 0;
}

void print_emps(struct emp *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d, %s, %lf\n", a[i].id, a[i].name, a[i].sal);
}









