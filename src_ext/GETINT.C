//getint.c

#include <reg167.h>
#include <stdio.h>
#include <getline.h>


int getint(){
  int i;
  unsigned int err;
  char buf[100];
  getline(buf,sizeof(buf));
  err=sscanf(buf,"%d",&i);
  if(!err) printf("\nError");
  return i;
}

void main(){
  int x;
  while(1){
    printf("\n\nIntegerzahl eingeben: ");
    x=getint();
    printf("\n%d",x);
  }
}
