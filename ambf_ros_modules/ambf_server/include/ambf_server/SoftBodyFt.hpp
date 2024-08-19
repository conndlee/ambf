#ifndef AFSOFTBODYFTCOMM_H
#define AFSOFTBODYFTCOMM_H

#include <string>
#include "ambf_server/SoftBodyFtRosCom.hpp"

namespace ambf_comm{

class SoftBodyFt: public SoftBodyFtRosCom{
public:
    SoftBodyFt(std::string a_name, 
        std::string a_namespace, 
        int a_freq_min, 
        int a_freq_max, 
        double time_out);

    // virtual ambf_msgs::SoftBodyFtCmd get_command();
    // void cur_position(double px, double py, double pz);
    // void cur_orientation(double roll, double pitch, double yaw);
    // void cur_orientation(double qx, double qy, double qz, double qw);
    // This method is to set the description of additional data that could for debugging purposes or future use
    // inline void set_userdata_desc(std::string description){m_State.userdata_description = description;}
    // This method is to set any additional data that could for debugging purposes or future use
    void set_userdata(float a_data);
    // This method is to set any additional data that could for debugging purposes or future use
    void set_userdata(std::vector<float> &a_data);

    void cur_vertices(std::vector<std::vector<float>> vertices);
    void cur_edges(std::vector<std::vector<int>> edges);
    void cur_faces(std::vector<std::vector<int>> face_vertices, std::vector<std::vector<float>> face_normals);
    
};
}

#endif
