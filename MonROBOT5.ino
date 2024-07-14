#include <PS4Controller.h>

// Définition des broches pour les moteurs
#define IN1 16 // G1
#define IN2 17 // G1
#define IN3 18 // G2
#define IN4 19 // G2
#define ENA 14 // G1 et G2
#define ENB 12 // D1 et D2
#define IN5 25 // D1
#define IN6 26 // D1
#define IN7 27 // D2
#define IN8 32 // D2
#define ENA2 15 // G1 et G2
#define ENB2 2  // D1 et D2

// Variables pour la manette PS4
int LX = 0;
int LY = 0;
int RStickX = 0;
int RY = 0;

int deadBand = 8;
bool connected = false;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(ENA2, OUTPUT);
  pinMode(ENB2, OUTPUT);

  Serial.begin(115200);
  PS4.begin("c0:49:ef:cf:03:1b"); // Remplacez par votre adresse MAC
  Serial.println("Prêt.");
  delay(200);
}

void loop() {
  if (PS4.isConnected() && !connected) {
    Serial.println("Connecté !");
    Serial.printf("Niveau de batterie : %d\n", PS4.Battery());
    connected = true;
  }

  if (PS4.isConnected()) {
    if (PS4.LStickX()) {
      LX = PS4.LStickX();
      if (abs(LX) < deadBand) {
        LX = 0;
      }
    }

    if (PS4.LStickY()) {
      LY = PS4.LStickY();
      if (abs(LY) < deadBand) {
        LY = 0;
      }
    }

    if (PS4.RStickX()) {
      RStickX = PS4.RStickX();
      if (abs(RStickX) < deadBand) {
        RStickX = 0;
      }
    }

    // Contrôle des moteurs en fonction des sticks et des gâchettes
    int speed = map(abs(LY), 0, 128, 0, 255);
    int turnSpeed = map(abs(RStickX), 0, 128, 0, 255);

    if (PS4.L2()) { // Inversion des gâchettes
      lateralGauche();
    } else if (PS4.R2()) { // Inversion des gâchettes
      lateralDroit();
    } else {
      controlMotors(LX, LY, RStickX, RY, speed, turnSpeed);
    }
  }
}

void controlMotors(int LX, int LY, int RStickX, int RY, int speed, int turnSpeed) {
  if (LY > 0) {
    avancer(speed);
  } else if (LY < 0) {
    reculer(speed);
  }

  if (RStickX > 0) {
    pivoterDroit(turnSpeed);
  } else if (RStickX < 0) {
    pivoterGauche(turnSpeed);
  }

  if (LY == 0 && RStickX == 0) {
    arreter();
  }
}

void avancer(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  analogWrite(ENA2, speed);
  analogWrite(ENB2, speed);
}

void reculer(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  analogWrite(ENA2, speed);
  analogWrite(ENB2, speed);
}

void lateralGauche() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  analogWrite(ENA2, 255);
  analogWrite(ENB2, 255);
}

void lateralDroit() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  analogWrite(ENA2, 255);
  analogWrite(ENB2, 255);
}

void pivoterGauche(int speed) {
  digitalWrite(IN1, HIGH); // G1 en avant
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); // G2 en avant
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); // D1 en arrière
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); // D2 en arrière
  digitalWrite(IN8, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  analogWrite(ENA2, speed);
  analogWrite(ENB2, speed);
}

void pivoterDroit(int speed) {
  digitalWrite(IN1, LOW); // G1 en arrière
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); // G2 en arrière
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH); // D1 en avant
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); // D2 en avant
  digitalWrite(IN8, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  analogWrite(ENA2, speed);
  analogWrite(ENB2, speed);
}

void arreter() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  analogWrite(ENA2, 0);
  analogWrite(ENB2, 0);
}