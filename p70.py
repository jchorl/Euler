from collections import defaultdict
from multiprocessing import Pool

LIMIT = 10 ** 7

def is_permutation(a, b):
    a = str(a)
    b = str(b)
    d = defaultdict(int)
    for i in a:
        d[i] += 1
    for i in b:
        d[i] -= 1
    return not any(d.values())

def calc_phi(n):
    n2 = n
    result = n
    i = 2
    while i * i <= n:
        if n % i == 0:
            while n % i == 0:
                n //= i
            result -= result // i
        i += 1
    if n > 1:
        result -= result // n
    if is_permutation(result, n2):
        return (n2, n2/result)
    return (0, 2)

p = Pool()
results = set(p.map(calc_phi, range(2, LIMIT + 1)))
p.close()

results.remove((0, 2))
mx = 2
mx_ratio = 8
for n, ratio in results:
    if ratio < mx_ratio:
        mx = n
        mx_ratio = ratio
print(mx)