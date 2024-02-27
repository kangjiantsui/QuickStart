docker rm -f php-fpm5.6
docker run -d --name php-fpm5.6 --network ro-network \
-v C:\\workspace\\ro_support_tool:/var/www/ro_support_tool \
php:5.6-fpm