import numpy as np
import numpy.linalg as alg

A = np.array([[1, 2, 3], 
              [4, 5, 6],
              [7, 8, 9]])

B = np.array([[10], 
              [31],
              [52]])

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


def resoudreSys(A, B):
    det = alg.det(A)

    if(abs(det) > 10e-15) :
        print("Inverse possible et vaut : ")
        invA = alg.inv(A)
        X = produitMatricielle(invA, B)
    else :
        print("Inverse impossible le déterminant vaut 0 ! ")
        X = None

    return X

sol = resoudreSys(A, B)
print("La matrice X solution de l'équation est :\n", sol)