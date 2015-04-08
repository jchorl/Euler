import itertools
import sys
import math

LIMIT = 10 ** 8
MAXLENGTH = len(str(int(math.sqrt(LIMIT))))

def sieve(n):
	primes = []
	nums = [True] * n
	for i in range(2, int(math.ceil(n / 2))):
		if nums[i]:
			for j in range(2 * i, n, i):
				nums[j] = False
	for i in range(2, n):
		if nums[i]:
			primes.append(str(i))
	return primes

PRIMELIST = sieve(LIMIT)
PRIMESET = set(PRIMELIST)
print("done generating")

def isPrime(n):
	return n in PRIMESET

def checkConcat(new, prior):
	for num in prior:
		if not (isPrime(num + new) and isPrime(new + num)):
			return False
	return True

priorCandidates = set()
for i0 in range(0, len(PRIMELIST) - 1):
	c0 = PRIMELIST[i0]
	priorCandidates = set([c0])
	for i1 in range(i0, len(PRIMELIST) - 1):
		c1 = PRIMELIST[i1]
		if len(c1) >= MAXLENGTH:
			break
		if checkConcat(c1, priorCandidates):
			priorCandidates.add(c1)
			for i2 in range(i1, len(PRIMELIST) - 1):
				c2 = PRIMELIST[i2]
				if len(c2) >= MAXLENGTH:
					break
				if checkConcat(c2, priorCandidates):
					priorCandidates.add(c2)
					for i3 in range(i2, len(PRIMELIST) - 1):
						c3 = PRIMELIST[i3]
						if len(c3) >= MAXLENGTH:
							break
						if checkConcat(c3, priorCandidates):
							priorCandidates.add(c3)
							for i4 in range(i3, len(PRIMELIST) - 1):
								c4 = PRIMELIST[i4]
								if len(c4) >= MAXLENGTH:
									break
								if checkConcat(c4, priorCandidates):
									print(int(c0) + int(c1) + int(c2) + int(c3) + int(c4))
									sys.exit()
							priorCandidates.remove(c3)
					priorCandidates.remove(c2)
			priorCandidates.remove(c1)
