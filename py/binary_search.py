import sys

def isOK(A, B, N, X):
    if A * N + B * len(str(N)) > X:
        return True
    else:
        return False


def main():
    input = sys.stdin.readline
    A, B, X = map(int, input().rstrip().split())
    left = -1
    right = 10**9+1

    while abs(right - left) > 1:
        mid = int(right + left / 2)

        if isOK(A, B, mid, X):
            right = mid
        else:
            left = mid
    
    print(right)




if __name__ == '__main__':
    main()
