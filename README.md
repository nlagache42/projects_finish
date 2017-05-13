# projects_finish
All 42 school projects

COREWAR
Le Corewar est un jeu très particulier. Il consiste à rassembler autour d’une "machine
virtuelle" des "joueurs", lesquels vont y charger des "champions" qui vont se
battre à l’aide de "processus", dans le but, entre autres, de faire en sorte qu’on dise
d’eux qu’ils sont "en vie".
• Les processus s’exécutent séquentiellement au sein de la même machine virtuelle,
et du même espace mémoire. Ils peuvent donc, entre autre chose, s’écrire les uns
sur les autres afin de se corrompre mutuellement, de forcer les autres à exécuter
des instructions qui leur font du mal, etc...
• Le jeu se termine quand plus aucun processus n’est en vie. À ce moment là, le
gagnant est le dernier joueur à avoir été rapporté comme étant "en vie".


FDF
Vous decouvrirez dans ce projet les bases de la programmation graphique, et en particulier,
le placement de points dans l’espace, comment les relier avec des segments et
surtout comment observer la scène depuis un certain point de vue.
Vous découvrirez également votre première bibliothèque graphique : La miniLibX.
Cette bibliothèque développée en interne rassemble le minimum nécéssaire pour ouvrir
une fenêtre, allumer un pixel et gérer les évènements lié à cette fenêtre : le clavier, la
souris et l’“expose”. Ce sera pour vous l’occasion de vous initier à la programmation dite
“evenementielle”. N’oubliez pas de regarder les vidéos sur l’e-learning !


FILLIT
Fillit ne consiste pas à recoder Tetris, mais reste une variante du jeu dans l’esprit.
Votre programme prendra en paramètre un fichier décrivant une liste de Tetriminos
qu’il devra ensuite agencer entre eux pour former le plus petit carré possible. Le but est
bien entendu de trouver ce plus petit carré le plus rapidement possible malgré un nombre
d’agencements qui croît de manière explosive avec chaque pièce supplémentaire.
Vous devrez donc bien réflechir à vos structures de données et à votre algorithme de
résolution pour que votre programme réponde rapidement.


FRACTOL
Ce projet consiste à créer un petit logiciel d’exploration fractale. Commencez donc
par voir ce qu’est une fractale.
Les contraintes sont les suivantes :
• Votre logiciel doit proposer au minimum 3 types de fractales différentes, dont au
moins l’ensemble de Julia et l’ensemble de Mandelbrot (soit au moins une troisième
fractale au choix).
• Il doit etre possible de faire varier avec la souris (sans clic) le paramètre de l’ensemble
de Julia. Pour les autres types de fractale, cela est laissé à votre discrétion.
• La molette de la souris permet de zoomer et dézoomer sur la position actuelle de
la souris, et cela de façon quasi infinie (modulo les limites de la machine). C’est
dans le principe même des fractales.
• Il doit y avoir un jeu de couleur minimum pour ressentir la profondeur de chaque
fractale. Mieux : lâchez-vous sur les effets psychédéliques.
• Un paramètre est passé en ligne de commande pour définir quel type de fractale
est à afficher. Si il n’y a pas de paramètre fourni, ou si le paramètre est invalide,
le programme affiche la liste des paramètres disponibles et quitte.
En ce qui concerne la représentation graphique :
• Vous devez utiliser la minilibX, dans sa version pour XQuartz installée par défaut
sur les dump, ou bien dans sa version native pour MacOS X.
• Vous devrez gérer l’expose correctement.
• La touche ESC permettra de quitter le programme.
• L’utilisation des images de la minilibX est fortement conseillée.


FT_PRINTF
Recoder la fonction printf existante


GET_NEXT_LINE
Ce projet va non seulement vous permettre d’ajouter une fonction très pratique à
votre collection, mais vous permettra également d’aborder un nouvel élément surprenant
de la programmation en C : les variables statiques.
Vous experimenterez également plus profondément les allocations, qu’elles aient lieu
sur la pile ou sur le tas, la manipulation et le cycle de vie d’un buffer, et la complexité
inattendue qu’implique l’utilisation d’une ou plusieurs variables statiques.
Bien entendu, vous renforcerez également votre rigueur grâce au respect de la Norme,
mais aussi en découvrant que l’état initial d’un variable dans une fonction peut varier
d’un appel à l’autre de cette fonction...


LEM_IN
On monte une fourmilière avec tout son lot de tunnels et de salles, on met des
fourmis d’un côté et on regarde comment elles trouvent la sortie.
Comment on monte une fourmilière ? On a besoin de tubes et de boîtes.
On relie les boîtes entre elles par plus ou moins de tubes. Un tube relie deux boîtes entre
elles et pas plus.
Une boîte peut être reliée à une infinité d’autres boîtes par autant de tubes qu’il en faudra.
Ensuite on enterre le tout (où vous voudrez) pour que les fourmis ne puissent pas tricher
en regardant avant de commencer.
Comme ici, on est pas trop bricolage à coup de boîtes, scotch et bouts de ficelle, on va
en faire une version high-tech.
Le but du projet sera donc de faire un simulateur de "Hex".


LIBFT
Réalisation d'une bibliotheque de multiples fonctions, utilisable par la suite dans divers projets.


PISCINE_PHP
Divers exercices de la piscine PHP, permettant de se familiariser avec le langage PHP/MySQL/HTML/CSS
Sous dossier RUSH : Réalisation d'un site web e-commerce avec base de donnée SQL, interface utilisateur, panier etc...


PUSH_SWAP
Le projet Push_swap est un projet d’algo simple et efficace : il faut trier. Vous avez
à votre disposition un ensemble d’entiers, deux piles, et un ensemble d’instructions pour
manipuler les piles.
Votre but ? Ecrire deux programmes en C :
• Un premier nommé checker qui prend des entiers en paramètres et qui lit des instructions
sur l’entrée standard. Une fois ces instructions lues, checker les exécute
puis affiche OK si les entiers sont triés, ou KO sinon.
• Un second nommé push_swap qui calcule et affiche sur la sortie standard le plus
petit programme dans le langage des instructions de Push_swap qui trie les entiers
passés en paramètre.


WOLF3D
Les objectifs de ce projet comprennent toujours les objectifs communs à tous les premiers
projets ayant lieu avant le stage : rigueur, pratique du C, pratique d’algos classiques,
recherche d’infos, exploitation de documentations, etc.
Étant un projet de programmation graphique, Wolf3D vous permettra également de
consolider vos acquis specifiques à cette discipline : les fenêtres, les couleurs, les events,
remplir des formes, etc.
Pour conclure, Wolf3d est un formidable terrain de jeu pour explorer les applications
vidéo-ludiques des mathématiques sans pour autant les comprendre en détails. John Carmack
est un genie pour avoir été l’un des premiers à y penser et reste célèbre pour ses
implémentations, mais à l’aide des très nombreuses documentations que vous trouverez
sur internet, les mathématiques ne seront pour vous qu’un outil pour créer des algorithmes
élégants et pourquoi pas, efficaces.
