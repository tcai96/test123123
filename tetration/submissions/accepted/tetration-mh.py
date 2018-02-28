import sys
n=float(input())
if n==0:
	print("%.6f"%0.0)
else:
	print("%.6f"%(n**(1/n)))
