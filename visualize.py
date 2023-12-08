import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('simulation_data.csv')

# Plotting
plt.plot(data['Step'], data['Population'], label='Population')
plt.xlabel('Simulation Step')
plt.ylabel('Population')
plt.title('Population over Time')
plt.legend()
plt.show(block=True)

