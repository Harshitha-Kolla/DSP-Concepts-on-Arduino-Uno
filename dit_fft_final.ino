int n = 8;
double x[8];
double xr[8], xi[8];
float wr[4] = {1.0, 0.707, 0.0, -0.707};
float wi[4] = {0.0, -0.707, -1.0, 0.707};
double mag[8];
double phase[8];

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
  }
  xr[0] = x[0];
  xr[1] = x[4];
  xr[2] = x[2];
  xr[3] = x[6];
  xr[4] = x[1];
  xr[5] = x[5];
  xr[6] = x[3];
  xr[7] = x[7];
  j=0;

  for(j=0;j<=3;j++){
    double sum1r = xr[i] + xr[i+1];
    double sum1i = xi[i] + xi[i+1];
    double sum2r = xr[i] - xr[i+1];
    double sum2i = xi[i] - xi[i+1];
    xr[i] = sum1r;
    xi[i] = sum1i;
    xr[i+1] = sum2r;
    xi[i+1] = sum2i;
    i = i+2;
  }
  int k;
  i=0;
  for(k=0;k<2;k++){
    int w=0;
    for(j=0;j<2;j++){
      double sum1r = xr[i]+(wr[w]*xr[i+2])-(wi[w]*xi[i+2]);
      double sum1i = xi[i]+(wr[w]*xi[i+2])+(wi[w]*xr[i+2]);
      double sum2r = xr[i]-(wr[w]*xr[i+2])+(wi[w]*xi[i+2]);
      double sum2i = xi[i]-(wr[w]*xi[i+2])-(wi[w]*xr[i+2]);
      xr[i] = sum1r;
      xi[i] = sum1i;
      xr[i+2] = sum2r;
      xi[i+2] = sum2i;
      i = i+1;
      w = w+2;
    }
    i = i+2;
  }
  i=0;
  int w=0;
  for(j=0;j<4;j++){
    double sum1r = xr[i]+(wr[w]*xr[i+4])-(wi[w]*xi[i+4]);
    double sum1i = xi[i]+(wr[w]*xi[i+4])+(wi[w]*xr[i+4]);
    double sum2r = xr[i]-(wr[w]*xr[i+4])+(wi[w]*xi[i+4]);
    double sum2i = xi[i]-(wr[w]*xi[i+4])-(wi[w]*xr[i+4]);
    xr[i] = sum1r;
    xi[i] = sum1i;
    xr[i+4] = sum2r;
    xi[i+4] = sum2i;
    i = i+1;
    w = w+1;
  }
  for(i=0;i<8;i++){
    mag[i] = sqrt((xr[i]*xr[i])+(xi[i]*xi[i]));
    Serial.print(" ");
    Serial.println(mag[i]);
  }
}
