import math

class Frac():
    def __init__(self, num, den, multiplier):
        self.num = num
        self.den = den
        self.multiplier = multiplier
    def __hash__(self):
        return hash((self.num, self.den, self.multiplier))
    def __str__(self):
        return '%d x %d/%d' %(self.multiplier, self.num, self.den)

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
    return int(sub/frac.den)

def reduce(frac):
    g = gcf(frac.den, frac.multiplier)
    frac.den = frac.den / g
    frac.multiplier = frac.multiplier / g
    return frac

def continuedFraction(num):
    a0 = int(math.sqrt(num))
    yield a0
    f = Frac(a0, num - a0 ** 2, 1)
    while True:
        yield pullOut(f, a0)
        f.multiplier = f.den
        f.den = num - (f.num ** 2)
        f.num = -f.num
        reduce(f)

def nonSquares():
    for i in range(2, 1001):
        if int(math.sqrt(i)) ** 2 != i:
            yield i

m = 0
D = 0
Ds = nonSquares()
for n in Ds:
    h = [0, 1]
    k = [1, 0]
    c = continuedFraction(n)
    for i in c:
        hn = i * h[-1] + h[-2]
        kn = i * k[-1] + k[-2]
        if hn ** 2 - n * (kn ** 2) == 1:
            if hn > m:
                m = hn
                D = n
            break
        h.append(hn)
        k.append(kn)
print('D: %d' %D)
print('h: %d' %m)