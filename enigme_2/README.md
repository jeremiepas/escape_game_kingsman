# escape game guerande
  ** enigme 2 switch et jack communication **

    active tous les switch dans le bonne ordre pour allume une LED et active les branchement.
    une fois les branchement jack active une LED s'allume
    l’énigme est fini et une information est envoyé par le port bus.


##  branchement

  + ** branchement capteur **

pin | valeur  | description
- |:-: | :-:
D2 | ``` int etape_1 = 2; ``` | branchement de l’étape un valeur reçu boolean
D3 | ``` int etape_2 = 3; ``` | branchement de l’étape valeur reçu boolean
D4 | ``` int led_1   = 4; ``` | branchement d'une led vérification de l’étape 1 une fois fini la led s'allume
D5 | ``` int led_2   = 5; ``` | branchement d'une led vérification de l’étape 2 une fois fini la led s'allume
D6 | ```  int trape   = 6; ``` |  branchement de la commande d'ouverture de trape 


  + ** communication bus **

pin | description
:-: |:-:
A4 | sda connexion
A5 | scl connexion
gnd | gnd connexion
