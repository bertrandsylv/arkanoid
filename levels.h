#ifndef __LEVELS_H__
#define __LEVELS_H__

#include <Arduboy2.h>

#define NB_OF_LEVELS 5

const char* levelTest =  "00000000000"
                      "00000000000"
                      "00000000000"
                      "01234567890"
                      "00000000000"
                      "00000000000";


const char* level0 =  "00000000000"
                      "01111111110"
                      "01111111110"
                      "01111111110"
                      "01111111110"
                      "00000000000";

const char* level1 =  "22222222222"
                      "20000000002"
                      "20011111002"
                      "20011111002"
                      "20000000002"
                      "22222222222";

const char* level2 =  "04440004440"
                      "04004040040"
                      "04000400040"
                      "04040004040"
                      "04000400040"
                      "00444044400";
                   
const char* level3 =  "77777777777"
                      "70000000777"
                      "70000077007"
                      "70077700007"
                      "77700000007"
                      "77777777777";


const char* levels[] = {level0, levelTest, level1, level2, level3};


#endif
