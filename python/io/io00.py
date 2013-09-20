#!/usr/bin/env python
import sys
import io
import os
import itertools

f = open(sys.argv[1], 'rb', 32768)
fd = f.fileno()
for i in itertools.count():
    record = os.read(fd, 16)
    if not record:
        break

print i

