# Task 4.9: Reproducible 10,000-Request Disk Scheduling Workload Simulator
import random

def generate_requests(n=10000, max_cyl=199, seed=42):
    rng = random.Random(seed)
    return [rng.randint(0, max_cyl) for _ in range(n)]

def fcfs_movement(reqs, head=53):
    pos = head
    total = 0
    for r in reqs:
        total += abs(r - pos)
        pos = r
    return total

def scan_movement(reqs, head=53, max_cyl=199):
    left = sorted([r for r in reqs if r <= head], reverse=True)
    right = sorted([r for r in reqs if r > head])
    seq = left + [0] + right
    pos = head
    total = 0
    for r in seq:
        total += abs(r - pos)
        pos = r
    return total

def look_movement(reqs, head=53):
    left = sorted([r for r in reqs if r <= head], reverse=True)
    right = sorted([r for r in reqs if r > head])
    seq = left + right
    pos = head
    total = 0
    for r in seq:
        total += abs(r - pos)
        pos = r
    return total

if __name__ == "__main__":
    reqs = generate_requests(n=10000, max_cyl=199, seed=42)
    print(f"10,000-Request Simulation (Seed=42, Head=53, Cylinders=0..199):")
    print(f"  FCFS Total Head Movement: {fcfs_movement(reqs):,} cylinders")
    print(f"  SCAN Total Head Movement: {scan_movement(reqs):,} cylinders")
    print(f"  LOOK Total Head Movement: {look_movement(reqs):,} cylinders")
