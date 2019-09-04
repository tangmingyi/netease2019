//
// Created by zb198 on 2019/9/3.
//
#include <iostream>
#include <math.h>
void initPoint(std::pair<int ,int >& point,std::pair<int,int >& conter){
    std::cin>>point.first;
    std::cin>>point.second;
    std::cin>>conter.first;
    std::cin>>conter.second;
}
std::pair<int,int > helpFunction(const std::pair<int,int> point,const std::pair<int,int >conter){
    int x,y;
    if(point.first<conter.first){
        x=-1;
    } else{
        x=1;
    }
    if(point.second<conter.second){
        y=-1;
    } else{
        y=1;
    }
    if(x==1&&y==1){
        x=-1;
    } else if(x==-1&&y==1){
        y=-1;
    } else if(x==-1&&y==-1){
        x=1;
    } else{
        y=1;
    }
    return std::make_pair(x,y);
}
void getNextPoint(std::pair<int,int>& point,const std::pair<int,int >conter, int& step,int num=1){
    for(int i=0;i<num;i++){
        int xchange = std::abs(conter.first-point.first);
        int ychange = std::abs(conter.second-point.second);
        std::pair<int,int > temp = helpFunction(point,conter);
        point.first = conter.first + temp.first*xchange;
        point.second = conter.second + temp.second*ychange;
        step++;
    }
}
bool equal(std::pair<int,int > a,std::pair<int,int >b){
    return (a.first==b.first) && (b.first==b.second);
}
int main(){
    int n;
    std::cin>>n;
    std::pair<int,int >a,b,c,d,conter1,conter2,conter3,conter4;
    for(int i=0;i<n;i++){        //todo:修改逻辑， 把所有判断放在最后的循环里，并封装。
        int result=-1;
        for(int i=0;i<4;i++){
            int step= 0;
            if(i==0){
                initPoint(a,conter1);
            } else{
                getNextPoint(a,conter1,step);
            }
            int stepa = step;
            for(int j=0;j<4;j++){
                if(j==0){
                    initPoint(b,conter2);
                } else{
                    getNextPoint(b,conter2,step);
                }
                std::pair<int,int > c1({a.first,a.second}),c2({a.first,a.second});
                int temp=0;
                getNextPoint(c1,b,temp,1);
                getNextPoint(c2,b,temp,3);
                int stepb = step;
                for(int s=0;s<4;s++){
                    int num;
                    if(s==0){
                        initPoint(c,conter3);
                    } else{
                        getNextPoint(c,conter3,step);
                    }
                    int stepc=step;
                    if(equal(c1,c)||equal(c2,c)) {
                        std::pair<int, int> d1({b.first, b.second});
                        if (equal(c1, c)) {
                            num = 1;
                        } else{
                            num = 3;
                        }
                        getNextPoint(d1, c, temp, num);
                        for(int m=0;m<4;m++){
                            if(m==0){
                                initPoint(d,conter4);
                            } else{
                                getNextPoint(d,conter4,step);
                            }
                            if(equal(d1,d)){
                                if(result==-1 || result>step){
                                    result = step;
                                }
                                step = stepc;
                                break;
                            }

                        }
                    }
                    step = stepb;
                }
                step = stepa;
            }
        }
        std::cout<<result<<std::endl;
    }
    return 0;
}
