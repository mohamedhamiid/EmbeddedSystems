int L1=10;
int L2=9;
int L3=6;
int L4=5;
int L5=3;

int P1=13;
int B2=12;
int B3=11;
int B4=8;
int B5=7;
int B6=2;

int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int f=0;
int i=0;

int k=0;
int l=0;
int m=0;
int n=0;
int o=0;
int c=0;
  

void setup()
{
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  
  pinMode(P1,INPUT);
  pinMode(B2,INPUT);
  pinMode(B3,INPUT);
  pinMode(B4,INPUT);
  pinMode(B5,INPUT);
  pinMode(B6,INPUT);
  Serial.begin(9600);

    
 
}

void loop()
{
  a = digitalRead(P1);
  delay(150);
  Serial.println(a);
  
    if(a==HIGH){
      
for (i=0;i<=255;i++){
analogWrite (L1,i);
     delay(2);}
for (i=0;i<=255;i++){   
analogWrite (L4,i);
      delay(2);}
for (i=0;i<=255;i++){
analogWrite(L2,i);
  delay(2);}
for (i=0;i<=255;i++){
analogWrite (L3,i);
    delay(2);}
for (i=0;i<=255;i++){
analogWrite (L5,i);
      delay(2);}
      
for (i=255;i>=0;i--){
 analogWrite(L1,i);
  delay(2);}
for (i=255;i>=0;i--){
 analogWrite(L4,i);
  delay(2);} 
for (i=255;i>=0;i--){ 
  analogWrite(L2,i);
  delay(2);}
for (i=255;i>=0;i--){  
  analogWrite(L3,i);
  delay(2);}
for (i=255;i>=0;i--){
  analogWrite(L5,i);
  delay(2);}
        } 
  
  
b = digitalRead(B2);
delay(150);
  
    if(b==HIGH){
for (i=0;i<=255;i++){   
analogWrite (L1,i);
analogWrite (L5,i);
analogWrite (L4,i);
analogWrite(L2,i);
analogWrite (L3,i);
      delay(2);
}
for (i=255;i>=0;i--){      
analogWrite(L2,i);
analogWrite(L4,i);
analogWrite(L1,i);
analogWrite(L5,i);
analogWrite(L3,i);
    delay(2);
}
    }      
        
  c = digitalRead(B3);
  delay(150);
  
    if(c==HIGH){
for (i=0;i<=255;i++){
analogWrite (L1,i);
      delay(2);
  analogWrite(L2,i);
      delay(2);}
for (i=255;i>=0;i--){  
analogWrite (L1,i);
      delay(2);
  analogWrite(L2,i);
      delay(2);}
for (i=0;i<=255;i++){        
analogWrite (L3,i);
      delay(2);
analogWrite (L4,i);
      delay(2);}
for (i=255;i>=0;i--){ 
analogWrite (L3,i);
      delay(2);
analogWrite (L4,i);
      delay(2);}
for (i=0;i<=255;i++){ 
  analogWrite (L5,i);
      delay(2);}
for (i=255;i>=0;i--){
  analogWrite(L5,i);
      delay(2);}
 
    }
  
 d = digitalRead(B4);
  
  
    if(d==HIGH){
for (i=0;i<=255;i++){
analogWrite (L1,i);
analogWrite (L3,i);
analogWrite (L5,i);
    delay(2);}
for (i=255;i>=0;i--){    
analogWrite(L1,i);
analogWrite(L3,i);
analogWrite(L5,i);
    delay(2);}
for (i=0;i<=255;i++){ 
analogWrite(L2,i);
analogWrite (L4,i);
    delay(2);}
for (i=255;i>=0;i--){
analogWrite(L2,i);
analogWrite(L4,i);
    delay(2);}
    }
    
  
  e = digitalRead(B5);
  delay(150);
    if(e==HIGH){
for (i=0;i<=255;i++){
analogWrite (L3,i);
delay(2);}
for (i=255;i>=0;i--){
analogWrite (L3,i);
delay(2);}
for (i=0;i<=255;i++){
analogWrite(L2,i);
analogWrite(L4,i);
    delay(2);}
for (i=255;i>=0;i--){
analogWrite(L2,i);
analogWrite(L4,i);
    delay(2);}
for (i=0;i<=255;i++){
analogWrite (L1,i);
analogWrite (L3,i);   
delay(2);}
for (i=255;i>=0;i--){    
analogWrite(L1,i);
analogWrite(L3,i);
delay(2);}    
}
}
    
