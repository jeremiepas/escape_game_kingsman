#! /bin/sh

export LANG=C.UTF-8
export LC_ALL=C.UTF-8
export FLASK_APP=app.py

cd /home/pi/server_escape_game/app_led

flask run --host=0.0.0.0 &

python3 gestion_enigme.py &
