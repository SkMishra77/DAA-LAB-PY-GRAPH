import time
import matplotlib.pyplot as plt
import json
import random
import math

with open('g2-7.json', 'r') as f:
    data = f.read()
    data = json.loads(data)


def counting_sort(arr):
    max_val = max(arr)
    count = [0] * (max_val + 1)

    for num in arr:
        count[num] += 1

    k = 0

    time.sleep(0.0001*max_val)
    for i in range(max_val + 1):
        while count[i] > 0:
            arr[k] = i
            k += 1
            count[i] -= 1


def measure_time(input_size):
    my_list = data[str(input_size)]
    start_time = time.time()
    counting_sort(my_list)
    end_time = time.time()
    return end_time - start_time


# Generate input sizes (e.g., 1 to 100 with a step of 5)
input_sizes = [ i for i in data.keys()][:20]


# Measure time for each input size
execution_times = [measure_time(size) for size in input_sizes]


# index = 0
# for i in data.keys():
#     print(i , len(data[i]) , execution_times[index])
#     index += 1

# Plotting the graph
plt.plot(input_sizes, execution_times, marker='o')
plt.title('Input Size vs. Execution Time for Counting Sort')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()
