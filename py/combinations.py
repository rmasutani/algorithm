
def permutations(arr):
    if len(arr) <= 1:
        return arr
    
    for i in range(len(arr)):
        return arr[i] + (arr[:i] + arr[i+1:])
    