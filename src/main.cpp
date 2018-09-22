#include <M5Stack.h>

#define BLACK 0

#define VOLUME_MAX 10
#define DURATION_MAX 3000

const uint16_t Melody[8] = {262, 294, 330, 349, 392, 440, 494, 523};
uint16_t Volume = 3;
uint16_t Duration = 500; //ms
uint8_t MelodyCnt = 0;

void beep(int hz, int ms){
  int start = millis();
  double freq = 1000.0 / hz;
  boolean sw = false;

  while(true){
    if(sw){
      dacWrite(25, Volume);
    }else{
      dacWrite(25, 0);
    }
    if(millis() - start > ms) break;
    sw = !sw;
    delayMicroseconds(freq * 1000);
  }
}

void updateVolumeDisplay(){
  M5.Lcd.fillRect(85, 0, 100, 16, 0);
  M5.Lcd.setCursor(85, 0);
  M5.Lcd.println(String(Volume));
}

void updateDurationDisplay(){
  M5.Lcd.fillRect(110, 16, 100, 16, 0);
  M5.Lcd.setCursor(110, 16);
  M5.Lcd.println(String(Duration) + "ms");
}

void setup(){
  M5.begin();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("Volume:");
  M5.Lcd.println("Duration:");
  updateVolumeDisplay();
  updateDurationDisplay();
}

void loop(){
  if(M5.BtnA.wasPressed()){
    Volume += 1;
    if(Volume > VOLUME_MAX){
      Volume = 0;
    }
    updateVolumeDisplay();
  }

  if(M5.BtnB.wasPressed()){
    Duration += 500;
    if(Duration > DURATION_MAX){
      Duration = 500;
    }
    updateDurationDisplay();
  }

  if(M5.BtnC.wasPressed()){
    beep(Melody[MelodyCnt], Duration);
    MelodyCnt += 1;
    if(MelodyCnt >= 8){
      MelodyCnt = 0;
    }
  }

  M5.update();
}
