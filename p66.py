import math
import itertools

SQUARES_UNDER_1000 = {x ** 2 for x in range(int(math.sqrt(1000)))}

def minX(d):
    # assuming d is not a square, otherwise no solutions exist
    for x in itertools.count(1):
        for y in itertools.count(1):
            res = (x ** 2) - d * (y ** 2)
            if res == 1:
                return x
            if res < 1:
                break

def is_square(x):
    return x in SQUARES_UNDER_1000

largestX = 0
correspondingD = 0
for d in range(1, 1001):
    print(d)
    if is_square(d):
        continue
    test = minX(d)
    if test > largestX:
        largestX = test
        correspondingD = d
print(correspondingD)