#include <Arduino.h>

// Motors Pins 
#define IN1_PIN GPIO_NUM_39
#define IN2_PIN GPIO_NUM_45
#define PWM_M1_PIN GPIO_NUM_46

#define IN3_PIN GPIO_NUM_40
#define IN4_PIN GPIO_NUM_41
#define PWM_M2_PIN GPIO_NUM_42  

#define LEDC_CANAL_MOTOR_ESQUERDO 0
#define LEDC_CANAL_MOTOR_DIREITO  1

#define LEDC_FREQ 1000
#define LEDC_RESOLUTION 8

void setupMotors() {
  gpio_set_direction(IN1_PIN, GPIO_MODE_INPUT_OUTPUT);
  gpio_set_direction(IN2_PIN, GPIO_MODE_INPUT_OUTPUT);

  gpio_set_direction(IN3_PIN, GPIO_MODE_INPUT_OUTPUT);
  gpio_set_direction(IN4_PIN, GPIO_MODE_INPUT_OUTPUT);
}

void motor(int vA, int vB) {
  if(vA > 0) {
    gpio_set_pull_mode(IN1_PIN, GPIO_PULLDOWN_ONLY);
    gpio_set_level(IN2_PIN, 1);
  } else {
    gpio_set_pull_mode(IN1_PIN, GPIO_PULLUP_ONLY);
    gpio_set_level(IN2_PIN, 0);
    vA *= -1;
  }

  if(vB > 0) {
    gpio_set_pull_mode(IN4_PIN, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(IN3_PIN, GPIO_PULLDOWN_ONLY);
  } else {
    gpio_set_pull_mode(IN3_PIN, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(IN4_PIN, GPIO_PULLDOWN_ONLY);
    vB *= -1;
  }

  ledcWrite(LEDC_CANAL_MOTOR_ESQUERDO, vA);
  ledcWrite(LEDC_CANAL_MOTOR_DIREITO, vB);
}

// QTR Pins 
#define S1_PIN GPIO_NUM_1
#define S2_PIN GPIO_NUM_2
#define S3_PIN GPIO_NUM_3
#define S4_PIN GPIO_NUM_4
#define S5_PIN GPIO_NUM_5
#define S6_PIN GPIO_NUM_6
#define S7_PIN GPIO_NUM_7

const uint8_t QTR_SENSOR_COUNT = 7;
const uint8_t QTR_SENSOR_COUNT_BARATINHA = 7; // Usando _BARATINHA


void setup() {
  Serial.begin(115200);
  delay(1000);

  setupMotors();
}

void loop() {
  motor(100, 100);
}
