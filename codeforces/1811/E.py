t = int(input())

while t > 0:
    a = int(input())
    l = []
    while a > 0:
        l.append(a%9)
        a //= 9

    l = list(map(lambda x: f"{x+1}" if x >= 4 else f"{x}", l))
    print("".join(l[::-1]))
    
    t -= 1
