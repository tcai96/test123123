#!/usr/bin/python3
import math
A, N = map(float, input().split())
maxA = (N*N)/(4.0*math.pi)
print("Diablo is happy!" if maxA >= A else "Need more materials!")
