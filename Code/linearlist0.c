/*************************************************************************
	> File Name: linearlist0.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月17日 星期四 20时15分58秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int size, length;
    int *data;
} Vector;

void init(Vector *vector, int size) {
	vector->size = size;
    vector->length = 0;
    vector->data = (int *)malloc(sizeof(int) * size);
}

void expand(Vector *vector) {
	int *old_data = vector->data;
    vector->size = vector->size * 2;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->data[i] = old_data[i];
    }
    free(old_data);
}

int insert(Vector *vector, int loc, int value) {
	if (loc < 0 || loc > vector->length) return 0;
    if (vector->length >= vector->size) return -1;
    for (int i = vector->length; i > loc; --i) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return 1;
}


void clear(Vector *vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 5);
	int n;
    int loc, val;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &loc, &val);
        int jud = insert(a, loc, val);
        if(jud == 1) printf("success\n");
        else if (jud == 0) printf("failed\n");
        else {
            printf("expand\n");
            expand(a);
            int jud2 = insert(a, loc, val);
        	if(jud2 == 1) printf("success\n");
        	else if (jud2 == 0) printf("failed\n");
        }
    }
    return 0;
}
