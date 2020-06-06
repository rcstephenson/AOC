import csv

data = []
with open("input.csv", newline='') as file:
    reader = csv.reader(file, delimiter='\n')
    for row in reader:
        data.append(row[0])
sumv = 0
for val in data: 
    sumv += int(val)//3 - 2
print(sumv)