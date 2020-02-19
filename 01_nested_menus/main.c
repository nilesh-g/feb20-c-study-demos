/*
 * main.c
 *
 *  Created on: 14-Feb-2020
 *      Author: nilesh
 */

#include <stdio.h>

#define PI 3.1415

enum main_menu_options {
	EXIT, CIRCLE, RECTANGLE, SQUARE
};

typedef enum sub_menu_options {
	PERI=1, AREA
}sub_menu_options_t;

void circle_operations();
void rectangle_operations();
void square_operations();

int main()
{
	enum main_menu_options choice;
	do {
		printf("\n0. exit\n1. circle\n2. rectangle\n3. square\nenter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case CIRCLE:
				circle_operations();
				break;
			case RECTANGLE:
				rectangle_operations();
				break;
			case SQUARE:
				square_operations();
				break;
		}
	}while(choice != 0);
	return 0;
}

void circle_operations()
{
	sub_menu_options_t choice;
	double rad, result;
	do {
		printf("\n0. exit\n1. perimeter\n2. area\nenter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case PERI:
				printf("enter radius: ");
				scanf("%lf", &rad);
				result = 2 * PI * rad;
				printf("perimeter: %.3lf\n", result);
				break;
			case AREA:
				printf("enter radius: ");
				scanf("%lf", &rad);
				result = PI * rad * rad;
				printf("area: %.3lf\n", result);
				break;
		}
	}while(choice != 0);
}

void rectangle_operations()
{
	sub_menu_options_t choice;
	double len, br, result;
	do {
		printf("\n0. exit\n1. perimeter\n2. area\nenter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case PERI:
				printf("enter length & breadth: ");
				scanf("%lf%lf", &len, &br);
				result = 2 * (len + br);
				printf("perimeter: %.3lf\n", result);
				break;
			case AREA:
				printf("enter length & breadth: ");
				scanf("%lf%lf", &len, &br);
				result = len * br;
				printf("area: %.3lf\n", result);
				break;
		}
	}while(choice != 0);
}

void square_operations()
{
	sub_menu_options_t choice;
	double side, result;
	do {
		printf("\n0. exit\n1. perimeter\n2. area\nenter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case PERI:
				printf("enter side: ");
				scanf("%lf", &side);
				result = 4 * side;
				printf("perimeter: %.3lf\n", result);
				break;
			case AREA:
				printf("enter side: ");
				scanf("%lf", &side);
				result = side * side;
				printf("area: %.3lf\n", result);
				break;
		}
	}while(choice != 0);
}














