def maxAndMin(arr,low,high):
    if(low == high):
        return arr[low],arr[low]
    elif(low == high-1):
        if(arr[low]>arr[high]):
            return arr[low],arr[high]
        else:
            return arr[high], arr[low]
    else:
        mid = (low+high)//2
        max,min = maxAndMin(arr,low,mid)
        max1,min1 = maxAndMin(arr,mid+1,high)
        if(max1>max):
            max = max1
        if(min1<min):
            min = min1
        return max,min


arr = [3, 1, 4, 6, 2, 8]
max_val, min_val = maxAndMin(arr, 0, len(arr) - 1,)
print("Max:", max_val)
print("Min:", min_val)