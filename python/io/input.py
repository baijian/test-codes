#!/usr/bin/env python

import os

str = raw_input("Enter you name: ")
print "Name: ", str

str = input("Enter python code: ");

os.mkdir('tmp');
os.chdir('tmp');
f = open('tmp.txt', 'wb')
f.write('hello world')
name = f.name
f.close()
os.rename(name, 'tmp2.txt')
os.remove('tmp2.txt')
pwd = os.getcwd()
os.rmdir(pwd)

