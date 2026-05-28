import matplotlib.pyplot as plt
import pandas as pd
import sys

df = pd.read_csv(sys.argv[1] if len(sys.argv) > 1 else "simulation.csv")

plt.plot(df["step"], df["fish"], color="green", label="Fish")
plt.plot(df["step"], df["sharks"], color="red", label="Sharks")
plt.xlabel("Step")
plt.ylabel("Count")
plt.title("WaTor Simulation")
plt.legend()
plt.show()