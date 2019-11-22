﻿#pragma once

// Limits
#define  MAX_NAME_LENGTH                20
#define  MAX_BUFFER_SIZE                1420
#define  MAX_VERSION_STRING_LENGTH      20
#define  MAX_MESSAGE_LENGTH             550  // note: actual size is "MAX_MESSAGE_LENGTH * 2" because we use std::wstring.
                                             // please, don't set this value more than 680 (1400 (~MTU) / 2 - MAX_NAME_LENGTH).


// TCP / UDP
#define  INTERVAL_TCP_MESSAGE_MS        120
#define  INTERVAL_UDP_MESSAGE_MS        3
#define  INTERVAL_KEEPALIVE_SEC         15
#define  CHECK_IF_SERVER_DIED_EVERY_MS  800  // note: also used in disconnect() and answerToFIN(): "Wait for serverMonitor() to end".
#define  ANTI_SPAM_MINIMUM_TIME_SEC         1.0f

// Ping
#define  PING_NORMAL_BELOW              190
#define  PING_WARNING_BELOW             280
