def core()->int:
    pass

if __name__ == '__main__':
    n,k = map(int,input().strip().split(" "))
    value = map(int,input().strip().split(" "))
    isRalse = map(bool,input().strip().split(" "))
    for i in range(n):
