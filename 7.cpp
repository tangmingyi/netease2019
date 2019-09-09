//
// Created by zb198 on 2019/9/8.
//
#include <iostream>
#include <string>
#include <math.h>
//long long count(int n,int total){
//    long long a=1,b=1;
//    for(int i=0;i<n;i++){
//        a *= (total-i);
//    }
//    for(int j=n;j>=1;j--){
//        b *= j;
//    }
//    return a/b;
//}
bool equl(double a, double b){
    return a-b < 0.001 && a-b > -0.001;
}
double count(int n,int total){
    double a=0.0,b=0.0;
    for(int i= 1;i<=total-n;i++){
        b += log(double(i));
    }
    for(int j=n+1;j<=total;j++){
        a += log(double(j));
    }
    return exp(a-b);

}
std::string core(double k,int n,int total){
    if(n==0 || total==n){
        std::string laststring;
        for(int i=0;i<total;i++){
            if(n==0) {
                laststring += 'z';
            } else{
                laststring += 'a';
            }
        }
        return laststring;
    }
    double temp = count(n-1,total-1);
    if(k<temp||equl(k,temp)){
        return 'a' + core(k,n-1,total-1);
    } else{
        return 'z' + core(k-temp,n,total-1);
    }
}

void test(){
    int temp = count(2,6);
    std::string result = core(6,2,4);
    int c = 0;
}
int main(){
    test();
    //总结：vector经过引用后尾指针失效（引用内和引用外都是），在引用内size()失效。
    int n,m;
    double k;
    std::scanf("%d%d",&n,&m);
    std::cin>>k;
    double temp = count(n,n+m);
    std::string resutl;
    if (temp > k || equl(temp,k)){
        resutl = core(k,n,m+n);
        std::cout<<resutl<<std::endl;
    } else{
        std::printf("%d",-1);
    }
    return 0;
}
