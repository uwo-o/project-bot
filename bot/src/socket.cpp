#include "socket.h"

WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

bool setup_socket()
{
    bool success = true;
    WiFi.begin(WIFI_SSID, WIFI_PWS);

    int timeout = 100;

    while (WiFi.status() != WL_CONNECTED)
    {

        if (timeout <= 0)
        {
            success = false;
            break;
        }

        Serial.print(".");
        delay(100);
        timeout--;
    }

    try
    {
        server.on("/", HTTP_GET, []()
                  { server.send(200, "text/plain", "Hello from ESP32!"); });
        server.begin();
    }
    catch (const std::exception &e)
    {
        add_error(e);
        success = false;
    }

    try
    {
        webSocket.begin();
        webSocket.onEvent([](uint8_t num, WStype_t type, uint8_t *payload, size_t length)
                          {
                              if (type == WStype_TEXT)
                              {
                                  Serial.printf("Message from client %d: %s\n", num, payload);
                                  webSocket.sendTXT(num, "Message received");
                              } });
    }
    catch (const std::exception &e)
    {
        add_error(e);
        success = false;
    }

    return success;
}

void loop_socket()
{
    server.handleClient();
    webSocket.loop();
}