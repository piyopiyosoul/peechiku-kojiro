#define SERVOMIN 500    // 最小パルス幅(μs)
#define SERVOMAX 2400   // 最大パルス幅(μs)

//ライブラリの読み込む
#include<Servo.h>
#include<math.h>
#include <Wire.h>
#include "Adafruit_PWMServoDriver.h"
#include "constant.h"

// PCA9685のI2Cアドレスを指定
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

//プロトタイプ宣言
void servoMove(int ch, float degree);
void initServo();
float sinDegree(float amp, float x, float lambda, float period);

void setup() {
  //プログラムの開始を通知
  Serial.begin(9600);
  Serial.println("---PROGRAM STARTS");

  pwm.begin();
  pwm.setPWMFreq(50);

  //サーボモータの初期化
  initServo();
}

void loop() {
  for (int i = 0; i < 10; i++) {
//    servoMove(channels[i], sinDegree(AMP, i, WAVELENGTH, PERIOD));
  }
  delay(10);
}

//サーボモータ制御関数
void servoMove(int ch, float degree) {
  int angle = map(degree, 0, 180, SERVOMIN, SERVOMAX);
  pwm.writeMicroseconds(ch, angle);
}

//サーボモータの初期化関数
void initServo() {
  for (int i = 0; i < channelsNum; i++) {
    servoMove(channels[i], 0);
  }
}

float sinDegree(float amp, float x, float wavelength, float period) {
  return amp * sin(2 * PI * ((x / wavelength) + (millis() / period))) + 90;
}
