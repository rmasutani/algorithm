import sys

def main():
    input = sys.stdin.readline
    N, K = map(int, input().rstrip().split())
    trees = []

    for _ in range(N):
        trees.append(int(input()))

    trees.sort()
    min_diff = float("inf")

    for i in range(K, N):
        min_diff = min(min_diff, trees[i]-trees[i-K])
    
    print(min_diff)



if __name__ == '__main__':
    main()
    