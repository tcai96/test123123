#!/usr/bin/env python2

import random

NW = random.randint(1,1000)
NH = random.randint(1,1000)

HW = min(NW + random.randint(0,1000), 1000)
HH = min(NH + random.randint(0,1000), 1000)

print(str(NW) + " " + str(NH))
for i in range(NH):
    s = ""
    for i in range(NW): s += " " + str(random.randint(0,1))
    print(s[1:])
print(str(HW) + " " + str(HH))
for i in range(HH):
    s = ""
    for i in range(HW): s += " " + str(random.randint(0,1))
    print(s[1:])
