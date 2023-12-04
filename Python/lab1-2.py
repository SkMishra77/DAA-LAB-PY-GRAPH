import time
import matplotlib.pyplot as plt
import json
import random

with open('g1-2.json', 'r') as f:
    data = f.read()
    data = json.loads(data)


def recursive_binary_search(arr, target, low, high):
    time.sleep(0.01)
    if low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            return mid
        if arr[mid] > target:
            return recursive_binary_search(arr, target, low, mid - 1)
        else:
            return recursive_binary_search(arr, target, mid + 1, high)
    return -1

def measure_time(input_size):
    my_list = data[str(input_size)]
    target_element = my_list[-1]
    low, high = 0, len(my_list)-1
    start_time = time.time()
    recursive_binary_search(my_list, target_element, low, high)
    end_time = time.time()
    return end_time - start_time


# Generate input sizes (e.g., 1 to 100 with a step of 5)
input_sizes = [ i for i in data.keys()][5:25]


# Measure time for each input size
execution_times = [measure_time(size) for size in input_sizes]


# index = 0
# for i in data.keys():
#     print(i , len(data[i]) , execution_times[index])
#     index += 1

# Plotting the graph
plt.plot(input_sizes, execution_times, marker='o')
plt.title('Input Size vs. Execution Time for Recursive Binary Search')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()
