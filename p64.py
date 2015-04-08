import math

class Frac():
    def __init__(self, num, den, multiplier):
        self.num = num
        self.den = den
        self.multiplier = multiplier
    def __eq__(self, other):
        return self.num == other.num and self.den == other.den and self.multiplier == other.multiplier

class NumRad():
    def __init__(self, num, rad):
        self.num = num
        self.rad = rad
    def __eq__(self, other):
        return self.num == other.num and self.rad == other.rad

def gcf(a, b):
    while b != 0:
        c = a % b
        a = b
        b = c
    return a

def pullOut(frac):
    #frac has numRad on top and int on bottom
    p = int((frac.num.num + math.sqrt(frac.num.rad)) / frac.den)
    sub = p * frac.den
    return Frac(NumRad(frac.num.num - sub, frac.num.rad), frac.den, frac.multiplier)

def reduce(frac):
    g = gcf(frac.den, frac.multiplier)
    frac.den = frac.den / g
    frac.multiplier = frac.multiplier / g
    return frac

def getPeriod(num):
    seen = []
    a0 = int(math.sqrt(num))
    if a0 ** 2 == num:
        return 0
    f = Frac(NumRad(a0, num), num - a0 ** 2, 1)
    while not f in seen:
        seen.append(f)
        f = pullOut(f)
        f.multiplier = f.den
        f.den = f.num.rad - (f.num.num ** 2)
        f.num.num = -f.num.num
        reduce(f)
    seen.reverse()
    return seen.index(f) + 1

oddCount = 0
for i in range(2, 10000):
    if getPeriod(i) % 2 == 1:
        oddCount = oddCount + 1
print(oddCount)