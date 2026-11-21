import math

def estimate_capacity(total_users=150000, window_hours=2, requests_per_user=5, peak_multiplier=2.5, rps_per_replica=50, safety_factor=1.25):
    window_seconds = window_hours * 3600
    avg_arrival_rate = total_users / window_seconds
    avg_rps = avg_arrival_rate * requests_per_user
    peak_rps = avg_rps * peak_multiplier
    raw_replicas = math.ceil(peak_rps / rps_per_replica)
    recommended_replicas = math.ceil(raw_replicas * safety_factor)
    return {
        "total_users": total_users,
        "window_seconds": window_seconds,
        "avg_arrival_rate_users_per_sec": round(avg_arrival_rate, 2),
        "estimated_peak_rps": round(peak_rps, 2),
        "raw_replicas": raw_replicas,
        "recommended_replicas_with_safety_margin": recommended_replicas
    }

if __name__ == "__main__":
    res = estimate_capacity()
    for k, v in res.items():
        print(f"{k}: {v}")
