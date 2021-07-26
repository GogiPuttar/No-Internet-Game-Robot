#include<Servo.h>
int darkVal;
int prevDark;
const int black=612;
const int LDR=A0;
//const int brace=1000;
int obstacle[5]={0};
int count=0;
const int objectVal=31;
int object=objectVal;
int jumpCount=11;
int jumpPress=10;
int coher=1;
int angle=24;
unsigned long int startTime=0;
unsigned long int currentTime=0;
int ctr=0;
Servo myServ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  myServ.attach(9);
  myServ.write(angle);
  Serial.println(count);           
  delay(3000);
}  
                                                                                                                        
void loop() {
  // put your main code here, to run repeatedly:
  darkVal=analogRead(LDR);
  currentTime=millis();
  Serial.print(object);
  Serial.print("  ");
  //Serial.print(currentTime-startTime);
  //Serial.print("    ");
  //Serial.print(darkVal);
  //Serial.print("  ");
  //Serial.print(prevDark); 
  //Serial.print("        ");
  //Serial.print("  ");
  for(int i=0; i<5; i++)
  {
    Serial.print(obstacle[i]); 
    Serial.print("/ ");    
  }
  Serial.println("  ");
  if(obstacle[0]==0)
   {
    ctr++;
    if(ctr>=30)
     {
      startTime=currentTime;
      object=objectVal;
    }
  }
  if(darkVal>=black && prevDark<black)
  {  
    if(obstacle[0]==0)
    {
      ctr=0;
    }
    //Serial.print(count);
    //Serial.print("-->");
    obstacle[count++]=object;
    //Serial.print(count);
    Serial.print(" **********");
    //Serial.println(obstacle[0]);
  }
  
  if(obstacle[0]!=0)
  {
    if(obstacle[0]>jumpPress && obstacle[0]<=2*jumpCount-jumpPress)
    {
      myServ.write(angle+11);
    }
    if(obstacle[0]<=2*jumpCount && obstacle[0]>2*jumpCount-jumpPress)
    {
        myServ.write(22+angle-obstacle[0]);
          //delay(coher);
      //obstacle[0]--;
    }
    else if(obstacle[0]<=jumpPress && obstacle[0]>1)
   {
       myServ.write(angle+obstacle[0]);
      //delay(coher);
      //obstacle[0]--;
    }
    else if(obstacle[0]==1)
    {
      for(int i=0; i<5; i++)
      {
        obstacle[i]=obstacle[i+1];
      }
      obstacle[4]=0;
      count--;
      //delay(coher);
    }
    delay(coher);
    for(int i=0; i<5; i++) 
    {
      if(obstacle[i]!=0) 
      {   
         obstacle[i]--;
      }
    }    
  }
  if(currentTime-startTime>=3400 && currentTime-startTime<=3460)
  {
    object=objectVal-1;;
  }  
  if(currentTime-startTime>=7000 && currentTime-startTime<=7060)
  {      
    object=objectVal-2;    
  }
  if(currentTime-startTime>=10700 && currentTime-startTime<10760)
  {   
    object=objectVal-3;
  }
  if(currentTime-startTime>=20400 && currentTime-startTime<=20460)
  {
    object=objectVal-4;
  }
  if(currentTime-startTime>=33000 && currentTime-startTime<=33060)
  {
    object=objectVal-5   ;
  }
  if(currentTime-startTime>=37000 && currentTime-startTime<=37060)
  {
    object=objectVal-6;
  }
  prevDark=darkVal;
}                             
