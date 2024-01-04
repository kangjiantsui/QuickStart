docker rm -f zookeeper-12181
docker run --name zookeeper-12181 -p 12181:2181 -d zookeeper