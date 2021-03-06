#ifndef __PPPD_TMP_H__
#define __PPPD_TMP_H__

#include "ppp_remark.h"

extern struct remark_ipinfo remark_ipinfo_all[];

void ppp_if_mem_malloc(void);
void ppp_remark_del_interface(unsigned int if_num);
void remark_channel_init();
void mcp_pppd_init_one_local_interface(int unit);
int mcp_ppp_interface_info_update_local(struct pppd_interface_info *info);
int pppd_interface_enable(int unit);
int pppd_interface_disable(int unit);
int mcp_pppd_have_channel_to_group(struct multilink_if_info* multi_info);
void ppp_if_mem_free(void);
void mcp_pppd_init_all_local_interface(void);
void ppp_if_create_init(void);
struct ppp_interface * ppp_if_exist_mp_mater(unsigned int group);
void ppp_set_ifip_by_groupip(unsigned int group, unsigned int groupip);
int ppp_have_interface_is_enable(void);
struct ppp_interface* mcp_pppd_is_channel_to_group(struct multilink_if_info* multi_info, unsigned int channel);
int ppp_if_close_all_enalbe_channel(void);
void pppd_interface_neg_variable_init(struct ppp_interface *pif);
int ppp_if_get_mp_mater(unsigned int unit);
int mcp_pppd_interface_changed(struct pppd_interface_info *info);
int mcp_pppd_disable_allinterface_addto_group(struct multilink_if_info* multi_info);

#endif

