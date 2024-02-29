docker rm -f php-fpm7.1
docker rmi my-php-fpm7.1
docker build -t my-php-fpm7.1 .