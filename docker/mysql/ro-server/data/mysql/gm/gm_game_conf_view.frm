TYPE=VIEW
query=select `gm`.`gm_language`.`lang_type` AS `lang_type`,`gm`.`gm_game_conf`.`conf_type` AS `conf_type`,`gm`.`gm_game_conf`.`conf_key` AS `conf_key`,`gm`.`gm_language`.`lang_name` AS `conf_value`,`gm`.`gm_language`.`lang_value` AS `language` from (`gm`.`gm_language` left join `gm`.`gm_game_conf` on((`gm`.`gm_game_conf`.`conf_value` = `gm`.`gm_language`.`lang_name`))) where (`gm`.`gm_language`.`visible` = 1)
md5=ee8d6287da9e840b1b94005b151138bb
updatable=0
algorithm=0
definer_user=root
definer_host=%
suid=1
with_check_option=0
timestamp=2024-03-08 06:33:53
create-version=1
source=select `gm_language`.`lang_type` AS `lang_type`,`gm_game_conf`.`conf_type` AS `conf_type`,`gm_game_conf`.`conf_key` AS `conf_key`,`gm_language`.`lang_name` AS `conf_value`,`gm_language`.`lang_value` AS `language` from (`gm_language` left join `gm_game_conf` on((`gm_game_conf`.`conf_value` = `gm_language`.`lang_name`))) where (`gm_language`.`visible` = 1)
client_cs_name=utf8mb4
connection_cl_name=utf8mb4_general_ci
view_body_utf8=select `gm`.`gm_language`.`lang_type` AS `lang_type`,`gm`.`gm_game_conf`.`conf_type` AS `conf_type`,`gm`.`gm_game_conf`.`conf_key` AS `conf_key`,`gm`.`gm_language`.`lang_name` AS `conf_value`,`gm`.`gm_language`.`lang_value` AS `language` from (`gm`.`gm_language` left join `gm`.`gm_game_conf` on((`gm`.`gm_game_conf`.`conf_value` = `gm`.`gm_language`.`lang_name`))) where (`gm`.`gm_language`.`visible` = 1)
