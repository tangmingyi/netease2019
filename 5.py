if __name__ == '__main__':
    a,b,c = map(int,input().split())
    result = 0
    print("%d"%max([a+b+c,a*b*c,a+b*c,(a+b)*c,a*b+c,a*(b+c)]))

