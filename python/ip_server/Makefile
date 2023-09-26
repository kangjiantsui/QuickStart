HOST=root@118.89.116.224
DEST_DIR=/projects/python-web-service
SRC_DIR=C:/workspace/QuickStart/python/ip_server/ip_server.py

deploy:
	@echo "Uploading ip_server.py to the server..."
	scp $(SRC_DIR) $(HOST):$(DEST_DIR)
	ssh root@118.89.116.224 'sudo systemctl restart ip-server.service'

