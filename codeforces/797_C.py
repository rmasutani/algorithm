import sys

# from regex import F


def main():
    input = sys.stdin.readline

    t = int(input())

    for i in range(t):
        n = int(input())
        s = list(map(int, input().split()))
        f = list(map(int, input().split()))
        d = []

        # 1個目は引き算するだけ
        d.append(f[0] - s[0])
        for j in range(1, n):
            d.append(f[j] - max(f[j-1], s[j]))

        print(" ".join(map(str, d)))

    return


if __name__ == '__main__':
    main()
