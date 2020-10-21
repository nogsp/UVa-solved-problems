from sys import stdin
for line in stdin :
    nums = str(line).split()
    arr = []
    for val in nums :
        if val == '-999999' :
            break
        arr.append(int(val))
    resp = 0
    flag = 0    
    for i in range(0, len(arr)) :
        multi = 1;
        for j in range(i, len(arr)) :
            multi = multi * arr[j]
            if multi > resp or flag == 0 :
                resp = multi
                flag = 1
    print(resp)
