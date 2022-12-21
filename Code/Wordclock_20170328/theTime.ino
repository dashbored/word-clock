/*
 * This function reads the RTC and lights the correct pixels according to 
 * the diagram found at https://github.com/dashbored/word-clock.
 * 
 * All LEDs are lit at the push at the end.
 * 
 */


void theTime(int hourAdjust, int minuteAdjust) {
  DateTime now = rtc.now(); // Shortened for readability.
  memset(pixel,0,sizeof(pixel)); // Set all pixels "off" before configuring them. Will not affect update frequency as all lights are pushed at the same time last.
 int minute = now.minute() + minuteAdjust; // minutes shortened for readability.
 int hour = now.hour() + hourAdjust; // hour shortened for readability.

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

// // ALWAYS LIT.
// // --------------------------------------------------------------------
//   for(int i=137; i<144; i++)  {   // "KLOCKAN".
//     pixel[i] = 1; 
//   }
//   for(int i=134; i<136; i++)  {   // "ÄR".
//     pixel[i] = 1;
//   } 
// // --------------------------------------------------------------------


// PRE SETS
// --------------------------------------------------------------------
  if(
      ((minute >= 5) && (minute < 25)) ||     // ??:05 - ??:25 | "ÖVER"
      ((minute >= 35) && (minute < 40))       // ??:35 - ??:40 | "ÖVER"
    )  {   
    for(int i=110; i<114; i++)  {
      pixel[i] = 1;
    }
  } else if(
      (minute >= 25) && (minute < 40)         // ??:25 - ??:40 | "HALV".
    )  {   
    for(int i=98; i<102; i++) {
      pixel[i] = 1;                                        
    }  
  } else if(
      ((minute >= 40) && (minute <= 59)) ||   // ??:40 - ??:59 | "I".
      ((minute >= 25) && (minute < 30))       // ??:25 - ??:30 | "I".
    )  {    
      pixel[96] = 1;                                         
  } 
// --------------------------------------------------------------------  


// MINUTES
// --------------------------------------------------------------------  
  if(
      ((minute >= 5) && (minute < 10)) ||     // ??:05 - ??:10 | "FEM".  
      ((minute >= 55) && (minute <= 59))      // ??:55 - ??:59 | "FEM".
    )  {     
    for(int i=129; i<132; i++)  {
      pixel[i] = 1;                                           
      }  
  } else if(
      ((minute >= 10) && (minute < 15)) ||    // ??:10 - ??:15 | "TIO".
      ((minute >= 50) && (minute < 55))       // ??:50 - ??:55 | "TIO".   
    )  {      
      for(int i=126; i<129; i++)  {
         pixel[i] = 1;                                        
      }  
  } else if(
      ((minute >= 15) && (minute < 20)) ||    // ??:15 - ??:20 | "KVART".
      ((minute >= 45) && (minute < 50))       // ??:45 - ??:50 | "KVART".
    )  {   
      for(int i=114; i<119; i++)  {
         pixel[i] = 1;                                         
      }
  } else if(
      ((minute >= 20) && (minute < 25)) ||    // ??:20 - ??:25 | "TJUGO".
      ((minute >= 40) && (minute < 45))       // ??:40 - ??:45 | "TJUGO".
    )  {    
      for(int i=121; i<126; i++)  {
         pixel[i] = 1;                                        
      }        
  }
// --------------------------------------------------------------------

//HOURS
// --------------------------------------------------------------------
  if(
      ((hour == 1 && minute < 30) || (hour == 13 && minute < 30)) ||    // 01:00 - 01:29 and 13:00 - 01:29 | "ETT".
      ((hour == 0 && minute >= 30) || (hour == 12 && minute >= 30))     // 00:30 - 01:00 and 12:30 - 13:00 | "ETT".
    ) {   
    for(int i=76; i<79; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 2 && minute < 30) || (hour == 14 && minute < 30)) ||    // 02:00 - 02:29 and 14:00 - 14:29 | "TVÅ".
      ((hour == 1 && minute >= 30) || (hour == 13 && minute >= 30))     // 01:30 - 02:00 and 13:30 - 14:00 | "TVÅ".
    ) {   
    for(int i=80; i<83; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 3 && minute < 30) || (hour == 15 && minute < 30)) ||    // 03:00 - 03:29 and 15:00 - 15:29 | "TRE".
      ((hour == 2 && minute >= 30) || (hour == 14 && minute >= 30))     // 02:30 - 03:00 and 14:30 - 15:00 | "TRE".
    ) {   
    for(int i=57; i<60; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 4 && minute < 30) || (hour == 16 && minute < 30)) ||    // 04:00 - 04:29 and 16:00 - 16:29 | "FYRA".
      ((hour == 3 && minute >= 30) || (hour == 15 && minute >= 30))     // 03:30 - 04:00 and 15:30 - 16:00 | "FYRA".
    ) {   
    for(int i=88; i<92; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 5 && minute < 30) || (hour == 17 && minute < 30)) ||    // 05:00 - 05:29 and 17:00 - 17:29 | "FEM".
      ((hour == 4 && minute >= 30) || (hour == 16 && minute >= 30))     // 04:30 - 05:00 and 16:30 - 17:00 | "FEM".
    )  {   
    for(int i=48; i<51; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 6 && minute < 30) || (hour == 18 && minute < 30)) ||    // 06:00 - 06:29 and 18:00 - 18:29 | "SEX".
      ((hour == 5 && minute >= 30) || (hour == 17 && minute >= 30))     // 05:30 - 06:00 and 17:30 - 18:00 | "SEX".
    ) {   
    for(int i=62; i<65; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 7 && minute < 30) || (hour == 19 && minute < 30)) ||    // 07:00 - 07:29 and 19:00 - 19:29 | "SJU".
      ((hour == 6 && minute >= 30) || (hour == 18 && minute >= 30))     // 06:30 - 07:00 and 18:30 - 19:00 | "SJU".
    ) {   
    for(int i=51; i<54; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 8 && minute < 30) || (hour == 20 && minute < 30)) ||    // 08:00 - 08:29 and 20:00 - 20:29 | "ÅTTA".
      ((hour == 7 && minute >= 30) || (hour == 19 && minute >= 30))     // 07:30 - 08:00 and 19:30 - 20:00 | "ÅTTA".        
    ) {   
    for(int i=92; i<96; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 9 && minute < 30) || (hour == 21 && minute < 30)) ||    // 09:00 - 09:29 and 21:00 - 21:29 | "NIO".
      ((hour == 8 && minute >= 30) || (hour == 20 && minute >= 30))     // 08:30 - 09:00 and 20:30 - 21:00 | "NIO".
    ) {   
    for(int i=72; i<75; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 10 && minute < 30) || (hour == 22 && minute < 30)) ||   // 10:00 - 10:29 and 22:00 - 22:29 | "TIO".
      ((hour == 9 && minute >= 30) || (hour == 21 && minute >= 30))     // 09:30 - 10:00 and 21:30 - 22:00 | "TIO".
    ) {   
    for(int i=54; i<57; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 11 && minute < 30) || (hour == 23 && minute < 30)) ||   // 11:00 - 11:29 and 23:00 - 23:29 | "ELVA".
      ((hour == 10 && minute >= 30) || (hour == 22 && minute > 30))     // 10:30 - 11:00 and 22:30 - 23:00 | "ELVA".
    ) {   
    for(int i=84; i<88; i++)  {
      pixel[i] = 1;
    }
  } else if(
      ((hour == 12 && minute < 30) || (hour == 0 && minute < 30)) ||    // 12:00 - 12:29 and 00:00 - 00:29 | "TOLV".
      ((hour == 11 && minute > 30) || (hour == 23 && minute >= 30))     // 11:30 - 12:00 and 23:30 - 00:00 | "TOLV".
    ) {   
    for(int i=66; i<69; i++)  {
      pixel[i] = 1;
    }
  }
// --------------------------------------------------------------------

// // POST SETS - INTE FÄRDIG
// // --------------------------------------------------------------------
//   if(!(((hour == 0) || (hour == 12)) && ((minute >= 0) && (minute <= 5)))) {   // ??:?? != 00:??/12:?? | "PÅ".
//     for(int i=44; i<46; i++)  {
//       pixel[i] = 1;
//     }
//     if((hour >= 2) && (hour < 9))  {   // 02:?? - 08:?? | "MORGONEN".
//       for(int i=27; i<35; i++)  {
//         pixel[i] = 1;
//       }
//     } else if((hour >= 9) && (hour < 12))  {   // 09:?? - 11:?? | "FÖRMIDDAGN".
//       for(int i=13; i<23; i++)  {
//         pixel[i] = 1;
//       }
//     } else if((hour >= 12) && (hour < 17)) {   // 12:?? - 16:?? | "EFTERMIDDAGN".
//       for(int i=0; i<12; i++)  {
//         pixel[i] = 1;
//       }
//     } else if((hour >= 17) || (hour < 2)) {   // 17:?? - 01:?? | "KVÄLLEN".
//       for(int i=36; i<43; i++)  {
//         pixel[i] = 1;
//       }
//     }
//   }
// // --------------------------------------------------------------------


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

