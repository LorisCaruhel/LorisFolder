# -*- coding: utf-8 -*-
"""
Created on Wed Apr 24 23:45:46 2024

@author: tiphaine
"""

import numpy as np
import numpy.random as rd
import matplotlib.pyplot as plt

def Moyenne(Serie):
    N=len(Serie)
    return sum(Serie)/N

def Variance(X):
    N=X.shape[0]
    Xm=sum(X)/N
    return sum((X-Xm)*(X-Xm))/N

##################################
#Exercice 3
##################################
#1
Chomage=np.array([7.9,9.4,11.7,9.3,8.1,8.8,
                  7.8,8.8,8.3,8.1,11,10.8,9.9])

Notes=np.array([11, 9, 14, 13, 11, 20, 9, 12, 16, 17, 7, 16, 15, 12, 12, 15, 15, 11, 14, 11])

#2
print(Moyenne(Chomage))
print(Variance(Chomage))

#3
plt.figure()
inter = [7.5,8, 8.5, 9.5, 10.5,12]
plt.hist(Chomage,inter,density=True)

plt.figure()
inter=[0,8,10,12,13,15,18,21]
plt.hist(Notes,inter,density=True)

#4
plt.figure()
plt.boxplot(Chomage)


##################################
#Exercice 4
##################################

def tirages_des(N):
    return rd.randint(1,7,size=N)  
Serie100=tirages_des(100)

plt.figure()
plt.hist(Serie100,[1,2,3,4,5,6,7],histtype='bar',align='left',rwidth=0.1)