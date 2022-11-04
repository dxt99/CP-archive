arr = [[" ","o", ""], ["/", "|" ,"\\"], ["/", " ", "\\"]]
turnF = False
def print_dancer(arr):
    Flag = turnF
    if Flag:
        if arr[0][0] == "(":
            if arr[0][2] == "":
                arr[0][0] = " "
                arr[0][2] = ")"
        
        elif arr[0][0] == " ":
            if arr[0][2] == ")":
                arr[0][0] = "("
                arr[0][2] = ""
        
        if arr[1][0] == "/":
            if arr[1][2] == ">":
                arr[1][0] = "<"
                arr[1][2] = "\\"
            if arr[1][2] == "":
                arr[1][0] = " "
                arr[1][2] = "\\"
            
        elif arr[1][0] == "<":
            if arr[1][2] == "\\":
                arr[1][0] = "/"
                arr[1][2] = ">"
            if arr[1][2] == "":
                arr[1][0] = " "
                arr[1][2] = ">"

        elif arr[1][0] == " ":
            if arr[1][2] == "\\":
                arr[1][2] = ""
                arr[1][0] = "/"
            if arr[1][2] == ">":
                arr[1][0] = "<"
                arr[1][2] = ""


        if arr[2][0] == "/":
            if arr[2][2] == ">":
                arr[2][0] = "<"
                arr[2][2] = "\\"
            if arr[2][2] == "":
                arr[2][0] = " "
                arr[2][2] = "\\"
            

        elif arr[2][0] == "<":
            if arr[2][2] == "\\":
                arr[2][0] = "/"
                arr[2][2] = ">"
            if arr[2][2] == "":
                arr[2][0] = " "
                arr[2][2] = ">"


        elif arr[2][0] == " ":
            if arr[2][2] == "\\":
                arr[2][2] = ""
                arr[2][0] = "/"
            if arr[2][2] == ">":
                arr[2][0] = "<"
                arr[2][2] = ""
    ret = ""
    for i in arr:
        for j in i:
            ret+=j
        ret+="\n"
    if Flag:
        if arr[0][0] == "(":
            if arr[0][2] == "":
                arr[0][0] = " "
                arr[0][2] = ")"
        
        elif arr[0][0] == " ":
            if arr[0][2] == ")":
                arr[0][0] = "("
                arr[0][2] = ""
        
        if arr[1][0] == "/":
            if arr[1][2] == ">":
                arr[1][0] = "<"
                arr[1][2] = "\\"
            if arr[1][2] == "":
                arr[1][0] = " "
                arr[1][2] = "\\"
            
        elif arr[1][0] == "<":
            if arr[1][2] == "\\":
                arr[1][0] = "/"
                arr[1][2] = ">"
            if arr[1][2] == "":
                arr[1][0] = " "
                arr[1][2] = ">"

        elif arr[1][0] == " ":
            if arr[1][2] == "\\":
                arr[1][2] = ""
                arr[1][0] = "/"
            if arr[1][2] == ">":
                arr[1][0] = "<"
                arr[1][2] = ""


        if arr[2][0] == "/":
            if arr[2][2] == ">":
                arr[2][0] = "<"
                arr[2][2] = "\\"
            if arr[2][2] == "":
                arr[2][0] = " "
                arr[2][2] = "\\"
            

        elif arr[2][0] == "<":
            if arr[2][2] == "\\":
                arr[2][0] = "/"
                arr[2][2] = ">"
            if arr[2][2] == "":
                arr[2][0] = " "
                arr[2][2] = ">"


        elif arr[2][0] == " ":
            if arr[2][2] == "\\":
                arr[2][2] = ""
                arr[2][0] = "/"
            if arr[2][2] == ">":
                arr[2][0] = "<"
                arr[2][2] = ""
    return ret[:-1]

def dancer(txt):
    global arr
    global turnF
    if txt[0:3] == "say":
        print(txt[4:len(txt)])
        return

    if ("left hand to head") in txt:
        arr[0][2] = ")"
        arr[1][2] = ""
        print(print_dancer(arr))

    if ("left hand to hip") in txt:
        arr[0][2] = ""
        arr[1][2] = ">"
        print(print_dancer(arr))

    if ("left hand to start") in txt:
        arr[0][2] = ""
        arr[1][2] = "\\"
        print(print_dancer(arr))

    if ("left leg in") in txt:
        arr[2][2] = ">"
        print(print_dancer(arr))

    if ("left leg out") in txt:
        arr[2][2] = "\\"
        print(print_dancer(arr))

    if ("right hand to head") in txt:
        arr[0][0] = "("
        arr[1][0] = " "
        print(print_dancer(arr))

    if ("right hand to hip") in txt:
        arr[0][0] = " "
        arr[1][0] = "<"
        print(print_dancer(arr))

    if ("right hand to start") in txt:
        arr[0][0] = " "
        arr[1][0] = "/"
        print(print_dancer(arr))

    if ("right leg in") in txt:
        arr[2][0] = "<"
        print(print_dancer(arr))

    if ("right leg out") in txt:
        arr[2][0] = "/"
        print(print_dancer(arr))

    if ("turn") in txt:
        if turnF:
            turnF = False
        else:
            turnF = True
        print(print_dancer(arr))


k = int(input())
n = int(input())
for i in range(k):
    arr = [[" ","o", ""], ["/", "|" ,"\\"], ["/", " ", "\\"]]
    turnF = False
    for _ in range(n):
        dancer(str(input()))