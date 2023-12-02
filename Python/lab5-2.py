import time
import matplotlib.pyplot as plt
import json
import random
import math

with open('g2-9.json', 'r') as f:
    data = f.read()
    data = json.loads(data)


def shell_sort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
                time.sleep(0.00001)
            arr[j] = temp

        gap //= 2


def measure_time(input_size):

    my_list = data[str(input_size)]
    start_time = time.time()
    shell_sort(my_list)
    end_time = time.time()
    return end_time - start_time

print("Started:")
# Generate input sizes (e.g., 1 to 100 with a step of 5)
input_sizes = [ i for i in data.keys()][:20]


# Measure time for each input size
execution_times = [measure_time(size) for size in input_sizes][:20]


# index = 0
# for i in data.keys():
#     print(i , len(data[i]) , execution_times[index])
#     index += 1

# Plotting the graph
plt.plot(input_sizes, execution_times, marker='o')
plt.title('Input Size vs. Execution Time for Shell Sort')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()
