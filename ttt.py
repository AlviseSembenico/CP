s = "This hotel has a nice view of the citycenter. The location is perfect."

for word in s.split(" "):
    word = word.lower()
    word = word.strip(",.")
    print(word)
