import random

n = 500;

nbrs = []

intmin = -2147483648
intmax = 2147483647

while len(nbrs) < n:
	nbrs.append(random.randint(intmin, intmax))
	nbrs = list(set(nbrs))

for i in range(n):
	print(nbrs[i], end=' ')
