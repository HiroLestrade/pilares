int state = 0,
    vel = 128;
String msg;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
  Serial.begin(9600);

  digitalWrite(3, HIGH);
}

void loop() {
  if(Serial.available()){
    msg = Serial.readString();
    
    if(msg.equals("L#")){
      //active
      state = !state;
      digitalWrite(2,state); 
    }
    else if(msg.startsWith("A#")){
      //forward
      mForward();
    }
    else if(msg.startsWith("I#")){
      //left
      mLeft();
    }
    else if(msg.startsWith("R#")){
      //back
      mBackward();
    }
    else if(msg.startsWith("D#")){
      //right
      mRight();
    }
    else if(msg.startsWith("P#")){
      if(msg.startsWith("P#P"){
        vel = msg.substring(msg.lastIndexOf("P") + 1, msg.lastIndexOf("#")).toInt()/4;  
      }
      
    }
    else if(msg.startsWith("S#")){
      //stop
      mStop();
    }
  }
}

void mForward(){
  analogWrite(5, vel);
  digitalWrite(6, LOW);
  analogWrite(9, vel);
  digitalWrite(10, LOW);
}

void mBackward(){
  digitalWrite(5, LOW);
  analogWrite(6, vel);
  digitalWrite(9, LOW);
  analogWrite(10, vel);
}

void mLeft(){
  analogWrite(5, vel);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  analogWrite(10, vel);
}

void mRight(){
  digitalWrite(5, LOW);
  analogWrite(6, vel);
  analogWrite(9, vel);
  digitalWrite(10, LOW);
}

void mStop(){
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}
