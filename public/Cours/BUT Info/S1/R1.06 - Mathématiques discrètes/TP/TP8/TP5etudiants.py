import matplotlib.pyplot as plt
import numpy as np
from random import*
import math

# nombre d'itérations :
nbpoints=10000

#point de départ :
p=np.zeros((2,1))

c = 0.255
r = 0.75
q = 0.625
theta1 = -np.pi/8
theta2 = np.pi/5

def produitMatricielle(A, B) :
    tailleA = A.shape
    tailleB = B.shape

    C = np.zeros((tailleA[0], tailleB[1]))

    if(tailleA[1] == tailleB[0]) : 
        for lA in range(tailleA[0]):
            for cB in range(tailleB[1]):
                somme = 0
                for cA in range(tailleA[1]):
                    somme = somme + (A[lA][cA] * B[cA][cB])
                    C[lA][cB] = somme
    else :
          print("Le nombre de colonne de A n'est pas égale au nombre de ligne de B")
    return C
 
def transformation1(p):
    A = np.array([[p[0,0]], 
                  [p[1,0]]])

    T1 = np.array([[0, 0], 
                   [0, 0.255]])

    U1 = np.array([[0.5], 
                   [0]])

    X = produitMatricielle(T1, A) + U1

    return X
    
     
def transformation2(p):
    A = np.array([[p[0,0]], 
                  [p[1,0]]])

    T2 = np.array([[r * np.cos(theta1), -r * np.sin(theta1)],
                [r * np.sin(theta1), r * np.cos(theta1)]])

    U2 = np.array([[0.5 - 0.5 * r * np.cos(theta1)], [c - 0.5 * r * np.sin(theta1)]])

    B = produitMatricielle(T2, A) + U2

    return B

def transformation3(p):
    A = np.array([[p[0,0]], 
                  [p[1,0]]])

    T3 = np.array([[q * np.cos(theta2), - r * np.sin(theta2)],
                [q * np.sin(theta2), r * np.cos(theta2)]])

    U3 = np.array([[0.5 - 0.5 * q * np.cos(theta2)], [0.6 * c - 0.5 * q * np.sin(theta2)]])

    C = produitMatricielle(T3, A) + U3

    return C

def transformation4(p):
    A = np.array([[p[0,0]], 
                  [p[1,0]]])

    T4 = np.array([[-0.15, 0.28], 
                   [0.26, 0.24]])

    U4 = np.array([[0], 
                   [0.44]])

    D = produitMatricielle(T4, A) + U4

    return D

def transforme(p):
    # Choix aléatoire (avec équiprobabilité) entre les 2 transformations de fonctions
    tirage=random()
    if tirage < 1/3 :
        res = transformation1(p)
    elif(tirage < 2/3) :
        res = transformation2(p)
    else :
        res = transformation3(p)
    return res

def construction(p, nbpoints):
    x = [p[0,0]]
    y = [p[1,0]]
    for i in range(nbpoints):
        p = transforme(p)
        x.append(p[0,0])
        y.append(p[1,0])
    
# Représentation graphique
    plt.plot(x, y, 'o')
    plt.title('Dragon de Heighway')
    plt.show()
    
construction(p,nbpoints)

