TYPE=VIEW
query=select `gm`.`gm_frozen_info`.`id` AS `id`,`gm`.`gm_frozen_verify`.`type` AS `type`,`gm`.`gm_frozen_verify`.`start_time` AS `start_time`,`gm`.`gm_frozen_verify`.`end_time` AS `end_time`,`gm`.`gm_frozen_info`.`uid` AS `uid`,`gm`.`gm_frozen_info`.`send_time` AS `send_time`,`gm`.`gm_frozen_info`.`send_num` AS `send_num`,`gm`.`gm_frozen_info`.`status` AS `status`,`gm`.`gm_frozen_verify`.`reason` AS `reason` from (`gm`.`gm_frozen_info` join `gm`.`gm_frozen_verify` on((`gm`.`gm_frozen_info`.`vid` = `gm`.`gm_frozen_verify`.`id`))) where ((`gm`.`gm_frozen_info`.`status` in (0,2)) and (`gm`.`gm_frozen_info`.`send_num` < 10) and (`gm`.`gm_frozen_verify`.`status` = 1))
md5=e98f236e2b1e0bc73c4006b62701f9c4
updatable=1
algorithm=0
definer_user=root
definer_host=%
suid=1
with_check_option=0
timestamp=2024-03-08 06:33:53
create-version=1
source=select `gm_frozen_info`.`id` AS `id`,`gm_frozen_verify`.`type` AS `type`,`gm_frozen_verify`.`start_time` AS `start_time`,`gm_frozen_verify`.`end_time` AS `end_time`,`gm_frozen_info`.`uid` AS `uid`,`gm_frozen_info`.`send_time` AS `send_time`,`gm_frozen_info`.`send_num` AS `send_num`,`gm_frozen_info`.`status` AS `status`,`gm_frozen_verify`.`reason` AS `reason` from (`gm_frozen_info` join `gm_frozen_verify` on((`gm_frozen_info`.`vid` = `gm_frozen_verify`.`id`))) where ((`gm_frozen_info`.`status` in (0,2)) and (`gm_frozen_info`.`send_num` < 10) and (`gm_frozen_verify`.`status` = 1))
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_general_ci
view_body_utf8=select `gm`.`gm_frozen_info`.`id` AS `id`,`gm`.`gm_frozen_verify`.`type` AS `type`,`gm`.`gm_frozen_verify`.`start_time` AS `start_time`,`gm`.`gm_frozen_verify`.`end_time` AS `end_time`,`gm`.`gm_frozen_info`.`uid` AS `uid`,`gm`.`gm_frozen_info`.`send_time` AS `send_time`,`gm`.`gm_frozen_info`.`send_num` AS `send_num`,`gm`.`gm_frozen_info`.`status` AS `status`,`gm`.`gm_frozen_verify`.`reason` AS `reason` from (`gm`.`gm_frozen_info` join `gm`.`gm_frozen_verify` on((`gm`.`gm_frozen_info`.`vid` = `gm`.`gm_frozen_verify`.`id`))) where ((`gm`.`gm_frozen_info`.`status` in (0,2)) and (`gm`.`gm_frozen_info`.`send_num` < 10) and (`gm`.`gm_frozen_verify`.`status` = 1))
