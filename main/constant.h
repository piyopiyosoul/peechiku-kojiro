#ifndef _constant_h
#define _constant_h

const int channels[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
const int channelsNum = sizeof(channels) / sizeof(int);
const int UPDATE_TIME = 10; 
const float AMP = 40.0;//振幅 10 - 60 10刻み
const float PERIOD = 2300.0;//周期 1000 - 5000
const float WAVELENGTH = channelsNum * 0.5;//波長

#endif
