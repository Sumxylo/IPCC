t=int(input())
for t_ in range(t):
	n,k=map(int,input().split())
	print(n**k%1000000007)