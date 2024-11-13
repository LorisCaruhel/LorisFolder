from cesar import *

def creation_alphabet(clef):
    res = list(clef)
    nombre_lettre = frequence(clef)

    if(nombre_lettre[0][1] == 1):
        for j in range(97, 123):
            if chr(j) not in list(clef):
                res.append(chr(j))
    else:
        print("Mot impossible, il doit contenir qu'un seul fois une lettre.")
    return res

def chiffrement(texte, clef):
    alphabet_clef = creation_alphabet(clef)
    res = ""

    for i in texte:
        index_lettre = (ord(i) + 26) - 122
        res += alphabet_clef[index_lettre]
    return res

print(chiffrement('carte', 'cpbx'))