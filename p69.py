from multiprocessing import Pool

LIMIT = 1000000

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
    return (n2, n2/result)

p = Pool()
results = p.map(calc_phi, range(2, LIMIT + 1))
p.close()

mx = 2
mx_ratio = 1
for n, ratio in results:
    if ratio > mx_ratio:
        mx = n
        mx_ratio = ratio
print(mx)