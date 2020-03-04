#ifndef tl
#define tl

#if (ARDUINO >=100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class robot_sumo  {
  public:
	robot_sumo(bool test=false);    
    void begin(const int seuil);
	void AG(int vitesseG);
	void AD(int vitesseD);
	void Stop();
	float ultrason();
	String Acouleur();
	String Rcouleur();
    

  private:
	  int _seuil;
	  int _vitesseG;
	  int _vitesseD;
	  long _duree;
};
#endif
