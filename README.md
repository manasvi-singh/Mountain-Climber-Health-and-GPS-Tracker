# Mountain-Climber-Health-and-GPS-Tracker

Welcome to the Mountain-Climber-Health-and-GPS-Tracker project! This system is designed to enhance the safety of mountain climbers by providing real-time vital monitoring and GPS tracking capabilities. By incorporating IoT technology, this project aims to address the challenges faced during search and rescue operations in remote or high-altitude locations. It enables climbers and their teams to track vital signs and location, allowing for prompt action in case of accidents or emergencies.

## Components
To build the Mountain-Climber-Health-and-GPS-Tracker system, you will need the following components:

1. ESP8266 WiFi Module
2. GPS (NEO-6M)
3. OLED (128*64)
4. Pulse and Oximeter Sensor (MAX 30100)
5. Push Button
6. Wirings

## Extra libraries
The extranal librarires used in the project.
1. TinyGPSPlus
2. Blynk
3. MAX30100lib
4. OakOLED
5. Adafruit SSD1306
6. Neo-6M_GPS



## Installation and Setup

To set up the system, follow these steps:

-**Hardware Assembly**: Connect the components according to the circuit diagram and ensure all electrical connections are secure. Take care to follow proper wiring practices and double-check the connections.

-**Software Configuration**: Upload the firmware to the ATmega controller using the appropriate programming tool or IDE. Make sure to configure the WiFi module with the necessary credentials for internet connectivity.

-**Power Supply**: Connect the power adapter to the power port of the system, ensuring the correct voltage and polarity. Verify that all components are receiving power and functioning properly.

-**User Configuration**: Use the buttons and switches provided in the system to configure the upper and lower limits for heart rate, as well as set the emergency mail for SMS alerts.

-**Operation**: Once the system is set up and configured, it will start monitoring the climber's vital signs and location in real-time. The OLED display will show the vital data, and in case of any limit crossings, an SMS alert will be sent with GPS coordinates.

## Usage
Here's how to use the Mountain-Climber-Health-and-GPS-Tracker system:

-**Power On**: Connect the power supply to the system and ensure all components are receiving power.

-**Set Limits**: Use the designated buttons or switches to set the upper and lower limits for the heart rate, considering the climber's health and safety requirements.

-**Configure Mail**: Use the blynk to configure the emergency mail to which SMS alerts will be sent in case of limit crossings.

-**Monitoring**: The system will continuously monitor the climber's heart rate and temperature. The OLED display will show the real-time vital data.

-**GPS Tracking**: The system will also track the climber's location using GPS technology. This information will be available for search and rescue purposes if needed.

-**Alerts**: If the heart rate exceeds the set limits, the system will trigger an alert. An SMS notification will be sent to the configured emergency mail, including GPS coordinates for accurate location tracking.

-**Safety Measures**: Based on the received alerts and location information, appropriate rescue actions can be taken to ensure the climber's safety.

-**System Shutdown**: After use, disconnect the power supply from the system and store all components safely.



## Contributing
To contribute to the repository, open an issue or a pull request.

## License
The  Mountain-Climber-Health-and-GPS-Tracker project is licensed under the MIT License. Feel free to modify and distribute the project as per the terms of the license.

## Acknowledgements
We would like to acknowledge the contributions of all the individuals and open-source projects that have helped make this project possible. Thank you for your support and dedication to improving the safety of mountain climbers.


## Circuit Diagram

![Screenshot (403)](https://github.com/PrachiPandey19/Mountain-Climber-Health-and-GPS-Tracker/assets/118668465/85835fa0-86b7-4cb1-89c8-636ef88a543c)

## Blynk Readings

![Screenshot (405)](https://github.com/PrachiPandey19/Mountain-Climber-Health-and-GPS-Tracker/assets/118668465/0a020e0c-8028-4a68-8900-75c462a8d7ab)
