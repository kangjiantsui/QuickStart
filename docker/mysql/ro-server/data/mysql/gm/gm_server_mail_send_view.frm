TYPE=VIEW
query=select `gm`.`gm_server_mail`.`id` AS `id`,`gm`.`gm_server_mail`.`mail_title` AS `mail_title`,`gm`.`gm_server_mail`.`mail_content` AS `mail_content`,`gm`.`gm_server_mail`.`mail_template` AS `mail_template`,`gm`.`gm_server_mail`.`device_platform` AS `device_platform`,`gm`.`gm_server_mail`.`start_time` AS `start_time`,`gm`.`gm_server_mail`.`end_time` AS `end_time`,`gm`.`gm_server_mail`.`send_time` AS `send_time`,`gm`.`gm_server_mail`.`attachment` AS `attachment`,`gm`.`gm_server_mail`.`new_player` AS `new_player`,`gm`.`gm_server_mail`.`version` AS `version`,`gm`.`gm_server_mail`.`language` AS `language`,`gm`.`gm_server_mail`.`status` AS `status`,`gm`.`gm_server_mail_info`.`id` AS `sid`,`gm`.`gm_server_mail_info`.`site_id` AS `site_id`,`gm`.`gm_server_mail_info`.`server_id` AS `server_id`,`gm`.`gm_server_mail_info`.`send_num` AS `send_num`,`gm`.`gm_server_mail_info`.`status` AS `send_status`,`gm`.`gm_server_mail_info`.`game_mail_id` AS `game_mail_id`,`gm`.`gm_server_mail_info`.`revoke_num` AS `revoke_num`,`gm`.`gm_server_mail_info`.`revoke_status` AS `revoke_status`,`gm`.`gm_server_mail`.`region` AS `region` from (`gm`.`gm_server_mail_info` left join `gm`.`gm_server_mail` on((`gm`.`gm_server_mail_info`.`server_mail_id` = `gm`.`gm_server_mail`.`id`))) where (((`gm`.`gm_server_mail`.`status` = 1) and (`gm`.`gm_server_mail_info`.`status` in (0,2)) and (`gm`.`gm_server_mail_info`.`send_num` < 10)) or ((`gm`.`gm_server_mail`.`status` = 3) and (`gm`.`gm_server_mail_info`.`revoke_status` in (0,2)) and (`gm`.`gm_server_mail_info`.`revoke_num` < 10)))
md5=3dc8bf5ad83a73a75737daf0a484b91c
updatable=0
algorithm=0
definer_user=root
definer_host=%
suid=1
with_check_option=0
timestamp=2024-03-08 06:33:53
create-version=1
source=select `gm_server_mail`.`id` AS `id`,`gm_server_mail`.`mail_title` AS `mail_title`,`gm_server_mail`.`mail_content` AS `mail_content`,`gm_server_mail`.`mail_template` AS `mail_template`,`gm_server_mail`.`device_platform` AS `device_platform`,`gm_server_mail`.`start_time` AS `start_time`,`gm_server_mail`.`end_time` AS `end_time`,`gm_server_mail`.`send_time` AS `send_time`,`gm_server_mail`.`attachment` AS `attachment`,`gm_server_mail`.`new_player` AS `new_player`,`gm_server_mail`.`version` AS `version`,`gm_server_mail`.`language` AS `language`,`gm_server_mail`.`status` AS `status`,`gm_server_mail_info`.`id` AS `sid`,`gm_server_mail_info`.`site_id` AS `site_id`,`gm_server_mail_info`.`server_id` AS `server_id`,`gm_server_mail_info`.`send_num` AS `send_num`,`gm_server_mail_info`.`status` AS `send_status`,`gm_server_mail_info`.`game_mail_id` AS `game_mail_id`,`gm_server_mail_info`.`revoke_num` AS `revoke_num`,`gm_server_mail_info`.`revoke_status` AS `revoke_status`,`gm_server_mail`.`region` AS `region` from (`gm_server_mail_info` left join `gm_server_mail` on((`gm_server_mail_info`.`server_mail_id` = `gm_server_mail`.`id`))) where (((`gm_server_mail`.`status` = 1) and (`gm_server_mail_info`.`status` in (0,2)) and (`gm_server_mail_info`.`send_num` < 10)) or ((`gm_server_mail`.`status` = 3) and (`gm_server_mail_info`.`revoke_status` in (0,2)) and (`gm_server_mail_info`.`revoke_num` < 10)))
client_cs_name=utf8
connection_cl_name=utf8_general_ci
view_body_utf8=select `gm`.`gm_server_mail`.`id` AS `id`,`gm`.`gm_server_mail`.`mail_title` AS `mail_title`,`gm`.`gm_server_mail`.`mail_content` AS `mail_content`,`gm`.`gm_server_mail`.`mail_template` AS `mail_template`,`gm`.`gm_server_mail`.`device_platform` AS `device_platform`,`gm`.`gm_server_mail`.`start_time` AS `start_time`,`gm`.`gm_server_mail`.`end_time` AS `end_time`,`gm`.`gm_server_mail`.`send_time` AS `send_time`,`gm`.`gm_server_mail`.`attachment` AS `attachment`,`gm`.`gm_server_mail`.`new_player` AS `new_player`,`gm`.`gm_server_mail`.`version` AS `version`,`gm`.`gm_server_mail`.`language` AS `language`,`gm`.`gm_server_mail`.`status` AS `status`,`gm`.`gm_server_mail_info`.`id` AS `sid`,`gm`.`gm_server_mail_info`.`site_id` AS `site_id`,`gm`.`gm_server_mail_info`.`server_id` AS `server_id`,`gm`.`gm_server_mail_info`.`send_num` AS `send_num`,`gm`.`gm_server_mail_info`.`status` AS `send_status`,`gm`.`gm_server_mail_info`.`game_mail_id` AS `game_mail_id`,`gm`.`gm_server_mail_info`.`revoke_num` AS `revoke_num`,`gm`.`gm_server_mail_info`.`revoke_status` AS `revoke_status`,`gm`.`gm_server_mail`.`region` AS `region` from (`gm`.`gm_server_mail_info` left join `gm`.`gm_server_mail` on((`gm`.`gm_server_mail_info`.`server_mail_id` = `gm`.`gm_server_mail`.`id`))) where (((`gm`.`gm_server_mail`.`status` = 1) and (`gm`.`gm_server_mail_info`.`status` in (0,2)) and (`gm`.`gm_server_mail_info`.`send_num` < 10)) or ((`gm`.`gm_server_mail`.`status` = 3) and (`gm`.`gm_server_mail_info`.`revoke_status` in (0,2)) and (`gm`.`gm_server_mail_info`.`revoke_num` < 10)))