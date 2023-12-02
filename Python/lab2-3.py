import time
import matplotlib.pyplot as plt
import json
import random

with open('g2-3.json', 'r') as f:
    data = f.read()
    data = json.loads(data)


def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        time.sleep(0.001)
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap arr[i] and arr[min_index]
        arr[i], arr[min_index] = arr[min_index], arr[i]

def measure_time(input_size):
    my_list = data[str(input_size)]
    start_time = time.time()
    selection_sort(my_list)
    end_time = time.time()
    return end_time - start_time


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
plt.title('Input Size vs. Execution Time for Selection Sort')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()
