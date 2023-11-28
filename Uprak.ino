#define echoPin 12 // attach pin D2 Arduino to pin Echo of JSN-SR04T
#define trigPin 13 //attach pin D3 Arduino to pin Trig of JSN-SR04T
long duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement
float x,x0=20.1,x1=29.7,x2=59,x3=87.5,x4=116.5;
float y,y0=20,y1=30,y2=60,y3=90,y4=120,p4x;
float a0l0,a1l1,a2l2,a3l3,a4l4;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baud rate speed
}

void loop() {
  //bacasensor();    //panggil fungsi baca sensor
  Serial.print("sensor=");
  Serial.println(distance,1);
  lagrange();    //panggil pfungsi lagrange didalan fungsi baca sensor
  Serial.print("numerik lagrange=");
  Serial.println(p4x,1);
  delay(1000);
}

void bacasensor(){
  digitalWrite(trigPin, LOW);  //
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  delay(100);
}

void lagrange(){
bacasensor(); //paggil fungsi sensor baca
x=distance;
a0l0=((y0*(x-x1)*(x-x2)*(x-x3)*(x-x4))/((x0-x1)*(x0-x2)*(x0-x3)*(x0-x4)));
a1l1=((y1*(x-x0)*(x-x2)*(x-x3)*(x-x4))/((x1-x0)*(x1-x2)*(x1-x3)*(x1-x4)));
a2l2=((y2*(x-x0)*(x-x1)*(x-x3)*(x-x4))/((x2-x0)*(x2-x1)*(x2-x3)*(x2-x4)));
a3l3=((y3*(x-x0)*(x-x1)*(x-x2)*(x-x4))/((x3-x0)*(x3-x1)*(x3-x2)*(x3-x4)));
a4l4=((y4*(x-x0)*(x-x1)*(x-x2)*(x-x3))/((x4-x0)*(x4-x1)*(x4-x2)*(x4-x3)));
p4x=a0l0+a1l1+a2l2+a3l3+a4l4;
}
