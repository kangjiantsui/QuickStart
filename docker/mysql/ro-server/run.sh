docker pull mysql:5.6

docker run --name mysql13306 -e MYSQL_ROOT_PASSWORD='^2mV5yZ@3gT!pB&8#dC' -p 13306:3306 -d -v C:/workspace/QuickStart/docker/mysql/ro-server/data/mysql:/var/lib/mysql mysql:5.6