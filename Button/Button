int button = 34;
bool currentstateButton;
bool laststateButton;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(button, INPUT);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // put your main code here, to run repeatedly:
  // laststateButton = currentstateButton;
  currentstateButton = digitalRead(button);
  Serial.println(currentstateButton);
  delay(500); // this speeds up the simulation
}
