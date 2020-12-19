from math import *
import sys
if "FILEIO" in sys.argv:
	sys.stdin=open("in","r")
	sys.stdout=open("out","w")
n=int(input())
print(1+(3*n*(n+4)+2-(-1)**n*(n*(n+4)+2))//8)