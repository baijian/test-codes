# -*- coding:utf-8 -*-
#!/usr/bin/env python
import re

def verifyPass(password):
    mutex = 0
    if re.search('\d+', password):
        mutex += 1
    if re.search('[a-zA-Z]+', password):
        mutex += 1
    if re.search('[^a-zA-Z0-9]+', password):
        mutex += 1
    if mutex == 3 :
        print 'suc'
    else:
        print mutex
        print 'fail'

if  __name__ == '__main__':
    verifyPass('abc12@#3');
