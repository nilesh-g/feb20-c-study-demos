/*
 * main.c
 *
 *  Created on: 19-Feb-2020
 *      Author: nilesh
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emp
{
	int id;
	char name[40];
	double sal;
}emp_t;

int comp_int(const void *e1, const void *e2)
{
	int *p1=(int*)e1, *p2=(int*)e2;
	int diff = *p1 - *p2;
	return diff;
}

int comp_double(const void *e1, const void *e2)
{
	double *p1=(double*)e1, *p2=(double*)e2;
	double diff = *p1 - *p2;
	if(diff > 0)
		return +1;
	if(diff < 0)
		return -1;
	return 0;
}

int comp_strings(const void *e1, const void *e2)
{
	char *p1=(char*)e1, *p2=(char*)e2;
	double diff = strcmp(p1, p2);
	return diff;
}

int comp_emp_sal_asc(const void *e1, const void *e2)
{
	emp_t *p1=(emp_t*)e1, *p2=(emp_t*)e2;
	double diff = p1->sal - p2->sal;
	if(diff > 0)
		return +1;
	if(diff < 0)
		return -1;
	return 0;
}

int comp_emp_sal_desc(const void *e1, const void *e2)
{
	emp_t *p1=(emp_t*)e1, *p2=(emp_t*)e2;
	double diff = p1->sal - p2->sal;
	if(diff > 0)
		return -1;
	if(diff < 0)
		return +1;
	return 0;
}

int main()
{
	int arr1[] = {44, 22, 77, 33, 66};
	double arr2[] = {4.4, 2.2, 7.7, 3.3, 6.6};
	char *arr3[] = {"mon", "tue", "wed", "thr", "fri"};
	emp_t arr4[] = {
			{44, "J", 345.67},
			{22, "B", 734.23},
			{77, "O", 245.66},
			{33, "N", 984.43},
			{66, "D", 643.22}
	};
	int i;

	printf("int arr asc sort.\n");
	qsort(arr1, 5, sizeof(int), comp_int);
	for(i=0; i<5; i++)
		printf("%d\n", arr1[i]);
	printf("\n");

	printf("double arr asc sort.\n");
	qsort(arr2, 5, sizeof(double), comp_double);
	for(i=0; i<5; i++)
		printf("%lf\n", arr2[i]);
	printf("\n");

	printf("string arr asc sort.\n");
	qsort(arr3, 5, sizeof(char*), comp_strings);
	for(i=0; i<5; i++)
		printf("%s\n", arr3[i]);
	printf("\n");

	printf("emp arr asc sort by sal.\n");
	qsort(arr4, 5, sizeof(emp_t), comp_emp_sal_asc);
	for(i=0; i<5; i++)
		printf("%d, %s, %lf\n", arr4[i].id, arr4[i].name, arr4[i].sal);
	printf("\n");

	printf("emp arr desc sort by sal.\n");
	qsort(arr4, 5, sizeof(emp_t), comp_emp_sal_desc);
	for(i=0; i<5; i++)
		printf("%d, %s, %lf\n", arr4[i].id, arr4[i].name, arr4[i].sal);
	printf("\n");
	return 0;
}

