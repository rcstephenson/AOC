import csv

data = []
with open("input.csv", newline='') as file:
    reader = csv.reader(file, delimiter=',')
    data = reader.__next__()
k=1
data2 = []

data[1] = 12
data[2] = 2

for i in range(0,len(data)):
    if ( (data[i] == '99') and (k%4==1) ):
        k=0
        #print('\n99', end ="\n\n")
        #print("EOF")
        break  
    else:
        #print(int(data[i]), end=" ")
        if k%4==0:
            #print("")
            data2.append(data[i-3:i+1])
        k += 1

for val in data2:
    if (int(val[0]) == 1):
        data[int(val[3])] = int(data[int(val[1])]) + int(data[int(val[2])])
    elif (int(val[0]) == 2):
        data[int(val[3])] = int(data[int(val[1])]) * int(data[int(val[2])])
    else:
        print(val[0], end="<---\n")

print(data[0])