# Arduino Motor Controller - Wiring Diagram (схема подключения)

## 🔌 Complete Wiring Diagram

```
┌─────────────────────────────────────────────────────────────────┐
│                    ARDUINO UNO CONNECTIONS                       │
└─────────────────────────────────────────────────────────────────┘

┌──────────────┐
│  ARDUINO UNO │
├──────────────┤
│ Pin 3  (PWM) ├──────────────┐
│ Pin 5  (PWM) ├──────────────┤
│ Pin 6  (PWM) ├──────────────┤
│ Pin 9  (PWM) ├──────────────┤
│              │              │
│ GND          ├──────────────┤
│ 5V           ├──────────────┘
└──────────────┘
       │
       │
       └─────────────────────────────────────┐
                                             │
                        ┌────────────────────┴──────────────────┐
                        │                                       │
                        ▼                                       ▼
                ┌──────────────────┐              ┌──────────────────┐
                │   L298N MOTOR    │              │   POWER SUPPLY   │
                │    DRIVER        │              │   (External)     │
                ├──────────────────┤              ├──────────────────┤
                │                  │              │                  │
                │ IN1 ←── Pin 3    │              │ +12V (or 5-35V)  │
                │ IN2 ←── Pin 5    │              │ GND              │
                │ IN3 ←── Pin 6    │              │                  │
                │ IN4 ←── Pin 9    │              │                  │
                │                  │              │                  │
                │ GND ←── Arduino  │              │ Connected to     │
                │       GND & +5V  │              │ Motor Driver     │
                │                  │              │                  │
                │ OUT1 ─────────→ Motor 1 ─────→ Wheel 1           │
                │ OUT2 ─────────→ Motor 1 ─────→                   │
                │                                                   │
                │ OUT3 ─────────→ Motor 2 ─────→ Wheel 2           │
                │ OUT4 ─────────→ Motor 2 ─────→                   │
                │                                                   │
                │ OUT5 ─────────→ Motor 3 ─────→ Wheel 3           │
                │ OUT6 ─────────→ Motor 3 ───��─→                   │
                │                                                   │
                │ OUT7 ─────────→ Motor 4 ─────→ Wheel 4           │
                │ OUT8 ─────────→ Motor 4 ─────→                   │
                │                                                   │
                └──────────────────┘              └──────────────────┘
```

---

## 📋 Таблица подключения (Wiring Table)

| Arduino Pin | Motor Driver Pin | Motor | Wheel | Function |
|------------|------------------|-------|-------|----------|
| Pin 3 (PWM) | IN1 | Motor 1 | Wheel 1 | Control Motor 1 Speed |
| Pin 5 (PWM) | IN2 | Motor 2 | Wheel 2 | Control Motor 2 Speed |
| Pin 6 (PWM) | IN3 | Motor 3 | Wheel 3 | Control Motor 3 Speed |
| Pin 9 (PWM) | IN4 | Motor 4 | Wheel 4 | Control Motor 4 Speed |
| GND | GND | - | - | Ground Connection |
| 5V | 5V | - | - | Logic Supply (if needed) |

---

## 🔌 Детальное подключение каждого мотора

### Motor 1 (Мотор 1)
```
Arduino Pin 3 ──────→ L298N IN1
                     L298N OUT1 ──→ Motor 1 + (Red wire)
                     L298N OUT2 ──→ Motor 1 - (Black wire)
                                    ↓
                                  WHEEL 1 (Круглая пластина)
```

### Motor 2 (Мотор 2)
```
Arduino Pin 5 ──────→ L298N IN2
                     L298N OUT3 ──→ Motor 2 + (Red wire)
                     L298N OUT4 ──→ Motor 2 - (Black wire)
                                    ↓
                                  WHEEL 2 (Круглая пластина)
```

### Motor 3 (Мотор 3)
```
Arduino Pin 6 ──────→ L298N IN3
                     L298N OUT5 ──→ Motor 3 + (Red wire)
                     L298N OUT6 ──→ Motor 3 - (Black wire)
                                    ↓
                                  WHEEL 3 (Круглая пластина)
```

### Motor 4 (Мотор 4)
```
Arduino Pin 9 ──────→ L298N IN4
                     L298N OUT7 ──→ Motor 4 + (Red wire)
                     L298N OUT8 ──→ Motor 4 - (Black wire)
                                    ↓
                                  WHEEL 4 (Круглая пластина)
```

---

## 🔋 Power Supply Connection (Подключение питания)

```
┌─────────────────────────────────────────────────────┐
│         EXTERNAL POWER SUPPLY (5-35V)               │
├─────────────────────────────────────────────────────┤
│                                                     │
│  Positive (+) ──→ L298N +12V (or your voltage)     │
│  Negative (-) ──→ L298N GND                        │
│                                                     │
│  ⚠️ IMPORTANT: Connect Arduino GND to Motor Driver │
│     GND to share common ground!                    │
└─────────────────────────────────────────────────────┘
```

---

## 🎯 Quick Connection Checklist

✅ **Arduino Side:**
- [ ] Pin 3 connected to L298N IN1
- [ ] Pin 5 connected to L298N IN2
- [ ] Pin 6 connected to L298N IN3
- [ ] Pin 9 connected to L298N IN4
- [ ] Arduino GND connected to L298N GND
- [ ] Arduino 5V connected to L298N 5V (if supported)

✅ **Motor Side:**
- [ ] Motor 1 connected to OUT1/OUT2
- [ ] Motor 2 connected to OUT3/OUT4
- [ ] Motor 3 connected to OUT5/OUT6
- [ ] Motor 4 connected to OUT7/OUT8
- [ ] All motors have wheels attached

✅ **Power Side:**
- [ ] Power supply + connected to L298N +12V
- [ ] Power supply - connected to L298N GND
- [ ] Power supply voltage matches motor specification (5-35V)
- [ ] All ground connections are secure

---

## ⚠️ Important Notes

1. **PWM Pins**: Arduino Uno has PWM on pins: 3, 5, 6, 9, 10, 11
   - We use 3, 5, 6, 9 for our 4 motors

2. **Motor Direction**: 
   - To reverse rotation, swap the + and - wires on the motor
   - Currently configured for CLOCKWISE rotation

3. **Speed Control**:
   - Speed = 0-255 (0 = OFF, 255 = MAX SPEED)
   - Controlled via PWM signal from Arduino pins

4. **Current Limiting**:
   - L298N can handle 2A per motor
   - Check your motor's current rating
   - Use appropriate power supply

5. **Ground Connection**:
   - ⚠️ CRITICAL: Always connect Arduino GND to Motor Driver GND
   - This creates common reference for all components

---

## 🔍 Troubleshooting

| Problem | Solution |
|---------|----------|
| Motors don't spin | Check motor connections, verify power supply |
| Only some motors work | Check individual pin connections |
| Motors run at wrong speed | Verify PWM pins, check power supply voltage |
| Motors run in wrong direction | Swap motor wire connections |
| Arduino resets unexpectedly | Ensure proper ground connections |

---

## 📸 Visual Pin Reference (Arduino Uno)

```
     ARDUINO UNO
    ┌─────────────┐
    │ RESET   TX  │
    │ 3.3V    RX  │
    │ 5V      0   │
    │ GND     1   │
    │ GND     2   │
    │ VIN     3 ← MOTOR 1
    │         4   │
    │         5 ← MOTOR 2
    │         6 ← MOTOR 3
    │         7   │
    │         8   │
    │         9 ← MOTOR 4
    │        10   │
    │        11   │
    │        12   │
    │        13   │
    │    A0-A5    │
    └─────────────┘
```

---

## 💡 Pro Tips

1. Use jumper wires with consistent colors:
   - Red = Positive/Power
   - Black = Ground
   - Yellow/Green = Signal

2. Test one motor at a time before connecting all 4

3. Use USB power for Arduino, separate power supply for motors (important!)

4. Keep wires organized with labels for easy identification

5. Double-check all connections before powering on
