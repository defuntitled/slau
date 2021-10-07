#include"stdlib.h"
#include"stdio.h"

struct Matrix
{
	double *data;
	int n;
	int m;
};
typedef struct Matrix matrix;

matrix *mkmatrix(int n,int m)
{
	matrix *mx = malloc(sizeof(matrix));
	mx->m = m;
	mx->n = n;
	mx->data = malloc(sizeof(double)*n*m);
	return mx;
}

void fill_matrix(matrix *mx) 
{
	for (int i = 0; i < mx->n; i++) {
		for (int j = 0; j < mx->m; j++) {
			scanf_s("%lf", mx->data + i * mx->n + j);
		}
	}
}

void switch_string(matrix *mx,int i,int j) {
	for (int k = 0; k < mx->m; k++) {
		*(mx->data + i * mx->n + k) += *(mx->data + j * mx->n + k);
		*(mx->data + j * mx->n + k) = *(mx->data + i * mx->n + k) - *(mx->data + j * mx->n + k);

	}
}

void multip(matrix *mx, int str, int k) {
	for (int i = 0; i < mx->m; i++) {
		*(mx->data + str * mx->n + i) *= k;
	}
}

void subtraction_rows(matrix*mx, int ded, int v) {
	for (int i = 0; i < mx->m; ++i) {
		*(mx->data + ded * mx->n + i) -= *(mx->data + v * mx->n + i);
	}
}

void zero_column(matrix *mx, int col) {
	if (*(mx->data+col*mx->n) == 0) {
		for (int i = 1; i < mx->n; i++) {
			if (*(mx->data + i * mx->n) != 0) {
				switch_string(mx, 0, i);
				break;
			}
		}
	}
}

void to_triangle(matrix *mx) {
	if (*mx->data == 0) {
		for (int i = 1; i < mx->n; i++) {
			if (*(mx->data + i * mx->n) != 0) {
				switch_string(mx, 0, i);
				break;
			}
		}
	}

}