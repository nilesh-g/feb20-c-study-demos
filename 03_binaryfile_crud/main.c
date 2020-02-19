/*
 * main.c
 *
 *  Created on: 17-Feb-2020
 *      Author: nilesh
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum menu
{
	EXIT, ADD_EMP, DISPLAY_ALL, FIND_EMP, EDIT_EMP, DEL_EMP
}menu_t;

typedef struct emp
{
	int id;
	char name[40];
	double sal;
}emp_t;

void accept_emp(emp_t *e)
{
	printf("enter id, name & sal: ");
	scanf("%d%s%lf", &e->id, e->name, &e->sal);
}
void print_emp(emp_t *e)
{
	printf("%d, %s, %.2lf\n", e->id, e->name, e->sal);
}

void add_emp()
{
	emp_t e;
	FILE *fp;
	int n;
	fp = fopen("emp.db", "ab");
	if(fp == NULL)
	{
		perror("fopen() failed");
		return;
	}

	accept_emp(&e);
	n = fwrite(&e, sizeof(emp_t), 1, fp);
	printf("emps added: %d\n", n);

	fclose(fp);
}

void display_all()
{
	emp_t e;
	FILE *fp;
	fp = fopen("emp.db", "rb");
	if(fp == NULL)
	{
		perror("fopen() failed");
		return;
	}

	while( fread(&e, sizeof(emp_t), 1, fp) != 0 )
		print_emp(&e);

	fclose(fp);
}

void find_emp_by_id()
{
	emp_t e;
	FILE *fp;
	int id, found=0;
	fp = fopen("emp.db", "rb");
	if(fp == NULL)
	{
		perror("fopen() failed");
		return;
	}

	printf("enter emp id to find: ");
	scanf("%d", &id);

	while( fread(&e, sizeof(emp_t), 1, fp) != 0 )
	{
		if(e.id == id)
		{
			print_emp(&e);
			found = 1;
		}
	}

	if(found == 0)
		printf("no such emp found.\n");
	fclose(fp);
}


void edit_emp()
{
	emp_t e;
	FILE *fp;
	int id, found=0, n;
	long size = sizeof(emp_t);
	fp = fopen("emp.db", "rb+");
	if(fp == NULL)
	{
		perror("fopen() failed");
		return;
	}

	printf("enter emp id to find: ");
	scanf("%d", &id);

	while( fread(&e, sizeof(emp_t), 1, fp) != 0 )
	{
		if(e.id == id)
		{
			print_emp(&e);
			found = 1;

			// add new details for emp
			accept_emp(&e);
			fseek(fp, -size, SEEK_CUR);
			n = fwrite(&e, sizeof(emp_t), 1, fp);
			printf("emp edited: %d\n", n);
		}
	}

	if(found == 0)
		printf("no such emp found.\n");
	fclose(fp);
}

void del_emp()
{
	FILE *fs, *fd;
	emp_t e;
	int id, found=0;
	printf("enter emp id to delete: ");
	scanf("%d", &id);
	fs = fopen("emp.db", "rb");
	if(fs == NULL)
	{
		perror("fopen() failed");
		return;
	}
	fd = fopen("temp.db", "wb");
	if(fd == NULL)
	{
		perror("fopen() failed");
		return;
	}
	while(fread(&e, sizeof(emp_t), 1, fs) != 0)
	{
		if(e.id == id)
			found = 1;
		else
			fwrite(&e, sizeof(emp_t), 1, fd);
	}
	fclose(fd);
	fclose(fs);
	remove("emp.db");
	rename("temp.db", "emp.db");

	if(found == 0)
		printf("no such emp found.\n");
}
int main()
{
	int choice;
	do {
		printf("\n0. EXIT\n1. ADD_EMP\n2. DISPLAY_ALL\n3. FIND_EMP\n4. EDIT_EMP\n5. DEL_EMP\nenter choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case EXIT:
			break;
		case ADD_EMP:
			add_emp();
			break;
		case DISPLAY_ALL:
			display_all();
			break;
		case FIND_EMP:
			find_emp_by_id();
			break;
		case EDIT_EMP:
			edit_emp();
			break;
		case DEL_EMP:
			del_emp();
			break;
		}
	}while(choice != EXIT);
	return 0;
}









