pid=$(pgrep dlv)
kill -9 "$pid"
echo "kill $pid"
