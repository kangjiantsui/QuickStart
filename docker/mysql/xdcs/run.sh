docker run --name mysql-3306-1 -e MYSQL_ROOT_PASSWORD=root -p 3306:3306 -d -v /data/docker-Volumes/mysql5.7/:/var/lib/mysql/ mysql:5.7.42

docker run --name mysql-3306-1 -e MYSQL_ROOT_PASSWORD=root -p 3306:3306 -d mysql:5.7.42