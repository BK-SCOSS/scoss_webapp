

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n = int(input())
        list_n = [int(i) for i in input()[:-1].split(' ')]
        list_n = set(list_n)

        m = int(input())
        list_m = [int(i) for i in input()[:-1].split(' ')]
        list_m = set(list_m)

        res = list_n.intersection(list_m)
        # print(res)
        print(len(res))