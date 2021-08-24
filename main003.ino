//ライブラリの読み込む
#include<Servo.h>
#include<math.h>

const int period = 2000;

//サーボモータ制御の変数宣言
Servo myServo[11];

//プロトタイプ宣言
void initServo();
float waveDegree(float amp, float phase);

void setup(){
    //シリアル通信開始4秒後にプログラムの開始を通知
    Serial.begin(9600);
    delay(4000);
    Serial.println("---PROGRAM STARTS");
    
    //各サーボモータの準備
    for (int i = 0; i < 11; i++){
        pinMode(i, OUTPUT);
        myServo[i].attach(i);
    }
    
    //サーボモータの初期化
    initServo();
}

void loop(){
    //サーボモータ制御
    for (int i = 0; i < 11; i++){
        myServo[i].write(waveDegree(40, 2*M_1_PI*i/11));
    }
    
    //サーボモータへの負荷軽減
    delay(100);
}

//サーボモータの初期化関数
void initServo(){
    for (int i = 0; i < 11; i++){
        myServo[i].write(90);
    }
}

//サーボモータ制御関数
float waveDegree(float amp, float phase){
  return amp*sin((millis()/period)*2*M_PI+phase)+90;
}
