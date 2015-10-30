from itertools import combinations, permutations
import time

num_times_initted = 0
num_times_valued = 0
time_initting = 0
time_value_calculating = 0

class nGon:

    def __init__(self, outsides):
        global time_initting
        global num_times_initted
        num_times_initted += 1
        time_initting -= time.time()

        self.lines = []
        num_lines = len(outsides)
        for idx in range(0, num_lines):
            self.lines.append([outsides[idx], 0, 0])

        time_initting += time.time()

    def set_insides(self, insides):
        num_lines = len(insides)
        for idx in range(0, num_lines):
            self.lines[idx][1] = insides[idx]
            self.lines[idx][2] = insides[(idx + 1) % num_lines]

            if idx == 0:
                s = sum(self.lines[0])
            else:
                # check to make sure that sum is the same as the prev sum
                if sum(self.lines[idx]) != s:
                    return False
        return True

    def value(self):
        global time_value_calculating
        global num_times_valued
        time_value_calculating -= time.time()
        num_times_valued += 1

        num_lines = len(self.lines)
        value_str = ''

        for idx in range(0, num_lines):
            value_str += ''.join(str(x) for x in self.lines[idx])

        time_value_calculating += time.time()

        return int(value_str)

start = time.time()

m = 0
# combinations of inside nums are 9 choose 5, since 10 cannot be inside
for inside_nums in combinations(range(1,10), 5):
    inside_nums_set = set(inside_nums)
    outside_nums = [i for i in range(1,10) if i not in inside_nums_set] + [10]
    # we need to shuffle and rotate the insides, but only shuffle the outsides (necklaces)
    # we can pick the lowest number on the outside, and permute the rest
    lowest_on_outside = min(outside_nums)
    outside_nums.remove(lowest_on_outside)
    for other_outsides in permutations(outside_nums):
        outsides = [lowest_on_outside] + list(other_outsides)
        n = nGon(outsides)
        for insides in permutations(inside_nums):
            if n.set_insides(insides):
                val = n.value()
                if val > m:
                    m = val

end = time.time()
print('Answer: %d' % m)
print('Elapsed time: %f' % (end - start))