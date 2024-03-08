TYPE=VIEW
query=select `gm`.`gm_trade_info`.`id` AS `id`,`gm`.`gm_trade_info`.`trade_id` AS `trade_id`,`gm`.`gm_trade`.`type` AS `type`,`gm`.`gm_trade`.`relation_id` AS `relation_id`,`gm`.`gm_trade`.`type_id` AS `type_id`,`gm`.`gm_trade_info`.`operation_type` AS `operation_type`,`gm`.`gm_trade_info`.`operation_state` AS `operation_state`,`gm`.`gm_trade_info`.`send_time` AS `send_time`,`gm`.`gm_trade_info`.`send_num` AS `send_num`,`gm`.`gm_trade_info`.`status` AS `status` from (`gm`.`gm_trade_info` join `gm`.`gm_trade` on((`gm`.`gm_trade_info`.`trade_id` = `gm`.`gm_trade`.`id`))) where ((`gm`.`gm_trade_info`.`status` in (0,2)) and (`gm`.`gm_trade_info`.`send_num` < 10))
md5=406d79aeca5d92f14006c949d23c914f
updatable=1
algorithm=0
definer_user=root
definer_host=%
suid=1
with_check_option=0
timestamp=2024-03-08 06:33:53
create-version=1
source=select `gm_trade_info`.`id` AS `id`,`gm_trade_info`.`trade_id` AS `trade_id`,`gm_trade`.`type` AS `type`,`gm_trade`.`relation_id` AS `relation_id`,`gm_trade`.`type_id` AS `type_id`,`gm_trade_info`.`operation_type` AS `operation_type`,`gm_trade_info`.`operation_state` AS `operation_state`,`gm_trade_info`.`send_time` AS `send_time`,`gm_trade_info`.`send_num` AS `send_num`,`gm_trade_info`.`status` AS `status` from (`gm_trade_info` join `gm_trade` on((`gm_trade_info`.`trade_id` = `gm_trade`.`id`))) where ((`gm_trade_info`.`status` in (0,2)) and (`gm_trade_info`.`send_num` < 10))
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_general_ci
view_body_utf8=select `gm`.`gm_trade_info`.`id` AS `id`,`gm`.`gm_trade_info`.`trade_id` AS `trade_id`,`gm`.`gm_trade`.`type` AS `type`,`gm`.`gm_trade`.`relation_id` AS `relation_id`,`gm`.`gm_trade`.`type_id` AS `type_id`,`gm`.`gm_trade_info`.`operation_type` AS `operation_type`,`gm`.`gm_trade_info`.`operation_state` AS `operation_state`,`gm`.`gm_trade_info`.`send_time` AS `send_time`,`gm`.`gm_trade_info`.`send_num` AS `send_num`,`gm`.`gm_trade_info`.`status` AS `status` from (`gm`.`gm_trade_info` join `gm`.`gm_trade` on((`gm`.`gm_trade_info`.`trade_id` = `gm`.`gm_trade`.`id`))) where ((`gm`.`gm_trade_info`.`status` in (0,2)) and (`gm`.`gm_trade_info`.`send_num` < 10))
