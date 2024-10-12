import numpy as np
import numpy.linalg as alg


A = np.array([[2, -1, -1, -2],
              [4, 4, 2, 0],
              [0, 4, -2, 0],
              [-1, -1, 0, -3]])


B = np.array([[-2, 2, 1, -3],
              [1, -3, 0, -2],
              [2, -1, -2, 3],
              [-4, 3, 3, 3]])

C = np.array([[0, -4, 3, 1],
              [4, 2, -4, 1],
              [1, -1, 3, 3],
              [4, 1, 4, -4]])

D = np.array([[-8, -6, 26, 0],
              [4, -8, 0, -11],
              [10, -5, 26, -6],
              [-12, -23, 0, 38]])


tailleC = C.shape
tailleD = D.shape

print(tailleC, tailleD)

J = C + D

def produitMatricielle(A, B) :
    tailleA = A.shape
    tailleB = B.shape

    W = np.zeros((tailleA[0], tailleB[1]))

    if(tailleA[0] == tailleB[1]) : 
        for lA in range(tailleA[0]):
            for cB in range(tailleB[1]):
                somme = 0
                for cA in range(tailleA[1]):
                    somme = somme + (A[lA][cA] * B[cA][cB])
                    W[lA][cB] = somme
    else :
          print("Le nombre de colonne de A n'est pas égale au nombre de ligne de B")
    return W

T = produitMatricielle ( J, J )
Z = ( produitMatricielle ( C, C ) ) + ( 2 * ( produitMatricielle ( C, D ) ) ) + ( produitMatricielle ( D, D ) )

print("(C + D)² =")
print(T)
print("C^2 + 2CD + D^2 =")
print(Z)