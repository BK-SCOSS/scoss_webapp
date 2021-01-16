t = int(input())
for _ in range(t):
    n = int(input())
    list_ = [int(i) for i in input()[:-1].split(' ')]
    
    res = 0
    
    while len(list_) != 1:
        res_temp = 0
        list_temp = []

        for i in range(0, len(list_) -1, 2):
            # print(i)
            m = list_[i] + list_[i+1]
            res_temp = max(res_temp, m)

            list_temp.append(m)
        
        res += res_temp

        if len(list_) % 2 != 0:
            list_temp.append(list_[-1])

        list_ = list_temp

    print(res)