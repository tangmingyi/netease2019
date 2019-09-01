if __name__ == '__main__':
    n,m = map(int,input().strip().split(" "))
    value = [int(i) for i in input().strip().split(" ")]
    rows = [0]*n
    for i in value:
        rows[i-1] += 1
    print("%d"%min(rows))

