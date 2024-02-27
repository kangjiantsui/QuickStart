docker rm -f my-nginx
docker run -d -p 18080:18080 --name my-nginx \
-v C:\\workspace\\QuickStart\\docker\\nginx\\nginx:/etc/nginx \
-v C:\\workspace\\ro_support_tool\\public:/var/www/ro_support_tool \
nginx