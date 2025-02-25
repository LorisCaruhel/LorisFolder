#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import numpy.linalg as alg

#############  Question 1 ###########################

# m,2,3 vaut 0

M1 = np.array([[5, 6, 7, 8, 9]])

M2 = np.ones((1, 5))  

M3 = np.array([[1], 
               [2], 
               [3]])

M4 = np.array([[1, 2, 4], 
               [-1, 2, 3], 
               [1, 8, 9]])

############ Question 2 #############################

A = np.array([[2, 2.3, 2.4],
              [9, -8, 9.81],
              [22, 1, 0.145]])

print(A[1 : 3, :]) # Affichage des lignes 2 et 3 de la matrice A :

print(A[1 : 3, 1 : 3]) # Affichage du bloc composé des lignes 2 et 3 et des colonnes 2 et 3 de la matrice A :

########### Question 3 ##############################

M5 = np.concatenate((M1, [[10]]), axis=1)
M6 = np.concatenate((M2, M1), axis=1)
M7 = np.concatenate((M2, M1), axis=0)
M8 = np.concatenate((M3, [[4]]), axis=0)
M9 = np.concatenate((M4, [[1], [7], [4]]), axis=1)
M10 = np.concatenate((M4, M3), axis=1)
M11 = np.concatenate((M4, M3.reshape((1,3))), axis=0)

########### Question 4 ##############################

M12 = np.concatenate(([[2]], M2), axis=1)
M13 = np.concatenate(([[9]], M3, [[8]]), axis=0)
M14 = np.delete(M4, 1, 0)
M15 = np.delete(M1, [0, 2], axis=1)
M16 = 
M17 = np.delete(M4, 1, axis=1)


