b=246515
t=739105
c=0

for i in range(b,t):
    s = str(i)
    if (int("".join(sorted(s))) == i) & (len(set(sorted(s))) < len(s)):
            c = c+1
print(c)



