#ifndef SOCKET_H
#define SOCKET_H

#include <WiFi.h>
#include <WebSocketsServer.h>
#include <WebServer.h>
#include "constants.h"
#include "errors.h"

bool setup_socket(void (*callback_msg)(uint8_t, WStype_t, uint8_t *, size_t));
void loop_socket();

#endif