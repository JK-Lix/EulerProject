/*************************************************************************
	> File Name: practice.c
	> Author: 
	> Mail: 
	> Created Time: 2019年01月05日 星期六 10时40分50秒
 ************************************************************************/
    
#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

#define DEBUG
#ifdef DEBUG
#define P(a) {\
              printf("%s : %s : %d]%s : %d\n", __FILE__, __func__, __LINE__,#a, a);\
             }
#else
#define P(a) {}
#endif

#define swap(a, b) {\
                    __typeof(a) __temp = a;\
                    a = b; b = __temp;\
                   }

#define MAX(a, b) ({// 小括号是为了使之成为单独的式子\
                   __typeof(a) __a = a;\
                   __typeof(b) __b = b;\
                   (__a) > (__b) ? (__a) : (__b);\
                  })

int main() {
    P(MAX(2, 3));
    P(3 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    int a = 7;
    P(MAX(a++, 6));
    P(a);
    return 0;
}
