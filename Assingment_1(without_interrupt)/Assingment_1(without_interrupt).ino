// Initializing which pins to be used
#define switch_1  22
#define switch_2  23

#define led_1  15
#define led_2  21

//Initilization of button states
int button_1 = 0;
int button_2 = 0;

int lastButton_1 = 0;
int lastButton_2 = 0;


void setup() 
{
// Setting which pins are inputs and outputs
  pinMode(switch_1, INPUT);
  pinMode(switch_2, INPUT);  

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);

}

void loop()
{


// Checking the button presses
  // if(digitalRead(switch_1) == 1 && digitalRead(switch_1) != lastButton_1)
  //   {
  //     button_1 = 1;
  //   }
  // lastButton_1 = button_1;

  // if(digitalRead(switch_2) == 1 && digitalRead(switch_2) != lastButton_2)
  //   {
  //     button_2 = 1;
  //   }
  // lastButton_2 = button_2;

  button_1 = digitalRead(switch_1);
  button_2 = digitalRead(switch_2);
// The coniditons of the buttons 
  if (button_1 == HIGH && button_2 == LOW)
    {

      digitalWrite(switch_2,HIGH);
      delayMicroseconds(50);
      digitalWrite(switch_2,LOW);

      for (int i=900; i>=1500;i=i+50)
        {
          digitalWrite(switch_1, HIGH);
          delayMicroseconds(i);

          digitalWrite(switch_1, LOW);
          delayMicroseconds(600);
        }

       delayMicroseconds(6000); 
    }

  if (button_1 == HIGH && button_2 == HIGH)
    {
      digitalWrite(switch_2,HIGH);
      delayMicroseconds(50);
      digitalWrite(switch_2,LOW);

      for (int j=1500; j<=900; j = j-50 )
        {
          digitalWrite(switch_2, HIGH);
          delayMicroseconds(j);

          digitalWrite(switch_2, LOW);
          delayMicroseconds(600);
        }
      delayMicroseconds(6000);
    }

  if (button_1 == LOW)
    {
      digitalWrite(switch_1, LOW);
      digitalWrite(switch_2, LOW);
    }

}


