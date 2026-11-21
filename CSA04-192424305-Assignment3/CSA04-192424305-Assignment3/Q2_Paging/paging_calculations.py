# Q2.3 & Q2.5 Effective Access Time & 100-Process Internal Fragmentation Estimate
import random

mem_ns = 100
tlb_ns = 10
for h in [0.80, 0.95, 0.99]:
    eat = h * (tlb_ns + mem_ns) + (1 - h) * (tlb_ns + 2 * mem_ns)
    print(f"TLB Hit Ratio {int(h*100)}% -> EAT = {eat:.1f} ns")

rng = random.Random(42)
proc_sizes = [rng.randint(4096, 1024 * 1024) for _ in range(100)]
for ps in [1024, 4096, 2 * 1024 * 1024]:
    total_waste = sum((ps - (s % ps)) % ps for s in proc_sizes)
    print(f"100 Processes (Seed=42) | Page Size = {ps:>7} B | Total Internal Fragmentation = {total_waste:,} B ({total_waste/1024:.2f} KiB)")
