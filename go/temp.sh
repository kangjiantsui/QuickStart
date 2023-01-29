array=(
  gamesvr
  roomsvr
)
for e in "${array[@]}"; do
  pid=$(pgrep -a "$e" | grep 14d61b4 | awk '{print $1}')
  # 判断是否为空
  if [ -z "$pid" ]; then
    break
  fi
    kill -9 "$pid"
  echo kill "$pid"
done
