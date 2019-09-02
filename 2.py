def core(value: list, isRalse: list, index: int, k: int) -> int:
    result = 0
    for i in range(k):
        if (isRalse[index + i] == False):
            result += value[index + 1]#这里马虎把i打成1，导致下边的测试用例不通过
    return result


import numpy as np

if __name__ == '__main__':
    # n,k = map(int,input().strip().split(" "))
    # value = [int(i) for i in input().strip().split(" ")]
    # isRalse = [int(i)==1 for i in input().strip().split(" ")]
    n, k = 10, 5
    value = [int(i) for i in "6481 6127 4477 5436 7356 3137 1076 7182 8147 835".split(" ")]
    isRalse = [int(i) == 1 for i in "1 0 1 0 1 1 0 0 0 1".strip().split(" ")]
    rightSum = np.dot(np.array([int(i) for i in "6481 6127 4477 5436 7356 3137 1076 7182 8147 835".split(" ")]) , np.array(
        [int(i) for i in "1 0 1 0 1 1 0 0 0 1".strip().split(" ")]).T)
    sum = 0
    maxNum = 0
    for i in range(n):
        if (isRalse[i]):
            sum += value[i]
        if (i >= n - k + 1):
            continue
        temp = core(value, isRalse, i, k)
        if (temp > maxNum):
            maxNum = temp
    print("%d" % (sum + maxNum))
