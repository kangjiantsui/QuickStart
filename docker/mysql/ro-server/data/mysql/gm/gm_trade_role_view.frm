TYPE=VIEW
query=select `t`.`id` AS `id`,`t`.`type` AS `type`,`sr`.`site_id` AS `site_id`,`st`.`site_name` AS `site_name`,`t`.`relation_id` AS `server_id`,`sr`.`name` AS `server_name`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts` from ((`gm`.`gm_trade` `t` join `gm`.`gm_server` `sr`) join `gm`.`gm_site` `st`) where ((`t`.`relation_id` = `sr`.`server_id`) and (`sr`.`site_id` = `st`.`site_id`) and (`t`.`type` = 3))
md5=4ebbabd6424269f1cae1bc7525062b3d
updatable=1
algorithm=0
definer_user=root
definer_host=%
suid=1
with_check_option=0
timestamp=2024-03-08 06:33:53
create-version=1
source=select `t`.`id` AS `id`,`t`.`type` AS `type`,`sr`.`site_id` AS `site_id`,`st`.`site_name` AS `site_name`,`t`.`relation_id` AS `server_id`,`sr`.`name` AS `server_name`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts` from ((`gm_trade` `t` join `gm_server` `sr`) join `gm_site` `st`) where ((`t`.`relation_id` = `sr`.`server_id`) and (`sr`.`site_id` = `st`.`site_id`) and (`t`.`type` = 3))
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_general_ci
view_body_utf8=select `t`.`id` AS `id`,`t`.`type` AS `type`,`sr`.`site_id` AS `site_id`,`st`.`site_name` AS `site_name`,`t`.`relation_id` AS `server_id`,`sr`.`name` AS `server_name`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts` from ((`gm`.`gm_trade` `t` join `gm`.`gm_server` `sr`) join `gm`.`gm_site` `st`) where ((`t`.`relation_id` = `sr`.`server_id`) and (`sr`.`site_id` = `st`.`site_id`) and (`t`.`type` = 3))
