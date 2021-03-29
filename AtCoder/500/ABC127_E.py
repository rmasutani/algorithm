import sys
from itertools import combinations

def combs(a, b):
    if (b == 0 or  a==b):
        return 1
    
    return combs(a-1, b) + combs(a-1, b-1)

def main():
    input = sys.stdin.readline
    N, M, K = map(int, input().split())

    coords = [(x, y) for x in range(N) for y in range(M)]
    pat = combs(N*M*2, K-2)

    ans = 0
    for i in range(N*M):
        for j in range(i+1, N*M):
            dx = abs(coords[0][0] - coords[1][0])
            ans += dx 
    
    ans *= pat
    
    

if __name__ == '__main__':
    main()
    
