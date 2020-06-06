import csv
import matplotlib.pyplot as plt

data = []
sample1 = [['R75','D30','R83','U83','L12','D49','R71','U7','L72'],
            ['U62','R66','U55','R34','D71','R55','D58','R83']]
sample2 = [['R98','U47','R26','D63','R33','U87','L62','D20','R33','U53','R51'],
            ['U98','R91','D20','R16','D67','R40','U7','R15','U6','R7']]
sol = [159,135]
with open("input.csv", newline='') as file:
    reader = csv.reader(file, delimiter=',')
    for val in reader:
        data.append(val)
#print(data[0])
sign = {'R': 1, 'L': -1, 'U': 1, 'D': -1}

def draw(dat):
    xdist = [0]
    ydist = [0]
    for vector in dat:
        ang = vector[0]
        mag = int(vector[1:])
        for i in range(mag):
            if ((ang == 'R') | (ang == 'L')):
                    xdist.append(sign.get(ang)+xdist[-1])
                    ydist.append(ydist[-1])
            elif ((ang == 'U') | (ang == 'D')):
                    ydist.append(sign.get(ang)+ydist[-1])
                    xdist.append(xdist[-1])
            else:
                print("Error")
                return 0
    return [xdist,ydist]

x1,y1 = draw(data[0])
x2,y2 = draw(data[1])       
#plt.plot(x1,y1)
#plt.plot(x2,y2)
#plt.show()

points = set()
a = set()
b = set()
for i in range(len(x1)):
    a.add((x1[i],y1[i]))
for j in range(len(x2)):
    b.add((x2[j],y2[j]))

c = a.intersection(b)
d=1e10
for v in c:
    print(v)
    chk = abs(v[0]) + abs(v[1])
    if (d > chk > 0):
        d = chk
print(d)