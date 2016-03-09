def closest_num(denominator):
    return int(3/7*denominator)

def reduce(num, b):
    a = num
    while b != 0:
        tmp = b
        b = a % b
        a = tmp
    return int(num/a)

num = 0
den = 0
closest = 0
for i in range(1, 1000000):
    check = closest_num(i)
    div = check/i
    if div > closest and div < 3/7:
        closest = div
        num = check
        den = i

print(reduce(num, den))