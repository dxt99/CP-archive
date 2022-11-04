# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

# numpy and scipy are available for use
import numpy
import scipy
lowercase = [chr(x + ord('a')) for x in range(26)]
uppercase = [chr(x + ord('A')) for x in range(26)]
cipher = str(input())

d = 14
plain = ""
for c in cipher:
    if not c in lowercase and not c in uppercase:
        plain += c
        continue
    if c in lowercase:
        i = lowercase.index(c)
        i = (i+d) % 26
        plain += lowercase[i]
    else:
        i = uppercase.index(c)
        i = (i+d) % 26
        plain += uppercase[i]
    
print(plain)