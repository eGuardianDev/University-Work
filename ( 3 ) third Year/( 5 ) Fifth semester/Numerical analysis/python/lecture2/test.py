import numpy as np
import matplotlib.pyplot as plt

# Function to interpolate
def f(x):
    return 1 / (1 + 25 * x**2)

# Number of interpolation points (increase to see more wiggles)
n = 15

# True function values for plotting
x_dense = np.linspace(-1, 1, 400)
y_true = f(x_dense)

# 1. Equally spaced nodes
x_eq = np.linspace(-1, 1, n + 1)
y_eq = f(x_eq)
coeff_eq = np.polynomial.polynomial.polyfit(x_eq, y_eq, n)
y_eq_interp = np.polynomial.polynomial.polyval(x_dense, coeff_eq)

# 2. Chebyshev nodes
x_ch = np.cos((2 * np.arange(n + 1) + 1) * np.pi / (2 * (n + 1)))
y_ch = f(x_ch)
coeff_ch = np.polynomial.polynomial.polyfit(x_ch, y_ch, n)
y_ch_interp = np.polynomial.polynomial.polyval(x_dense, coeff_ch)

# Plot both interpolations
plt.figure(figsize=(12, 5))

# Interpolation curves
plt.subplot(1, 2, 1)
plt.plot(x_dense, y_true, 'k', label='True function f(x)', linewidth=2)
plt.plot(x_dense, y_eq_interp, 'r--', label='Equally spaced nodes')
plt.plot(x_dense, y_ch_interp, 'b-', label='Chebyshev nodes')
plt.scatter(x_eq, y_eq, color='red', s=40)
plt.scatter(x_ch, y_ch, color='blue', s=40)
plt.title(f'Polynomial interpolation (n = {n})')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.grid(True)

# Plot interpolation error
plt.subplot(1, 2, 2)
plt.plot(x_dense, y_eq_interp - y_true, 'r--', label='Error: equally spaced')
plt.plot(x_dense, y_ch_interp - y_true, 'b-', label='Error: Chebyshev')
plt.title('Interpolation error')
plt.xlabel('x')
plt.ylabel('Error')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.show()

