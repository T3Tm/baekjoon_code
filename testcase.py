import random#L,X,.
'''
LX.X.X.X.X.X.X.X.
X.X.X.X.X.X.X.X.X
'''
with open('output.txt','w') as file:
    n=3*(10**5)
    m=1
    file.write(f'{n} {m}\n')
    file.write(f'{n} '*n)