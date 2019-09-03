def getResult(quire:int,bound:list)->int:
    start = 0
    end = len(bound)-1
    middle = (start+end)//2
    while(True):
        if(bound[middle]<quire):
            start = middle+1
            middle = (start+end)//2
        else:
            if(bound[middle-1]<quire):
                return middle
            else:
                end = middle-1
                middle = (start+end)//2
        if(end-start==1):
            middle = end

if __name__ == '__main__':
    n = int(input())
    # n = 5
    bound = [0]*(n+1)
    for index,num in enumerate([int(i) for i in input().strip().split(" ")]):
        bound[index+1] = num
        bound[index+1] += bound[index]
    m = int(input())
    # m = 3
    for quire in  [int(i) for i in input().strip().split(" ")]:
        print("%d"%getResult(quire,bound))
