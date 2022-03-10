#include "gps_handler.h"

bool init_cfg_port(void)
{
    // Init Radar Config Port
    try
    {
        ROS_INFO("I'm here 2");
        ser_Data_Port.setPort(ser_Data_Port_Name);
        ser_Data_Port.setBaudrate(115200);
        serial::Timeout to1 = serial::Timeout::simpleTimeout(1000);
        ser_Data_Port.setTimeout(to1);
        ser_Data_Port.open();
        ROS_INFO("I'm here 3");
    }
    catch (serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open config port ");
        return false;
    }
    if(ser_Data_Port.isOpen()){
        ROS_INFO_STREAM("Radar Config Port initialized");
    }else{
        return false;
    }
}

void timer_uart_Callback(const ros::TimerEvent& )
{
    if(ser_Data_Port.available())
    {
        uint16_t dataLen = 0;
        dataLen = ser_Data_Port.available();
        std_msgs::UInt8MultiArray raw_data;
        ser_Data_Port.read(raw_data.data, ser_Data_Port.available());
        ROS_INFO("Read: %u byte ---------------------", dataLen);
        for(auto i = 0; i < dataLen; i++)
        {
            ROS_INFO("frame %d: %c", i, raw_data.data[i]);
        }

        
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "gps_handler");
    ros::NodeHandle n;
    // ttcRadar_pub = n.advertise<ttcRadar_pkg::ttcRadar_msg>("ttcRadar_Data", 1000);

    // Timer to receive data from GPS
    ros::Timer timer_uart = n.createTimer(ros::Duration(0.1), timer_uart_Callback);

    if(init_cfg_port())
    {

    }
    else{
        return -1;
    }

    // While loop do nothing, data received by interrupt
    while(ros::ok())
    {
        ros::spinOnce();
    }

    string raw_data = "$GPGLL,4717.11634,N,00833.91297,E,124923.00,A,A*6E";

    co_ordinates raw_ltn = {0, 0};
    coord_strore raw_data_spl;
    co_ordinates desire_ltn = {0, 0};
    sog_cog raw_sog_cog = {0, 0};

    gps_analysis_param analysis_param = {"GP", 0, 0, 0, 0, 0, 0, 0, 0};
    dec_drift_data_param dec_drift_param = {0, 0, 0.7, 0.0001, 0};

    // GPRMC_analysis(raw_data, raw_ltn, raw_sog_cog, analysis_param);
    // update_gps_spl(raw_data_spl, raw_ltn);
    // dec_drift_data(raw_data_spl, desire_ltn, dec_drift_param);

    return 0;
}

void GPGLL_analysis(string raw_data, co_ordinates &raw_ltn, gps_analysis_param analysis_param)
{
    if (raw_data.find('*') == string::npos)
    {
        return;
    }
    else if ((analysis_param.pos = raw_data.find('$')) != 0)
    {
        raw_data.erase(0, analysis_param.pos);
    }
    else
    {
        while ((analysis_param.pos = raw_data.find(',')) != string::npos)
        {
            
            switch (analysis_param.cnt)
            {
            case 1:
                analysis_param.token = raw_data.substr(0, analysis_param.pos);
                if(!(analysis_param.token.empty()))
                {
                    analysis_param.degLat = atoi(analysis_param.token.substr(0, 2).c_str());
                    analysis_param.minLat = atof(analysis_param.token.substr(2).c_str())/60;
                    raw_ltn.lat = (float)analysis_param.degLat + analysis_param.minLat;
                }
                else
                {
                    break;
                }
                break;

            case 3:
                analysis_param.token = raw_data.substr(0, analysis_param.pos);
                if(!(analysis_param.token.empty()))
                {
                    analysis_param.degLng = atoi(analysis_param.token.substr(0, 3).c_str());
                    analysis_param.minLng = atof(analysis_param.token.substr(3).c_str())/60;
                    raw_ltn.lng = (float)analysis_param.degLng + analysis_param.minLng;
                    return;
                }
                else
                {
                    break;
                }
                return;
            
            default:
                break;
            }
            raw_data.erase(0, analysis_param.pos + 1);
            analysis_param.cnt++;
        }
    }

    return;
}

void GPRMC_analysis(string raw_data, co_ordinates &raw_ltn, sog_cog &raw_sog_cog, gps_analysis_param analysis_param)
{
    if (raw_data.find('*') == string::npos)
    {
        return;
    }
    else if ((analysis_param.pos = raw_data.find('$')) != 0)
    {
        raw_data.erase(0, analysis_param.pos);
    }
    else
    {
        while ((analysis_param.pos = raw_data.find(',')) != string::npos)
        {

            switch (analysis_param.cnt)
            {
            case 3:
                analysis_param.token = raw_data.substr(0, analysis_param.pos);
                if(!(analysis_param.token.empty()))
                {
                    analysis_param.degLat = atoi(analysis_param.token.substr(0, 2).c_str());
                    analysis_param.minLat = atof(analysis_param.token.substr(2).c_str())/60;
                    raw_ltn.lat = (float)analysis_param.degLat + analysis_param.minLat;
                }
                else
                {
                    break;
                }
                break;

            case 5:
                analysis_param.token = raw_data.substr(0, analysis_param.pos);
                if(!(analysis_param.token.empty()))
                {
                    analysis_param.degLng = atoi(analysis_param.token.substr(0, 3).c_str());
                    analysis_param.minLng = atof(analysis_param.token.substr(3).c_str())/60;
                    raw_ltn.lng = (float)analysis_param.degLng + analysis_param.minLng;
                }
                else
                {
                    break;
                }
                break;

            case 7:
                analysis_param.token = raw_data.substr(0, analysis_param.pos);
                if(!(analysis_param.token.empty()))
                {
                    raw_sog_cog.sog = atof(analysis_param.token.substr(0).c_str());
                }
                else
                {
                    break;
                }
                break;

            case 8:
                analysis_param.token = raw_data.substr(0, analysis_param.pos);
                if(!(analysis_param.token.empty()))
                {
                    raw_sog_cog.cog = atof(analysis_param.token.substr(0).c_str());
                }
                else
                {
                    break;
                }
                return;
            
            default:
                break;

            }
            raw_data.erase(0, analysis_param.pos + 1);
            analysis_param.cnt++;
        }
    }

    return;
}

void update_gps_spl(coord_strore &raw_data_spl, co_ordinates raw_ltn)
{
    if(raw_data_spl.lat_spl.size() >= gps_spl_quantity)
    {
        raw_data_spl.lat_spl.erase(raw_data_spl.lat_spl.begin());
        raw_data_spl.lng_spl.erase(raw_data_spl.lng_spl.begin());
    }
    raw_data_spl.lat_spl.push_back(raw_ltn.lat);
    raw_data_spl.lng_spl.push_back(raw_ltn.lng);

    return;
}

void dec_drift_data(coord_strore &raw_data_spl, co_ordinates &desire_ltn, dec_drift_data_param dec_drift_param)
{
    for(int i = 0; i < raw_data_spl.lat_spl.size(); i++)
    {
    dec_drift_param.lat0 = dec_drift_param.lat0 + raw_data_spl.lat_spl.at(i)/raw_data_spl.lat_spl.size();
    dec_drift_param.lng0 = dec_drift_param.lng0 + raw_data_spl.lng_spl.at(i)/raw_data_spl.lng_spl.size();
    }
    dec_drift_param.n = raw_data_spl.lat_spl.size();
    while(((float)dec_drift_param.n)/raw_data_spl.lat_spl.size() > dec_drift_param.p)
    {
        for(int i = 0; i < dec_drift_param.n; i++)
        {
            if((raw_data_spl.lat_spl.at(i) - dec_drift_param.lat0 > dec_drift_param.step) || (raw_data_spl.lng_spl.at(i) - dec_drift_param.lng0 > dec_drift_param.step))
            {
                raw_data_spl.lat_spl.erase(raw_data_spl.lat_spl.begin() + i);
                raw_data_spl.lng_spl.erase(raw_data_spl.lng_spl.begin() + i);
                dec_drift_param.n--;
            }
            else
            {
                dec_drift_param.n = dec_drift_param.p;
            }
        }
        dec_drift_param.step += 0.0001;
    }
    dec_drift_param.lat0 = 0.0;
    dec_drift_param.lng0 = 0.0;
    for(int i = 0; i < raw_data_spl.lat_spl.size(); i++)
    {
        dec_drift_param.lat0 = dec_drift_param.lat0 + raw_data_spl.lat_spl.at(i)/raw_data_spl.lat_spl.size();
        dec_drift_param.lng0 = dec_drift_param.lng0 + raw_data_spl.lng_spl.at(i)/raw_data_spl.lng_spl.size();
    }
    desire_ltn.lat = dec_drift_param.lat0;
    desire_ltn.lng = dec_drift_param.lng0;

    return;
}