#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

/* Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  digitalWrite(LED_BUILTIN, HIGH);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}