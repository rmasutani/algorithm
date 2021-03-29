import sys

def main():
    input = sys.stdin.readline
    N, K = map(int, input().rstrip().split())
    nums = []
    for i in range(N):
        a, b = map(int, input().rstrip().split())
        nums.append((a, b))
    
    nums = sorted(nums, key=lambda x: x[0])

    cnt = 0
    for i in range(N):
        cnt += nums[i][1]
        if cnt >= K:
            print(nums[i][0])
            break
        

if __name__ == "__main__":
    main()
