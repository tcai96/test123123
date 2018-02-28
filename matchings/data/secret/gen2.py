#!/usr/bin/env python2

import random

NW = random.randint(1,100)
NH = random.randint(1,100)

HW = min(NW + random.randint(0,100), 100)
HH = min(NH + random.randint(0,100), 100)

print(str(NW) + " " + str(NH))
for i in range(NH):
    s = ""
    for i in range(NW): s += " " + str(int(round(random.randint(0,100)/180.0)))
    print(s[1:])
print(str(HW) + " " + str(HH))
for i in range(HH):
    s = ""
    for i in range(HW): s += " " + str(int(round(random.randint(0,100)/180.0)))
    print(s[1:])
