# escape game guerande
## enigme 2 switch et jack communication

active tous les switch dans le bonne ordre pour allume une LED et active les branchement.
une fois les branchement jack active une LED s'allume l’énigme est fini et une information est envoyé par le port bus.


####  branchement

  * branchement capteur
    ```
    D2 = le circuit des switch;
    D3 = le circuit des branchements jack;
    D4 = la led qui s'allume une fois les switch mis dans la bonne position;
    D5 la led qui s'allume une les jack branche;
    ```
  * communication bus
    ```
      A4 = sda connexion
      A5 = scl connexion
    ```
