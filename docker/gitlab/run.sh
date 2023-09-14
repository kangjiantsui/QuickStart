docker run --detach \
  --hostname kangjian-gitlib \
  --publish 443:443 --publish 80:80 --publish 2222:22 \
  --name gitlab \
  --restart always \
  --volume /data/docker-Volumes/gitlab/config:/etc/gitlab \
  --volume /data/docker-Volumes/gitlab/logs:/var/log/gitlab \
  --volume /data/docker-Volumes/gitlab/data:/var/opt/gitlab \
  gitlab/gitlab-ce:latest