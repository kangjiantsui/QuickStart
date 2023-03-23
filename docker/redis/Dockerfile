FROM kangjiantsui/redis:chuyao

#COPY dump.rdb /data

COPY redis.conf /usr/local/etc/redis/redis.conf

CMD [ "redis-server", "/usr/local/etc/redis/redis.conf" ]