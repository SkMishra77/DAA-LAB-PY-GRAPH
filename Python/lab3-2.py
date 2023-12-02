import time
import matplotlib.pyplot as plt
import json
import random

with open('g2-5.json', 'r') as f:
    data = f.read()
    data = json.loads(data)


def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        time.sleep(0.002*len(arr))
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quick_sort(less) + [pivot] + quick_sort(greater)

def measure_time(input_size):
    my_list = data[str(input_size)]
    start_time = time.time()
    quick_sort(my_list)
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
plt.title('Input Size vs. Execution Time for Quick Sort')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()
