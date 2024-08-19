#include "ambf_server/SoftBodyFt.hpp"
namespace ambf_comm{

SoftBodyFt::SoftBodyFt(std::string a_name, std::string a_namespace, int a_freq_min, int a_freq_max, double time_out): SoftBodyFtRosCom(a_name, a_namespace, a_freq_min, a_freq_max, time_out){
}

// void SoftBodyFt::cur_position(double px, double py, double pz){
//     m_trans.setOrigin(tf::Vector3(px, py, pz));
//     m_State.pose.position.x = px;
//     m_State.pose.position.y = py;
//     m_State.pose.position.z = pz;
// }

// void SoftBodyFt::cur_orientation(double roll, double pitch, double yaw){
//     tf::Quaternion rot_quat;
//     rot_quat.setRPY(roll, pitch, yaw);
//     m_trans.setRotation(rot_quat);
//     tf::quaternionTFToMsg(rot_quat, m_State.pose.orientation);
// }

// void SoftBodyFt::cur_orientation(double qx, double qy, double qz, double qw){
//     tf::Quaternion rot_quat(qx, qy, qz, qw);
//     m_trans.setRotation(rot_quat);
//     tf::quaternionTFToMsg(rot_quat, m_State.pose.orientation);
// }

// ambf_msgs::SoftBodyFtCmd SoftBodyFt::get_command(){
//     ambf_msgs::SoftBodyFtCmd temp_cmd = m_Cmd;
//     int joint_commands_size = m_Cmd.joint_cmds.size();
//     temp_cmd.joint_cmds.resize(joint_commands_size);
//     temp_cmd.position_controller_mask.resize(joint_commands_size);
//     temp_cmd.enable_position_controller = m_Cmd.enable_position_controller;
//     for(size_t idx = 0; idx < joint_commands_size ; idx++){
//         temp_cmd.joint_cmds[idx] = m_Cmd.joint_cmds[idx];
//         if (idx < m_Cmd.position_controller_mask.size()){
//             temp_cmd.position_controller_mask[idx] = m_Cmd.position_controller_mask[idx];
//         }
//         else{
//             temp_cmd.position_controller_mask[idx] = 0;
//         }
//     }
//     return temp_cmd;
// }

void SoftBodyFt::set_userdata(float a_data){
    // if (m_State.userdata.size() != 1){
    //     m_State.userdata.resize(1);
    // }
    // m_State.userdata[0] = a_data;
}

void SoftBodyFt::set_userdata(std::vector<float> &a_data){
    // if (m_State.userdata.size() != a_data.size()){
    //     m_State.userdata.resize(a_data.size());
    // }
    // m_State.userdata = a_data;
}

void SoftBodyFt::cur_vertices(std::vector<std::vector<float>> vertices){
    if(m_State.vertices.size() == 0){
        m_State.vertices.resize(vertices.size());
    }
    m_State.vertices.clear();
    // std::cout << m_State.vertices.size() << "\n";
    // std::pair<int, float[3]> vertex;
    int i = 0;
    geometry_msgs::Point p;
    for(std::vector<float> v : vertices){
        p.x = v[0];
        p.y = v[1];
        p.z = v[2];
        m_State.vertices.push_back(p);
        i++;
    }
    // std::cout << m_State.vertices.size() << "\n";
}

void SoftBodyFt::cur_edges(std::vector<std::vector<int>> edges){
    if(m_State.edges.size() == 0){
        m_State.edges.resize(edges.size());
    }
    m_State.edges.clear();
    // std::cout << m_State.vertices.size() << "\n";
    // std::pair<int, float[3]> vertex;
    int i = 0;
    ambf_msgs::sb_edge l;
    for(std::vector<int> e : edges){
        l.vertices[0] = e[0];
        l.vertices[1] = e[1];
        m_State.edges.push_back(l);
        i++;
    }
    // std::cout << m_State.vertices.size() << "\n";
}

void SoftBodyFt::cur_faces(std::vector<std::vector<int>> face_vertices, std::vector<std::vector<float>> face_normals){
    if(m_State.faces.size() == 0){
        m_State.faces.resize(face_normals.size());
    }
    m_State.faces.clear();
    ambf_msgs::sb_face f;
    for (int i=0; i < face_normals.size(); i++){
        f.vertices[0] = face_vertices[i][0];
        f.vertices[1] = face_vertices[i][1];
        f.vertices[2] = face_vertices[i][2];

        f.normal.x = face_normals[i][0];
        f.normal.y = face_normals[i][1];
        f.normal.z = face_normals[i][2];
        m_State.faces.push_back(f);
    }
}

extern "C"{

SoftBodyFt* create_SoftBodyFt(std::string a_name, std::string a_namespace="/ambf_comm/", int a_min_freq=50, int a_max_freq=1000, double time_out=0.5){
    return new SoftBodyFt(a_name, a_namespace, a_min_freq, a_max_freq, time_out);
}

void destroy_SoftBodyFt(SoftBodyFt* obj){
    delete obj;
}

}

}
