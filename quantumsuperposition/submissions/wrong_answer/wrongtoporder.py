#!/usr/bin/python3
v1, v2, e1, e2 = map(int,input().split())

edges1={i:set() for i in range(1,v1+1)}
for i in range(e1):
    u1, u2 = map(int,input().split())
    edges1[u1].add(u2)

edges2={i:set() for i in range(1,v2+1)}
for i in range(e2):
    u1, u2 = map(int,input().split())
    edges2[u1].add(u2)

results1 = set()
steps1 = {i:set() for i in range(1,v1+1)}
steps1[1].add(0);
for v in range(1,v1+1):
    for u in edges1[v]:
        for s in steps1[v]:
            steps1[u].add(s+1)
results1 = steps1[v1]

results2 = set()
steps2 = {i:set() for i in range(1,v1+1)}
steps2[1].add(0);
for v in range(1,v2+1):
    for u in edges2[v]:
        for s in steps2[v]:
            steps2[u].add(s+1)
results2 = steps2[v2]

q = int(input())
for i in range(q):
    s = int(input())
    result = "No"
    for r in results1:
        if s-r in results2:
            result = "Yes"
            break
    print(result)
