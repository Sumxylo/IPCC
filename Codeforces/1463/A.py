from math import *
import sys
if "FILEIO" in sys.argv:
	sys.stdin=open("in","r")
	sys.stdout=open("out","w")
t=int(input())
for _ in range(t):
	a,b,c=map(int,input().split())
	if (a+b+c)%9==0:
		if min(a,b,c)>=(a+b+c)//9:
			print("YES")
			continue
	print("NO")