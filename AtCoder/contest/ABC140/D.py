import sys 

def main():
    input = sys.stdin.readline
    N, K = map(int, input().rstrip().split())
    S = input()
    
    score = 0
    for i in range(0, N-1):
        if S[i] == 'R' and S[i+1] == 'R':
            score += 1
    
    for i in range(1, N):
        if S[i] == 'L' and S[i-1] == 'L':
            score += 1

    print(min(score+K*2, N-1))


if __name__ == '__main__':
    main()
    