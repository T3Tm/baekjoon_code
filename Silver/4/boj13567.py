import sys
input = sys.stdin.readline

class Map:
    boundary = 0
    dir = 1
    
    def __init__(self, x):
        self.x = 0
        self.y = 0
        
        self.boundary = x
    
    def isBoundary(self):
        if self.x < -self.boundary or self.x > 0:return True
        if self.y > self.boundary or self.y < 0:return True
        return False

    def Turnning(self, dir):
        self.dir = (self.dir + 1 + (- 2 * (dir == 0))  + 4) % 4
        
    def Moving(self, d):
        self.x = self.x +  (1 - 2 * (self.dir % 3 == 0)) * (self.dir % 2 == 0) * d
        self.y = self.y +  (1 - 2 * (self.dir % 3 == 0)) * (self.dir % 2) * d
        
    def __str__(self):
        return f'{self.y} {-self.x}'
    
m,n=map(int,input().split())

my = Map(m)

for _ in range(n):
    command, d = input().split()
    d = int(d)
    if command[0] == 'M':
        my.Moving(d)
        if my.isBoundary():
            print(-1)
            exit(0)
    else:
        my.Turnning(d)

print(my)