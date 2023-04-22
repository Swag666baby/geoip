#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <curl/curl.h>
#include <stdio.h>
#include <exception>

using namespace std;

size_t write_callback(char *ptr, size_t size, size_t nmemb, string *stream) {
    size_t bytes = size * nmemb;
    stream->append(ptr, bytes);
    return bytes;
}

int main() 
{
    
        string ip;
        system("clear");
        cout << "geoip desenvolvido por Swag666baby\n\n";
        cout << "digite o ip: "; cin >> ip;
        system("clear");
        
        string url = "https://ipwhois.app/json/";
        url += ip;
    
        CURL *curl;
        CURLcode res;
        string response;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

    
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
            res = curl_easy_perform(curl);

            if(res != CURLE_OK) {
            
                cerr << "Erro: " << curl_easy_strerror(res) << endl;
            
            } else {
            
            const char* json = response.c_str();
            
            rapidjson::Document d;
            d.Parse(json);
            cout << "ip: " << d["ip"].GetString() << std::endl;
            cout << "tipo: " << d["type"].GetString() << std::endl;
            cout << "continente: "<< d["continent"].GetString() << std::endl;
            cout << "pais: " << d["country"].GetString() << std::endl;
            cout << "estado: " << d["region"].GetString() << std::endl;
            cout << "cidade: " << d["city"].GetString() << std::endl;
            cout << "asn: " << d["asn"].GetString() << std::endl;
            cout << "org: " << d["org"].GetString() << std::endl;            cout << "latitude: " << d["latitude"].GetDouble() << std::endl;
            cout << "longitude: " << d["longitude"].GetDouble() << std::endl;
            
            cout << "\nobrigado por usar :)";
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    return 0;
}
