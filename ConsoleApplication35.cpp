#include <iostream>
#include <fstream>
#include <json/json.h>
using namespace std;

int main()
{
    Json::Value val;
    Json::Value vec(Json::arrayValue);

    for (size_t i = 0; i < 10; i++) vec.append(i);

    val["array"] = vec;

    val["name"] = "oleg";
    val["age"] = 13;
    val["a"] = "asergwer";
    val["b"] = "bbraeber";
    val["c"] = "ccvfbd";

    Json::StreamWriterBuilder builder;
    const std::string json_file = Json::writeString(builder, val);
    std::cout << json_file << std::endl;

    ofstream ofile("text.json");
    ofile << json_file;
    ofile.close();


    Json::Reader reader;
    reader.parse(json_file, val);

    cout << val["name"] << endl << val["age"] << endl << val["a"] << endl;

    cout << val["array"] << endl;

    for (int i = 0; i < val["array"].size(); i++) cout << val["array"][i] << " ";
    cout << endl;

    int x = val["array"][5].asInt();

    cout << x << endl;
}