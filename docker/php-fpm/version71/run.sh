docker rm -f php-fpm7.1
docker run -d --name php-fpm7.1 --network ro-network \
-p 19003:9003 \
-v C:\\workspace\\ro_support_tool:/var/www/ro_support_tool \
my-php-fpm7.1