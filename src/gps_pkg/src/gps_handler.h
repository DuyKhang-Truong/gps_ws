#ifndef GPS_HANDLER_H
#define GPS_HANDLER_H

#include <iostream>
#include <vector>
#include <string>
#include <ros/ros.h>
#include <serial/serial.h>
#include "std_msgs/UInt8MultiArray.h"

using namespace std;

serial::Serial ser_Data_Port;

#define ser_Data_Port_Name "/dev/ttyUSB0"
#define gps_spl_quantity 10

struct co_ordinates
{
    float lat;
    float lng;
};

struct coord_strore
{
    vector<float> lat_spl;
    vector<float> lng_spl;
};

struct gps_analysis_param
{
    int pos;
    int cnt;
    int degLat;
    int degLng;
    float minLat;
    float minLng;
    string token;
};

struct dec_drift_data_param
{
    float lat0;
    float lng0;
    float p;
    float step;
    int n;
};



void gps_analysis(string raw_data, char delimiter, co_ordinates &raw_ltn, gps_analysis_param analysis_param);

void update_gps_spl(coord_strore &raw_data_spl, co_ordinates raw_ltn);

void dec_drift_data(coord_strore &raw_data_spl, co_ordinates &desire_ltn, dec_drift_data_param dec_drift_param);

#endif // GPS_HANDLER_H