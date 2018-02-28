#!/usr/bin/python3
import math, sys
A, N = map(float, input().split())
maxA = (N*N)/(4.0*math.pi)
assert(math.fabs(maxA - A) > 0.1)
sys.exit(42)
