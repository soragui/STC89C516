MAIN: 	SETB  P1.0  ;  P1.0 = 1;
		MOV   30H, #255 ;
	 	LCALL DELAY	;  delay();
		CLR	  P1.0  ;  P1.0 = 0;
		MOV   30H, #200 ;
		LCALL DELAY ;  delay();
		LJMP  MAIN  ;  while (1);

DELAY:  MOV R7, 30H ;	delay()
D1:     MOV R6, #250 ;	while (i --)
D2:     DJNZ R6, D2  ;
		DJNZ R7, D1  ;
		RET			 ;
		END          ; 	  return
 