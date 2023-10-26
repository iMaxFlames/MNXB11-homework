import numpy as np
import csv

# Set the parameters for the normal distribution
mean_area = 10
std_dev_area = 3

# Number of data points to generate
num_points = 10000

# Generate random areas following a normal distribution
areas = np.random.normal(mean_area, std_dev_area, num_points)

# Ensure that the generated areas are non-negative
areas = np.maximum(areas, 0)

# Generate corresponding widths and heights independently
widths = np.random.uniform(1, 10, num_points)  # Random widths between 1 and 10
heights = areas / widths

# Create a list of tuples containing (width, height) pairs
data = [(width, height) for width, height in zip(widths, heights)]

# Write the data to a CSV file
csv_filename = 'rectangle_dimensions.csv'
with open(csv_filename, 'w', newline='') as csvfile:
    csv_writer = csv.writer(csvfile)
    csv_writer.writerow(['Width', 'Height'])  # Write header
    csv_writer.writerows(data)

print(f"Data written to {csv_filename}")