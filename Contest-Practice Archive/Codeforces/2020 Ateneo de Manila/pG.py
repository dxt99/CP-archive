l1 = input().strip().split(" ")
l2 = input().strip().split(" ")

w = int(l1[0])
l = int(l1[1])
x = int(l2[0])
y = int(l2[1])

sp = w * l
ul = (x * y)
ur = x * (l - y + 1)
bl = (w - x + 1) * y
br = (w - x + 1) * (l - y + 1)
fan = min(ul, ur, bl, br)
if fan * 2 >= sp:
    print("I don't wanna do this anymore!")
else:
    print(fan)