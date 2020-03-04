instalation de la librairie :

-créer un nouveau dossier "robot_sumo" dans le dossier librairies de l'IDe arduino

-telecharger les quatres fichier

-copier tous les fichiers dans le dossier "robot_sumo"


fonctionnement de la librairie :

initialisation :

	robot_sumo robot();  
 
	robot_sumo.begin(seuil des capteurs infrarouge);

commande du robot :
	
	robot.AG(vitesse);	fait tourner le moteur gauche vers l'avant si la vitesse est positive et vers l'arriere si la vitesse est negative
	
	robot.AD(vitesse);	meme chose que .AG mais pour le moteur droit
	
	robot.Stop();		arrete tous les moteurs
	
	robot.ultrason();	retourne la distance du capteur ultrason en CM
	
	robot.Acouleur();	retourne la couleur des capteurs infrarouge de devant
	
	robot.Rcouleur();	meme chose que acouleur mais pour l'arriere 