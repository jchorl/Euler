import math
import time

class Frac():
    def __init__(self, num, den, multiplier):
        self.num = num
        self.den = den
        self.multiplier = multiplier
    def __hash__(self):
        return hash((self.num, self.den, self.multiplier))

def gcf(a, b):
    while b != 0:
        c = a % b
        a = b
        b = c
    return a

def pullOut(frac, rt):
    p = int((frac.num + rt) / frac.den)
    sub = p * frac.den
    frac.num = frac.num - sub
    return frac

def reduce(frac):
    g = gcf(frac.den, frac.multiplier)
    frac.den = frac.den / g
    frac.multiplier = frac.multiplier / g
    return frac

def getPeriod(num):
    seen = []
    seenSet = set()
    a0 = int(math.sqrt(num))
    if a0 ** 2 == num:
        return 0
    f = Frac(a0, num - a0 ** 2, 1)
    while True:
        h = hash(f)
        if h in seenSet:
            break
        seen.append(h)
        seenSet.add(h)
        f = pullOut(f, a0)
        f.multiplier = f.den
        f.den = num - (f.num ** 2)
        f.num = -f.num
        reduce(f)
    return len(seen) - seen.index(hash(f))

start_time = time.time()
oddCount = 0
for i in range(2, 10000):
    if getPeriod(i) % 2 == 1:
        oddCount = oddCount + 1
end_time = time.time()
print(oddCount)
print('%s seconds' %(end_time - start_time))