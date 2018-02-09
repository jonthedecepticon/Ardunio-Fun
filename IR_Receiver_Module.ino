#include "IRremote.h"

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11

//Define Pins for LEDs
#define BLUE 6
#define GREEN 5
#define RED 3


/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

/*-----( Function )-----*/
// takes action based on IR code received
void translateIR() 
{
  // describing Remote IR codes 
  switch(results.value)
  {
  case 0xFFA25D:
      Serial.println("POWER OFF");
      if (digitalRead(BLUE) == HIGH || digitalRead(RED) == HIGH || digitalRead(GREEN) == HIGH)
      {
        digitalWrite(BLUE, LOW);
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
      }
    break;
  case 0xFFE21D: 
      Serial.println("FUNC/STOP");
    break;
  case 0xFF629D:
      Serial.println("VOL+");
    break;
  case 0xFF22DD:
      Serial.println("FAST BACK");
    break;
  case 0xFF02FD:
      Serial.println("PAUSE");
    break;
  case 0xFFC23D:
      Serial.println("FAST FORWARD");
    break;
  case 0xFFE01F:
      Serial.println("DOWN");    
    break;
  case 0xFFA857: 
      Serial.println("VOL-");    
    break;
  case 0xFF906F:
      Serial.println("UP");    
    break;
  case 0xFF9867: 
      Serial.println("EQ");   
    break;
  case 0xFFB04F: 
      Serial.println("ST/REPT"); 
    break;
  case 0xFF6897: 
      Serial.println("0");    
    break;
  case 0xFF30CF: 
      Serial.println("1");
      digitalWrite(BLUE, HIGH);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);    
    break;
  case 0xFF18E7: 
      Serial.println("2"); 
      digitalWrite(BLUE, LOW);
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);  
    break;
  case 0xFF7A85: 
      digitalWrite(BLUE, LOW);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH); 
    break;
  case 0xFF10EF: 
      Serial.println("4");   
    break;
  case 0xFF38C7: 
      Serial.println("5");    
    break;
  case 0xFF5AA5: 
      Serial.println("6");    
    break;
  case 0xFF42BD: 
      Serial.println("7");    
    break;
  case 0xFF4AB5: 
      Serial.println("8");    
    break;
  case 0xFF52AD: 
      Serial.println("9");    
    break;
  case 0xFFFFFFFF: 
      Serial.println(" REPEAT");
    break;  
  default: 
    Serial.println(" other button ");
  }
  delay(500); // Do not get immediate repeat
} //END translateIR

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
  // Setup LEDs
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}/*--(end setup )---*/

// define variables
int redValue;
int greenValue;
int blueValue;

void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  } 
}/* --(end main loop )-- */


