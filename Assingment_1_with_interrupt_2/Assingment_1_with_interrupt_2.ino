// Initializing which pins to be used
#define switch_1 22
#define switch_2 23

#define led_1 15
#define led_2 21

//Initilization of button states
int button_1 = 0;
int button_2 = 0;

int lastButton_1 = 0;
int lastButton_2 = 0;


void IRAM_ATTR ISR() 
{
    // Checking the button presses
    Serial.println("i am in isr\n");
  if(digitalRead(switch_1) == 1 && digitalRead(switch_1) != lastButton_1)
    {
      button_1 = 1;
    }
  lastButton_1 = button_1; 

  if(digitalRead(switch_2) == 1 && digitalRead(switch_2) != lastButton_2)
    {
      button_2 = 1;
    }
  lastButton_2 = button_2;

  
}

void setup() 
{
// Setting which pins are inputs and outputs
  pinMode(switch_1, INPUT);
  pinMode(switch_2, INPUT);  

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);

  attachInterrupt(switch_1, ISR, HIGH);
  attachInterrupt(switch_2, ISR, HIGH);

  Serial.begin(9600);
  Serial.println("setup done\n");

}

void loop()
{

button_1 = digitalRead(switch_1);
button_2 = digitalRead(switch_2);
delay(50);
// The coniditons of the buttons 
Serial.println("in loop\n");
  if (button_1 == 1 && button_2 == 0 && lastButton_1 != button_1)
    {
      
      digitalWrite(led_2,HIGH);
      Serial.println("LED2 pulse\n");

      delayMicroseconds(50);
      digitalWrite(led_2,LOW);
      Serial.println("LED2 low\n");

      for (int i=0; i<12; i++)
        {
          Serial.println("LED1 pulse\n");
          digitalWrite(led_1, HIGH);
          delayMicroseconds(900 + (i*50));

          Serial.println("LED1 LOW\n");
          digitalWrite(led_1, LOW);
          delayMicroseconds(600);
        }

       delayMicroseconds(6000); 
    }

  if (button_1 == 1 && button_2 == 1 && lastButton_2 != button_2)
    {
      digitalWrite(led_2,HIGH);
      delayMicroseconds(50);
      digitalWrite(led_2,LOW);

      Serial.println("mode 2 pulse\n");

      for (int j=0; j<12; j = j++ )
        {
          digitalWrite(led_2, HIGH);
          delayMicroseconds(1450 - (j*50));

          digitalWrite(led_2, LOW);
          delayMicroseconds(600);
          Serial.println("for loop \n");
        }
      delayMicroseconds(6000);
    }

  while (button_1 == LOW)
    {
      Serial.println("in 0\n");
      digitalWrite(led_1, LOW);
      digitalWrite(led_2, LOW);
      delay(50);
      
      button_1 = digitalRead(switch_1);
    }

}


