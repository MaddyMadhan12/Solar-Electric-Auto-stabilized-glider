#include "esp_camera.h"
#include "FS.h"
#include "SD_MMC.h"

#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

#define TRIGGER_PIN 13   // Pixhawk AUX signal (HIGH when armed)

File videoFile;
bool recording = false;

// Initialize camera
void startCamera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_VGA;
  config.jpeg_quality = 10;
  config.fb_count = 2;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.println("Camera init failed");
    return;
  }
}

// Start recording video file
void startRecording() {
  videoFile = SD_MMC.open("/flight.mjpeg", FILE_WRITE);
  recording = true;
  Serial.println("Recording Started");
}

// Stop recording
void stopRecording() {
  videoFile.close();
  recording = false;
  Serial.println("Recording Stopped");
}

// Capture frame and write to SD card
void recordFrame() {
  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) return;

  videoFile.write(fb->buf, fb->len);
  esp_camera_fb_return(fb);
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN, INPUT);

  startCamera();

  if(!SD_MMC.begin()){
    Serial.println("SD Card Mount Failed");
    return;
  }

  Serial.println("System Ready");
}

void loop() {
  int triggerState = digitalRead(TRIGGER_PIN);

  // Aircraft armed → start recording
  if(triggerState == HIGH && !recording) {
    startRecording();
  }

  // Aircraft disarmed → stop recording
  if(triggerState == LOW && recording) {
    stopRecording();
  }

  // Record frames during flight
  if(recording) {
    recordFrame();
    delay(100); // ~10 FPS video
  }
}
