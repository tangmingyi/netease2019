//
// Created by zb198 on 2019/9/8.
//
#include <iostream>
#include <vector>
#include <string>
void initVecter(std::vector<int >& a){
    for(int i=0;i<a.size();i++){
        a[i] = i;
    }
}

bool updateA(std::vector<int>& a, int end,int endIndex){
    //能用index尽量就别用指针
    a[end] += 1;
    if(a[end]>endIndex){
        a[end] -= 1;
//        int change = end-1;
        for(int change= end-1;change>=0;change--){
            if(a[change+1]-a[change] != 1){
                a[change] += 1;
                for(int i=change+1;i<=end;i++){
                    a[i] = a[i-1] + 1;
                }
                return true;
            }
        }
        a[end] -=1;
        return false;
    }
    return true;
}
void printResult(std::vector<int>& a, int n,int m){
    std::string result(m+n,'z');
    for(int i=0;i<n;i++){
        result[a[i]] = 'a';
    }
    std::cout<<result<<std::endl;
}
int main(){
    //总结：vector经过引用后尾指针失效（引用内和引用外都是），在引用内size()失效。
    int n,m,k;
    std::scanf("%d%d%d",&n,&m,&k);
    std::vector<int > a(n);//a of index
    initVecter(a);
    int endIndex = n+m-1;
    bool flagResult = true;
    for(int i=1;i<k;i++){
        flagResult = updateA(a,n-1,endIndex);
        if(!flagResult){
            break;
        }
    }
    if(flagResult) {
        printResult(a,n,m);
    } else{
        std::printf("%d",-1);
    }
    return 0;
}
