nohup dlv --listen=:2345 --headless=true --api-version=2 --continue --accept-multiclient exec ./go -- -env=test -service=login,msgq,game,fusion,agent,debug &
