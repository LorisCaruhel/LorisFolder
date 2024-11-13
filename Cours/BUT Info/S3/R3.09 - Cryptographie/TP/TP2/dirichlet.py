import random

# Dirichlet
def dirichlet(N) :
    res = []
    while(len(res) != N) :
        k = random.randrange(15000)
        nb = (6 * k + 1)
        if nb < 100000 :
            res.append(nb)
    return res

print("\nDirichlet : ")
print(dirichlet(10))


# Dirichlet 2
def dirichlet2(p, N) :
    res = []
    while(len(res) != N) :
        k = random.randrange(15000) 
        nb = (30 * k + p)
        if nb < 100000 :
            res.append(nb)
    return res

print("\nDirichlet2 : ")
print(dirichlet2(10, 10))


# Euler
def euler(N) :
    res = []
    while(len(res) != N) :
        n = random.randrange(15000)
        nb = (pow(n, 2) + n + 41)
        if(nb < 100000) :
            res.append(nb)
    return res

print("\nEuler : ")
print(euler(10))


# Legendre
def legendre(N) :
    res = []
    while(len(res) != N) :
        n = random.randrange(15000)
        nb = (2 * pow(n, 2) + 29)
        if nb < 100000 :
            res.append(nb)
    return res

print("\nLegendre : ")
print(legendre(10))


# Ruby
def ruby(N) :
    res = []
    while(len(res) != N) :
        n = random.randrange(15000)
        nb = (103 * pow(n, 2) - 3945 * n + 34381)
        if (nb > 0 and nb < 100000) :
            res.append(nb)
    return res

print("\nRuby : ")
print(ruby(10))


# Fermat
def fermat(p) :
    a = [2, 3, 5, 7]
    isPremier = False
    for i in a : 
        if ( (pow(i, p-1, p) == 1) ) :
            isPremier = True
        else :
            return False
    return isPremier

print("\nFermat :")
listeNombresDirichlet = dirichlet(100)
listeNombresDirichlet2 = dirichlet2(13, 100)
listeNombresEuler = euler(100)
listeNombresLegendre = legendre(100)
listeNombresRuby = ruby(100)

listesNombres = {
    "Dirichlet": listeNombresDirichlet,
    "Dirichlet2": listeNombresDirichlet2,
    "Euler": listeNombresEuler,
    "Legendre": listeNombresLegendre,
    "Ruby": listeNombresRuby
}

for technique, liste in listesNombres.items():
    pseudoPremier = []
    for i in liste:
        if fermat(i) :
            pseudoPremier.append(i)
            # print(i, ":", fermat(i))
    pourcentagePremier = len(pseudoPremier) * 100 / len(liste)
    print(f"{technique} :", pourcentagePremier, "%")


def rabinMiller(n) :
    a = random.randrange(1, n - 1)
    s = 0
    d = n - 1
    while d % 2 == 0 :
        s += 1
        d /= 2

    if ( (pow(a, d, n) == 1) or (pow(a, d, n) == -1) ) :
        return None
    
    for i in range(1, s) :
        x = pow(a, (d * 2 * i), n)

        if(x == -1 or x == 1 or x != 1) :
            return None
        