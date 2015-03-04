from collections import Counter
import itertools

permutations = {}

def finished():
	for i in permutations:
		if len(permutations[i]) == 5:
			print(min(permutations[i]))
			return True
	return False

for n in itertools.count():
	l = list(str(n ** 3))
	s = "".join(sorted(l))
	if s in permutations:
		permutations[s].append(n ** 3)
	else:
		permutations[s] = [n ** 3]
	if finished():
		exit()
