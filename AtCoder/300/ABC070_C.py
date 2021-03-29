import sys

def gcd(a, b):
    if b == 0:
        return a
    
    return gcd(b, a%b)

def gcd_multi(i, arr):
    if len(arr) <= 1:
        return gcd(i, arr[0])
    
    return gcd(i, gcd_multi(arr[0], arr[1:]))

def lcs(a, b):
    return a*b // gcd(a, b)

def lcs_multi(i, arr):
    if len(arr) <= 1:
        return lcs(i, arr[0])
    
    return lcs(i, lcs_multi(arr[0], arr[1:]))


def main():
    input = sys.stdin.readline
    N = int(input())
    T = []
    for i in range(N):
        T.append(int(input()))
    T = T[::-1]

    if N == 1:
        print(T[0])
        return


    print(lcs_multi(T[0], T[1:]))
    


if __name__ == "__main__":
    main()