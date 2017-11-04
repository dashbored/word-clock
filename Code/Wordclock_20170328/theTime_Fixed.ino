/*
 * This function reads the RTC and lights the correct pixels according to 
 * the diagram found at https://github.com/dashbored/word-clock.
 * 
 * All LEDs are lit at the push at the end.
 * 
 */


void theTime() {
  DateTime now = rtc.now(); // Shortened for readability.
  memset(pixel,0,sizeof(pixel)); // Set all pixels "off" before configuring them. Will not affect update frequency as all lights are pushed at the same time last.
//  minute = now.minute(); // minutes shortened for readability.
//  hour = now.hour(); // hour shortened for readability.
  
// Follow code lights up the corresponding LED:s
Serial.print(" Hour = ");
Serial.print(now.hour());
Serial.print(" Minute = ");
Serial.print(now.minute());
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
  if((now.minute() >= 5) && (now.minute() < 25))  {   // ??:05 - ??:25 | "ÖVER"
    for(int i=110; i<114; i++)  {
      pixel[i] = 1;
    }
  } else if((now.minute() >= 35) && (now.minute() < 40))  {   // ??:35 - ??:40 | "ÖVER"
    for(int i=110; i<114; i++)  {
      pixel[i] = 1;                                           
    }           
  } else if((now.minute() >= 25) && (now.minute() < 40))  {   // ??:25 - ??:40 | "HALV".
      for(int i=98; i<102; i++) {
        pixel[i] = 1;                                        
      }  
  } else if((now.minute() >= 40) && (now.minute() <= 59)) {    // ??:40 - ??:59 | "I".
      pixel[96] = 1;                                         
  } 
  else if((now.minute() >= 25) && (now.minute() < 30)) {    // ??:25 - ??:30 | "I".
      pixel[96] = 1;                                         
  }
// --------------------------------------------------------------------  


// MINUTES
// --------------------------------------------------------------------  
  if((now.minute() >= 5) && (now.minute() < 10))  {    // ??:05 - ??:10 | "FEM".   
    for(int i=129; i<132; i++)  {
      pixel[i] = 1;                                           
      }  
  } else if((now.minute() >= 55) && (now.minute() <= 59))  {    // ??:55 - ??:59 | "FEM".   
      for(int i=129; i<132; i++)  {
         pixel[i] = 1;                                           
      }
  } else if((now.minute() >= 10) && (now.minute() < 15))  {   // ??:10 - ??:15 | "TIO".   
      for(int i=126; i<129; i++)  {
         pixel[i] = 1;                                        
      }  
  } else if((now.minute() >= 50) && (now.minute() < 55))  {   // ??:50 - ??:55 | "TIO".   
      for(int i=126; i<129; i++)  {
         pixel[i] = 1;                                        
      }     
  } else if((now.minute() >= 15) && (now.minute() < 20))  {   // ??:15 - ??:20 | "KVART".
      for(int i=114; i<119; i++)  {
         pixel[i] = 1;                                         
      }
  } else if((now.minute() >= 45) && (now.minute() < 50))  {   // ??:45 - ??:50 | "KVART".
      for(int i=114; i<119; i++)  {
         pixel[i] = 1;                                         
      }
  } else if((now.minute() >= 20) && (now.minute() < 25))  {    // ??:20 - ??:25 | "TJUGO".
      for(int i=121; i<126; i++)  {
         pixel[i] = 1;                                        
      }        
  } else if((now.minute() >= 40) && (now.minute() < 45))  {    // ??:40 - ??:45 | "TJUGO".
      for(int i=121; i<126; i++)  {
         pixel[i] = 1;                                        
      }        
  }
// --------------------------------------------------------------------

//HOURS
// --------------------------------------------------------------------
  if((now.hour() == 1 && now.minute() < 30) || (now.hour() == 13 && now.minute() < 30)) {   // 01:00 - 01:29 and 13:00 - 01:29 | "ETT".
    for(int i=76; i<79; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 0 && now.minute() => 30) || (now.hour() == 12 && now.minute() => 30)) {   // 00:30 - 01:00 and 12:30 - 13:00 | "ETT".
    for(int i=76; i<79; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 2 && now.minute() < 30) || (now.hour() == 14 && now.minute() < 30)) {   // 02:00 - 02:29 and 14:00 - 14:29 | "TVÅ".
    for(int i=80; i<83; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 1 && now.minute() => 30) || (now.hour() == 13 && now.minute() => 30)) {   // 01:30 - 02:00 and 13:30 - 14:00 | "TVÅ".
    for(int i=80; i<83; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 3 && now.minute() < 30) || (now.hour() == 15 && now.minute() < 30)) {   // 03:00 - 03:29 and 15:00 - 15:29 | "TRE".
    for(int i=57; i<60; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 2 && now.minute() => 30) || (now.hour() == 14 && now.minute() => 30)) {   // 02:30 - 03:00 and 14:30 - 15:00 | "TRE".
    for(int i=57; i<60; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 4 && now.minute() < 30) || (now.hour() == 16 && now.minute() < 30)) {   // 04:00 - 04:29 and 16:00 - 16:29 | "FYRA".
    for(int i=88; i<92; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 3 && now.minute() => 30) || (now.hour() == 15 && now.minute() => 30)) {   // 03:30 - 04:00 and 15:30 - 16:00 | "FYRA".
    for(int i=88; i<92; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 5 && now.minute() < 30) || (now.hour() == 17 && now.minute() < 30)) {   // 05:00 - 05:29 and 17:00 - 17:29 | "FEM".
    for(int i=48; i<51; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 4 && now.minute() => 30) || (now.hour() == 16 && now.minute() => 30)) {   // 04:30 - 05:00 and 16:30 - 17:00 | "FEM".
    for(int i=48; i<51; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 6 && now.minute() < 30) || (now.hour() == 18 && now.minute() < 30)) {   // 06:00 - 06:29 and 18:00 - 18:29 | "SEX".
    for(int i=62; i<65; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 5 && now.minute() => 30) || (now.hour() == 17 && now.minute() => 30)) {   // 05:30 - 06:00 and 17:30 - 18:00 | "SEX".
    for(int i=62; i<65; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 7 && now.minute() < 30) || (now.hour() == 19 && now.minute() < 30)) {   // 07:00 - 07:29 and 19:00 - 19:29 | "SJU".
    for(int i=51; i<54; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 6 && now.minute() => 30) || (now.hour() == 18 && now.minute() => 30)) {   // 06:30 - 07:00 and 18:30 - 19:00 | "SJU".
    for(int i=51; i<54; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 8 && now.minute() < 30) || (now.hour() == 20 && now.minute() < 30)) {   // 08:00 - 08:29 and 20:00 - 20:29 | "ÅTTA".
    for(int i=92; i<96; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 7 && now.minute() => 30) || (now.hour() == 19 && now.minute() => 30)) {   // 07:30 - 08:00 and 19:30 - 20:00 | "ÅTTA".
    for(int i=92; i<96; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 9 && now.minute() < 30) || (now.hour() == 21 && now.minute() < 30)) {   // 09:00 - 09:29 and 21:00 - 21:29 | "NIO".
    for(int i=72; i<75; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 8 && now.minute() => 30) || (now.hour() == 20 && now.minute() => 30)) {   // 08:30 - 09:00 and 20:30 - 21:00 | "NIO".
    for(int i=72; i<75; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 10 && now.minute() < 30) || (now.hour() == 22 && now.minute() < 30)) {   // 10:00 - 10:29 and 22:00 - 22:29 | "TIO".
    for(int i=54; i<57; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 9 && now.minute() => 30) || (now.hour() == 21 && now.minute() => 30)) {   // 09:30 - 10:00 and 21:30 - 22:00 | "TIO".
    for(int i=54; i<57; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 11 && now.minute() < 30) || (now.hour() == 23 && now.minute() < 30)) {   // 11:00 - 11:29 and 23:00 - 23:29 | "ELVA".
    for(int i=84; i<88; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 10 && now.minute() => 30) || (now.hour() == 22 && now.minute() => 30)) {   // 10:30 - 11:00 and 22:30 - 23:00 | "ELVA".
    for(int i=84; i<88; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 12 && now.minute() < 30) || (now.hour() == 0 && now.minute() < 30)) {   // 12:00 - 12:29 and 00:00 - 00:29 | "TOLV".
    for(int i=66; i<69; i++)  {
      pixel[i] = 1;
    }
  } else if((now.hour() == 11 && now.minute() => 30) || (now.hour() == 23 && now.minute() => 30)) {   // 11:30 - 12:00 and 23:30 - 00:00 | "TOLV".
    for(int i=66; i<69; i++)  {
      pixel[i] = 1;
    }
  }
// --------------------------------------------------------------------

////HOURS
//// --------------------------------------------------------------------
//  if((now.hour() == 1) || (now.hour() == 13)) {   // 01:?? and 13:?? | "ETT".
//    for(int i=76; i<79; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 2) || (now.hour() == 14)) {   // 02:?? and 14:?? | "TVÅ".
//    for(int i=80; i<83; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 3) || (now.hour() == 15)) {   // 03:?? and 15:?? | "TRE".
//    for(int i=57; i<60; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 4) || (now.hour() == 16)) {   // 04:?? and 16:?? | "FYRA".
//    for(int i=88; i<92; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 5) || (now.hour() == 17)) {   // 05:?? and 17:?? | "FEM".
//    for(int i=48; i<51; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 6) || (now.hour() == 18)) {   // 06:?? and 18:?? | "SEX".
//    for(int i=62; i<65; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 7) || (now.hour() == 19)) {   // 07:?? and 19:?? | "SJU".
//    for(int i=51; i<54; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 8) || (now.hour() == 20)) {   // 08:?? and 20:?? | "ÅTTA".
//    for(int i=92; i<96; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 9) || (now.hour() == 21)) {   // 09:?? and 21:?? | "NIO".
//    for(int i=72; i<75; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 10) || (now.hour() == 22)) {   // 10:?? and 22:?? | "TIO".
//    for(int i=54; i<57; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 11) || (now.hour() == 23)) {   // 11:?? and 23:?? | "ELVA".
//    for(int i=84; i<88; i++)  {
//      pixel[i] = 1;
//    }
//  } else if((now.hour() == 12) || (now.hour() == 0)) {   // 12:?? and 00:?? | "TOLV".
//    for(int i=66; i<69; i++)  {
//      pixel[i] = 1;
//    }
//  }
//// --------------------------------------------------------------------


// POST SETS - INTE FÄRDIG
// --------------------------------------------------------------------
  if(!(((now.hour() == 0) || (now.hour() == 12)) && ((now.minute() >= 0) && (now.minute() <= 5)))) {   // ??:?? != 00:??/12:?? | "PÅ".
    for(int i=44; i<46; i++)  {
      pixel[i] = 1;
    }
    if((now.hour() >= 2) && (now.hour() < 9))  {   // 02:?? - 08:?? | "MORGONEN".
      for(int i=27; i<35; i++)  {
        pixel[i] = 1;
      }
    } else if((now.hour() >= 9) && (now.hour() < 12))  {   // 09:?? - 11:?? | "FÖRMIDDAGN".
      for(int i=13; i<23; i++)  {
        pixel[i] = 1;
      }
    } else if((now.hour() >= 12) && (now.hour() < 17)) {   // 12:?? - 16:?? | "EFTERMIDDAGN".
      for(int i=0; i<12; i++)  {
        pixel[i] = 1;
      }
    } else if((now.hour() >= 17) && (now.hour() < 2)) {   // 17:?? - 01:?? | "KVÄLLEN".
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
