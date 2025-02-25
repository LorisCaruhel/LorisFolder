import numpy as np
import matplotlib.pyplot as plt

def f1prime(x):
    return (2 * x - 4)

def f2prime(x):
    return (3 * ( x**2 ) - 6)

def Gradient1D(x0,alpha,n,fp):
    previous = x0
    for i in range(0,n):
        current = previous - alpha * (fp(previous))
        previous = current
    return current

# print("Choix avec page 14 du cours :", Gradient1D(-2, 0.2, 2, f1prime))

# print("Test minimum de la fonction 2 :", Gradient1D(2, 0.1, 2000000, f2prime))


def df1x(x,y):
    return (4 * x + 2 + y)

def df1y(x,y):
    return (10 * y + x)

def df2x(x,y):
    return (2 * x - 1.9)

def df2y(x,y):
    return (2 * y)

def Gradient2D(fx,fy,x0,y0,alpha,n):
    previousX = x0
    previousY = y0
    for i in range(0,n):
        currentX = previousX - alpha * (fx(previousX, previousY))
        currentY = previousY - alpha * (fy(previousX, previousY))
        previousX = currentX
        previousY = currentY
    return (currentX, currentY)

# print("Choix page 18 du cours f1 : ", Gradient2D(df1x, df1y, -2, 2, 0.2, 2))
# print("Test minimum f2 : ", Gradient2D(df2x, df2y, 0, 0, 0.9, 20000))


def dFa(a, b):
    return (13.5632 * a + 11.44 * b - 90.4)

def dFb(a, b):
    return (10 * b + 11.44 * a - 72)

# print("Exemple du cours page 20 : ", Gradient2D(dFa, dFb, 20, -10, 0.05, 20000))

X = np.array([0.84, 0.98, 1.14, 1.2, 1.44]).reshape(-1, 1)
Y = np.array([2, 4, 8, 10, 12]).reshape(-1, 1)

# print(tailleEnfant, ageEnfant)

def Erreurs(a, b):
    if len(X) != len(Y):
        return -1
    
    valeurs = [(Y[i] - (a * X[i] + b)) for i in range(len(X))]
    return np.array(valeurs).reshape(-1, 1)

print("Test age et taille ax+b : ")
print(Erreurs(1,1))

def F(E):
    return (np.dot(E.T, E)) 

print("Calcul de la somme des erreurs : ", F(Erreurs(1, 1)))

def dFa1(X, E):
    return (-2 * np.dot(X.T, E))

def dFb1(Y, E):
    return (-2 * np.dot(np.ones(len(X), 1), E))

X, Y = np.meshgrid(np.linspace(-2, 3, 21), np.linspace(-2, 2, 21))

print(X.shape, Y.shape)

def f2(x, y):
    return df1x(x, y)

X, Y = np.meshgrid(np.linspace(-2, 3, 21), np.linspace(-2, 2, 21))

Z = f2(X, Y)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='viridis') 
plt.title("Surface 3D de f2(x, y)")
plt.show()

fig1 = plt.figure() 
plt.contour(X, Y, Z, 20, cmap='plasma')  
plt.colorbar()
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Courbes de niveau de f2(x, y)")
plt.show()

