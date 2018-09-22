#include <M5Stack.h>

#define C4 262 //ド
#define D4 294 //レ
#define E4 330 //ミ
#define DUR 200 //ms

void setup() {
  M5.begin();
}

void loop() {
  if(M5.BtnA.wasPressed()){
    M5.Speaker.tone(C4, DUR);
  }

  if(M5.BtnB.wasPressed()){
    M5.Speaker.tone(D4, DUR);
  }

  if(M5.BtnC.wasPressed()){
    M5.Speaker.tone(E4, DUR);
  }

  M5.update();
}