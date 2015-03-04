from collections import Counter
import itertools

permutations = {}

for n in itertools.count():
	l = str(n ** 3)
	s = "".join(sorted(l))
	if s in permutations:
		permutations[s].append(n ** 3)
		if len(permutations[s]) == 5:
			print(min(permutations[s]))
			exit()
	else:
		permutations[s] = [n ** 3]
