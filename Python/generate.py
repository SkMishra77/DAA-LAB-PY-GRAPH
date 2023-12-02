import random
import json

def generate_random_numbers(n):
    # Generate a list of n random numbers in the range 1 to 10^5
    random_numbers = [random.randint(1, 10**5) for _ in range(n)]
    return random_numbers

data = {}

for i in range(1,1000,10):
    # Get user input for the number of elements (n)
    n = i

    # Generate the list of random numbers
    random_list = generate_random_numbers(n)

    # Save the data in a dictionary with 'n' as key and 'random_list' as value
    data.update({
        n:sorted(random_list)
    })

# Save the data to a JSON file named 'g.json'
with open("g.json", "w") as json_file:
    json.dump(data, json_file)

print(f"Generated list of random numbers saved in 'g.json'.")
