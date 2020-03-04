#include "robot_sumo.h"

// Moteur A
#define pwma 3
#define ain1 9
#define ain2 10

// Moteur B
#define pwmb 5
#define bin1 7
#define bin2 6

#define STBY 8
//capteur ultrason
#define trig 12
#define echo 11
//capteur infrarouge
#define capteur_avant_gauche A2
#define capteur_centre A1
#define capteur_avant_droit A0
#define capteur_arriere_droit A7
#define capteur_arriere_gauche A6


robot_sumo::robot_sumo(bool test = false) {
	if (test) {
	
}
};
//fonction d'initialisation de tout les pins
void robot_sumo::begin(int seuil) {
	pinMode(pwma, OUTPUT);
	pinMode(ain1, OUTPUT);
	pinMode(ain2, OUTPUT);

	pinMode(pwmb, OUTPUT);
	pinMode(bin1, OUTPUT);
	pinMode(bin2, OUTPUT);

	pinMode(STBY, OUTPUT);

	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);

	pinMode(capteur_avant_droit, INPUT);
	pinMode(capteur_avant_gauche, INPUT);
	pinMode(capteur_centre, INPUT);
	pinMode(capteur_arriere_gauche, INPUT);
	pinMode(capteur_arriere_droit, INPUT);
	Serial.begin(9600);

	Serial.println("library initialized !");

	int _seuil = seuil;
  }

void robot_sumo::AG(int vitesseG) {

	if (vitesseG < 0) _vitesseG = (vitesseG - (2 * vitesseG));
	if (vitesseG > 0) _vitesseG = vitesseG;

	analogWrite(pwma, _vitesseG);
	digitalWrite(STBY, HIGH);

	if (vitesseG > 0) {
		digitalWrite(ain1, HIGH);
		digitalWrite(ain2, LOW);
	}

	if (vitesseG < 0) {
	analogWrite(pwma, 100);
		digitalWrite(ain1, LOW);
		digitalWrite(ain2, HIGH);
	}
	
	Serial.println("AG");
}

void robot_sumo::AD(int vitesseD) {

	if (vitesseD < 0) _vitesseD = (vitesseD - (2 * vitesseD));
	if (vitesseD > 0) _vitesseD = vitesseD;

	analogWrite(pwma, _vitesseD);
	digitalWrite(STBY, HIGH);

	if (vitesseD > 0) {
		digitalWrite(bin1, HIGH);
		digitalWrite(bin2, LOW);
	}

	if (vitesseD < 0) {
		digitalWrite(bin1, LOW);
		digitalWrite(bin2, HIGH);
	}
	Serial.println("AD");

}

void robot_sumo::Stop() {

	digitalWrite(ain1, HIGH);
	digitalWrite(ain2, HIGH);

	digitalWrite(bin1, HIGH);
	digitalWrite(bin2, HIGH);
	Serial.println("Stop");
}

float robot_sumo::ultrason() {

	digitalWrite(trig, HIGH);

	delayMicroseconds(10);

	digitalWrite(trig, LOW);

	long _duree = pulseIn(echo, HIGH);
	float distance = (_duree / 2) / 29.1;
	return distance;
	Serial.println("ultrason");
}

String robot_sumo::Acouleur() {

	int c1 = analogRead(capteur_avant_droit);
	int c2 = analogRead(capteur_avant_gauche);
	int c3 = analogRead(capteur_centre);

	String couleurretenue;

	if (c1 > 200 & c2 > 200 & c3 > 200) {
		couleurretenue = "Noir";
	}
	else if (c1 <= 200 || c2 <= 200 || c3 <= 200) {
		couleurretenue = "Blanc";
	}
	return couleurretenue;
}

String robot_sumo::Rcouleur() {	

	int c4 = analogRead(capteur_arriere_gauche);
	int c5 = analogRead(capteur_arriere_droit);

	String couleurretenue;

		if (c4 > 200 & c5 > 200) {
			couleurretenue = "Noir";
		}
		else if (c4 <= 200 || c5 <= 200) {
			couleurretenue = "Blanc";
		}
		return couleurretenue;
	}

