# Far_distance_light_switch
## English 
### Material :
- NRF 24LO1
- Arduino Uno
- Arduino Nano
- Breadboard
- Mini breadboard
- 14 male to female wires
- 14 male to male wires
- 2 10 KΩ resistors
- 2 buttons
- Double sided tape
- 2 servo motors
- 2 screws
- 9 volt batteries
### 3D printing Info :
The STL file posted might not work on every light switch since the shape and size varies from house to house, so before printing it is better to check if the measurments are aligned with the shape of your switch. It is still in its prototype phase so the servo motors might not fit properly depending on the used printer.
### Assembly Info :
1. Upload the transmitter code to the arduino Nano the proceed to the wiring.
2. Upload the receiver code to the arduino Uno.
3. Screw the servo motor heads and use tape to stick the servo motors to the holes of the printed part.
4. Use the double sided tape to stick the components and 3D printed piece to the Wall.
5. Adjust the initial and final angles of the servo motors since the angles required to turn of a switch could vary from house to house (the code to modify is indicated on the c++ file).
### Important Info :
This is a prototype and might not work if the light switches require more strenght than the one that a servo motor can produce. Changing the angles could in some cases fix the problem.
### Credit for the code :
A part of the code for the NRF 24L01 was taken a modified from the channel called "How To Mehatronics".
## Français
### Materiel :
- NRF 24LO1
- Arduino Uno
- Arduino Nano
- Plaque d'essai
- Mini plaque d'essai
- 14 cables male à femelle
- 14 cables male à male 
- 2 résistances 10 KΩ 
- 2 bouttons
- Ruban adhésif double face
- 2 servomoteur
- 2 vis (pour les têtes des moters)
- batterie 9 volt (pour le arduino Uno)
### Info pour l'impression 3D :
Le fichier STL ne marche pas sur tout les interupters plus que les formes et tailles varient entre différents maisons, ils faut donc s'assurer avant d'imprimer que les mesures soient cohérentes avant d'imprimer. Ce projet est toujours un prototypes donc la piece imprimée en 3D peut ne pas être parfaitement ajusté pour les servomoteur dépendement de l'imprimante 3D.
### Info sur l'assemblage :
1. Télécharger le code du transmitteur dans le arduino Nano et faire le cablage.
2. Télécharger le code du récepteur sur l'arduino Uno.
3. Visser les têtes du servomoteurs et utiliser du ruban adhésif à double face pour mettre les servomotteurs dans les tours de la pièce imprimée.
6. Utiliser le ruban adhésif à double face pour coller les pièces au murs.
7. Ajuster les angles initiaux et finaux du servomotteurs plus que les angles requis pour éteindre lumière peut varier de maison en maison (le code pour le modifier est indiqué sur le fichiers c++).
### Info Importante :
C'est un prototype qui peut ne pas marcher parfaitement sur certains interupteurs s'il a besion de plus de force que possède les servomotteurs. Changer les angles dans quelques cas peut arranger le problème.
### Crédits pour le code :
Une part du code pour le modules NRF 24L01 est prise de la chaîne "How To Mechatronics" sur youtube et a été modifié pour mon projet
