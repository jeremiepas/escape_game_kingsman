# escape Game Guérande
## énigme 4 échec et math

    place le roi,  la reine, le cavalier et le fou pour  mettre le roi en échec.
    le roi ce déplace a l'aide d'un moteur cache, il est tracte par un aimant
    une fois déplace il faut mettre le rois en échec et math pour faire apparaître un code.


####  branchement

  * branchement capteur

    ```

    D12 = pin permettent de le resetage de la carte a partir d'un envoie de signale bus.
    D3 = pin connexion au capteur switch magnétique pour la raine
    D4 = pin connexion au capteur switch magnétique pour le roi
    A0 = pin connexion au capteur  magnétique pour le fou;
    A1 = pin connexion au capteur  magnétique pour le premier placement du cavalier;
    A2 = pin connexion au capteur  magnétique pour le deuxième placement du cavalier

    ```

  * communication bus

    ```
      A4 = sda connexion
      A5 = scl connexion
      gnd = gnd connexion

    ```
