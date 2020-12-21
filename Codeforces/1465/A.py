from math import *
import sys
if "FILEIO" in sys.argv:
	sys.stdin=open("in","r")
	sys.stdout=open("out","w")
T=int(input())
for t in range(T):
	n=int(input())
	s=input()
	flag=False
	for i in s[(n-1)//2:]:
		if i!=')':
			flag=True
			break
	if flag:
		print("No")
	else:
		print("Yes")