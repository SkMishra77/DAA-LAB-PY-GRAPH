def greedy_activity_selector(start_time, finish_time):
    n = len(start_time)
    selected_activities = []

    # The first activity is always selected
    selected_activities.append(0)

    # Consider the rest of the activities
    j = 0
    for i in range(1, n):
        # If this activity has a start time greater than or equal to the
        # finish time of the previously selected activity, then select it
        if start_time[i] >= finish_time[j]:
            selected_activities.append(i)
            j = i

    return selected_activities


# Example usage
start_times = [1, 3, 0, 5, 8, 5]
finish_times = [2, 4, 6, 7, 9, 9]

result = greedy_activity_selector(start_times, finish_times)
print("Selected activities:", result)
