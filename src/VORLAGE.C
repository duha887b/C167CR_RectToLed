// ###############################
// Gruppe: 			ABS-1-005
// Bearbeiter:	Dingeldein, Kleon
//							Hanusch, Dustin
// Datum:				11.05.2023
// ###############################

#include <reg167.h>
#include <stdio.h>
#include <stdlib.h>




sbit led0 = P2^0;		//LED Leiste
sbit led1 = P2^1;
sbit led2 = P2^2;
sbit led3 = P2^3;
sbit led4 = P2^4;
sbit led5 = P2^5;
sbit led6 = P2^6;
sbit led7 = P2^7;
sbit led8 = P2^8;
sbit led9 = P2^9;
sbit led10 = P2^10;
sbit led11 = P2^11;
sbit led12 = P2^12;
sbit led13 = P2^13;
sbit led14 = P2^14;
sbit led15 = P2^15;

unsigned int activeLEDs = 0;

signed int count = 0;
signed int count90 = 0;
unsigned int per90 = 6; //rastungen pro 90°

unsigned int conditionNew; 
unsigned int conditionOld; 
unsigned int conditionTable[4] = {3,1,0,2};


void led_controle(unsigned int  number,bit  state){
	switch (number){
		case 0: led0 = state;
		case 1: led1 = state;
		case 2: led2 = state;
		case 3: led3 = state;
		case 4: led4 = state;
		case 5: led5 = state;
		case 6: led6 = state;
		case 7: led7 = state;
		case 8: led8 = state;
		case 9: led9 = state;
		case 10: led10 = state;
		case 11: led11 = state;
		case 12: led12 = state;
		case 13: led13 = state;
		case 14: led14 = state;
		case 15: led15 = state;
}
	}

void LEDBar(unsigned int nLEDs){
	unsigned int n;
	
	for(n=0; n<nLEDs;n++){
		led_controle(n,1);
	}
	for(n = nLEDs; n<=15;n++){
		led_controle(n,0);
	}
		
}


void setup(void){
	DP2 = 0xFFFF; // Port 2 auf Ausgang 
	DP8 = 0x00; // Port 8 auf Eingang
	ODP8 = 0xFF;
	CCM4 = CCM4|0x0002;
	CC16IC = 0x44;

	IEN = 0xFFFF; // Interrupts freigeben 
	
	activeLEDs = 8;
	LEDBar(activeLEDs);
	
	
	conditionOld, conditionNew = P8;
	
		
}

void cc_extern() interrupt 0x30{ //TODO finde das richtige register; 8.0;
	conditionNew = P8;
	
	if(P8 == 0) { // Drehung gegen Uhrzeigersinn dektekiert
		count++;
	}
	if (P8 == 2) {
		count--;
	}
	
	
	if(count == per90){
		count = 0;
		if(activeLEDs > 16){return;}
		activeLEDs++;
	}
	if(count == -per90){
		count = 0;
		if(activeLEDs == 0){return;}
		activeLEDs--;
		
	}
	
	LEDBar(activeLEDs);
}



void main(){

	setup();
	

  while(1){

  }//end while(1)
}//end main()