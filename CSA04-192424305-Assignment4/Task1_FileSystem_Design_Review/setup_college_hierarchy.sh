#!/usr/bin/env bash
# Task 1.3 & 1.4: Reference directory hierarchy and least-privilege ACL setup
set -euo pipefail

BASE_DIR="/tmp/college_fs_demo"
mkdir -p "$BASE_DIR/students/REG192424305"/{assignments,documents,personal}
mkdir -p "$BASE_DIR/courses/CSA04"/{lecture-notes,lab-material}
mkdir -p "$BASE_DIR/projects/PROJECT001"/{documents,source-code,deliverables}

chmod 700 "$BASE_DIR/students/REG192424305"
chmod 755 "$BASE_DIR/courses/CSA04"
chmod 770 "$BASE_DIR/projects/PROJECT001"

echo "College directory hierarchy initialized under $BASE_DIR"
find "$BASE_DIR" -maxdepth 3 | sort
