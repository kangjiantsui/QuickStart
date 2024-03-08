TYPE=VIEW
query=select `t`.`id` AS `id`,`t`.`type` AS `type`,`t`.`relation_id` AS `site_id`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts`,`st`.`site_name` AS `site_name`,`c`.`conf_value` AS `conf_value` from ((`gm`.`gm_trade` `t` join `gm`.`gm_site` `st`) join `gm`.`gm_game_conf` `c`) where ((`t`.`relation_id` = `st`.`site_id`) and (`t`.`type_id` = `c`.`conf_key`) and (`c`.`conf_type` in (\'item\',\'equip\')) and (`t`.`type` = 2))
md5=62c247794a5c6693ab56c8908fa6ada9
updatable=1
algorithm=0
definer_user=root
definer_host=%
suid=1
with_check_option=0
timestamp=2024-03-08 06:33:53
create-version=1
source=select `t`.`id` AS `id`,`t`.`type` AS `type`,`t`.`relation_id` AS `site_id`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts`,`st`.`site_name` AS `site_name`,`c`.`conf_value` AS `conf_value` from ((`gm_trade` `t` join `gm_site` `st`) join `gm_game_conf` `c`) where ((`t`.`relation_id` = `st`.`site_id`) and (`t`.`type_id` = `c`.`conf_key`) and (`c`.`conf_type` in (\'item\',\'equip\')) and (`t`.`type` = 2))
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_general_ci
view_body_utf8=select `t`.`id` AS `id`,`t`.`type` AS `type`,`t`.`relation_id` AS `site_id`,`t`.`type_id` AS `type_id`,`t`.`commerce_state` AS `commerce_state`,`t`.`booth_state` AS `booth_state`,`t`.`create_ts` AS `create_ts`,`t`.`update_ts` AS `update_ts`,`st`.`site_name` AS `site_name`,`c`.`conf_value` AS `conf_value` from ((`gm`.`gm_trade` `t` join `gm`.`gm_site` `st`) join `gm`.`gm_game_conf` `c`) where ((`t`.`relation_id` = `st`.`site_id`) and (`t`.`type_id` = `c`.`conf_key`) and (`c`.`conf_type` in (\'item\',\'equip\')) and (`t`.`type` = 2))
