import pandas as pd
import matplotlib
matplotlib.use('TkAgg') # set the backend to TkAgg
import matplotlib.pyplot as plt

# Read CSV file into a pandas DataFrame
df = pd.read_csv('results/data.csv')

# Define dictionary of method names and corresponding data series
method_data = {
    'BubbleSort': df['BubbleSort'],
    'InsertionSort': df['InsertionSort'],
    'HeapSort': df['HeapSort'],
    'MergeSort': df['MergeSort'],
    'QuickSort': df['QuickSort'],
    'SequentialSearch': df['SequentialSearch'],
    'BinarySearch': df['BinarySearch']
}

# Loop through dictionary and create scatter plot for each method
for method, data in method_data.items():
    plt.scatter(df['Size'], data, s=16, label=method)

# Set title and labels for axes
plt.title('Effort of Search and Sorting Methods by Size')
plt.xlabel('Size')
plt.ylabel('Time in us')

plt.legend()

# Show the graph
plt.savefig("results/graph.svg", dpi=300)
