#include <xCore.h>  //add core library
#include <xSW01.h>  //add weather sensor library
#include <xOD01.h>

xSW01 SW01;

const int DelayTime = 500; //Defining set delay time that could be used elsewhere in the code

//Create a variable to store the data read from SW01
float dew_point;

void setup(){

  //Initialise variables to zero
  dew_point = 0;
  
  //Start Serial Monitor
  Serial.begin(115200);

  //Start I2C communication
  Wire.begin(2, 14);

  //Start SW01 Sensor
  SW01.begin();
  OLED.begin();
  
  //String intro for project
  OD01.println("Dew Point");
  OD01.println("____________________________");

  //Delay for sensor to normalise
  delay(3000);
  
}

void loop(){
  
  //Read and calculate data from SW01
  SW01.poll();

  //Request to get humidity, temperature and dew point data then store in the variables
  dew_point = SW01.getDewPoint();


  //Display recorded data over the Serial Monitor

  OD01.print("Dew Point:");
  OD01.print(dew_point);
  OD01.println("℃ ");
 

  delay(5000);

}

