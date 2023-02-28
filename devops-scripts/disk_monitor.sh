while true; do
  disk_usage=$(df -h | grep '/dev/' | awk '{print $5}' | sed 's/%//'|head -1)
  if [[ $disk_usage -ge 80 ]]; then
    echo "Disk usage is above 80%. Executing some method..."
    # 这里执行你想要执行的某个方法
  fi
  sleep 10
done