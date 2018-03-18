import json
import requests
import os
from time import sleep
from pprint import pprint

def bot():
    server = "http://192.168.1.90:5000/"
    os.system("clear")
    print("\n")
    with open('./question_reponse.json', 'r') as json_data:
        histoire = json.load(json_data)
    v = 0
    r = requests.post(server+'enigme_bot/reload', data = {'reload': 'True'})
    while v != "1":
        r = requests.get(server+'enigme_bot')
        b = requests.get(server+'enigme_bot/reload')
        if b.text == "1":
            bot()
        v = r.text
        sleep(0.5)
    os.system('cvlc --no-audio --play-and-exit -V caca asciikingsmen1000.mp4')
    print(histoire['partie_1']['introduction']+"\n")
    partie = "partie_1"
    faut = 0
    while True:
        if b.text == "1":
            bot()
        try:
            b = requests.get(server+'enigme_bot/reload')
            var = input("#> ")
            if var in histoire[partie]['attendu']:
                if partie == "partie_2":
                    r = requests.post(server+'enigme_bot/bot/1', data = {'porte': '2', "etat": '1'})
                elif partie == "partie_3":
                    r = requests.post(server+'enigme_bot/bot/1', data = {'porte': '3', "etat": '1'})
                partie = histoire[partie]["reponse"]
                print("#>"+ histoire[partie]["introduction"])
            elif var == "exit":
                exit()
            elif var == "reboot":
                bot()
                 # goto check
            else:
                if len(histoire[partie]['reponse_erreur']) <= faut:
                    faut = 0
                print(histoire[partie]['reponse_erreur'][faut])
                faut += 1

        except KeyboardInterrupt:
            print("not working")
bot()
