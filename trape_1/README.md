# escape game guerande
  **trape 1**

      Arduino contrôlent la trappe d'ouverture permettent d’avoirs l’accès a l'énigme 2.
      Activable de puis la plateforme ou par l’énigme 1.


##  branchement

  + **branchement capteur**

pin | valeur  | description
:-:|:-:|:-:
D2 | ``` int interupteur = 2; ``` | branchement a un interrupteur pour une ouverture manuelle
D3 | ``` int porte = 3;``` | branchement au switch alimentation porte.

  + **communication bus**

pin | description
:-: |:-:
A4 | sda connexion
A5 | scl connexion
gnd | gnd connexion
