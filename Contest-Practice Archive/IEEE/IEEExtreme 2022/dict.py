f = open("words.txt", "r+")
rows = f.readlines()
fs = {}
lowercase = [chr(x + ord('a')) for x in range(26)]
for c in lowercase:
    fs[c]=0
for word in rows:
    fs[word[0]]+=1
print(fs)