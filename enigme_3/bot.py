import json
import requests
import os
from time import sleep
from pprint import pprint

os.system("clear")
print("\n")
with open('./question_reponse.json', 'r') as json_data:
    histoire = json.load(json_data)
v = 0
while v != "1":
    r = requests.get('http://localhost:5000/enigme_bot')
    v = r.text
    sleep(0.5)
os.system('cvlc --no-audio --play-and-exit -V caca ascii-video-kingsmen480p.mov')
print(histoire['partie_1']['introduction']+"\n")
partie = "partie_1"

while True:
    try:
        var = input("#> ")
        if var in histoire[partie]['attendu']:
            x = histoire['partie_1']["reponse"][var]
            print("#>"+ histoire[x]["reponse"][var])
        if var == "exit":
            exit()
    except KeyboardInterrupt:
        print("not working")
