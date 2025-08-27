for i in range(13, 38):
    r = 0
    for j in {2, 3, 5, 7}:
        if i % j == 0:
            print("removing", i, "because it is divisible by", j)
            r += 1
    for j in {6, 10, 14, 15, 21, 35}:
        if i % j == 0:
            print("adding", i, "because it is divisible by", j)
            r -= 1
    # if r >= 2:
    print(i, r)
