#!/bin/sh
# Usage: dummy-secrets.sh <project>/esphome
# Writes secrets.yaml from secrets.yaml.example with a random base64 key in place of every
# REPLACE_WITH_..._KEY placeholder, and copies it next to every config (ESPHome only reads
# secrets.yaml from the folder of the config it builds). Only for CI: it overwrites secrets.yaml.
set -e
cd "$1"
KEY=$(openssl rand -base64 32)
sed -E "s#REPLACE_WITH_[A-Z0-9_]*KEY[A-Z0-9_=]*#$KEY#" secrets.yaml.example > secrets.yaml
for d in */; do
  [ -d "$d" ] && cp secrets.yaml "$d" 2>/dev/null || true
done
