# Q4.2 Effective Access Time with Page Faults
mem_ns = 100
pf_ns = 8_000_000
for label, p in [("1/1,000", 1/1000), ("1/100,000", 1/100000), ("1/1,000,000", 1/1000000)]:
    eat = (1 - p) * mem_ns + p * pf_ns
    print(f"p = {label:<11} -> EAT = {eat:10.4f} ns ({eat/mem_ns:.2f}x slowdown)")

max_p = 10 / (pf_ns - mem_ns)
print(f"Max fault rate p for <=10% slowdown (EAT <= 110 ns): {max_p:.2e} (~1 fault per {int(round(1/max_p)):,} accesses)")
