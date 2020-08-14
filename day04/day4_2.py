b=246515
t=739105
c=0

for i in range(b,t):
    s = str(i)
    if (int("".join(sorted(s))) == i) & (len(set(sorted(s))) < len(s)):
            match=False
            for l in s:
                if (s.count(l) == 2):
                    match=True 
                    break     
            if match:
                c = c+1
print(c)



