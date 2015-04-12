import math
class Frac():
    def __init__(self, num, den):
        self.num = num
        self.den = den
    def __str__(self):
        return str(self.num) + '/' + str(self.den)
    def removeDenFrac(self):
        self.num = self.num * self.den.den
        self.den = self.den.num
        return self

def sumNum(frac):
    s = 0
    num = frac.num
    while num:
        s = s + num % 10
        num /= 10
    return s

def add(num, frac):
    frac.num = frac.num + num * frac.den
    return frac

def calc(last0, last1, last2, remaining):
    if remaining == 0:
        return Frac(0, 1)
    if last0 != 1 or last1 != 1:
        return Frac(1, add(1, calc(1, last0, last1, remaining - 1))).removeDenFrac()
    return Frac(1, add(last2 + 2, calc(last2 + 2, 1, 1, remaining - 1))).removeDenFrac()

print(sumNum(add(2, calc(1, 0, 0, 99))))
