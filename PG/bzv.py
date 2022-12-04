import sys


def main():
    input = sys.stdin.readline

    N = int(input().rstrip())
    bs = list(map(int, input().rstrip().split()))

    # sort
    bs.sort()

    # seek max diff
    max_diff = bs[1] - bs[0]
    max_idx = 0
    for i in range(2, N):
        if bs[i] - bs[i-1] > max_diff:
            max_diff = bs[i] - bs[i-1]
            max_idx = i-1

    print(bs[max_idx] + int(max_diff / 2))

    return


if __name__ == '__main__':
    main()
