#ifndef SoftBodyFtROSCOM_H
#define SoftBodyFtROSCOM_H

#include "ambf_server/RosComBase.h"
#include "ambf_msgs/SoftBodyFtState.h"
#include "ambf_msgs/SoftBodyFtCmd.h"
#include "ambf_msgs/sb_edge.h"
#include "ambf_msgs/sb_face.h"


class SoftBodyFtRosCom: public RosComBase<ambf_msgs::SoftBodyFtState, ambf_msgs::SoftBodyFtCmd>{
public:
    SoftBodyFtRosCom(std::string a_name, std::string a_namespace, int a_freq_min, int a_freq_max, double time_out);
    virtual void init();

protected:
    virtual void reset_cmd();
    void sub_cb(ambf_msgs::SoftBodyFtCmdConstPtr msg);
};


#endif
