import random

def pgcd(a, b):
    r = a%b
    if r == 0:
        return b

    return pgcd(b, r)

print("Test fonction PGCD : ", pgcd(450, 198))


def proba(n):
    cmptPremier = 0
    NOMBRE_REP = 1000000

    for i in range(0, NOMBRE_REP):
        a = random.randint(1, n)
        b = random.randint(1, n)

        if pgcd(a, b) == 1:
            cmptPremier += 1

    
    return ( (cmptPremier * 100) /  NOMBRE_REP )

print("Test fonction proba : ", proba(1000000))


