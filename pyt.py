import math

def piecewise_function(x, a, b):
    if x <= a:
        return math.sin(x) - 1
    elif x < b:
        return math.cos(x) + 2
    else:
        # Проверка области определения тангенса
        if abs(x - math.pi/2) % math.pi < 1e-10:
            return float('nan')  # Не определено
        return math.tan(x) - 0.5

# Пример использования
a = 0
b = math.pi/2
test_values = [-1, 0, 1, math.pi/4, math.pi/2, 2]

print("Python реализация:")
print(f"a = {a}, b = {b}")
print("x\t\tf(x)")
print("-" * 30)
for x in test_values:
    result = piecewise_function(x, a, b)
    print(f"{x:.4f}\t\t{result:.4f}")
