import numpy as np
import numpy.linalg as alg

M4 = np.array([[1, 2, 4], 
               [-1, 2, 3], 
               [1, 8, 9]])

print(np.delete(M4, 1, axis=1))