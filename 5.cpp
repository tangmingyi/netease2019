//
// Created by zb198 on 2019/9/6.
//
#include <iostream>
#include <math.h>
int main(){
    int a,b,c;
    std::scanf("%d%d%d",&a,&b,&c);
    int max=0;
    int temp=a+b+c;
    max = std::max(max,temp);
    temp = a*b*c;
    max = std::max(max,temp);
    temp = a+b*c;
    max = std::max(max,temp);
    temp = (a+b)*c;
    max = std::max(max,temp);
    temp = a*b+c;
    max = std::max(max,temp);
    temp = a*(b+c);
    max = std::max(max,temp);
    printf("%d",max);
    return 0;
}
