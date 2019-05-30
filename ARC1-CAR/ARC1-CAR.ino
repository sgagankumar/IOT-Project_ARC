int ip = D1;
int red_led = D2;
int green_led = D3;
int IR3= D4;
int val =0;

void setup() 
{
  pinMode(ip,INPUT);
  pinMode(IR3,INPUT);
  Serial.begin(9600);
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
}

void loop() 
{
  
  val=digitalRead(ip);
  val=1;
  if(val == 1)
  {
      Serial.println("val high");
      while(digitalRead(IR3)==1) //on red led while there is a car stuck
      {   Serial.println("ir3 high :car detected");
          digitalWrite(green_led,LOW);
          digitalWrite(red_led,HIGH);
          
      }
     
         
  }

  digitalWrite(green_led,HIGH);
  digitalWrite(red_led,LOW);
      

  delay(500);
  // put your main code here, to run repeatedly:

}
