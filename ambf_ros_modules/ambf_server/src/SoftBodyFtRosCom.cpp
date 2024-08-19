
#include "ambf_server/SoftBodyFtRosCom.hpp"

SoftBodyFtRosCom::SoftBodyFtRosCom(std::string a_name, std::string a_namespace, int a_freq_min, int a_freq_max, double time_out): RosComBase(a_name, a_namespace, a_freq_min, a_freq_max, time_out){
    init();
}

void SoftBodyFtRosCom::init(){
    m_State.name.data = m_name;
    m_State.sim_step = 0;

    m_pub = nodePtr->advertise<ambf_msgs::SoftBodyFtState>("/" + m_namespace + "/" + m_name + "/State", 10);
    m_sub = nodePtr->subscribe("/" + m_namespace + "/" + m_name + "/Command", 10, &SoftBodyFtRosCom::sub_cb, this);

    m_thread = boost::thread(boost::bind(&SoftBodyFtRosCom::run_publishers, this));
    std::cerr << "INFO! Thread Joined: " << m_name << std::endl;
}

void SoftBodyFtRosCom::reset_cmd(){
    // m_Cmd.enable_position_controller = false;
    // m_Cmd.wrench.force.x = 0;
    // m_Cmd.wrench.force.y = 0;
    // m_Cmd.wrench.force.z = 0;
    // m_Cmd.wrench.torque.x = 0;
    // m_Cmd.wrench.torque.y = 0;
    // m_Cmd.wrench.torque.z = 0;
    // for(size_t idx = 0 ; idx < m_Cmd.joint_cmds.size() ; idx++){
    //     m_Cmd.joint_cmds[idx] = 0;
    // }
    // for(size_t idx = 0 ; idx < m_Cmd.position_controller_mask.size() ; idx++){
    //     m_Cmd.position_controller_mask[idx] = 0;
    // }
}

void SoftBodyFtRosCom::sub_cb(ambf_msgs::SoftBodyFtCmdConstPtr msg){
    m_Cmd = *msg;
    m_watchDogPtr->acknowledge_wd();
}
