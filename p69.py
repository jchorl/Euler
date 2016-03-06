from math import sqrt

LIMIT = 1000000

def is_prime(n):
    if n > 2 and n % 2 == 0:
        return False
    for i in range(3, int(sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

prod = 1
for i in range(2, LIMIT):
    if prod * i > LIMIT:
        print(prod)
        break
    if is_prime(i):
        prod *= i