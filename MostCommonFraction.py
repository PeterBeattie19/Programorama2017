import collections
from fractions import Fraction
from decimal import Decimal

p = []
for i in range(int(input())):
  a,b = map(int, input().split("/"))
  p.append(Fraction(a,b))

k = collections.Counter(p).most_common(1)[0]
s1 = k[0].denominator

print('%s/%s' % (k[0],s1) if not str(k[0]).count('/') == 1 else k[0])