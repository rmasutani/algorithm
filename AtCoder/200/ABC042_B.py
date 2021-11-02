import sys


def main():
    input = sys.stdin.readline
    N, L = map(int, input().rstrip().split())
    S = []
    for i in range(N):
        S.append(input().rstrip())

    print("".join(sorted(S)))

    return


if __name__ == '__main__':
    main()
