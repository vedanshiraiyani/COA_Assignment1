import numpy as np
import time

def mult(A, B):
    return np.dot(A, B)

sizes = [64, 128, 256, 512, 1024]

for N in sizes:
    A = np.random.randint(0, 10, size=(N, N), dtype=int)
    B = np.random.randint(0, 10, size=(N, N), dtype=int)

    start = time.time()
    C = mult(A, B)
    end = time.time()

    t = end - start
    print(f"N = {N}: Time = {t} seconds")
