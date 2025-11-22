# Automated Rain Protected Cloth Drying System (IoT Based)

This project is an IoT-enabled smart cloth drying system that automatically protects clothes from rain using real-time environmental monitoring. The system uses a NodeMCU (ESP8266), rain sensor, LDR sensor, and dual servo motors to detect weather changes and move a protective cover accordingly. Remote monitoring and notifications are provided through the Blynk IoT platform.

---

## 🌦️ Project Overview
Sudden rain is a common problem in urban areas, often damaging clothes left outside for drying. This IoT system solves the issue by detecting rainfall instantly and covering the clothes automatically. When sunlight returns, the system uncovers the clothes to resume drying.

This removes the need for manual intervention and increases convenience for households.

---

## 📁 Features
- ✔️ Automatic rain detection  
- ✔️ Sunlight-based cloth uncovering  
- ✔️ Dual servo motor mechanism (cover + sensor wipe)  
- ✔️ Real-time IoT dashboard (mobile + web)  
- ✔️ Instant rain alerts through Blynk  
- ✔️ Wi-Fi enabled remote monitoring  
- ✔️ Low-cost, practical home automation solution  

---

## 🛠️ Hardware Components
- NodeMCU ESP8266  
- Rain Sensor Module  
- LDR Sensor  
- Servo Motor 1 (Cover movement)  
- Servo Motor 2 (Rain sensor wiping mechanism)  
- Blynk IoT Platform  
- Power Supply  

*(All component diagrams and pin connections are shown on pages 2–3 of the report :contentReference[oaicite:1]{index=1})*

---

## 🔌 Circuit & Workflow

### **Flowchart**
(Shown on page 4 of the report :contentReference[oaicite:2]{index=2})

### **Block Diagram**
(Also available on page 4)

### **System Logic**
1. **Rain detected →** Servo motor moves cover to protect clothes.  
2. **Rain stops + Sunlight detected →** Cover retracts, allowing drying.  
3. **Night-time / low light →** Clothes stay protected.  
4. **Servo 2** wipes the rain sensor repeatedly during rainfall.  
5. **IoT Dashboard** displays real-time LDR + rain sensor data.  

---

## 📲 IoT Platform (Blynk Integration)

- Real-time sensor visualization  
- Notifications using `Blynk.logEvent()`  
- Threshold-based alerts (rain, extreme light changes)  
- Dashboard accessible via both mobile & web  

*(Example dashboards available on page 7 of the report :contentReference[oaicite:3]{index=3})*

---

## 🧠 Algorithm & Code Summary
Main tasks performed in code:

- Read LDR analog values  
- Read rain sensor digital values  
- Control servos based on conditions  
- Send data & notifications to Blynk  
- Run IoT loop continuously  

(Full working code is found in the report on pages 5–6 :contentReference[oaicite:4]{index=4})

---

## 📊 Result Summary
- System responds instantly to rainfall.  
- Sunlight-based decision-making works accurately.  
- IoT dashboard gives reliable real-time updates.  
- Dual-servo design increases system efficiency.  
*(Detailed analysis: pages 7–8 :contentReference[oaicite:5]{index=5})*

---

## ⚠️ Limitations
- Requires stable Wi-Fi for IoT features  
- Sensor calibration needed periodically  
- Can handle light/medium clothes only  
*(Full list on page 8)*  

---

## 🚀 Future Improvements
- Add wind speed/air quality sensors  
- Implement mobile app features  
- Use ML models for predictive weather response  

---

## 🏷️ Credit Notice
**If you reuse any part of this project or documentation, please provide proper credit to the author.**

---

## 📜 License
Licensed under the **MIT License** (see below).

