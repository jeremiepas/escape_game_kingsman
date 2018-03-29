#!/bin/sh
start()
{
  export LANG=C.UTF-8
  export LC_ALL=C.UTF-8
  export FLASK_APP=app.py

  cd /home/pi/server_escape_game/app_led

  pidflask = flask run --host=0.0.0.0 &

  pidenigme = python3 gestion_enigme.py &
}
stop()
{
     # Mettez ici un kill sur votre programme
	kill pidenigme
  kill pidflask
}

restart()
{
    stop;
    sleep 1;
    start;
}
case $1 in
start)
      start;;
stop)
      stop;;
restart)
      restart;;
*)
      start;;
esac
