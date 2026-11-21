# Task 1 – File-System Design Review
- **Critique of Flat Directory:** Rejects placing 12,000 students in a single flat namespace due to filename collisions, external fragmentation under contiguous allocation, and total lack of privacy controls.
- **Recommended Architecture:** Hierarchical tree (`/college/students/<REG_NO>`, `/college/courses/<COURSE_ID>`, `/college/projects/<TEAM_ID>`), standardized naming (`course_task_version_date.ext`), per-user permissions, and college-managed cloud tenant policies.
