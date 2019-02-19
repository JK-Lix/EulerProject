/*************************************************************************
	> File Name: Lix.h
	> Author: 
	> Mail: 
	> Created Time: 2019年01月14日 星期一 11时19分35秒
 ************************************************************************/

#ifndef _LIX_H
#define _LIX_H
#include<assert.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#define user "USER=haizei"
#define host "JOKER-X"

char pwd[7];
char a = '?';
void setpwd() {
    char c = a;
    FILE *r = fopen("homework3pwd", "r");
    assert(r != NULL);
    fscanf(r, "%s", pwd);
    for (int i = 0; i < 6; i++) {
        pwd[i] = pwd[i];
        c++;
    }
    fclose(r);
}

void change(char *check) {
    char c = a;
    for (int i = 0; i < strlen(check); i++) {
        check[i] = check[i] ^ c;
        c++;
    }
    return ;
}

void change2(char *argv[]){
    char c = a;
    for (int i = 0; i < strlen(argv[1]); i++) {
        argv[1][i] = argv[1][i] ^ c;
        c++;
    }
    return ;
}

#endif
