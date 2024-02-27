docker rm -f my-nginx
docker run -d -p 18080:18080 --name my-nginx --network ro-network \
-v C:\\workspace\\QuickStart\\docker\\nginx\\nginx:/etc/nginx \
-v C:\\workspace\\ro_support_tool:/var/www/ro_support_tool \
nginx