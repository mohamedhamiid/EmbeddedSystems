int L1 = 7 ;
int L2 = 9 ;
int x=0;
int c=0;
void setup() {

pinMode( L1 , OUTPUT );
pinMode ( L2 , OUTPUT);
pinMode ( 8 , INPUT ) ;

Serial.begin(9600);
}

void loop() {

x = digitalRead (8) ;
delay (150);
Serial.println(x);
if(x==HIGH){
  c++ ;
Serial.println(c);
if ( c==1 ){
  digitalWrite(L1 , HIGH);
}
if (c==2){
  digitalWrite(L2 , HIGH);
}
   
if ( c==3 ){
  digitalWrite(L1 , LOW);
  digitalWrite(L2 , LOW);
  }}
}
