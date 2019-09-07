def updateHight(towers:list,hight:int,hightBegin:int,hightEnd:int)->tuple:
    towers[hight][0] -=1
    if(hight==hightBegin):
        hight=hightEnd
        if(towers[hightBegin][0]==towers[hightBegin-1][0]):
            hightBegin -=1
    else:
        hight -=1
    return hight,hightBegin
def updateLower(towers:list,lower:int,lowerBegin:int,lowerEnd:int)->tuple:
    towers[lower][0] += 1
    if(lower==lowerEnd):
        lower=lowerBegin
        if(towers[lowerEnd][0]==towers[lowerEnd+1][0]):
            lowerEnd += 1
    else:
        lower +=1
    return lower,lowerEnd
if __name__ == '__main__':
    n,k = map(int,input().split(" "))
    towers = [[int(i),index] for index,i in enumerate(input().split(" "))]
    moves = []
    towers = sorted(towers,key=lambda x:x[0])
    lower = 0
    lowerBegin = 0
    lowerEnd = 0
    while(towers[lowerEnd][0]==towers[lowerEnd+1][0]):
        lowerEnd+=1
    hight = len(towers)-1
    hightBegin = len(towers)-1
    hightEnd = len(towers)-1
    while(towers[hightBegin][0]==towers[hightBegin-1][0]):
        hightBegin-=1
    step = 0
    for i in range(k):
        if(towers[lower][0]==towers[hight][0]):
            step = i
            break
        moves.append((towers[hight][1],towers[lower][1]))
        hight,hightBegin = updateHight(towers,hight,hightBegin,hightEnd)
        lower,lowerEnd = updateLower(towers,lower,lowerBegin,lowerEnd)
        step = i
    print("%d %d"%(towers[hight][0]-towers[lower][0],step+1))
    for move in moves:
        print("%d %d"%(move[0]+1,move[1]+1))
