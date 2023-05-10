//gethex.c

#include <reg167.h>
#include <stdio.h>
#include <getline.h>


int gethex(){
  unsigned int i;
  unsigned int err;
  char buf[100];
  getline(buf,sizeof(buf));
  err=sscanf(buf,"%x",&i);
  if(!err) printf("\nError");
  return i;
}

void main(){
  unsigned int x;
  while(1){
    printf("\n\nHexadezimalzahl eingeben: ");
    x=gethex();
    printf("\n%X",x);
  }
}
