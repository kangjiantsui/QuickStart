docker rm -f php-fpm
docker run -d --name php-fpm --network ro-network \
-v C:\\workspace\\ro_support_tool:/var/www/ro_support_tool \
-v C:\\workspace\\QuickStart\\docker\\php-fpm\\etc:/usr/local/etc \
php:fpm