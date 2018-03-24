#!/bin/bash


cp demarrage_server_game.sh /etc/init.d/server_game

chmod 755 /etc/init.d/server_game

update-rc.d  server_game defaults

update-rc.d server_game enable
