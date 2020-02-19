/*
 * main.c
 *
 *  Created on: 19-Feb-2020
 *      Author: nilesh
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// text file
#define LOCATIONS_DB "locations.txt"
// binary files
#define DEPT_DB "dept.db"
#define EMP_DB "emp.db"

typedef enum options
{
	EXIT, ADD_LOCATION, LIST_LOCATIONS, ADD_DEPT, LIST_DEPTS, ADD_EMP, LIST_EMPS
}option_t;

typedef struct dept
{
	int id;
	char name[40];
	char loc[40];
}dept_t;

typedef struct emp
{
	int id;
	char name[40];
	double sal;
	int deptid;
}emp_t;

void accept_dept(dept_t *d)
{
	printf("Enter id, name, loc: ");
	scanf("%d%s%s", &d->id, d->name, d->loc);
}

void print_dept(dept_t *d)
{
	printf("deptid=%d, name=%s, loc=%s\n", d->id, d->name, d->loc);
}

void accept_emp(emp_t *e)
{
	printf("Enter id, name, sal & deptid: ");
	scanf("%d%s%lf%d", &e->id, e->name, &e->sal, &e->deptid);
}

void print_emp(emp_t *e)
{
	printf("empid=%d, name=%s, sal=%lf, deptid=%d\n", e->id, e->name, e->sal, e->deptid);
}

void add_loc()
{
	FILE *fp;
	char loc[40];

	fp = fopen(LOCATIONS_DB, "a");
	if(fp == NULL)
	{
		perror("failed to open " LOCATIONS_DB);
		return;
	}

	printf("enter location:\n");
	fgets(loc, sizeof(loc), stdin); // scan from console
	fputs(loc, fp);

	fclose(fp);
}

void display_all_locs()
{
	FILE *fp;
	char loc[40];
	int i;

	fp = fopen(LOCATIONS_DB, "r");
	if(fp == NULL)
	{
		perror("failed to open " LOCATIONS_DB);
		return;
	}

	i=1;
	while(fgets(loc, sizeof(loc), fp) != NULL)
		printf("%d. %s", i++, loc);

	fclose(fp);
}

void add_dept()
{
	FILE *fp;
	dept_t d;
	int n;

	fp = fopen(DEPT_DB, "ab");
	if(fp == NULL)
	{
		perror("failed to open " DEPT_DB);
		return;
	}

	accept_dept(&d);
	n = fwrite(&d, sizeof(dept_t), 1, fp);
	printf("dept added: %d\n", n);

	fclose(fp);
}

void display_all_dept()
{
	FILE *fp;
	dept_t d;

	fp = fopen(DEPT_DB, "rb");
	if(fp == NULL)
	{
		perror("failed to open " DEPT_DB);
		return;
	}

	while(fread(&d, sizeof(dept_t), 1, fp) > 0)
		print_dept(&d);

	fclose(fp);
}

int find_dept(int dept_id, dept_t *pd)
{
	FILE *fp;
	dept_t d;
	int found = 0;

	fp = fopen(DEPT_DB, "rb");
	if(fp == NULL)
	{
		perror("failed to open " DEPT_DB);
		return 0;
	}

	while(fread(&d, sizeof(dept_t), 1, fp) > 0)
	{
		if(d.id == dept_id)
		{
			*pd = d;
			found = 1;
			break;
		}
	}

	fclose(fp);
	return found;
}

void add_emp()
{
	FILE *fp;
	emp_t e;
	int n;

	fp = fopen(EMP_DB, "ab");
	if(fp == NULL)
	{
		perror("failed to open " EMP_DB);
		return;
	}

	accept_emp(&e);
	n = fwrite(&e, sizeof(emp_t), 1, fp);
	printf("emp added: %d\n", n);

	fclose(fp);
}

void display_all_emp()
{
	FILE *fp;
	emp_t e;
	dept_t d;

	fp = fopen(EMP_DB, "rb");
	if(fp == NULL)
	{
		perror("failed to open " EMP_DB);
		return;
	}

	while(fread(&e, sizeof(emp_t), 1, fp) > 0)
	{
		if(find_dept(e.deptid, &d) == 0)
			strcpy(d.name, "Not Found");
		printf("dept: %s, emp: ", d.name);
		print_emp(&e);
	}

	fclose(fp);
}

int main()
{
	int choice;
	do {
		printf("\n0. EXIT\n1. ADD_LOCATION\n2. LIST_LOCATIONS\n3. ADD_DEPT\n4. LIST_DEPTS\n5. ADD_EMP\n6. LIST_EMPS\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case EXIT:
				printf("bye!\n");
				break;
			case ADD_LOCATION:
				add_loc();
				break;
			case LIST_LOCATIONS:
				display_all_locs();
				break;
			case ADD_DEPT:
				add_dept();
				break;
			case LIST_DEPTS:
				display_all_dept();
				break;
			case ADD_EMP:
				add_emp();
				break;
			case LIST_EMPS:
				display_all_emp();
				break;
		}
	}while(choice != EXIT);
	return 0;
}

