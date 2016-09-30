import random
import math
 
def gen_rand_sqrt(lo, hi):
    # generates a random number from lo to hi, inclusive
    return int((random.random()*math.sqrt(hi-lo+1))**2)+lo
 
n = gen_rand_sqrt(2,100000)
m = gen_rand_sqrt(2*n,10*n)
 
print "%d %d" % (n, m)
for i in range(m):
    a,b = random.sample(xrange(n), 2)
    print "%d %d" % (a+1, b+1)
