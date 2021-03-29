import sys 

def main():
    input = sys.stdin.readline
    N = int(input())
    B = list(map(int, input().rstrip().split()))

    ans = B[0]
    for i in range(1, N-1):
        ans += min(B[i], B[i-1])
    ans += B[-1]
    
    print(ans)




if __name__ == '__main__':
    main()
    