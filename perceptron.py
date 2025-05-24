# Простой перцептрон для определения чётности числа с вводом
import random

# Функция для получения признаков числа
def get_features(number):
    last_digit = number % 10  # Последняя цифра
    digit_sum = sum(int(d) for d in str(number))  # Сумма цифр
    return [last_digit, digit_sum]

# Функция для проверки, чётное ли число (для тренировки)
def is_even(number):
    return 1 if number % 2 == 0 else 0

# Начальные веса: большой для последней цифры, маленький для суммы
weights = [0.9, 0.01]  # Последняя цифра важнее!
bias = -1.0  # Отрицательный сдвиг для чётных чисел
learning_rate = 0.02  # Маленький шаг для точной настройки

# Тренировка перцептрона
for _ in range(5000):  # 5000 примеров
    number = random.randint(1, 100)  # Случайное число
    features = get_features(number)  # Признаки
    target = is_even(number)  # Цель: 1 (чётное) или 0 (нечётное)
    
    # Вычисляем предсказание
    weighted_sum = sum(f * w for f, w in zip(features, weights)) + bias
    prediction = 1 if weighted_sum > 0 else 0
    
    # Обновляем веса, если ошибка
    error = target - prediction
    if error != 0:
        for i in range(len(weights)):
            weights[i] += learning_rate * error * features[i]
        bias += learning_rate * error

# Ввод числа от пользователя с обработкой EOF
try:
    test_number = int(input("Введите число (1-100): "))  # Запрашиваем число
    if not 1 <= test_number <= 100:
        print("Число вне диапазона, использую 42.")
        test_number = 42
except (EOFError, ValueError):
    print("Ошибка ввода, использую число 42.")
    test_number = 42

# Проверка введённого числа
features = get_features(test_number)
weighted_sum = sum(f * w for f, w in zip(features, weights)) + bias
prediction = 1 if weighted_sum > 0 else 0
print(f"Число {test_number}: {'Чётное' if prediction == 1 else 'Нечётное'}")
print(f"Веса: {weights}, Сдвиг: {bias}")