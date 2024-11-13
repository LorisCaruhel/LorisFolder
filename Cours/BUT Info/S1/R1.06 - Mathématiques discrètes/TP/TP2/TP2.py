#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import numpy.linalg as alg
from math import *

#############  Exercice 1 ###########################

def absolue(x) :
	x = x * x
	a = sqrt(x)
	return(a)
  
def fact(x):
    if x == 0:
        return 1
    else:
        resultat = 1
        for k in range(2, x + 1):
            resultat *= k
        return resultat
	
def puissance(x, n):
    if n == 0:
        return 1
    else:
        resultat = 1
        for i in range(n):
            resultat *= x
        return resultat

############ Exercice 2 #############################

def transpose(A):
    n, p = A.shape

    B = np.zeros((p, n))

    for i in range(n):
        for j in range(p):
            B[j][i] = A[i][j]
    return B

	
def diagonale(A) :
    n, p = A.shape

    B = np.zeros((n, p))

    for i in range(0, 3):
        B[i][i] = A[i][i]
    return B
	

def trace(A) :
    somme = 0
    for i in range(0, 3):
        somme += A[i][i]
    return somme
	
def valeurmax(A) :
    valMax = 0
    for i in range(0, 3):
        for j in range(0, 3):
            if A[i][j] > valMax :
                valMax = A[i][j]
                co = (i, j)
    return valMax, co
