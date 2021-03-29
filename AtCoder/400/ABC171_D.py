import sys
from collections import defaultdict

def main():
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().rstrip().split()))
    Q = int(input())

    sum_init = sum(A)
    d = defaultdict(int)
    for n in A:
        d[n] += 1
    
    for j in range(Q):
        B, C = map(int, input().rstrip().split())
        diff = d[B] * C - d[B] * B
        sum_init += diff
        print(sum_init)
        d[C] += d[B]
        del d[B]

if __name__ == '__main__':
    main()
    

