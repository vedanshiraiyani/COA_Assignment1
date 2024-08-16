import matplotlib.pyplot as plt

N_vals = [64, 128, 256, 512, 1024]
int_times_cpp = [0.00303, 0.033435, 0.226099, 1.89039, 14.0054]
dbl_times_cpp = [0.005422, 0.027777, 0.247847, 2.00949, 17.3577]
int_times_py = [0.0001964569091796875, 0.003136873245239258, 0.022209644317626953, 0.3873453140258789, 5.907103538513184]
dbl_times_py = [0.000209808349609375, 0.025841474533081055, 0.008276224136352539, 0.0941324234008789,]

plt.figure(figsize=(14, 6))

plt.subplot(1, 2, 1)
plt.plot(N_vals, int_times_cpp, label='C++ Int')
plt.plot(N_vals, dbl_times_cpp, label='C++ Double')
plt.plot(N_vals, int_times_py, label='Python Int')
plt.plot(N_vals, dbl_times_py, label='Python Double')
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (s)')
plt.title('Time vs Matrix Size')
plt.legend()

plt.subplot(1, 2, 2)
# Add similar plots for other data if needed

plt.show()
