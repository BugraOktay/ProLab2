#include <Wire.h>
#include <Adafruit_GFX.h> // grafik tabanli projeler icin
#include <Adafruit_SSD1306.h> // metin tabanli projeler icin
#define SCREEN_WIDTH 128 // genislik
#define SCREEN_HEIGHT 64 // yukseklik

static const unsigned char PROGMEM gemi[]={0x00, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x66, 0xff};
static const unsigned char PROGMEM engel[]={0x00, 0x3c, 0x5a, 0x66, 0x66, 0x5a, 0x3c, 0x00};
static const unsigned char PROGMEM engel1[]={0x7e, 0xbd, 0xdb, 0xe7, 0xe7, 0xdb, 0xbd, 0x7e};
static const unsigned char PROGMEM hp[]={0x00, 0x18, 0x18, 0x7e, 0x7e, 0x18, 0x18, 0x00};
static const unsigned char PROGMEM kalkan[]={0x00, 0x3c, 0x5a, 0x5a, 0x42, 0x5a, 0x3c, 0x00};
static const unsigned char PROGMEM odul[]={0x18, 0x24, 0x5a, 0xa5, 0xa5, 0x5a, 0x24, 0x18};
static const unsigned char PROGMEM silah[]={0x03, 
0x07, 
0x0e, 
0xdc, 
0xf8, 
0x70, 
0xf8, 
0xd8};

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int a[64];
int b[64];
int z1,z2,z3,z4,z5,z6,z7,z8,z9=0;
int hiz =500;
int x=0;
int y=0;
int can=100;

int potpin=A0;
int buzzerpin=8;
int potValue=0;
int mapValue=0;
int led1=11;
int led2=12;
int led3=13;
int mil1;
int mil2;


void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // i2c adresi
    Serial.println(F("SSD1306 baglanti prob"));
    for(;;);
  }
  pinMode(potpin,INPUT);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.setRotation(3);
  for(int i=0;i<64;i++){
    a[i]=0;
  }
  for(int i=0;i<64;i++){
    b[i]=16+y;
    y+=8;
  }
  
  pinMode(buzzerpin,OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
}



void loop() {
  unsigned long mil=millis();
  mil1=millis();
  potValue=analogRead(potpin);
  
  mapValue=map(potValue,0,1023,0,7);
  display.drawBitmap(8*mapValue,120,gemi,8,8,1);


  int saniye =mil/hiz;
  
  digitalWrite(buzzerpin, LOW);
  
  nesne_getir(0,1,mapValue);    
  if(saniye>x){
    a[0]+=8;
    x++;   
  }
  
  
  
  for(int i=0;i<60;i++){
    if(i+2>43){
      nesne_getir(i+1,62-i,mapValue); 
      f_1(0,i,i+1);      
    }
    else if(i+2>21){
      nesne_getir(i+1,42-i,mapValue); 
      f_1(0,i,i+1);
    }
    else{
      nesne_getir(i+1,i+2,mapValue); 
      f_1(0,i,i+1);
      }
  }
  

 
  display.display();
  
  display.clearDisplay();

  
  



}

  void f_1(int i, int j, int k){ 
    if(a[i]>=b[j]){
     a[k]+=8;  
     b[j]+=8;
    }
  }
  
  
  void nesne_getir(int i, int r, int mapValue){

    

    if(r==1){
   if(a[i]==120){
      if(8*mapValue==8 || 8*mapValue==16 || 8*mapValue==32 || 8*mapValue==40 || 8*mapValue==48){
        digitalWrite(buzzerpin, HIGH);
       
        digitalWrite(led1, LOW);
      }
    }
   display.drawBitmap(8,a[i],engel,8,8,1);
   display.drawBitmap(16,a[i],engel,8,8,1);
   display.drawBitmap(32,a[i],engel,8,8,1);
   display.drawBitmap(40,a[i],engel,8,8,1);
   display.drawBitmap(48,a[i],engel,8,8,1);
   
    }
    if(r==3){
   if(a[i]==120){
      if(8*mapValue==0 || 8*mapValue==16 || 8*mapValue==32 || 8*mapValue==48){
        digitalWrite(buzzerpin, HIGH);}
        
        
      }
   display.drawBitmap(0,a[i],engel,8,8,1);
   display.drawBitmap(16,a[i],engel,8,8,1);
   display.drawBitmap(32,a[i],engel,8,8,1);
   display.drawBitmap(48,a[i],engel,8,8,1);
    
    }
    if(r==5){
   if(a[i]==120){
      if(8*mapValue==8 || 8*mapValue==24 ||  8*mapValue==40 || 8*mapValue==56){
        digitalWrite(buzzerpin, HIGH);}
        
      }
   display.drawBitmap(8,a[i],engel,8,8,1);
   display.drawBitmap(24,a[i],engel,8,8,1);
   display.drawBitmap(40,a[i],engel,8,8,1);
   display.drawBitmap(56,a[i],engel,8,8,1); 
    }
    if(r==7){
      if(a[i]==120){
      if(8*mapValue==0 || 8*mapValue==8 || 8*mapValue==32 || 8*mapValue==56 ){
        digitalWrite(buzzerpin, HIGH);}
        
      }
   display.drawBitmap(0,a[i],engel,8,8,1);
   display.drawBitmap(8,a[i],engel,8,8,1);
   display.drawBitmap(32,a[i],engel,8,8,1);
   display.drawBitmap(56,a[i],engel,8,8,1); 
    }
    if(r==9){
   if(a[i]==120){
      if(8*mapValue==24 || 8*mapValue==16  || 8*mapValue==56 || 8*mapValue==48){
        digitalWrite(buzzerpin, HIGH);}
        
      }
   display.drawBitmap(16,a[i],engel,8,8,1);
   display.drawBitmap(24,a[i],engel,8,8,1);
   display.drawBitmap(48,a[i],engel,8,8,1);
   display.drawBitmap(56,a[i],engel,8,8,1);
    }
    if(r==11){
      if(a[i]==120){
      if(8*mapValue==0 || 8*mapValue==8 || 8*mapValue==16 || 8*mapValue==56 ){
        digitalWrite(buzzerpin, HIGH);}
        
      }
   display.drawBitmap(0,a[i],engel,8,8,1);
   display.drawBitmap(8,a[i],engel,8,8,1);
   display.drawBitmap(16,a[i],engel,8,8,1);
   display.drawBitmap(56,a[i],engel,8,8,1);
    }
    if(r==13){
      if(a[i]==120){
      if(8*mapValue==0 || 8*mapValue==8 || 8*mapValue==16 || 8*mapValue==24 || 8*mapValue==48|| 8*mapValue==56){
        digitalWrite(buzzerpin, HIGH);}
        
      }
   display.drawBitmap(0,a[i],engel,8,8,1);
   display.drawBitmap(8,a[i],engel,8,8,1);
   display.drawBitmap(16,a[i],engel,8,8,1);
   display.drawBitmap(24,a[i],engel,8,8,1);
   display.drawBitmap(48,a[i],engel,8,8,1);
   display.drawBitmap(56,a[i],engel,8,8,1);
    }
    if(r==15){
      if(a[i]==120){
      if(8*mapValue==32 || 8*mapValue==16 || 8*mapValue==56 || 8*mapValue==40 || 8*mapValue==48){
        digitalWrite(buzzerpin, HIGH);}
        
      }
   display.drawBitmap(16,a[i],engel,8,8,1);
   display.drawBitmap(32,a[i],engel,8,8,1);
   display.drawBitmap(40,a[i],engel,8,8,1);
   display.drawBitmap(48,a[i],engel,8,8,1);
   display.drawBitmap(56,a[i],engel,8,8,1);
    }
    if(r==17){
   if(a[i]==120){
      if(8*mapValue==8 || 8*mapValue==16 || 8*mapValue==32 || 8*mapValue==24 || 8*mapValue==48 || 8*mapValue==40){
        digitalWrite(buzzerpin, HIGH);}
        
        
      }
   display.drawBitmap(8,a[i],engel,8,8,1);
   display.drawBitmap(16,a[i],engel,8,8,1);
   display.drawBitmap(24,a[i],engel,8,8,1);
   display.drawBitmap(32,a[i],engel,8,8,1);
   display.drawBitmap(40,a[i],engel,8,8,1);
   display.drawBitmap(48,a[i],engel,8,8,1);
   
    }
    if(r==19){
      if(a[i]==120){
      if(8*mapValue==0 || 8*mapValue==24 || 8*mapValue==32 || 8*mapValue==56){
        digitalWrite(buzzerpin, HIGH);}
        
        
      }
   display.drawBitmap(0,a[i],engel,8,8,1);
   display.drawBitmap(24,a[i],engel,8,8,1);
   display.drawBitmap(32,a[i],engel,8,8,1);
   display.drawBitmap(56,a[i],engel,8,8,1);
    }
    
    if(r==21){
      if(a[i]==120 ){
      if(8*mapValue==0 || 8*mapValue==16 || 8*mapValue==24 || 8*mapValue==40 || 8*mapValue==56){
        digitalWrite(buzzerpin, HIGH);}
        
        
        
      }
   display.drawBitmap(0,a[i],engel,8,8,1);
   display.drawBitmap(16,a[i],engel,8,8,1);
   display.drawBitmap(24,a[i],engel,8,8,1);
   display.drawBitmap(40,a[i],engel,8,8,1);
   display.drawBitmap(56,a[i],engel,8,8,1);
    }
    


  }




