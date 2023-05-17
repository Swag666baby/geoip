
# installation 
```
apt-get install git
git clone https://github.com/Swag666baby/geoip
```
# compiling and running 
**to compile you will need clang installed on your machine and the curl and rapidjson libraries.**
```
cd geoip
g++ main.cpp -o main -lcurl -lrapidjson
./main
```
or 
# just run 
```
cd geoip
./main
```
