/*************************************************************************
	> File Name: practice2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年01月15日 星期二 14时15分37秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int num[10] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};
int prime[18] = {0};
int ans[12] = {0};
int get_num(int i) {
    return num[i] * 100 + num[i + 1] * 10 + num[i + 2];
}

void isprime(){
    for (int i = 2; i < 18; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > 18) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_num(int jud, int i) {
    if (jud % prime[i] == 0) return 1;
    return 0;
}

void get_ans() {
    for (int i = 0; i < 10; i++) {
        ans[i + 1] += num[9 - i];
    }
    for (int j = 1; j <= ans[0]; j++) {
        if (ans[j] < 10) continue;
        ans[j + 1] += ans[j] / 10;
        ans[j] %= 10;
        ans[0] += (j == ans[0]);
    }
    return ;
}

int main(){
    ans[0] = 1;
    isprime();
    do{
        int i = 0;
        for (i = 7; i > 0; i--) {
            int jud = get_num(i);
            if (!is_num(jud, i)) break;
        }
        if (i == 0) {
            for (int j = 0; j < 10; j++) {
                cout << num[j] ;
            }
            cout << '\n' << endl;
            get_ans();
        }
    }while(next_permutation(num,num + 10));
    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout <<'\n'<<endl;
    return 0;
}
