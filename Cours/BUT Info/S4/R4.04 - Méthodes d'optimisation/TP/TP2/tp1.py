import numpy as np
import numpy.random as rd
import random

Lieux1=['Paris','Lyon','Nice','Nantes','Strasbourg','Montpellier','Lille',
        'Rennes','Reims','Saint-Étienne','Angers','Grenoble','Nîmes',
        'Aix-en-Provence','Brest']

Carte1=np.array([[  0 ,462,931,380,488,746,219,348,143,522,293,575,710,759,589],
        [462,  0 ,472,681,494,302,689,718,487, 62,594,107,251,299,970],
        [930,471, 0,1143,790,326,1157,1186,955,490,1062,465,279,176,1440],
        [380,682,1145,  0 ,860,824,597,107,515,662,  88,786,874,972,296],
        [487,491,788,860,  0  ,791,549,827,347,550,773,533,739,787,1069],
        [746,303,327,823,791,  0  ,963,895,787,322,771,297,56,154,1120],
        [217,690,1159,598,522,963,  0 ,572,199,749,511,803,938,986,759],
        [347,718,1186,106,827,894,572,  0 ,483,699,126,823,948,1013,241],
        [143,487,955,516,347,786,198,483,  0  ,546,429,600,735,783,725],
        [523, 64,491,661,552,322,750,698,548,  0  ,574,155,271,319,950],
        [293,595,1062,88,773,770,511,128,429,576,  0  ,700,824,890,377],
        [574,106,466,786,534,296,801,823,599,155,699,  0  ,245,293,1075],
        [711,252,281,872,740, 55,938,949,736,271,825,246,  0  ,108,1169],
        [757,298,178,970,786,153,984,1013,781,317,889,291,106,  0 ,1267],
        [590,971,1441,298,1070,1121,760,241,725,952,378,1076,1171,1269,0]])

Carte0 = np.array([[0, 210, 95, 180],
                   [210, 0, 126, 53],
                   [95, 126, 0, 113],
                   [180, 53, 113, 0]])

def TrajetAlea(n):
    rep = list(range(1, len(Lieux1)))
    np.random.shuffle(rep)
    return rep

trajetAlea = TrajetAlea(15)
print("Trajet Alea :", trajetAlea)

def PopAlea(n, p):
    return [TrajetAlea(n) for i in range(p)]

popAlea = PopAlea(15, 10)
print("Pop Alea :")
for i in popAlea:
    print(i)

def LTrajet(t, Carte):
    long = Carte[0][t[0]]
    for i in range(len(t)-1):
        long += Carte[t[i]][t[i+1]]
    long += Carte[0][t[-1]]
    return long

# Trajet Rennes, Saint Brieuc, Brest, Quimper, Rennes
longTrajet = LTrajet([2, 1, 3], Carte0)
print("LTrajet :", longTrajet)

def LPop(P, Carte):
    long = []
    for i in P:
        long.append(LTrajet(i, Carte))
    return long

longTrajets = LPop([[2, 1, 3], [1, 3, 2]], Carte0)
print("LPop :")
for i in longTrajets:
    print(i)

trajetTestCarte0 = LPop([[2, 1, 3], [1, 3, 2]], Carte0)
trajetTestCarte1 = LPop(popAlea, Carte1)
print("Test avec carte0 :")
for i in trajetTestCarte0:
    print(i)

print("Test avec carte1 :")
for i in trajetTestCarte1:
    print(i)

def Selection(P, Carte):
    P1 = []
    longTrajets = LPop(P, Carte)
    longTrajets.sort()

    for i in P:
        if LTrajet(i, Carte) in longTrajets:
            P1.append(i)

    return P1

print("Sélection : ")
selection1 = Selection(popAlea, Carte1)
print(selection1)

def Croisement(P1, P2):
    i = random.randint(1, len(P1))
    enf = P1[:i]
    for i in P2:
        if (i not in enf) and (len(enf) <= len(P1)):
            enf.append(i)

    return enf

print("Croisement :")
croisement = Croisement(TrajetAlea(15), TrajetAlea(15))
print(croisement)

def PopCroisement(P):
    # Faire un tableau avec des pairs
    pairs = [(P[i], P[i + 1]) for i in range(0, len(P), 2)]
    enfs = []
    for i in pairs:
        enfs.append(Croisement(i[0], i[1]))
        enfs.append(Croisement(i[1], i[0]))
    return enfs

print("PopCroisement :")
popCroisement = PopCroisement(popAlea)
for i in popCroisement:
    print(i)