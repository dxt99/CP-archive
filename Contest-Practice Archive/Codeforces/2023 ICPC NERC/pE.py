class Point:
    def __init__(self, x, y):
        self.horizontal = x
        self.vertical = y
        self.rdiag = x - y
        self.ldiag = x + y
    
    def __str__(self):
        return f"{self.horizontal} {self.vertical}"

    def intersect_self(self, p):
        return self.horizontal == p.horizontal or self.vertical == p.vertical or self.rdiag == p.rdiag or self.ldiag == p.ldiag

t = int(input())

for _ in range(t):
    n = int(input())
    arr = []
    for _ in range(n):
        xy = input().split()
        x = int(xy[0])
        y = int(xy[1])
        arr.append(Point(x, y))
    if n == 1:
        print("YES")
        print(arr[0])
        continue
    pivot: Point = arr[0]
    arr = arr[1:]
    
    # Checking horizontal
    allHori = True
    possible = []
    for pt in arr:
        assert(type(pt) is Point)
        if pivot.horizontal == pt.horizontal:
            continue
        if allHori:
            v = pt.vertical
            rdiag = pt.rdiag
            ldiag = pt.ldiag
            possible.append(Point(pivot.horizontal, v))
            possible.append(Point(pivot.horizontal, pivot.horizontal - rdiag))
            possible.append(Point(pivot.horizontal, ldiag - pivot.horizontal))
        allHori = False
        possible = [c for c in possible if c.intersect_self(pt)]
        
    
    if allHori or len(possible) > 0:
        print("YES")
        if allHori:
            print(pivot)
        else:
            print(possible[0])
        continue
    
    # Checking vertical
    allVert = True
    possible = []
    for pt in arr:
        assert(type(pt) is Point)
        if pivot.vertical == pt.vertical:
            continue
        if allVert:
            h = pt.horizontal
            rdiag = pt.rdiag
            ldiag = pt.ldiag
            possible.append(Point(h, pivot.vertical))
            possible.append(Point(rdiag + pivot.vertical, pivot.vertical))
            possible.append(Point(ldiag - pivot.vertical, pivot.vertical))
        allVert = False
        possible = [c for c in possible if c.intersect_self(pt)]
        
    
    if allVert or len(possible) > 0:
        print("YES")
        if allVert:
            print(pivot)
        else:
            print(possible[0])
        continue
    
    # Checking rdiag
    allRdiag = True
    possible = []
    for pt in arr:
        assert(type(pt) is Point)
        if pivot.rdiag == pt.rdiag:
            continue
        if allRdiag:
            h = pt.horizontal
            v = pt.vertical
            ldiag = pt.ldiag
            possible.append(Point(h, h - pivot.rdiag)) # Same horizontal
            possible.append(Point(pivot.rdiag + v, v)) # Same vertical
            if (pivot.rdiag + ldiag) % 2 == 0:
                possible.append(Point((pivot.rdiag + ldiag) // 2, (ldiag - pivot.rdiag) // 2))
        allRdiag = False
        possible = [c for c in possible if c.intersect_self(pt)]
        
    
    if allRdiag or len(possible) > 0:
        print("YES")
        if allRdiag:
            print(pivot)
        else:
            print(possible[0])
        continue
    
    # Checking ldiag
    allLdiag = True
    possible = []
    for pt in arr:
        assert(type(pt) is Point)
        if pivot.ldiag == pt.ldiag:
            continue
        if allLdiag:
            h = pt.horizontal
            v = pt.vertical
            rdiag = pt.rdiag
            possible.append(Point(h, pivot.ldiag - h)) # Same horizontal
            possible.append(Point(pivot.ldiag - v, v)) # Same vertical
            if (pivot.ldiag + rdiag) % 2 == 0:
                possible.append(Point((pivot.ldiag + rdiag) // 2, (pivot.ldiag - rdiag) // 2))
        allLdiag = False
        possible = [c for c in possible if c.intersect_self(pt)]
        
    
    if allLdiag or len(possible) > 0:
        print("YES")
        if allLdiag:
            print(pivot)
        else:
            print(possible[0])
        continue
    
    # Nope
    print("NO")