import csv

data = []
data_i = []
with open("input.csv", newline='') as file:
    reader = csv.reader(file, delimiter=',')
    data_i = reader.__next__()

for b in range(100):  
    for c in range(b+1):
        data = data_i.copy()
        data[1] = b
        data[2] = c

        k=1
        data2 = []
        for i in range(0,len(data)):
            if ( (data[i] == '99') and (k%4==1) ):
                k=0
                break  
            else:
                if k%4==0:
                    data2.append(data[i-3:i+1])
                k += 1
        for val in data2:
            if (int(val[0]) == 1):
                data[int(val[3])] = int(data[int(val[1])]) + int(data[int(val[2])])
            elif (int(val[0]) == 2):
                data[int(val[3])] = int(data[int(val[1])]) * int(data[int(val[2])])
            else:
                break
        if (int(data[0]) == 19690720):
            print(f"ANS: {b} {c}")
print("EOF")
print(data[0])