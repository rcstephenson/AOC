import csv

data = []
with open("input.csv", newline='') as file:
    reader = csv.reader(file)
    for row in reader:
        data.append(row[0])
sumv = 0
f = lambda x : x//3 -2
for val in data:
    s0 = f(int(val))
    sumv += s0
    while f(int(s0)) > 0:
        s0 = f(int(s0))
        sumv += s0

print(sumv)