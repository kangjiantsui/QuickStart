docker stats $(docker ps --format '{{.Names}}')
read -r -p "Press [Enter] key to continue..."
