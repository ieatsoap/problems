alph = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
at = 0
counter = 0
word = input("gimme a word: ")
for i in word:
    if (abs(alph.index(i) - at) < 13):
        counter += abs(alph.index(i)-at)
        at = alph.index(i)
    else:
        counter += 26 - abs(alph.index(i)-at)
        at = alph.index(i)
print(counter)