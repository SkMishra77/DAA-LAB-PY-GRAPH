import time
import matplotlib.pyplot as plt
import json
import random
import math

with open('g2-8.json', 'r') as f:
    data = f.read()
    data = json.loads(data)


def getMax(arr):
    time.sleep(0.0001*len(arr))
    max_num = max(arr)
    return max_num if max_num > 0 else 1

def countingSort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10
    time.sleep(0.0001*n)

    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]

def radixSort(arr):
    max_num = getMax(arr)
    exp = 1
    while max_num // exp > 0:
        countingSort(arr, exp)
        exp *= 10


def measure_time(input_size):
    my_list = data[str(input_size)]
    start_time = time.time()
    radixSort(my_list)
    end_time = time.time()
    return end_time - start_time


# Generate input sizes (e.g., 1 to 100 with a step of 5)
input_sizes = [ i for i in data.keys()][:20]
print("Started:")

# Measure time for each input size
execution_times = [measure_time(size) for size in input_sizes][:20]



plt.plot(input_sizes, execution_times, marker='o')
plt.title('Input Size vs. Execution Time for Radix Sort')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()
