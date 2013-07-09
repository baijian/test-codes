# -*- coding:utf-8 -*-
#!/usr/bin/env python

def cosVector(x, y):
    if(len(x) != len(y)):
        print "error input!"
        return
    res1 = 0.0
    res2 = 0.0
    res3 = 0.0
    for i in range( len(x) ):
        res1 += x[i] * y[i]
        res2 += x[i] ** 2
        res3 += y[i] ** 2
    r = (res2 * res3) ** 0.5
    print ("result is " + str(res1/r) )

if  __name__ == '__main__':
    cosVector([1,1],[1,1])
