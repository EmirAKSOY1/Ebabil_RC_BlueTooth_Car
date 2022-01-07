#include <SoftwareSerial.h>
#include <Servo.h>
const int motorA1  = 11;  // L298N'in IN3 Girişi
const int motorA2  = 10;  // L298N'in IN1 Girişi
const int Enable =9;//Motorun enable pini

/*Hc-05 Bilgieri
İsim=EBABİL-HC05
Şifre=1234
*/

/*Yaılımcı Bilgieri
Emir AKSOY
05426307649
emiraksoy10@gmail.com
bir Sorunuz olursa Ulaşabiilirsin*/
/*UYARILAR
Telefon uygulaması üzerinden sürekli olarak komut göndermeyiniz(Aynı anda tuşlara basmak gibi)
HC-05'in kilitlenmesine sebep olur.(Komut gönderilmemsine Sebep Olur Motorların Durmadan Çalışır)
Eğer Kilitlenirse Pillerden birisini veya Hc-05'in Vcc Pinini Takıp Çıkartın.
Bluetooth Modülü Bağlıyken Bilgisayardan Arduino Kod atarken Arduino Üzerinden TX RX pinlerinin birisinin Bağlantı Kablosunu akıp yükleyin.
Yükleme İşi Bittikten Sonra Kabloyu Aynı Yere Takabilirsiniz.(Aksi Takdirde Kodunuz Yüklenmeyip Hata Alıcaksınız) 
Uygulama Üzerinde Hız Ayarı Olmasına Rağmen verileri Düzgün alamıyor bu Yüzden  Hız ayarı Yapılamıyor.Bundan Dolayı Enable Konnektörünü Yerine Taktım.
Araç sabit Hızda Çalışabiliyor.
*/
Servo servo;
int veri;

int Hiz=255;
 
void setup() {
  
  
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(Enable,OUTPUT);
    servo.attach(6);  
    int aciDegeri=45;
    Serial.begin(9600);}
    
    void loop(){
     if (Serial.available() > 0) { //Seri haberleşmeden veri gelmesini bekliyoruz.
    veri = Serial.read(); //Seri haberleşmeden gelen veriyi okuyoruz.
  }
  if(veri=="0"){
    Hiz=0;
   
  }
  else if(veri=="1"){
    Hiz=25;
   
  }else if(veri=="2"){
    Hiz=50;
    
  }
  else if(veri=="3"){
    Hiz=75;
    
    }
   else if(veri=="4"){
    Hiz=95;
    
  }
  else if(veri=="5"){
    Hiz=110;
    
  }
  else if(veri=="6"){
    Hiz=125;
    
    }
   else  if(veri=="7"){
    
    Hiz=150;
   
  }
  else if(veri=="8"){
    
    Hiz=175;
    
  }
  else if(veri=="9"){
    
    Hiz=215;
    
    
  }
  else if(veri=="q"){
    Hiz=255;
    
  }
      if (veri == 'F') {//İleri Gİt
        
     analogWrite(motorA1, Hiz); analogWrite(motorA2, 0);
     
     
     }
     
     else  if (veri == 'B') {//Geri Git
       
     analogWrite(motorA1, 0);   analogWrite(motorA2, Hiz); 
      }
       
       else  if (veri == 'R') {
        
    
        servo.write(90);  //Sağa Döner
      }
      else if (veri == 'L'){
       
        servo.write(0);  //Sola Döner
    }  
     else if (veri == 'G') {//İleri Sol Çapraz
      servo.write(0) ; 
      delay(500);
      analogWrite(motorA1,Hiz ); analogWrite(motorA2, 0);  }

        else if (veri == 'I') {//İleri Sağ Çapraz
      servo.write(90) ; 
      delay(500);
      analogWrite(motorA1,Hiz ); analogWrite(motorA2, 0);  }  
       
   else  if (veri == 'H') {//Geri Sol
        
        servo.write(0);
        delay(500);
     analogWrite(motorA1, 0);   analogWrite(motorA2, Hiz); 
      }
       else  if (veri == 'H') {//Geri Sağ
        
        servo.write(90);
        delay(500);
     analogWrite(motorA1, 0);   analogWrite(motorA2, Hiz); 
      }
      else if (veri== 'S'){//Dur
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        
    } 
    else if (veri== 'D'){//Stop All
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        
    } 
    else{
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
    }
     
     
     }
    
