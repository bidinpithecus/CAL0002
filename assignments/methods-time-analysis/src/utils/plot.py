import pandas as pd
import matplotlib
matplotlib.use('TkAgg') # set the backend to TkAgg
import matplotlib.pyplot as plt
from PIL import ImageTk

# Read CSV file into a pandas DataFrame
df = pd.read_csv('results/data.csv')

# # Create a line graph for each method
# for method in df.columns[1:]:
#     plt.plot(df['Size'], df[method], label=method)


# Extract data for each search method
bubble_sort = df['BubbleSort']
insertion_sort = df['InsertionSort']
heap_sort = df['HeapSort']
merge_sort = df['MergeSort']
quick_sort = df['QuickSort']
seq_search = df['SequentialSearch']
binary_search = df['BinarySearch']

# Create scatter plot for each search method
plt.scatter(df['Size'], bubble_sort, s=16, label='BubbleSort')
plt.scatter(df['Size'], insertion_sort, s=16, label='InsertionSort')
plt.scatter(df['Size'], heap_sort, s=16, label='HeapSort')
plt.scatter(df['Size'], merge_sort, s=16, label='MergeSort')
plt.scatter(df['Size'], quick_sort, s=16, label='QuickSort')
plt.scatter(df['Size'], seq_search, s=16, label='SequentialSearch')
plt.scatter(df['Size'], binary_search, s=16, label='BinarySearch')

# Set title and labels for axes
plt.title('Effort of Search and Sorting Methods by Size')
plt.xlabel('Size')
plt.ylabel('Time in usec')

plt.legend()

# Show the graph
plt.savefig("results/graph.png")
