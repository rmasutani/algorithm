import requests
import sys

def main():
    URL = "https://r3k3audez7.execute-api.ap-northeast-1.amazonaws.com/Prod/coffeepot/"
    left = 0
    right = 180

    while right - left > 1:
        mid = left + int((right - left) / 2)

        payload = {"minutes": mid}
        r = requests.get(url=URL, params=payload)
        d = r.json()


        if d["remaining"] == 0:
            right = mid
        else:
            left = mid 

    print(right)



# a = [1, 14, 32, 51, 51, 51, 243, 419, 750, 910]

# def isOK(idx, key):
#     if a[idx] >= key:
#         return True
    
#     return False

# def lower_bound(key):
#     left = -1
#     right = len(a)

#     while right - left > 1:
#         mid = left + int((right - left) / 2)

#         if isOK(mid, key):
#             right = mid
#         else:
#             left = mid 

#     print(right)


if __name__ == '__main__':
    main()
    # lower_bound(51)
    # lower_bound(1)
    # lower_bound(910)
    # lower_bound(52)
    # lower_bound(0)
    # lower_bound(911)
    