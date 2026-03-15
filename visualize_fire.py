import numpy as np
import matplotlib.pyplot as plt
import time

N = 30
STEPS = 12 

TREE = 1
FIRE = 2
BURNED = 3

forest = np.ones((N,N))

# start fire
forest[N//2,N//2] = FIRE
forest[N//2+1,N//2] = FIRE
forest[N//2-1,N//2] = FIRE
forest[N//2,N//2+1] = FIRE
forest[N//2,N//2-1] = FIRE

plt.ion()
fig, ax = plt.subplots()

for step in range(STEPS):

    ax.clear()
    ax.imshow(forest, cmap="hot", vmin=1, vmax=3)
    ax.set_title(f"Wildfire Spread - Step {step+1}")
    plt.pause(0.5)

    new = forest.copy()

    for i in range(N):
        for j in range(N):

            if forest[i,j] == FIRE:
                new[i,j] = BURNED

            elif forest[i,j] == TREE:

                fire = False

                if i>0 and forest[i-1,j]==FIRE: fire=True
                if i<N-1 and forest[i+1,j]==FIRE: fire=True
                if j>0 and forest[i,j-1]==FIRE: fire=True
                if j<N-1 and forest[i,j+1]==FIRE: fire=True

                if fire:
                    new[i,j] = FIRE

    forest = new

plt.ioff()
plt.show()
