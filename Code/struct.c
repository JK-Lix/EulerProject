/*************************************************************************
	> File Name: practice2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月11日 星期五 18时13分58秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

 

int main() {

struct node1 {
        char a;
        char b;
        int c;
    };

    struct node2 {
        char a;
        int c;
        char b;
    };

    printf("%lu\n", sizeof(struct node1));
    printf("%lu", sizeof(struct node2));
    return 0;
}
