import numpy as np
import time

def multiply_matrices(A, B):
    return np.dot(A, B)

sizes = [64, 128, 256, 512, 1024]

for N in sizes:
    A = np.random.uniform(0.0, 10.0, size=(N, N))
    B = np.random.uniform(0.0, 10.0, size=(N, N))

    start_time = time.time()
    C = multiply_matrices(A, B)
    end_time = time.time()

    cpu_time = end_time - start_time
    print(f"N = {N}: CPU time = {cpu_time} seconds")