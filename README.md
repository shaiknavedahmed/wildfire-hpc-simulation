# Parallel Wildfire Spread Simulation (HPC)

This project demonstrates a wildfire spread simulation using concepts from High Performance Computing (HPC). The wildfire spreads across a 2D forest grid and propagates from burning cells to neighboring trees over multiple time steps.

The project also demonstrates containerized execution and visualization of simulation results.

---

## Technologies Used

- C
- MPI (Message Passing Interface)
- Docker
- Python
- Matplotlib

---

## Project Description

The forest is represented as a two-dimensional grid. Each cell in the grid represents a portion of the forest and can be in one of three states:

| Symbol | Meaning |
|------|------|
| T | Tree |
| F | Fire |
| B | Burned |

The simulation follows these rules:

1. The forest grid is initialized with trees.
2. Fire is ignited at the center of the grid.
3. At every simulation step:
   - Burning trees become burned.
   - Neighboring trees catch fire if adjacent to a burning tree.
4. The simulation continues for multiple time steps.

---

## Project Structure

```
wildfire-hpc-simulation
│
├── wildfire.c          # MPI wildfire simulation
├── visualize_fire.py   # Python visualization
├── Dockerfile          # Container environment
└── README.md
```

---

## Running the Simulation

### Build the Docker container

```bash
docker build -t wildfire-hpc .
```

### Run the simulation

```bash
docker run wildfire-hpc
```

---

## Running the Visualization

Run the wildfire visualization using Python:

```bash
python3 visualize_fire.py
```

This displays a graphical simulation showing wildfire spread step by step.

---

## Example Simulation Output

The wildfire spreads outward from the center across the forest grid over multiple iterations.

```
T T T F F T
T F F B B F
F B B B B B
T F B B B F
T T F F F T
```

---

## HPC Concepts Demonstrated

- Grid-based computational modeling
- Iterative simulation
- Parallel runtime using MPI
- Containerized execution using Docker
- Visualization of simulation results

---

## Author

Naved Ahmed Shaik
B.Tech Computer Science & Engineering  
SR University
