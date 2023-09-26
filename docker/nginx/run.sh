docker run -d -p 80:80 --name my-nginx \
  -v /data/docker-Volumes/nginx/conf.d:/etc/nginx/conf.d \
  nginx