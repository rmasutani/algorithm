import sys 

def main():
    input = sys.stdin.readline
    N = int(input())

    A = list(map(int, input().rstrip().split()))
    B = list(map(int, input().rstrip().split()))
    C = list(map(int, input().rstrip().split()))

    ans = B[A[0]]
    for i in range(1, N):
        ans += B[A[i]-1]

        if A[i] - A[i-1] == 1:
            ans += C[A[i-1]-1]

    print(ans) 



if __name__ == '__main__':
    main()
    