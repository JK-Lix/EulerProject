/*************************************************************************
	> File Name: practice2.cmZ	> Author: 
	> Mail: 
	> Created Time: 2019年01月12日 星期六 11时58分52秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<inttypes.h>
#include<time.h>

int add(int a,int b) {
    return a + b;
}

typedef int (*func)(int, int);
/*
int main() {
    func fun = (func)add;
    printf("%d\n", fun(3, 4));
    return 0;
}

*/
int main(int argc, char *argv[], char *env[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
   // for (char **p = env; p[0] != NULL; p++) {
    //        printf("%s\n", p[0]);
   // }
    return 0;
}

