from fractions import Fraction

from linear_space import *

a = lin_space([2, 5], [4, 10], n=2)
b = lin_space([3, 1], [1, 0], n=2)
g = [[0, 2, 3, 5], [0, 4, 6, 5], [6, 7, 8, 7], [2, 3, 4, 6], [4, 6, 5, 6]]
# g = list(map(lambda lst: list(map(lambda x: Fraction(x), lst)), g))
m = lin_space(g, n=4)
print(m.vec)
print(m.gauss())
print(m.basis())
print(a.basis())
print(lin_space(b.vec[0], n=2))
print(a >= b)
print(a)
