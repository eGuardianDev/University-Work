import matplotlib.pyplot as plt
import pandas as pd
import sys

files = sys.argv[1:] if len(sys.argv) > 1 else ["simulation.csv"]

for f in files:
    df = pd.read_csv(f)
    plt.plot(df["step"], df["fish"], label=f"{f} - Fish")
    plt.plot(df["step"], df["sharks"], label=f"{f} - Sharks", linestyle="--")

plt.xlabel("Step")
plt.ylabel("Count")
plt.title("WaTor Simulation")
plt.legend()
plt.show()