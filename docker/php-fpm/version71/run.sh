docker rm -f php-fpm7.1
docker run -d --name php-fpm7.1 --network ro-network \
-v C:\\workspace\\ro_support_tool:/var/www/ro_support_tool \
-v C:\\workspace\\QuickStart\\docker\\php-fpm\\version71\\data\\etc:/usr/local/etc \
my-php-fpm7.1