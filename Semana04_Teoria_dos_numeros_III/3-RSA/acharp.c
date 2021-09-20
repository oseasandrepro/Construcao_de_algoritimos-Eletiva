//achar p
   	for (i=1; i <=np; i++)
     	{
     		long double div = n/P[i];
     		
     		sprintf(str, "%.5Lf", div);
     		
     		printf("duble string: %s\n", str);
     				
     		sscanf(str, "%[^.].%d", bu, &decimal);
     		
     		printf("parte inteira: %s\n", bu);
     		printf("parte decimal: %d\n", decimal);
     		if( P[i] == 99871.0 ){
     			printf("***\n");
     			break;
     		}
     		if( decimal == 0){
     			p = P[i];
     			break;
     		}  
     	}

x = div;
	   	/*achar q*/
	   	for ( i=i+1; i <=np; i++)
	     	{
	     		div = x/P[i];
	     		sprintf(str, "%.5Lf", div);
	     		sscanf(str, "%*[^.].%d",  &decimal);
	     		if( decimal == 0){
	     			q = P[i];
	     			break;
	     		}  
	     	}
	     	//ultimo fator e r;
	   	r = div;
