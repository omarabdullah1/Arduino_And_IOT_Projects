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

### Microcontrollers

* Arduino Uno
* ESP8266 NodeMCU (For Wi-Fi & IoT capabilities)
* ESP32 (For Bluetooth & Wi-Fi capabilities)

### Sensors & Modules

* DHT11/DHT22 (Temperature & Humidity)
* HC-SR04 (Ultrasonic Distance)
* MQ-2 (Gas/Smoke)
* LDR (Light Dependent Resistor)
* PIR Sensor (Motion)
* IR Receiver & Remote
* Joystick Module
* RFID-RC522
* Soil Moisture Sensor
* Water Level Sensor
* Relay Modules
* LED Matrix (MAX7219)
* LCD 16x2 (I2C)

### Actuators & Outputs

* LEDs
* Servo Motors (SG90)
* DC Motors (with L298N Driver)
* Buzzers
* LED Strips (WS2812B NeoPixel)

### Communication & IoT

* Wi-Fi (ESP boards)
* Bluetooth (HC-05, HC-06 modules and ESP32)
* RFID (Radio-Frequency Identification)
* IR (Infrared Communication)

### Platforms & Libraries

* Arduino IDE
* Blynk IoT Platform (For smartphone dashboards)
* Adafruit IO (For cloud data logging)
* ThingSpeak (For IoT analytics)
* Arduino Libraries: DHT sensor library, Servo, LiquidCrystal\_I2C, NewPing, MQ2, FastLED, etc.

---

## 📂 Project List

Here's a summary of the projects included in this repo:

| Project Name                                                                                                                        | Microcontroller  | Key Components               | Description                                               |
| ----------------------------------------------------------------------------------------------------------------------------------- | ---------------- | ---------------------------- | --------------------------------------------------------- |
| [8\_8\_LED\_Matrix\_MAX7219](./8_8_LED_Matrix_MAX7219/)                                                                             | Arduino Uno      | MAX7219, 8×8 LED Matrix      | Displays custom patterns, text, and animations.           |
| [ARDUINO\_\_OBSTACLE\_AVOIDING\_ROBOT\_USING\_3\_ULTRASONIC\_SENSOR](./ARDUINO__OBSTACLE_AVOIDING_ROBOT_USING_3_ULTRASONIC_SENSOR/) | Arduino Uno      | 3× HC-SR04, L298N, DC Motors | Robot avoids obstacles using multiple ultrasonic sensors. |
| [Arduino\_Glove\_Control\_Pc\_Mouse](./Arduino_Glove_Control_Pc_Mouse/)                                                             | Arduino Nano     | Flex Sensors, MPU6050, HC-05 | Gesture-controlled glove that moves PC mouse cursor.      |
| [Arduino\_Smart\_Voting\_System](./Arduino_Smart_Voting_System/)                                                                    | Arduino Uno      | Keypad, LCD I2C, EEPROM      | Secure and tamper-proof electronic voting machine.        |
| [Arduino\_Fire\_Alarm\_System\_With\_Free\_RTOS](./Arduino_Fire_Alarm_System_With_Free_RTOS/)                                       | Arduino Uno/MEGA | MQ-2, DHT11, Buzzer          | Fire and smoke alarm system using FreeRTOS.               |
| [ESP32\_Smart\_Irrigation\_Project\_With\_Blync](./ESP32_Smart_Irrigation_Project_With_Blync/)                                      | ESP32            | Soil Moisture, Relay, Blynk  | Automated irrigation system controllable via mobile app.  |

*(Extend the table with all other projects in the repo.)*

---

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
├── 8_8_LED_Matrix_MAX7219/
│   ├── code.ino
│   └── circuit_diagram.png
├── ARDUINO__OBSTACLE_AVOIDING_ROBOT_USING_3_ULTRASONIC_SENSOR/
├── Arduino_Glove_Control_Pc_Mouse/
├── Arduino_Smart_Voting_System/
├── Arduino_Fire_Alarm_System_With_Free_RTOS/
├── ESP32_Smart_Irrigation_Project_With_Blync/
├── ... # Other project folders
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
