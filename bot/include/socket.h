#ifndef SOCKET_H
#define SOCKET_H

#include <WiFi.h>
#include <WebSocketsServer.h>
#include <WebServer.h>
#include "constants.h"
#include "errors.h"

bool setup_socket();
void loop_socket();

#endif