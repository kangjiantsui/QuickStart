TYPE=VIEW
query=select `l`.`id` AS `id`,`l`.`admin_id` AS `admin_id`,`l`.`username` AS `username`,`l`.`url` AS `url`,`l`.`title` AS `title`,`l`.`content` AS `content`,`l`.`ip` AS `ip`,`l`.`useragent` AS `useragent`,`l`.`createtime` AS `createtime`,`a`.`nickname` AS `nickname` from (`gm`.`admin_log` `l` join `gm`.`admin` `a`) where (`l`.`admin_id` = `a`.`id`)
md5=c44d836f066d14281ad97a6b2a4c114b
updatable=1
algorithm=0
definer_user=root
definer_host=%
suid=1
with_check_option=0
timestamp=2024-03-08 06:33:53
create-version=1
source=select `l`.`id` AS `id`,`l`.`admin_id` AS `admin_id`,`l`.`username` AS `username`,`l`.`url` AS `url`,`l`.`title` AS `title`,`l`.`content` AS `content`,`l`.`ip` AS `ip`,`l`.`useragent` AS `useragent`,`l`.`createtime` AS `createtime`,`a`.`nickname` AS `nickname` from (`admin_log` `l` join `admin` `a`) where (`l`.`admin_id` = `a`.`id`)
client_cs_name=utf8
connection_cl_name=utf8_general_ci
view_body_utf8=select `l`.`id` AS `id`,`l`.`admin_id` AS `admin_id`,`l`.`username` AS `username`,`l`.`url` AS `url`,`l`.`title` AS `title`,`l`.`content` AS `content`,`l`.`ip` AS `ip`,`l`.`useragent` AS `useragent`,`l`.`createtime` AS `createtime`,`a`.`nickname` AS `nickname` from (`gm`.`admin_log` `l` join `gm`.`admin` `a`) where (`l`.`admin_id` = `a`.`id`)
