import time
import matplotlib.pyplot as plt
import random
import string
import matplotlib.pyplot as plt

def lcs(X, Y):
    m, n = len(X), len(Y)

    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            time.sleep(0.0001)
            if X[i - 1] == Y[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    length = dp[m][n]
    return length




def generate_random_string(length):
    return ''.join(random.choice(string.ascii_lowercase) for _ in range(length))

def generate_test_cases(num_cases):
    test_cases = []
    for i in range(num_cases):
        length_X = random.randint(i, i)
        length_Y = random.randint(i, i)
        X = generate_random_string(length_X)
        Y = generate_random_string(length_Y)
        test_cases.append([X, Y])
    return test_cases



caseNumber = 0


def measure_time(X, Y):
    start_time = time.time()
    length = lcs(X, Y)
    
    global caseNumber
    caseNumber += 1

    print("Case : ",caseNumber,"Result :",length , "str1 : ",X , "str2" , Y)
    end_time = time.time()
    return length, end_time - start_time



num_cases = 20
test_cases = generate_test_cases(num_cases)




print("Started:")

lengths_and_times = [measure_time(X, Y) for X, Y in test_cases]

lengths, execution_times = zip(*lengths_and_times)

plt.plot(lengths, execution_times, marker='o')
plt.title('Input Size vs. Execution Time for LCS')
plt.xlabel('Input Size')
plt.ylabel('Execution Time (seconds)')
plt.show()



