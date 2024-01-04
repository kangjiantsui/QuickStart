docker rm -f ro-zk-docker
docker run --name ro-zk-docker --network ro-network -p 12181:2181 -d zookeeper