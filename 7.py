import math
def count(m:int,n:int):
    a = 0
    b = 0
    for i in range(1,n-m+1):
        b += math.log(i)
    for j in range(m+1,n+1):
        a += math.log(j)
    return math.exp(a-b)
def equal(a:float,b:float)->bool:
    return a-b < 0.001 and a-b > -0.001
def  core(m:int,n:int,k:float):
    if(m==0 or m==n):
        tempstr = ""
        for _ in range(n):
            if(m==0):
                tempstr += "z"
            else:
                tempstr += "a"
        return tempstr
    temp = count(m-1,n-1)
    if(k < temp or equal(k,temp)):
        return "a" + core(m-1,n-1,k)
    else:
        return "z" + core(m,n-1,k-temp)
if __name__ == '__main__':
    n,m,k = map(int,input().split(" "))
    all = count(n,n+m)
    if(k>all):
        print("%d"%-1)
    else:
        result = core(n,n+m,k)
        print("%s"%result)
