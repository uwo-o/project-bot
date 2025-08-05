#include "socket.h"

WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

bool setup_socket(void (*callback_msg)(uint8_t, WStype_t, uint8_t *, size_t))
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
        webSocket.onEvent([callback_msg](uint8_t num, WStype_t type, uint8_t *payload, size_t length)
                          {
                              if (type == WStype_TEXT)
                              {
                                  String message = String((char *)payload);
                                  Serial.printf("Message from client %d: %s\n", num, message.c_str());
                                  if (callback_msg)
                                      callback_msg(num, type, payload, length);
                              } });
        webSocket.onEvent(callback_msg);
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