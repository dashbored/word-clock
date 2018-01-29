/*
 * This function reads the RTC and lights the correct pixels according to 
 * the diagram found at https://github.com/dashbored/word-clock.
 * 
 * All LEDs are lit at the push at the end.
 * 
 */


void theTime(int hour_holder, int minute_holder) {
  DateTime now = rtc.now(); // Shortened for readability.
  memset(pixel,0,sizeof(pixel)); // Set all pixels "off" before configuring them. Will not affect update frequency as all lights are pushed at the same time last.
 int minute = now.minute() + minute_holder; // minutes shortened for readability.
 int hour = now.hour() + hour_holder; // hour shortened for readability.

  if (hour > 23) {
    hour = hour - 24;
  }

  if (minute > 59) {
    minute = minute - 60;
  }

  
// Follow code lights up the corresponding LED:s
Serial.print(" Hour = ");
Serial.print(hour);
Serial.print(" Minute = ");
Serial.print(minute);
Serial.print(" Second = ");
Serial.println(now.second());

// ALWAYS LIT.
// --------------------------------------------------------------------
  for(int i=137; i<144; i++)  {   // "KLOCKAN".
    pixel[i] = 1; 
  }
  for(int i=134; i<136; i++)  {   // "ÄR".
    pixel[i] = 1;
  } 
// --------------------------------------------------------------------


// PRE SETS
// --------------------------------------------------------------------
  if((minute >= 5) && (minute < 25))  {   // ??:05 - ??:25 | "ÖVER"
    for(int i=110; i<114; i++)  {
      pixel[i] = 1;
    }
  } else if((minute >= 35) && (minute < 40))  {   // ??:35 - ??:40 | "ÖVER"
    for(int i=110; i<114; i++)  {
      pixel[i] = 1;                                           
    }           
  } 
  if((minute >= 25) && (minute < 40))  {   // ??:25 - ??:40 | "HALV".
      for(int i=98; i<102; i++) {
        pixel[i] = 1;                                        
      }  
  }
  if((minute >= 40) && (minute <= 59)) {    // ??:40 - ??:59 | "I".
      pixel[96] = 1;                                         
  }
  if((minute >= 25) && (minute < 30)) {    // ??:25 - ??:30 | "I".
      pixel[96] = 1;                                         
  }
// --------------------------------------------------------------------  


// MINUTES
// --------------------------------------------------------------------  
  if((minute >= 5) && (minute < 10))  {    // ??:05 - ??:10 | "FEM".   
    for(int i=129; i<132; i++)  {
      pixel[i] = 1;                                           
      }  
  } else if((minute >= 55) && (minute <= 59))  {    // ??:55 - ??:59 | "FEM".   
      for(int i=129; i<132; i++)  {
         pixel[i] = 1;                                           
      }
  } else if((minute >= 25) && (minute < 30))  {    // ??:25 - ??:29 | "FEM".   
      for(int i=129; i<132; i++)  {
         pixel[i] = 1;                                           
      }
  } else if((minute >= 35) && (minute < 40))  {    // ??:35 - ??:39 | "FEM".   
      for(int i=129; i<132; i++)  {
         pixel[i] = 1;                                           
      }
  } else if((minute >= 10) && (minute < 15))  {   // ??:10 - ??:15 | "TIO".   
      for(int i=126; i<129; i++)  {
         pixel[i] = 1;                                        
      }  
  } else if((minute >= 50) && (minute < 55))  {   // ??:50 - ??:55 | "TIO".   
      for(int i=126; i<129; i++)  {
         pixel[i] = 1;                                        
      }     
  } else if((minute >= 15) && (minute < 20))  {   // ??:15 - ??:20 | "KVART".
      for(int i=115; i<120; i++)  {
         pixel[i] = 1;                                         
      }
  } else if((minute >= 45) && (minute < 50))  {   // ??:45 - ??:50 | "KVART".
      for(int i=115; i<120; i++)  {
         pixel[i] = 1;                                         
      }
  } else if((minute >= 20) && (minute < 25))  {    // ??:20 - ??:25 | "TJUGO".
      for(int i=121; i<126; i++)  {
         pixel[i] = 1;                                        
      }        
  } else if((minute >= 40) && (minute < 45))  {    // ??:40 - ??:45 | "TJUGO".
      for(int i=121; i<126; i++)  {
         pixel[i] = 1;                                        
      }        
  }
// --------------------------------------------------------------------

//HOURS
// --------------------------------------------------------------------
  if((hour == 1 && minute < 25) || (hour == 13 && minute < 25)) {   // 01:00 - 01:24 and 13:00 - 01:24 | "ETT".
    for(int i=76; i<79; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 0 && minute >= 25) || (hour == 12 && minute >= 25)) {   // 00:25 - 01:00 and 12:25 - 13:00 | "ETT".
    for(int i=76; i<79; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 2 && minute < 25) || (hour == 14 && minute < 25)) {   // 02:00 - 02:24 and 14:00 - 14:24 | "TVÅ".
    for(int i=80; i<83; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 1 && minute >= 25) || (hour == 13 && minute >= 25)) {   // 01:25 - 02:00 and 13:25 - 14:00 | "TVÅ".
    for(int i=80; i<83; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 3 && minute < 25) || (hour == 15 && minute < 25)) {   // 03:00 - 03:24 and 15:00 - 15:24 | "TRE".
    for(int i=57; i<60; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 2 && minute >= 25) || (hour == 14 && minute >= 25)) {   // 02:25 - 03:00 and 14:25 - 15:00 | "TRE".
    for(int i=57; i<60; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 4 && minute < 25) || (hour == 16 && minute < 25)) {   // 04:00 - 04:24 and 16:00 - 16:24 | "FYRA".
    for(int i=88; i<92; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 3 && minute >= 25) || (hour == 15 && minute >= 25)) {   // 03:25 - 04:00 and 15:25 - 16:00 | "FYRA".
    for(int i=88; i<92; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 5 && minute < 25) || (hour == 17 && minute < 25)) {   // 05:00 - 05:24 and 17:00 - 17:24 | "FEM".
    for(int i=48; i<51; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 4 && minute >= 25) || (hour == 16 && minute >= 25)) {   // 04:25 - 05:00 and 16:25 - 17:00 | "FEM".
    for(int i=48; i<51; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 6 && minute < 25) || (hour == 18 && minute < 25)) {   // 06:00 - 06:24 and 18:00 - 18:24 | "SEX".
    for(int i=62; i<65; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 5 && minute >= 25) || (hour == 17 && minute >= 25)) {   // 05:25 - 06:00 and 17:25 - 18:00 | "SEX".
    for(int i=62; i<65; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 7 && minute < 25) || (hour == 19 && minute < 25)) {   // 07:00 - 07:24 and 19:00 - 19:24 | "SJU".
    for(int i=51; i<54; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 6 && minute >= 25) || (hour == 18 && minute >= 25)) {   // 06:25 - 07:00 and 18:25 - 19:00 | "SJU".
    for(int i=51; i<54; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 8 && minute < 25) || (hour == 20 && minute < 25)) {   // 08:00 - 08:24 and 20:00 - 20:24 | "ÅTTA".
    for(int i=92; i<96; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 7 && minute >= 25) || (hour == 19 && minute >= 25)) {   // 07:25 - 08:00 and 19:25 - 20:00 | "ÅTTA".
    for(int i=92; i<96; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 9 && minute < 25) || (hour == 21 && minute < 25)) {   // 09:00 - 09:24 and 21:00 - 21:24 | "NIO".
    for(int i=72; i<75; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 8 && minute >= 25) || (hour == 20 && minute >= 25)) {   // 08:25 - 09:00 and 20:25 - 21:00 | "NIO".
    for(int i=72; i<75; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 10 && minute < 25) || (hour == 22 && minute < 25)) {   // 10:00 - 10:24 and 22:00 - 22:24 | "TIO".
    for(int i=54; i<57; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 9 && minute >= 25) || (hour == 21 && minute >= 25)) {   // 09:25 - 10:00 and 21:25 - 22:00 | "TIO".
    for(int i=54; i<57; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 11 && minute < 25) || (hour == 23 && minute < 25)) {   // 11:00 - 11:24 and 23:00 - 23:24 | "ELVA".
    for(int i=84; i<88; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 10 && minute >= 25) || (hour == 22 && minute >= 25)) {   // 10:25 - 11:00 and 22:25 - 23:00 | "ELVA".
    for(int i=84; i<88; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 12 && minute < 25) || (hour == 0 && minute < 25)) {   // 12:00 - 12:24 and 00:00 - 00:24 | "TOLV".
    for(int i=66; i<70; i++)  {
      pixel[i] = 1;
    }
  } else if((hour == 11 && minute >= 25) || (hour == 23 && minute >= 25)) {   // 11:25 - 12:00 and 23:25 - 00:00 | "TOLV".
    for(int i=66; i<70; i++)  {
      pixel[i] = 1;
    }
  }
// --------------------------------------------------------------------

////HOURS
//// --------------------------------------------------------------------
//  if((hour == 1) || (hour == 13)) {   // 01:?? and 13:?? | "ETT".
//    for(int i=76; i<79; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 2) || (hour == 14)) {   // 02:?? and 14:?? | "TVÅ".
//    for(int i=80; i<83; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 3) || (hour == 15)) {   // 03:?? and 15:?? | "TRE".
//    for(int i=57; i<60; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 4) || (hour == 16)) {   // 04:?? and 16:?? | "FYRA".
//    for(int i=88; i<92; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 5) || (hour == 17)) {   // 05:?? and 17:?? | "FEM".
//    for(int i=48; i<51; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 6) || (hour == 18)) {   // 06:?? and 18:?? | "SEX".
//    for(int i=62; i<65; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 7) || (hour == 19)) {   // 07:?? and 19:?? | "SJU".
//    for(int i=51; i<54; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 8) || (hour == 20)) {   // 08:?? and 20:?? | "ÅTTA".
//    for(int i=92; i<96; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 9) || (hour == 21)) {   // 09:?? and 21:?? | "NIO".
//    for(int i=72; i<75; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 10) || (hour == 22)) {   // 10:?? and 22:?? | "TIO".
//    for(int i=54; i<57; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 11) || (hour == 23)) {   // 11:?? and 23:?? | "ELVA".
//    for(int i=84; i<88; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((hour == 12) || (hour == 0)) {   // 12:?? and 00:?? | "TOLV".
//    for(int i=66; i<69; i++)  {
//      pixel[i] = 1;
//    }
//  }
//// --------------------------------------------------------------------


// POST SETS - INTE FÄRDIG
// --------------------------------------------------------------------
  if(!(((hour == 0) || (hour == 12)) && ((minute >= 0) && (minute <= 5)))) {   // ??:?? != 00:??/12:?? | "PÅ".
    for(int i=44; i<46; i++)  {
      pixel[i] = 1;
    }
    if((hour >= 2) && (hour < 9))  {   // 02:?? - 08:?? | "MORGONEN".
      for(int i=27; i<35; i++)  {
        pixel[i] = 1;
      }
    } else if((hour >= 9) && (hour < 12))  {   // 09:?? - 11:?? | "FÖRMIDDAGN".
      for(int i=13; i<23; i++)  {
        pixel[i] = 1;
      }
    } else if((hour >= 12) && (hour < 17)) {   // 12:?? - 16:?? | "EFTERMIDDAGN".
      for(int i=0; i<12; i++)  {
        pixel[i] = 1;
      }
    } else if((hour >= 17) || (hour < 2)) {   // 17:?? - 01:?? | "KVÄLLEN".
      for(int i=36; i<43; i++)  {
        pixel[i] = 1;
      }
    }
  }
// --------------------------------------------------------------------


// LIGHT LED ACCORDING TO TIME
// --------------------------------------------------------------------
  for(int i=0; i<(sizeof(pixel)/sizeof(pixel[0])); i++) {   // (sizeof(pixel)/sizeof(pixel[0])) spits out an int instead of a byte which the first part spits out.
    if(pixel[i] == 1) {
      strip.setPixelColor(i, strip.Color(150, 150, 150)); // Turn on correct LEDs.
    } else {
      strip.setPixelColor(i, strip.Color(0, 0, 0)); // Turn off all other LEDs.
    }
  }

  strip.show(); // Push to strip and light it up!
  delay(100);
// --------------------------------------------------------------------



}

