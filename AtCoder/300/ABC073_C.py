import sys
from collections import Counter

def main():
    input = sys.stdin.readline
    N = int(input())
    A = []
    for i in range(N):
        A.append(int(input()))
    
    cnt = Counter(A)
    ans = 0
    for k, v in cnt.items():
        if v % 2 == 1:
            ans += 1
    
    print(ans)


if __name__ == '__main__':
    main()
    