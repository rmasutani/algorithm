import sys


def main():
    input = sys.stdin.readline

    t = int(input())

    for i in range(t):
        n, k = map(int, input().split())
        board = input()

        # 情報のリストを作る
        arr = []
        count = 1
        prev = board[0]
        for j in range(1, n):
            if board[j] == prev:
                count += 1
                continue

            arr.append((prev, count))
            prev = board[j]
            count = 1

        arr.append((prev, count))

        # Find B max length, look left and right
        max_len = -1
        max_idx = 0
        for k in range(len(arr)):
            if arr[k][0] == "B" and arr[k][1] > max_len:
                max_idx = k
                max_len = arr[k][1]

        print(arr)

    return


if __name__ == '__main__':
    main()
