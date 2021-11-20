# dwp-assistant
DWP Home Assistant Config


Step to run Home-Assistant
1. set timezone and create timezone symlink
```
sudo timedatectl set-timezone Asia/Jakarta

sudo ln -s /usr/share/zoneinfo/Asia/Jakarta /etc/localtime

date
```

2. create docker compose to run home-assistant on container

3. create config file `configuration.yml`

4. 