#!/usr/bin/env python3

i=input
n=i()
k=int(i())%len(n)
print(int(n[-k:]+n[:-k]))
