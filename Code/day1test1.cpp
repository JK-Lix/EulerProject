/*************************************************************************
	> File Name: day1test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年11月17日 星期六 14时19分42秒
 ************************************************************************/
//欧拉第一题
#include<iostream>
using namespace std;
int main(){
    int sum = 0;
    for(int i=1;i<1000;i++){
        if(i%3==0||i%5==0) sum+=i;
    }
    printf("%d", sum);
}
