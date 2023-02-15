// Initializing which pins to be used for the button switches and LED
#define switch_1 22
#define switch_2 23

#define led_1 15
#define led_2 21

//Initilization of button states
int button_1 = 0;
int button_2 = 0;


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
  // Read the button state after starting each loop
  button_1 = digitalRead(switch_1);
  button_2 = digitalRead(switch_2);
  // The coniditons of the buttons 

    // When none of the buttons are pressed  
    if (button_1 == 0 && button_2 == 0)
      {
        // Signal B wave form
        digitalWrite(led_2,HIGH);

        delayMicroseconds(50);
        digitalWrite(led_2,LOW);

        // For loop for signal A wave form for normal mode (12 waveforms)
        for (int i = 0; i < 12; i++)
         {
            digitalWrite(led_1, HIGH);
            delayMicroseconds((900 + (50*i)));

            digitalWrite(led_1, LOW);
            delayMicroseconds(600);
         }

        // Down time in between signal A and B waveforms
        delayMicroseconds(6000); 
      }
  
  // When button 2 is pressed 
  if (button_1 == 0 && button_2 == 1)
    {
      // Signal B waveform 
      digitalWrite(led_2,HIGH);
      delayMicroseconds(50);
      digitalWrite(led_2,LOW);

        // Signal A waveform mode 2 (inverted) (12 waveforms)
        for (int j = 0; j < 12; j++ )
          {
            digitalWrite(led_1, HIGH);
            delayMicroseconds((1450 - (50*j)));

            digitalWrite(led_1, LOW);
            delayMicroseconds(600);
          }  
        delayMicroseconds(6000);
    }
  
  // When button 1 is pressed, it will stop any waveforms from happening 
  if (button_1 == 1)
    {
    
      digitalWrite(led_1, LOW);
      digitalWrite(led_2, LOW);
      delay(50);
      
    }

}


