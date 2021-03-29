import sys
import math

def main():
    input = sys.stdin.readline
    N = int(input().rstrip())
    A = list(map(int, input().rstrip().split()))
    A.sort()
    is_ans = [True] * N
    
    for i in range(N):
        if not is_ans[i]:
            continue

        for j in range(i+1, N):
            if A[j] == A[i]:
                is_ans[i] = is_ans[j] = False
            elif A[j] % A[i] == 0:
                is_ans[j] = False
    
    # print(A)
    # print(is_ans)
    print(sum(is_ans))
            
    
if __name__ == '__main__':
    main()
    