import sys
import math

def isMatch(arr, k):
    res = []
    ans = isMatchRecursive(arr, k, 0, [], res)
    return ans, res

def isMatchRecursive(arr, k, idx, acc, res):
    # Base cases
    if (idx >= len(arr) and k != 0) or k < 0: # 和がkを超えてしまった or 最後尾に到達した
        return False
    if k == 0: # 答を発見できたとき
        res.append(acc)
        return True

    return isMatchRecursive(arr, k-arr[idx], idx+1, acc+[arr[idx]], res) \
                or isMatchRecursive(arr, k, idx+1, acc, res)

def main():
    arr = [3, 6, -5, 7]
    k = 8

    ans, res = isMatch(arr, k)

    print(ans)
    print(res)

if __name__ == '__main__':
    main()
    
