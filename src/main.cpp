#include <M5Stack.h>

#define C4 262 //do
#define D4 294 //le
#define E4 330 //mi
#define VOLUME 3 //0 to 255

void beep(int hz, int ms){
  int start = millis();
  double freq = 1000.0 / hz;
  boolean sw = false;

  while(true){
    if(sw){
      dacWrite(25, VOLUME);
    }else{
      dacWrite(25, 0);
    }
    if(millis() - start > ms) break;
    sw = !sw;
    delayMicroseconds(freq * 1000);
  }
}

void setup(){
  M5.begin();
}

void loop(){
  if(M5.BtnA.wasPressed()){
    beep(C4, 500);
  }

  if(M5.BtnB.wasPressed()){
    beep(D4, 500);
  }

  if(M5.BtnC.wasPressed()){
    beep(E4, 500);
  }

  M5.update();
}
