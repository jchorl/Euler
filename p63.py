import itertools

count = 0
for n in itertools.count(1):
	if len(str(9 ** n)) < n:
		break
	for i in itertools.count(1):
		if i == 10:
			break
		length = len(str(i ** n))
		if length > n:
			break
		if length == n:
			count += 1
print(count)
