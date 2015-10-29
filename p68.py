from itertools import permutations

class nGon:
    def __init__(self, *args):
        self.lines = []
        self.lines.append([args[0], args[1], args[2]])
        for i in range(1, int(len(args) / 2) - 1):
            self.lines.append([args[2 * i + 1], args[2 * i], args[2 * i + 2]])
        self.lines.append([args[-1], args[-2], args[1]])
        pass

    def check_valid(self):
        s = sum(self.lines[0])
        return all(sum(i) == s for i in self.lines[1:])

    def value(self):
        num_lines = len(self.lines)
        i = 0
        m = int(''.join(str(x) for x in self.lines[0]))
        concat_values = [m]
        value_str = ''

        for idx in range(1, num_lines):
            concat_value = int(''.join(str(x) for x in self.lines[idx]))
            if concat_value < m:
                i = idx
                m = concat_value
            concat_values.append(concat_value)

        for j in range(0, num_lines):
            value_str += str(concat_values[(i + j) % num_lines])

        return int(value_str)

m = 0
invalid_10_spots = [1,2,4,6,8]
for perm in permutations(range(1, 11)):
    # all permutations starting at 7, ... will be repetitions
    if perm[0] == 7:
        break
    for i in invalid_10_spots:
        if perm[i] == 10:
            break
    else:
        n = nGon(*perm)
        if n.check_valid():
            val = n.value()
            if val > m:
                m = val

print(m)