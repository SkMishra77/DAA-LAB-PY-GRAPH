import time
import matplotlib.pyplot as plt
import json
import random

with open('g2-4.json', 'r') as f:
    data = f.read()
    data = json.loads(data)


def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        time.sleep((0.001*(len(left_half)+len(right_half))))

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1


def measure_time(input_size):
    my_list = data[str(input_size)]
    start_time = time.time()
    merge_sort(my_list)
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
plt.title('Input Size vs. Execution Time for Merge Sort')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()
