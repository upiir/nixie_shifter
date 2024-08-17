// Learn how to create a custom 3D printed shifter knob with Nixie Tube display

// created by upir, 2024
// youtube channel: https://www.youtube.com/upir_upir

// YOUTUBE VIDEO: https://youtu.be/_gC2J5ZqJfQ
// SOURCE files: https://github.com/upiir/nixie_shifter/

// Links from the video:
// Do you like this video? You can buy me a coffee ☕: https://www.buymeacoffee.com/upir
// BambuLab X1C printer: https://shareasale.com/r.cfm?b=2353821&u=3422904&m=138211&urllink=&afftrack=
// Buy EasyNixie (10% discount: 193A891C): https://www.tindie.com/products/allexok/easynixie/ 
// IN12A Nixie Tube: https://s.click.aliexpress.com/e/_DlUjPK7
// IN15A/B Nixie Tube: https://s.click.aliexpress.com/e/_DmaUnEj
// IN17 Nixie Tube: https://s.click.aliexpress.com/e/_DDCYMux
// Nixie Radio Project Video: https://www.youtube.com/watch?v=4qMpQlD0UOU
// YouTube tutorial: https://www.youtube.com/watch?v=-vvVOH5VGAM&t=5s&ab_channel=OKuTech
// GitHub with library: https://github.com/allexoK/EasyNixie/
// Breadboard wires: https://s.click.aliexpress.com/e/_Dkbngin
// Arduino UNO: https://s.click.aliexpress.com/e/_AXDw1h
// Arduino breadboard prototyping shield: https://s.click.aliexpress.com/e/_ApbCwx
// Arduino Breadboard: https://s.click.aliexpress.com/e/_DegBvPl
// EasyNixie Kickstarter: https://www.kickstarter.com/projects/esp32-stick/easynixie
// Dalibor Farny Nixie tubes: https://www.daliborfarny.com/
// MOMO shifter knob: https://s.click.aliexpress.com/e/_DnKeTPb
// Car shifter keyring: https://s.click.aliexpress.com/e/_DkjX6eL

// Related videos:
// Custom Shifter Knob with Display: https://www.youtube.com/playlist?list=PLjQRaMdk7pBb6r6xglZb92DGyWJTgBVaV
// CHEAP DIY BOOST GAUGE: https://youtu.be/cZTx7T9uwA4
// Pitch Roll Indicator: https://youtu.be/S_ppdbb0poQ
// Nixie Tube Clock Without Nixie Tubes: https://youtu.be/cbU3y4pe4FQ
// 1 clocks, 194 400 pixels: https://youtu.be/Q-yf9hQRpU4
// 100 Themes in 1 Hour: https://youtu.be/F6b85vHGwGI
 
#include "EasyNixie.h" // include EasyNixie library - install from GitHub:
#define OUT_EN 3   //connect Pin ArduinoUNO 3 to OUT_EN
#define SHCP   2   //connect Pin ArduinoUNO 2 to SHCP
#define STCP   6   //connect Pin ArduinoUNO 6 to STCP
#define DSIN   7   //connect Pin ArduinoUNO 7 to DSIN

// connection:
// VPOWER >> +5v, min 420mA power supply
// GND >> power supply GND
// DSIN >>pin.7
// DSOUT >> no connection (if you use more modules, connect this pin to DSIN EasyNixie of the next module in chain)
// STCP >> pin.6
// SHCP >> pin.2
// OUT_EN >> pin.3
// VLOGIC >> 5v/3,3v (its depended from your board)

EasyNixie en(OUT_EN,SHCP, STCP, DSIN); //Initialisation 'en' protocole

void setup() 
{
  Serial.begin(115200);
}
void loop()                          //Writing 0-9 number Value
{
  for (uint8_t i = 0; i <= 9; i++)      
  {                                  
    en.SetNixie(i,5,true,true,0);    //en.SetNixie(NixieNubmer , Color , ON/Off_Nixie);   Set color= 5= Purple; dimming=0 - max brightness
    en.Latch();                      //Send your set to EaseNixie 

    Serial.print("'i' is equal: ");  //Print to COM actual Value
    Serial.println(i);
    delay(1400);                     //Wait 1,4sec  
  }  
  
}
