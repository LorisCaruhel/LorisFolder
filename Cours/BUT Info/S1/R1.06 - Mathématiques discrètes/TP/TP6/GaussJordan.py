import numpy as np
import numpy.linalg as alg

M = np.array([[1, 2, 3, 4], 
              [4, 5, 6, 4],
              [7, 8, 9, 1]])

def multiplicationreel(M,i,k):
    taille = M.shape
    for j in range(taille[1]):
        M[i][j] = M[i][j]*k
    return M

def elimination(M,i,j,k):
    taille = M.shape
    for h in range(taille[1]):
        M[j][h] = M[j][h] - (M[j][h] * k)
    return M

print(elimination(M, 0, 1, 2))