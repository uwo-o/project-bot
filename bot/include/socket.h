#ifndef SOCKET_H
#define SOCKET_H

#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#include "constants.h"

bool setup_socket();
void loop_socket();

#endif