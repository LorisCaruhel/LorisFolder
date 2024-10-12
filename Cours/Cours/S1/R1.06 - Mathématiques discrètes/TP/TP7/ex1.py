import numpy as np

A = np.array([[1, 2, 3], 
              [4, 5, 6],
              [7, 8, 9]])

def mineur(X, l, c):
    X = np.delete(X, l, axis=0)
    X = np.delete(X, c, axis=1)
    return X

def det2(A):
    det = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0])
    return det

def colonne(A):
    tailleA = A.shape
    for i in range(1, tailleA[0]):
        elimination(A, 0, i, A[i][0] / A[0][0])

    return A

def elimination(M, i, j, k):
    taille = M.shape
    for h in range(taille[1]):
        M[j][h] = M[j][h] - (M[i][h] * k)

def determinant(M):
    xM = M.shape
    if xM[0] == 2 and xM[1] == 2:
        det = det2(M)
    else:
        B = colonne(M)
        B = mineur(B, 0, 0)
        det = M[0][0] * determinant(B)

    return det

print(A)
elimination(A, 0, 1, 1)
print(A)
print(colonne(A))
print(determinant(A))
 