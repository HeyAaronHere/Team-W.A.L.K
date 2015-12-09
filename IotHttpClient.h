Name: Chua An Rong, Aaron, Kenny Chia Zhi Wei, Laurenz Dave D. Comendador, Zhang Wei Wei

#ifndef IOTHTTPCLIENT_H
#define IOTHTTPCLIENT_H

#include <arduino.h>
#include <LWiFi.h>
#include <LWiFiClient.h>

#include <string>

// ********************************************
// ****** START user defined definitions ******
// ********************************************
#define AZURE_SERVICE_BUS_NAME_SPACE    "ehdevices-Deborah"
#define AZURE_EVENT_HUB_NAME            "ehdevices"
#define AZURE_POLICY_NAME               "ehPolicy"

//#define AZURE_KEY                       "AhBB/d6/tJj/awnV9MPgj1UzXjeboHNzszF5ShcD2FY="
#define AZURE_KEY                       "Zrae3WxR69iPepYdg2MPw09yGSLobsyMOydosVBC5qc="



// ******************************************
// ****** END user defined definitions ******
// ******************************************

#define AZURE_HOST                      AZURE_SERVICE_BUS_NAME_SPACE".servicebus.windows.net"
#define AZURE_URL                       "/"AZURE_EVENT_HUB_NAME"/messages"

// Set to year 2020 so that it will not expire.

#define AZURE_UTC_2020_01_01            "1577836800"

/* HttpClient implementation to be used on the Mtk device. */
class IotHttpClient
{
    LWiFiClient client;
    
public:
    IotHttpClient();
    /* Send http request and return the response. */
    char* send(const char *request, const char* serverUrl, int port);
    int SendAzureHttpsData(std::string);
    
protected:
    char* sendHTTP(const char *request, const char* serverUrl, int port);
    char* sendHTTPS(const char *request, const char* serverUrl, int port);
    
public:
    static boolean sendHTTPS_remotecall(void*);
    static void sendHTTPS_ssl_callback(VMINT handle, VMINT event);
};

#endif
