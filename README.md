# Arduino & IoT Projects Collection 🚀

A curated collection of hands-on Arduino and Internet of Things (IoT) projects, ranging from beginner-friendly tutorials to more advanced integrations. This repository serves as a practical learning resource for electronics enthusiasts, students, and hobbyists.

---

## 📖 Table of Contents

* [Overview](#-overview)
* [🛠️ Technologies & Components Used](#️-technologies--components-used)
* [📂 Project List](#-project-list)
* [🚀 Getting Started](#-getting-started)
* [📁 Repository Structure](#-repository-structure)
* [🤝 Contributing](#-contributing)
* [📜 License](#-license)
* [📞 Contact](#-contact)

---

## 📖 Overview

This repository contains practical implementations of core Arduino and IoT concepts. Each project is designed to demonstrate a specific set of skills, from basic sensor reading and actuator control to cloud connectivity and smartphone integration. The code is well-commented and the circuits are designed for clarity and learning.

---

## 🛠️ Technologies & Components Used

### 🖥 Microcontrollers
- **Arduino UNO / Nano / Mega** → Core controller for robots, vending machines, sensor-based systems, and automation projects.  
- **ESP32 / ESP32-CAM** → Smart irrigation system, surveillance car robot, motor control (RemoteXY).  
- **NodeMCU (ESP8266)** → Solar panel tracker system and IoT-based applications.  

---

### 📡 Sensors & Modules
- **Ultrasonic Sensors (HC-SR04)** → Obstacle avoiding robots, parking system, radar project.  
- **IR Sensors** → Line follower robots (2, 3, and 4 IR variations).  
- **GPS Module** → Arduino V2V system with NRF GPS module.  
- **GSR Sensor** → Raw data dumper to Excel + LCD I2C.  
- **Flex Sensors** → Flex glove PC mouse control, Parkinson’s disease arm project.  
- **Moisture Sensor** → Soil monitoring and irrigation systems.  
- **Pressure Sensor** → Water pressure motor control.  
- **Gas / Air Quality Sensors** → Air quality monitoring station.  
- **Proximity Sensor** → Massage chair control unit.  
- **Fire Sensor / Flame Detector** → Fire alarm system.  
- **Temperature & Weather Sensors (DHT, BMP, etc.)** → Weather station Tx/Rx with NRF + OLED.  
- **Color Sensor** → Color sorter project.  

---

### ⚙️ Actuators & Outputs
- **Motors (DC, Servo, Stepper)** → Self-balancing robots, robotic arms, drones, RC airplanes, wire bending machine.  
- **Motor Driver (L298N)** → Motor-controlled robots.  
- **Relays** → Irrigation pump/motor control.  
- **LEDs & LED Matrix** → 8x8 LED Matrix (MAX7219).  
- **Displays**:  
  - LCD (I2C) → Moisture data dumper, sensor visualizations.  
  - 7-segment → Massage chair control unit.  
  - TFT Display → Flappy Bird game.  
  - OLED → Weather station receiver.  
  - Projection Glasses → Voltameter project.  
- **Servo Mechanisms** → Robot arms, flex-controlled servos, gimbals.  

---

### 🌍 Communication & IoT
- **NRF24L01** →  
  - Weather station Tx/Rx  
  - V2V system with GPS  
  - RC airplanes with NRF24L01  
  - Robots with NRF-based control  
- **Bluetooth (HC-05/HC-06)** → Robot with BT control, robotic arm with smartphone.  
- **WiFi (ESP8266/ESP32)** → ESP32 irrigation with Blynk, ESP32 surveillance car, motor control via RemoteXY.  
- **Processing IDE** → Radar project visualization.  
- **RemoteXY** → ESP32 motor remote control.  

---

### 🛠 Platforms & Libraries
- **Arduino IDE** → Main development environment.  
- **FreeRTOS** → Fire alarm system, vending machine (car-FreeRTOS), XYZ shape/size finder.  
- **Blynk** → IoT-based smart irrigation system.  
- **Processing** → Radar system visualization.  
- **Firebase** → IoT data logging and backend integration.  

---

## 📂 Project List

Here's a summary of the projects included in this repo:

| Project Name                                                             | Link                                                                                                                                                                  | Microcontroller                 | Key Components                   | Description                                             |
| ------------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------- | -------------------------------- | ------------------------------------------------------- |
| 8\_8\_LED\_Matrix\_MAX7219                                               | [8\_8\_LED\_Matrix\_MAX7219](./8_8_LED_Matrix_MAX7219)                                                                                                                | Arduino Uno                     | MAX7219, 8×8 LED Matrix          | Displays text and patterns on LED matrix.               |
| ARDUINO\_\_OBSTACLE\_AVOIDING\_ROBOT\_USING\_3\_ULTRASONIC\_SENSOR       | [ARDUINO\_\_OBSTACLE\_AVOIDING\_ROBOT\_USING\_3\_ULTRASONIC\_SENSOR](./ARDUINO__OBSTACLE_AVOIDING_ROBOT_USING_3_ULTRASONIC_SENSOR)                                    | Arduino Uno                     | 3× HC-SR04, Motors, L298N        | Obstacle-avoiding robot using three ultrasonic sensors. |
| Arduino Flex Sensor Glove Control Pc                                     | [Arduino Flex Sensor Glove Control Pc/lastvsystem](./Arduino%20Flex%20Sensor%20Glove%20Control%20Pc/lastvsystem)                                                      | Arduino Uno                     | Flex sensors, Glove              | Gesture-controlled glove for PC input.                  |
| Arduino Glove Control Pc Mouse                                           | [Arduino Glove Control Pc Mouse/flex\_sensor\_mouse\_control](./Arduino%20Glove%20Control%20Pc%20Mouse/flex_sensor_mouse_control)                                     | Arduino Uno                     | Flex sensors                     | Glove acts as a mouse to control PC.                    |
| Arduino HealthCare System For Hospitals                                  | [Arduino HealthCare System For Hospitals](./Arduino%20HealthCare%20System%20For%20Hospitals)                                                                          | Arduino Uno                     | Sensors (Temp, HR), LCD          | Monitors patient health in hospitals.                   |
| Arduino Shoulder Excersises System                                       | [Arduino Shoulder Excersises System](./Arduino%20Shoulder%20Excersises%20System)                                                                                      | Arduino Uno                     | Sensors, Servo                   | Rehabilitation system for shoulder exercises.           |
| Arduino Smart Voting System                                              | [Arduino Smart Voting System/Smart\_Vote](./Arduino%20Smart%20Voting%20System/Smart_Vote)                                                                             | Arduino Uno                     | Keypad, LCD, EEPROM              | Secure electronic voting machine.                       |
| Arduino Solar Panel Tracker System                                       | [Arduino Solar Panel Tracker System/NodeMCU](./Arduino%20Solar%20Panel%20Tracker%20System/NodeMCU)                                                                    | NodeMCU ESP8266                 | LDRs, Servo                      | Tracks sunlight to optimize solar energy.               |
| Arduino V2V System With NRF GPS Module                                   | [Arduino V2V System With NRF GPS Module](./Arduino%20V2V%20System%20With%20NRF%20GPS%20Module)                                                                        | Arduino Uno                     | NRF24L01, GPS                    | Vehicle-to-vehicle communication system.                |
| Arduino Voltameter Glasses Projection                                    | [Arduino Voltameter Glasses Projection](./Arduino%20Voltameter%20Glasses%20Projection)                                                                                | Arduino Uno                     | Display, Sensors                 | Glasses project for voltmeter readings.                 |
| Arduino Water Pressure Sensor Control Motor                              | [Arduino Water Pressure Sensor Control Motor/water\_pressure\_sensor\_control](./Arduino%20Water%20Pressure%20Sensor%20Control%20Motor/water_pressure_sensor_control) | Arduino Uno                     | Pressure sensor, Motor, Relay    | Controls motor based on water pressure.                 |
| Arduino-Gesture-Control-Robot                                            | [Arduino-Gesture-Control-Robot](./Arduino-Gesture-Control-Robot)                                                                                                      | Arduino Uno                     | Accelerometer, RF                | Robot controlled by hand gestures.                      |
| Arduino\_3D\_Wire\_Bending\_Machine                                      | [Arduino\_3D\_Wire\_Bending\_Machine](./Arduino_3D_Wire_Bending_Machine)                                                                                              | Arduino Uno                     | Stepper motors, Frame            | Automates 3D wire bending process.                      |
| Arduino\_3\_Vending\_Machine\_With\_Car\_FreeRTOS\_Project               | [Arduino\_3\_Vending\_Machine\_With\_Car\_FreeRTOS\_Project](./Arduino_3_Vending_Machine_With_Car_FreeRTOS_Project)                                                   | Arduino Uno                     | Motors, FreeRTOS                 | Vending machine with car demo using FreeRTOS.           |
| Arduino\_Air\_Quality\_Monitoring\_System                                | [Arduino\_Air\_Quality\_Monitoring\_System](./Arduino_Air_Quality_Monitoring_System)                                                                                  | Arduino Uno                     | MQ sensors, LCD                  | Monitors air quality and displays results.              |
| Arduino\_Camera\_Slider                                                  | [Arduino\_Camera\_Slider](./Arduino_Camera_Slider)                                                                                                                    | Arduino Uno                     | Stepper motor, Rails             | Automated camera slider for smooth shots.               |
| Arduino\_Color\_Sorter\_Project                                          | [Arduino\_Color\_Sorter\_Project](./Arduino_Color_Sorter_Project)                                                                                                     | Arduino Uno                     | Color sensor, Servo              | Sorts objects based on color.                           |
| Arduino\_Door\_Lock\_Access\_Control\_Project                            | [Arduino\_Door\_Lock\_Access\_Control\_Project](./Arduino_Door_Lock_Access_Control_Project)                                                                           | Arduino Uno                     | Keypad/RFID, Servo               | Smart door lock with authentication.                    |
| Arduino\_Fire\_Alarm\_System\_With\_Free\_RTOS                           | [Arduino\_Fire\_Alarm\_System\_With\_Free\_RTOS](./Arduino_Fire_Alarm_System_With_Free_RTOS)                                                                          | Arduino Uno                     | Flame sensor, Buzzer, FreeRTOS   | Fire alarm system with multitasking.                    |
| Arduino\_Flappy\_Bird\_Game\_With\_TFT                                   | [Arduino\_Flappy\_Bird\_Game\_With\_TFT](./Arduino_Flappy_Bird_Game_With_TFT)                                                                                         | Arduino Uno                     | TFT Display, Buttons             | Flappy Bird clone on Arduino TFT.                       |
| Arduino\_L298N\_Driver\_Robot                                            | [Arduino\_L298N\_Driver\_Robot](./Arduino_L298N_Driver_Robot)                                                                                                         | Arduino Uno                     | L298N, Motors                    | Robot controlled via L298N motor driver.                |
| Arduino\_Line\_Follower\_Robot\_with\_2\_IR\_Sensor                      | [Arduino\_Line\_Follower\_Robot\_with\_2\_IR\_Sensor](./Arduino_Line_Follower_Robot_with_2_IR_Sensor)                                                                 | Arduino Uno                     | 2× IR sensors, Motors            | Basic line follower using 2 sensors.                    |
| Arduino\_Line\_Follower\_Robot\_with\_3\_IR\_Sensor                      | [Arduino\_Line\_Follower\_Robot\_with\_3\_IR\_Sensor](./Arduino_Line_Follower_Robot_with_3_IR_Sensor)                                                                 | Arduino Uno                     | 3× IR sensors, Motors            | More accurate line following.                           |
| Arduino\_Line\_Follower\_Robot\_with\_4\_IR\_Sensor                      | [Arduino\_Line\_Follower\_Robot\_with\_4\_IR\_Sensor](./Arduino_Line_Follower_Robot_with_4_IR_Sensor)                                                                 | Arduino Uno                     | 4× IR sensors, Motors            | Advanced line follower.                                 |
| Arduino\_Message\_Chair\_Control\_Unit\_\_7seg\_-*encoder*-*proximity*   | [Arduino\_Message\_Chair\_Control\_Unit\_\_7seg\_-*encoder*-*proximity*](./Arduino_Message_Chair_Control_Unit__7seg_-_encoder_-_proximity_)                           | Arduino Uno                     | 7-seg, Encoder, Proximity sensor | Smart chair with controls & indicators.                 |
| Arduino\_Moisture\_Data\_Dumper\_With\_LCD\_I2C                          | [Arduino\_Moisture\_Data\_Dumper\_With\_LCD\_I2C](./Arduino_Moisture_Data_Dumper_With_LCD_I2C)                                                                        | Arduino Uno                     | Soil moisture sensor, LCD I2C    | Logs soil moisture readings.                            |
| Arduino\_Parking\_system                                                 | [Arduino\_Parking\_system](./Arduino_Parking_system)                                                                                                                  | Arduino Uno                     | Ultrasonic sensors, Display      | Parking assistant system.                               |
| Arduino\_Programable\_ON\_OFF\_Timer                                     | [Arduino\_Programable\_ON\_OFF\_Timer](./Arduino_Programable_ON_OFF_Timer)                                                                                            | Arduino Uno                     | RTC, LCD, Relay                  | Programmable timer for automation.                      |
| Arduino\_RC\_Airplane\_With\_Nrf24l01                                    | [Arduino\_RC\_Airplane\_With\_Nrf24l01](./Arduino_RC_Airplane_With_Nrf24l01)                                                                                          | Arduino Uno                     | NRF24L01, Motors, Servos         | RC airplane with wireless control.                      |
| Arduino\_RC\_Airplane\_With\_Nrf24l01\_Receiver                          | [Arduino\_RC\_Airplane\_With\_Nrf24l01\_Receiver](./Arduino_RC_Airplane_With_Nrf24l01_Receiver)                                                                       | Arduino Uno                     | NRF24L01, Receiver module        | Receiver for RC airplane project.                       |
| Arduino\_RC\_Receiver                                                    | [Arduino\_RC\_Receiver](./Arduino_RC_Receiver)                                                                                                                        | Arduino Uno                     | RF Receiver                      | Generic RC receiver module.                             |
| Arduino\_RC\_Transmitter                                                 | [Arduino\_RC\_Transmitter](./Arduino_RC_Transmitter)                                                                                                                  | Arduino Uno                     | RF Transmitter                   | Generic RC transmitter module.                          |
| Arduino\_Radar\_Project                                                  | [Arduino\_Radar\_Project](./Arduino_Radar_Project)                                                                                                                    | Arduino Uno                     | Servo, HC-SR04                   | Ultrasonic radar scanner.                               |
| Arduino\_Radar\_Project\_Processing                                      | [Arduino\_Radar\_Project\_Processing](./Arduino_Radar_Project_Processing)                                                                                             | Arduino Uno + Processing        | Servo, HC-SR04, Processing       | Radar visualized on Processing IDE.                     |
| Arduino\_Range\_Measurer\_and\_Digital\_Spirit\_Level                    | [Arduino\_Range\_Measurer\_and\_Digital\_Spirit\_Level](./Arduino_Range_Measurer_and_Digital_Spirit_Level)                                                            | Arduino Uno                     | Accelerometer, HC-SR04           | Measures distance & angle.                              |
| Arduino\_Raw\_Data\_GSR\_Sensor\_Dumper\_in\_Excel\_Sheet\_And\_LCD\_I2C | [Arduino\_Raw\_Data\_GSR\_Sensor\_Dumper\_in\_Excel\_Sheet\_And\_LCD\_I2C](./Arduino_Raw_Data_GSR_Sensor_Dumper_in_Excel_Sheet_And_LCD_I2C)                           | Arduino Uno                     | GSR sensor, LCD I2C              | Logs galvanic skin response data.                       |
| Arduino\_Robot\_Arm\_and\_Car\_With\_Mobile\_App\_Automatic\_Operation   | [Arduino\_Robot\_Arm\_and\_Car\_With\_Mobile\_App\_Automatic\_Operation](./Arduino_Robot_Arm_and_Car_With_Mobile_App_Automatic_Operation)                             | Arduino Uno                     | Robot arm, Car, Mobile app       | Multi-purpose robotic arm + car.                        |
| Arduino\_Robot\_Arm\_with\_Smartphone\_Control                           | [Arduino\_Robot\_Arm\_with\_Smartphone\_Control](./Arduino_Robot_Arm_with_Smartphone_Control)                                                                         | Arduino Uno                     | Robot arm, Bluetooth             | Arm controlled via smartphone.                          |
| Arduino\_Robot\_With\_BT\_Control                                        | [Arduino\_Robot\_With\_BT\_Control](./Arduino_Robot_With_BT_Control)                                                                                                  | Arduino Uno                     | HC-05, Motors                    | Bluetooth-controlled robot car.                         |
| Arduino\_Robot\_with\_nrf24l01\_control                                  | [Arduino\_Robot\_with\_nrf24l01\_control](./Arduino_Robot_with_nrf24l01_control)                                                                                      | Arduino Uno                     | NRF24L01, Motors                 | RF-controlled robot car.                                |
| Arduino\_Security\_and\_Alarm\_System\_Project                           | [Arduino\_Security\_and\_Alarm\_System\_Project](./Arduino_Security_and_Alarm_System_Project)                                                                         | Arduino Uno                     | Sensors, Buzzer                  | Basic security alarm system.                            |
| Arduino\_Self\_Balancing\_Robot\_Stepper                                 | [Arduino\_Self\_Balancing\_Robot\_Stepper](./Arduino_Self_Balancing_Robot_Stepper)                                                                                    | Arduino Uno                     | Stepper motors, MPU6050          | Balancing robot with steppers.                          |
| Arduino\_Self\_Balancing\_Robot\_\_DC                                    | [Arduino\_Self\_Balancing\_Robot\_\_DC](./Arduino_Self_Balancing_Robot__DC)                                                                                           | Arduino Uno                     | DC motors, MPU6050               | Balancing robot with DC motors.                         |
| Arduino\_Self\_Stabilizing\_Gimbal                                       | [Arduino\_Self\_Stabilizing\_Gimbal](./Arduino_Self_Stabilizing_Gimbal)                                                                                               | Arduino Uno                     | MPU6050, Servos                  | Stabilizing camera gimbal.                              |
| Arduino\_Shape\_Size\_Finder\_XYZ\_With\_FreeRTOS                        | [Arduino\_Shape\_Size\_Finder\_XYZ\_With\_FreeRTOS](./Arduino_Shape_Size_Finder_XYZ_With_FreeRTOS)                                                                    | Arduino Uno                     | Ultrasonic, FreeRTOS             | Finds shape/size in 3D space.                           |
| Arduino\_Single\_Ultrasonic\_Obstical\_Avoiding                          | [Arduino\_Single\_Ultrasonic\_Obstical\_Avoiding](./Arduino_Single_Ultrasonic_Obstical_Avoiding)                                                                      | Arduino Uno                     | HC-SR04, Motors                  | Basic obstacle avoiding robot.                          |
| Arduino\_Vending\_Machine                                                | [Arduino\_Vending\_Machine](./Arduino_Vending_Machine)                                                                                                                | Arduino Uno                     | Motors, Buttons                  | Vending machine simulation.                             |
| Arduino\_Weather\_Station\_Receiver\_with\_Nrf24l01\_And\_OLED           | [Arduino\_Weather\_Station\_Receiver\_with\_Nrf24l01\_And\_OLED](./Arduino_Weather_Station_Receiver_with_Nrf24l01_And_OLED)                                           | Arduino Uno                     | NRF24L01, OLED                   | Receives data from weather station.                     |
| Arduino\_Weather\_Station\_Transmitter\_with\_Nrf24l01                   | [Arduino\_Weather\_Station\_Transmitter\_with\_Nrf24l01](./Arduino_Weather_Station_Transmitter_with_Nrf24l01)                                                         | Arduino Uno                     | NRF24L01, DHT11                  | Sends weather data to receiver.                         |
| Dintest Robot Arm Project                                                | [Dintest Robot Arm Project](./Dintest%20Robot%20Arm%20Project)                                                                                                        | Arduino Uno                     | Robot arm, Servos                | Robot arm prototype.                                    |
| Drone                                                                    | [Drone](./Drone)                                                                                                                                                      | Arduino Uno / Flight Controller | Motors, IMU                      | Arduino-based drone project.                            |
| ESP32\_Cam\_Survilance\_Car\_Robot                                       | [ESP32\_Cam\_Survilance\_Car\_Robot](./ESP32_Cam_Survilance_Car_Robot)                                                                                                | ESP32-CAM                       | Camera, Motors                   | ESP32-CAM car with live surveillance.                   |
| ESP32\_Smart\_Irrigation\_Project\_With\_Blync                           | [ESP32\_Smart\_Irrigation\_Project\_With\_Blync](./ESP32_Smart_Irrigation_Project_With_Blync)                                                                         | ESP32                           | Soil sensor, Blynk IoT           | Smart irrigation with IoT control.                      |
| Parkenson's desies arm project                                           | [Parkenson's desies arm project/flex\_controlled\_servo1](./Parkenson's%20desies%20arm%20project/flex_controlled_servo1)                                              | Arduino Uno                     | Flex sensor, Servo               | Assists Parkinson’s patients with arm movement.         |
| ROV                                                                      | [ROV](./ROV)                                                                                                                                                          | Arduino Uno                     | Motors, Joystick                 | Remotely operated underwater vehicle.                   |
| Smart Home                                                               | [Smart Home](./Smart%20Home)                                                                                                                                          | Arduino Uno / NodeMCU           | Sensors, Relays                  | Smart home automation system.                           |
| esp32\_control\_motor\_remotexy                                          | [esp32\_control\_motor\_remotexy](./esp32_control_motor_remotexy)                                                                                                     | ESP32                           | RemoteXY app, Motor driver       | ESP32 motor control via RemoteXY.                       |


## 🚀 Getting Started

### Prerequisites

* **Arduino IDE:** [Download & Install](https://www.arduino.cc/en/software)
* **ESP8266/ESP32 Board Support:** Install via Arduino IDE Boards Manager.
* **Required Libraries:** Install project-specific libraries (DHT, Blynk, LiquidCrystal\_I2C, etc.) via Arduino IDE Library Manager.

### Installation & Usage

1. Clone the repository:

   ```bash
   git clone https://github.com/omarabdullah1/Arduino_And_IOT_Projects.git
   ```
2. Navigate to the desired project folder.
3. Open the `.ino` file in Arduino IDE.
4. Connect your board (Arduino/NodeMCU/ESP32).
5. Select the correct **board** and **port** in Tools menu.
6. For IoT projects:

   * Configure Blynk/Adafruit IO credentials.
   * Replace `Auth Token` and Wi-Fi credentials in the sketch.
   * Setup dashboard as instructed.
7. Upload the code and monitor using Serial Monitor.

---

## 📁 Repository Structure

```bash
Arduino_And_IOT_Projects/
│
├── 8_8_LED_Matrix_MAX7219/
│ └── 8_8_LED_Matrix_MAX7219.ino
├── ARDUINO__OBSTACLE_AVOIDING_ROBOT_USING_3_ULTRASONIC_SENSOR/
│ └── ARDUINO__OBSTACLE_AVOIDING_ROBOT_USING_3_ULTRASONIC_SENSOR.ino
├── Arduino Flex Sensor Glove Control Pc/
│ └── lastvsystem/
│ └── lastvsystem.ino
├── Arduino Glove Control Pc Mouse/
│ └── flex_sensor_mouse_control/
│ ├── flex_sensor_mouse_control.ino
│ └── flex_sensor_mouse_control.ino.TEENSY2.hex
├── Arduino HealthCare System For Hospitals/
│ ├── HMI/ # Human-Machine Interface resources
│ ├── SIM/ # Simulation project files
│ ├── test_ecg/
│ │ └── test_ecg.ino
│ ├── test_galvanic/
│ │ └── test_galvanic.ino
│ └── test_temp_lcd/
│ └── test_temp_lcd.ino
├── Arduino Shoulder Excersises System/
│ ├── Mobile_App/ # Flutter mobile app
│ └── wifi_manager_websocket_code_last/
│ └── wifi_manager_websocket_code_last.ino
├── Arduino Smart Voting System/
│ └── Smart_Vote/
│ ├── Functions.ino
│ ├── Smart_Vote.ino
│ └── def.h
├── Arduino Solar Panel Tracker System/
│ └── NodeMCU/
│ ├── Functions.ino
│ ├── NodeMCU.ino
│ └── def.h
├── Arduino V2V System With NRF GPS Module/
│ ├── Transmitter/
│ │ └── test_with_gps_device1/
│ └── reciever.ino/
│ └── reciever.ino.ino
├── Arduino Voltameter Glasses Projection/
│ ├── SIM/
│ ├── glasses/
│ │ ├── glasses.ino
│ │ └── compiled HEX files
│ └── voltmeter/
│ ├── voltmeter.ino
│ └── compiled HEX files
├── Arduino Water Pressure Sensor Control Motor/
│ └── water_pressure_sensor_control/
│ └── water_pressure_sensor_control.ino
├── Arduino-Gesture-Control-Robot/
│ ├── receiver-car-code/
│ │ └── receiver-car-code.ino
│ └── transmitter-glove-code/
│ └── transmitter-glove-code.ino
├── Arduino_3D_Wire_Bending_Machine/
│ └── Arduino_3D_Wire_Bending_Machine.ino
├── Arduino_3_Vending_Machine_With_Car_FreeRTOS_Project/
│ └── Arduino_3_Vending_Machine_With_Car_FreeRTOS_Project.ino
├── Arduino_Air_Quality_Monitoring_System/
│ └── Arduino_Air_Quality_Monitoring_System.ino
├── Arduino_Camera_Slider/
│ └── Arduino_Camera_Slider.ino
├── Arduino_Color_Sorter_Project/
│ └── Arduino_Color_Sorter_Project.ino
├── Arduino_Door_Lock_Access_Control_Project/
│ └── Arduino_Door_Lock_Access_Control_Project.ino
├── Arduino_Fire_Alarm_System_With_Free_RTOS/
│ ├── Arduino_Fire_Alarm_System_With_Free_RTOS.ino
│ └── SIM/ # Simulation project files
├── Arduino_Flappy_Bird_Game_With_TFT/
│ └── Arduino_Flappy_Bird_Game_With_TFT.ino
├── Arduino_L298N_Driver_Robot/
│ └── Arduino_L298N_Driver_Robot.ino
├── Arduino_Line_Follower_Robot_with_2_IR_Sensor/
│ └── Arduino_Line_Follower_Robot_with_2_IR_Sensor.ino
├── Arduino_Line_Follower_Robot_with_3_IR_Sensor/
│ └── Arduino_Line_Follower_Robot_with_3_IR_Sensor.ino
├── Arduino_Line_Follower_Robot_with_4_IR_Sensor/
│ └── Arduino_Line_Follower_Robot_with_4_IR_Sensor.ino
├── Arduino_Message_Chair_Control_Unit__7seg_-encoder-proximity/
│ └── Arduino_Message_Chair_Control_Unit__7seg_-encoder-proximity.ino
├── Arduino_Moisture_Data_Dumper_With_LCD_I2C/
│ └── Arduino_Moisture_Data_Dumper_With_LCD_I2C.ino
├── Arduino_Parking_system/
│ └── Arduino_Parking_system.ino
├── Arduino_Programable_ON_OFF_Timer/
│ └── Arduino_Programable_ON_OFF_Timer.ino
├── Arduino_RC_Airplane_With_Nrf24l01/
│ └── Arduino_RC_Airplane_With_Nrf24l01.ino
├── Arduino_RC_Airplane_With_Nrf24l01_Receiver/
│ └── Arduino_RC_Airplane_With_Nrf24l01_Receiver.ino
├── Arduino_RC_Receiver/
│ └── Arduino_RC_Receiver.ino
├── Arduino_RC_Transmitter/
│ └── Arduino_RC_Transmitter.ino
├── Arduino_Radar_Project/
│ └── Arduino_Radar_Project.ino
├── Arduino_Radar_Project_Processing/
│ └── Arduino_Radar_Project_Processing.pde
├── Arduino_Range_Measurer_and_Digital_Spirit_Level/
│ └── Arduino_Range_Measurer_and_Digital_Spirit_Level.ino
├── Arduino_Raw_Data_GSR_Sensor_Dumper_in_Excel_Sheet_And_LCD_I2C/
│ └── Arduino_Raw_Data_GSR_Sensor_Dumper_in_Excel_Sheet_And_LCD_I2C.ino
├── Arduino_Robot_Arm_and_Car_With_Mobile_App_Automatic_Operation/
│ └── Arduino_Robot_Arm_and_Car_With_Mobile_App_Automatic_Operation.ino
├── Arduino_Robot_Arm_with_Smartphone_Control/
│ └── Arduino_Robot_Arm_with_Smartphone_Control.ino
├── Arduino_Robot_With_BT_Control/
│ └── Arduino_Robot_With_BT_Control.ino
├── Arduino_Robot_with_nrf24l01_control/
│ └── Arduino_Robot_with_nrf24l01_control.ino
├── Arduino_Security_and_Alarm_System_Project/
│ └── Arduino_Security_and_Alarm_System_Project.ino
├── Arduino_Self_Balancing_Robot_Stepper/
│ ├── Arduino_Self_Balancing_Robot_Stepper.ino
│ ├── PID.cpp
│ └── PID.h
├── Arduino_Self_Balancing_Robot__DC/
│ └── Arduino_Self_Balancing_Robot__DC.ino
├── Arduino_Self_Stabilizing_Gimbal/
│ └── Arduino_Self_Stabilizing_Gimbal.ino
├── Arduino_Shape_Size_Finder_XYZ_With_FreeRTOS/
│ └── Arduino_Shape_Size_Finder_XYZ_With_FreeRTOS.ino
├── Arduino_Single_Ultrasonic_Obstical_Avoiding/
│ └── Arduino_Single_Ultrasonic_Obstical_Avoiding.ino
├── Arduino_Vending_Machine/
│ └── Arduino_Vending_Machine.ino
├── Arduino_Weather_Station_Receiver_with_Nrf24l01_And_OLED/
│ └── Arduino_Weather_Station_Receiver_with_Nrf24l01_And_OLED.ino
├── Arduino_Weather_Station_Transmitter_with_Nrf24l01/
│ └── Arduino_Weather_Station_Transmitter_with_Nrf24l01.ino
├── Dintest Robot Arm Project/
│ ├── WinFormsApp2/
│ └── robot arm project/ # PlatformIO project
├── Drone/
│ ├── MultiWii_2_3/
│ ├── PPM_Reciever_one_pin/
│ │ └── PPM_Reciever_one_pin.ino
│ └── remote/
│ └── remote.ino
├── ESP32_Cam_Survilance_Car_Robot/
│ └── ESP32_Cam_Survilance_Car_Robot.ino
├── ESP32_Smart_Irrigation_Project_With_Blync/
│ └── ESP32_Smart_Irrigation_Project_With_Blync.ino
├── Parkenson's desies arm project/
│ └── flex_controlled_servo1/
│ └── flex_controlled_servo1.ino
├── ROV/
│ ├── Ground station/
│ └── R O V/
├── Smart Home/
│ ├── Charity org System/
│ └── ESP32-Home-Automation-with-Google-Assistant-Alexa-using-Sinric-/
│ └── ESP32-Home-Automation-with-Google-Assistant-Alexa-using-Sinric-.ino
├── esp32_control_motor_remotexy/
│ └── esp32_control_motor_remotexy.ino
├── LICENSE
└── README.md
```

---

## 🤝 Contributing

Contributions are welcome! To contribute:

1. Fork this repo.
2. Create a new branch (`git checkout -b feature/NewProject`).
3. Commit your changes (`git commit -m 'Add NewProject'`).
4. Push to the branch (`git push origin feature/NewProject`).
5. Open a Pull Request.

---

## 📜 License

This repository is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

## 📞 Contact

**Omar Abdullah**
Portfolio: [omarabdullah1.github.io/my\_website.io](https://omarabdullah1.github.io/my_website.io/)
GitHub: [omarabdullah1](https://github.com/omarabdullah1)
LinkedIn: [Omar Abdullah](https://www.linkedin.com/in/omar-abdullah1/)

Project Link: [Arduino & IoT Projects](https://github.com/omarabdullah1/Arduino_And_IOT_Projects)
