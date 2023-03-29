while true; do
  disk_usage=$(df -h | grep '/dev/' | awk '{print $5}' | sed 's/%//' | head -1)
  if [[ $disk_usage -ge 90 ]]; then
    sh ./data/app/clear_log.sh
  fi
  sleep 10
done
