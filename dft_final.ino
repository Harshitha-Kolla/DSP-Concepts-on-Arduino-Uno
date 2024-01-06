int n = 8;
float x[8];
float xr[8], xi[8];
float mag[8];
float phase[8];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i, j;
  for(j=0;j<8;j++){
    x[j] = 5 + 2*cos(2*PI*j/4.0-(PI/2)) + 3*cos(4*PI*j/4.0);
    xr[j]=0;
    xi[j]=0;
    for(i=0;i<8;i++){
      xr[j] = xr[j] + x[i]*cos(2*PI*i*j/8);
      xi[j] = xi[j] - x[i]*sin(2*PI*i*j/8);
    }
    mag[j] = sqrt((xr[j]*xr[j])+(xi[j]*xi[j]));
//    //Serial.print(mag[j]);
    Serial.print(" ");
    Serial.println(mag[j]);
    if(xr[j]==0 && xi[j]==0) phase[j]=0;
    else phase[j] = atan(xi[j]/xr[j]);
//    Serial.print(" ");
//    Serial.println(xi[j]);
  }
}
