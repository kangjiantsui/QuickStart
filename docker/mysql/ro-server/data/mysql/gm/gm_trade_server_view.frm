TYPE=VIEW
query=select `sr`.`server_id` AS `server_id`,`sr`.`name` AS `server_name`,`s`.`site_id` AS `site_id`,`s`.`site_name` AS `site_name`,`t`.`id` AS `id`,`t`.`type` AS `type`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts` from ((`gm`.`gm_server` `sr` left join `gm`.`gm_site` `s` on((`sr`.`site_id` = `s`.`site_id`))) left join `gm`.`gm_trade` `t` on(((`sr`.`server_id` = `t`.`relation_id`) and (`t`.`type` = 1))))
md5=b6076c2a441f05aa3e6e7e6c6cd76755
updatable=0
algorithm=0
definer_user=root
definer_host=%
suid=1
with_check_option=0
timestamp=2024-03-08 06:33:53
create-version=1
source=select `sr`.`server_id` AS `server_id`,`sr`.`name` AS `server_name`,`s`.`site_id` AS `site_id`,`s`.`site_name` AS `site_name`,`t`.`id` AS `id`,`t`.`type` AS `type`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts` from ((`gm_server` `sr` left join `gm_site` `s` on((`sr`.`site_id` = `s`.`site_id`))) left join `gm_trade` `t` on(((`sr`.`server_id` = `t`.`relation_id`) and (`t`.`type` = 1))))
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_general_ci
view_body_utf8=select `sr`.`server_id` AS `server_id`,`sr`.`name` AS `server_name`,`s`.`site_id` AS `site_id`,`s`.`site_name` AS `site_name`,`t`.`id` AS `id`,`t`.`type` AS `type`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts` from ((`gm`.`gm_server` `sr` left join `gm`.`gm_site` `s` on((`sr`.`site_id` = `s`.`site_id`))) left join `gm`.`gm_trade` `t` on(((`sr`.`server_id` = `t`.`relation_id`) and (`t`.`type` = 1))))
