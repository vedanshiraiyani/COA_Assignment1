import matplotlib.pyplot as plt
import numpy as np

# Sizes of the matrices
sizes = [64, 128, 256, 512, 1024]

# Time taken for different data types
time_random_uniform = [0.004087, 0.02483, 0.235532, 1.85167, 14.1033]
time_random_double = [0.006002, 0.037322, 0.374454, 2.28783, 17.7382]
time_integer = [0.0003, 0.0034, 0.0468, 1.3608, 6.1482]
time_double = [0.0001, 0.0002, 0.0010, 0.0070, 0.0532]

# Plotting the data
plt.figure(figsize=(10, 6))

plt.plot(sizes, time_random_uniform, label='Random Uniform', marker='o')
plt.plot(sizes, time_random_double, label='Random Double', marker='o')
plt.plot(sizes, time_integer, label='Integer', marker='o')
plt.plot(sizes, time_double, label='Double', marker='o')

plt.xlabel('Matrix Size (N x N)')
plt.ylabel('Time (seconds)')
plt.title('Matrix Multiplication Performance')
plt.legend()
plt.grid(True)

plt.show()