import time
import matplotlib.pyplot as plt
import json
import random

with open('g1-1.json', 'r') as f:
    data = f.read()
    data = json.loads(data)


def recursive_linear_search(arr, target, index=0):
    time.sleep(0.01)
    if index < len(arr):
        if arr[index] == target:
            return index
        else:
            return recursive_linear_search(arr, target, index + 1)
    else:
        return -1

def measure_time(input_size):
    my_list = data[str(input_size)]
    target_element = my_list[-1]

    start_time = time.time_ns()
    recursive_linear_search(my_list, target_element)
    end_time = time.time_ns()

    return end_time - start_time


# Generate input sizes (e.g., 1 to 100 with a step of 5)
input_sizes = [ i for i in data.keys()][:20]
# 

# Measure time for each input size
execution_times = [measure_time(size) for size in input_sizes]


# index = 0
# for i in data.keys():
#     print(i , len(data[i]) , execution_times[index])
#     index += 1

# Plotting the graph
plt.plot(input_sizes, execution_times, marker='o')
plt.title('Input Size vs. Execution Time for Recursive Linear Search')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()
