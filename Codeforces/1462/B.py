t=int(input())
for _ in range(t):
	n=int(input())
	s=input()
	if s[:4]=="2020" or s[-4:]=="2020":
		print("YES")
		continue
	if s[:1]=="2" and s[-3:]=="020":
		print("YES")
		continue
	if s[:2]=="20" and s[-2:]=="20":
		print("YES")
		continue
	if s[:3]=="202" and s[-1:]=="0":
		print("YES")
		continue
	print("NO")