//getfloat.c

#include <reg167.h>
#include <stdio.h>
#include <getline.h>


float getfloat(){
  float f;
  unsigned int err;
  char buf[100];
  getline(buf,sizeof(buf));
  err=sscanf(buf,"%f",&f);
  if(!err) printf("\nError");
  return f;
}

void main(){
  float x;
  while(1){
    printf("\n\nFloatzahl eingeben: ");
    x=getfloat();
    printf("\n%f",x);
  }
}
