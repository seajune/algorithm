def BubbleSort(data): #冒泡排序
    for i in range(len(data)-1):
        for j in range(len(data)-1-i):
            if data[j]>data[j+1]:
                temp = data[j]
                data[j] = data[j+1]
                data[j+1] = temp

    return data

def BubbleSortWithFlag(data): #带标志的冒泡排序
    flag = len(data)-1
    while flag > 0:
        j = flag
        flag = 0
        for i in range(j):
            if data[i] > data[i+1]:
                data[i], data[i+1] = data[i+1], data[i]
                flag = i

    return data

def BubbleSortWithDoubleSide(data): #双向冒泡排序/鸡尾酒排序
    left = 0
    right = len(data)-1
    while left < right:
        for i in range(left,right):
            if data[i] > data[i+1]:
                temp = data[i]
                data[i] = data[i+1]
                data[i+1] = temp
        right -= 1
        for i in range(right, left, -1):
            if data[i-1] > data[i]:
                temp = data[i-1]
                data[i-1] = data[i]
                data[i] = temp
        left += 1

    return data

def NumberOfThree(data, left, right):
    middle = left + (right-left)//2
    #print("middle data: ", data[middle])
    if data[left] > data[right]:
        data[left],data[right] = data[right],data[left]
    if data[left] > data[middle]:
        data[left],data[middle] = data[middle],data[left]
    if data[middle] > data[right]:
        data[middle],data[right] = data[right],data[middle]

    data[left],data[middle] = data[middle],data[left]
    return data[left]

def Partion(data, left, right):
    #temp = data[left] # 固定基准
    temp = NumberOfThree(data, left, right) # 三数取中
    #print("temp: ", temp)
    i = left
    j = right
    while i < j:
        while i < j and data[j] >= temp:
            j -= 1
        if i < j:
            data[i] = data[j]
            i += 1
        while i < j and data[i] <= temp:
            i += 1
        if i < j:
            data[j] = data[i]
            j -= 1
    data[i] = temp
    return i

def QuickSort(data, left, right): #快速排序
    if left < right:
        pivot = Partion(data, left, right)
        QuickSort(data, left, pivot-1)
        QuickSort(data, pivot+1, right)

    return data

def InsertSort(data): #插入排序
    for i in range(1, len(data)):
        temp = data[i]
        j = i-1
        while j>=0 and data[j]>temp:
            data[j+1]=data[j]
            j-=1
        data[j+1] = temp

    return data

def BinInserSort(data): #二分插入排序
    for i in range(1, len(data)):
        temp = data[i]
        low = 0
        high = i-1
        while low <= high:
            mid = (low+high)//2
            if data[mid] > temp:
                high = mid-1
            else:
                low = mid+1
        for j in range(i-1, low-1, -1):
            data[j+1] = data[j]
        data[low] = temp
    
    return data

def ShellSort(data): #希尔排序
    h = 0
    while h <= len(data):
        h = h*3+1
    while h > 0:
        for i in range(h, len(data)):
            temp = data[i]
            j = i-h
            while j >= 0 and data[j] > temp:
                data[j+h] = data[j]
                j -= h
            data[j+h] = temp
        h = (h-1) // 3
    
    return data 

def SelectSort(data): #选择排序
    for i in range(len(data)-1):
        k = i
        for j in range(i+1, len(data)):
            if data[j] < data[k]:
                k = j
        if k != i:
            data[k],data[i] = data[i],data[k]
    
    return data 

def SiftDown(data, start, end):
    temp = data[start]
    i = start
    j = start*2+1
    while j <= end:
        if j < end and data[j] < data[j+1]:
            j += 1
        if data[j] <= temp:
            break
        data[i] = data[j]
        i = j
        j = 2*i+1
    data[i] = temp

def HeapSort(data): #堆排序
    for i in range(len(data)//2-1, -1, -1):
        SiftDown(data, i, len(data)-1) # 构建大顶堆
    for i in range(len(data)-1, 0, -1):
        data[0], data[i] = data[i], data[0]
        SiftDown(data, 0, i-1) # 堆排序

    return data

def Merge(list1, list2):
    list1_index, list2_index = 0, 0
    result = []
    while list1_index < len(list1) and list2_index < len(list2):
        if list1[list1_index] <= list2[list2_index]:
            result.append(list1[list1_index])
            list1_index+=1
        else:
            result.append(list2[list2_index])
            list2_index+=1
    result += list1[list1_index:]
    result += list2[list2_index:]
    return result

def MergeSort(data): #归并排序
    if len(data) <= 1:
        return data
    mid = len(data)//2
    left = MergeSort(data[:mid])
    right = MergeSort(data[mid:])
    return Merge(left,right)

def CountSort(data): #计数排序
    max_value = max(data)
    min_value = min(data)
    count_list = [0] * (max_value-min_value+1)
    for i in data:
        count_list[i-min_value] += 1
    result = []
    for index, value in enumerate(count_list):
        while value > 0:
            result.append(index+min_value)
            value -= 1
    return result

def RadixSort(data): #基数排序
    i = 0
    max_value = max(data)
    j = len(str(max_value))
    while i < j:
        bucket_list = [[] for index in range(10)]
        for item in data:
            bucket_list[item//(10**i)%10].append(item)
        data.clear()
        for k in bucket_list:
            for v in k:
                data.append(v)
        i+=1

    return data

def BucketSort(data): #桶排序
    min_value = min(data)
    max_value = max(data)
    bucket_range = (max_value-min_value)/len(data)
    bucket_list = [[] for i in range(len(data)+1)]
    for item in data:
        bucket_list[int((item-min_value)//bucket_range)].append(item)
    data.clear()
    for k in bucket_list:
        for v in sorted(k):
            data.append(v)

    return data

data = [3,5,15,36,26,27,2,38,4,19,44]
#print("after bubble sort: ", BubbleSort(data))
print("after bubble sort with flag: ", BubbleSortWithFlag(data))
#print("after bubble sort with double side: ", BubbleSort(data))
#print("after quick sort: ", QuickSort(data, 0, len(data)-1))
#print("after insert sort: ", InsertSort(data))
#print("after bin insert sort: ", BinInserSort(data))
#print("after shell sort: ", ShellSort(data))
#print("after select sort: ", SelectSort(data))
#print("after heap sort: ", HeapSort(data))
#print("after merge sort: ", MergeSort(data))
#print("after count sort: ", CountSort(data))
#print("after radix sort: ", RadixSort(data))
#print("after bucket sort: ", BucketSort(data))