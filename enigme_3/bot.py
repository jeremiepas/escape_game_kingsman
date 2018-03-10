import json
import requests
import os
from time import sleep
from pprint import pprint
server = "http://192.168.1.90:5000/"
os.system("clear")
print("\n")
with open('./question_reponse.json', 'r') as json_data:
    histoire = json.load(json_data)
v = 0
while v != "1":
    r = requests.get(server+'enigme_bot')
    v = r.text
    sleep(0.5)
os.system('cvlc --no-audio --play-and-exit -V caca Connexion.mp4')
print(histoire['partie_1']['introduction']+"\n")
partie = "partie_1"

while True:
    try:
        var = input("#> ")
        if var in histoire[partie]['attendu']:
            x = histoire['partie_1']["reponse"][var]
            print("#>"+ histoire[x]["reponse"][var])
        if var == "404":
            r = requests.post(server+'enigme_bot/bot/1', data = {'porte': '2', "etat": "1"})
            print("#> "+ r.text)
        if var == "9467":
            r = requests.post(server+'enigme_bot/bot/1', data = {'porte': '3', "etat": '1'})
            print("#> oki")
        if var == "exit":
            exit()
    except KeyboardInterrupt:
        print("not working")
