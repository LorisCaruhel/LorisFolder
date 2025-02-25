def bin(n, en_binaire=False):
    """Convertit un nombre entier en binaire ou en décomposition de puissances de 2 selon le paramètre booléen"""
    if n == 0:
        return [0]
    
    if en_binaire:
        # Conversion en binaire (représentation avec 0 et 1)
        res = []
        while n > 0:
            res.append(n % 2)  # Ajoute le reste de la division par 2 (0 ou 1)
            n = n // 2  # Divise le nombre par 2 et garde la partie entière
        return res[::-1]  # Inverse la liste pour avoir les bits dans le bon ordre

    else:
        # Décomposition en puissances de 2
        puissances = []
        i = 0

        while 2**i <= n:
            if n >= 2**i:
                puissances.append(2**i)  # Ajoute la puissance de 2 dans la liste
                n -= 2**i  # Soustrait la puissance de 2 du nombre
            i += 1
        return puissances

def powermod(a, e, n):
    res = 0
    powBinaire = bin(e)
    resPower = 1
   
    for pow in powBinaire:
        resPower *= a**pow
    print(resPower)


    return res

print(powermod(17, 154, 100))