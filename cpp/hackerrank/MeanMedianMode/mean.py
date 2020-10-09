import sys

entries = int(sys.stdin.readline())

values = sys.stdin.readline().split()
values = [int(x) for x in values]
values.sort()

mean = sum(values) / float(entries)

print(mean)
