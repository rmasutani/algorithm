import sys 
import math

def g(N):
    return int(N*(N+1)/2)

def main():
    input = sys.stdin.readline
    N = int(input())

    ans = 0
    for i in range(1, N+1):
        ans += i * g(int(N*(N+1)/2))
    
    print(ans)

if __name__ == '__main__':
    main()
    