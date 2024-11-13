#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import numpy.linalg as alg

#####################################################
##########  Somme et produit par un scalaire ########


#############  Exemple 1 ###########################
#A = np.array([[5, -1, 0],
#              [-2, 2, 3]])

#B = np.array([[0, 7, -1],
#              [2, 1, 4]])

#1. A+B = [[ 5  6 -1]
# 		  [ 0  3  7]]

#2. 2 * A = [[10 -2  0]
#         [-4  4  6]]

#3. 3 * B = [[ 0 21 -3]
#         [ 6  3 12]]

#4. 2 * A - 3 * B = [[ 10 -23   3]
#              [-10   1  -6]]

#############  Exemple 2 ########################### 

#2. [[4, 2, 1]]x[[8],[3],[-2]] = [[32 16  8]
# 							      [12  6  3]
# 							      [-8 -4 -2]]

#############  Exercice 2 ###########################

def produitScalaire(A, B) :
    tailleA = A.shape
    tailleB = B.shape
    C = 0
    if(tailleA[0] == tailleB[1]) : 
        for i in range(tailleA[0]):
             for j in range(tailleB[1]):
                  C = C + (A[0][i] * B[j][0])
    else :
          print("Le nombre de colonne de A n'est pas égale au nombre de ligne de B")
    return C


#############  Exercice 4 ###########################

def produitMatricielle(A, B) :
    tailleA = A.shape
    tailleB = B.shape

    C = np.zeros((tailleA[0], tailleB[1]))

    if(tailleA[0] == tailleB[1]) : 
        for lA in range(tailleA[0]):
            for cB in range(tailleB[1]):
                somme = 0
                for cA in range(tailleA[1]):
                    somme = somme + (A[lA][cA] * B[cA][cB])
                    C[lA][cB] = somme
    else :
          print("Le nombre de colonne de A n'est pas égale au nombre de ligne de B")
    return C

#############  Exercice 5 ###########################
#A=np.arrray([[2, -1, -1,-2],[4, 4, 2, 0],[0, 4, 2, 0],[-1, -1, 0, -3]])
#B=np.arrray([[-2, 2, 1,3],[1, -3, 0, -2],[2, -1, -2, 3],[-4, 3, 3, 3]])
#C=np.arrray([[0, -4, 3,1],[4, 2, -4, 1],[1, -1, 3, 3],[4, 1, 4, -4]])
#D=np.arrray([[-8, -6, 26,0],[4, -8, 0, -11],[10, -5, 26, -6],[-12, -23, 0, 38]])

#1) (A + B)^2 = [[ 30.  -9. -13.  -2.]
# 				 [ 19.   8. -12. -21.]
# 				 [ -8.  -1.  31. -28.]
#				 [ 16.   6.  -8.  30.]]
#2) A^2 + 2AB + B^2 = [[ 24. -24. -19. -28.]
# 					   [ 27.  13.  -5. -39.]
# 					   [ -5.   6.  35. -29.]
# 					   [ 28. -27. -22.  27.]]

#3) (C + D)² =
#                [[ 295.  -56.  653.   39.]
#                [ -76.  200.  100. -260.]
#                [ 207. -182. 1172. -118.]
#                [-340. -560.  108. 1356.]]

#4) C^2 + 2CD + D^2 = 
#                [[ 295.  -56.  653.   39.]
#                [ -76.  200.  100. -260.]
#                [ 207. -182. 1172. -118.]
#                [-340. -560.  108. 1356.]]

