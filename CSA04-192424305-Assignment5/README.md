# SIMATS Engineering – Operating Systems Assignment 5 (CO5)
## Linux, Containers and Virtualisation for Efficient Operations

**Repository Name:** `CSA04-192424305-Assignment5`  
**Student Name:** B. Lokeshwaran  
**Register Number:** 192424305  
**Course Outcome:** CO5  

---

## Repository Structure

```text
CSA04-192424305-Assignment5/
├── README.md
├── docs/
│   └── Operating_Systems_Assignment5_CO5.pdf
├── figures/
│   ├── figA1_linux_architecture.png
│   ├── figA2_portal_admin_blueprint.png
│   ├── figA3_virtualisation_layer.png
│   ├── figA4_container_isolation.png
│   ├── figA5_cloud_kubernetes_arch.png
│   └── figB4_recommended_hybrid.png
├── outputs/
│   ├── taskB1_script_execution_output.txt
│   └── taskB4_capacity_estimate_output.txt
├── PartA_Design/
│   ├── TaskA1_Linux_System_Components/README.md
│   ├── TaskA2_System_Administration/
│   │   ├── nginx_portal.conf
│   │   └── portal.service
│   ├── TaskA3_Virtualisation/README.md
│   ├── TaskA4_Containerisation/README.md
│   └── TaskA5_Cloud_Kubernetes/README.md
└── PartB_Implementation/
    ├── TaskB1_Linux_Server_Admin/
    │   ├── access_log_summary.sh
    │   └── disk_alert.sh
    ├── TaskB2_Containerise_Portal/
    │   ├── Dockerfile
    │   ├── app.py
    │   ├── docker-compose.yml
    │   └── requirements.txt
    ├── TaskB3_Comparison_and_K8s/
    │   ├── benchmark_measurements_template.md
    │   └── deployment.yaml
    └── TaskB4_Engineering_Decision/
        ├── capacity_estimator.py
        └── docker-compose-hybrid.yml
```

## Quick Reproduction Steps

1. **Task B1 – Log Analysis & Disk Alert Scripts:**
   ```bash
   chmod +x PartB_Implementation/TaskB1_Linux_Server_Admin/*.sh
   ./PartB_Implementation/TaskB1_Linux_Server_Admin/access_log_summary.sh
   ./PartB_Implementation/TaskB1_Linux_Server_Admin/disk_alert.sh
   ```
2. **Task B2 – Containerise the University Result Portal:**
   ```bash
   cd PartB_Implementation/TaskB2_Containerise_Portal
   docker build -t result-portal .
   docker run -d --name portal-demo -p 8000:8000 result-portal
   docker exec portal-demo whoami   # Expected: portal
   docker compose up -d
   ```
3. **Task B3 – Kubernetes Deployment & Self-Healing:**
   ```bash
   kubectl apply -f PartB_Implementation/TaskB3_Comparison_and_K8s/deployment.yaml
   kubectl get pods
   kubectl scale deployment result-portal --replicas=6
   ```
4. **Task B4 – Hybrid Extension & Capacity Estimator:**
   ```bash
   python3 PartB_Implementation/TaskB4_Engineering_Decision/capacity_estimator.py
   docker compose -f PartB_Implementation/TaskB4_Engineering_Decision/docker-compose-hybrid.yml up -d
   ```
