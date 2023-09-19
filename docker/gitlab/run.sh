docker run --detach \
  --hostname kangjian-gitlib \
  --publish 10081:80 --publish 2222:22 \
  --name gitlab \
  --restart always \
  --volume C:\\data\\docker\\gitlab\\config:/etc/gitlab \
  --volume C:\\data\\docker\\gitlab\\logs:/var/log/gitlab \
  --volume C:\\data\\docker\\gitlab\\data:/var/opt/gitlab \
  gitlab/gitlab-ce:latest