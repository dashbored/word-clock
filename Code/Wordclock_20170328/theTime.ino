

void theTime() {
  DateTime now = rtc.now();
  memset(pixel,0,sizeof(pixel));
  
 // Light up "KLOCKAN" and "ÄR"
 // "KLOCKAN"
  for(int i=136; i<143; i++) {
    pixel[i] = 1;
  }

 // "ÄR" 
  for(int i=133; i<135; i++) {
    pixel[i] = 1;
  } 


  
}

