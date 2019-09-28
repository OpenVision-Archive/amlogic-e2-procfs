/*
 * e2_procfs_bus.c
 *
 * (c) 2015 SIP-Online
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include "e2_procfs.h"

#include <linux/dvb/frontend.h>
#include "dvbdev.h"

#define DVB_MAX_FRONTEND 8


int e2procfs_nim_sockets_write(struct ProcWriteInfo *proc_info, char *kbuf)
{
	int len = 0;

	proc_info->bpage = kbuf;

	return len;
}
int e2procfs_nim_sockets_show(struct seq_file *m, void* data)
{
	struct ProcWriteInfo *proc_info = m->private;
	int len = 0;
	if (proc_info->count > 0)
	{
		len = seq_printf(m, "%s\n", proc_info->bpage);
	}
	else
	{
		len += seq_printf(m,
		"NIM Socket 0:\n"
		"\tType: DVB-T2\n"
		"\tName: Availink avl6862\n"
		"\tHas_Outputs: no\n"
		"\tFrontend_Device: 0\n"
		);
	}
	return len;


// 	struct file* fe_fd = NULL;
// 	int adapter_num = 0, nsocket_index = 0, len = 0;
// 	char devstr[MAX_CHAR_LENGTH];
// 	struct
// 	{
// 		int type;
// 		char *pType;
// 	} typeMap[] = {
// /*
// 		{ FE_QPSK,	"DVB-S2" },
// 		{ FE_QAM,	"DVB-C" },
// 		{ FE_OFDM,	"DVB-T" },
// 		{ FE_ATSC,	"ATSC" }
// */
// 		{ SYS_UNDEFINED,	"UNDEFINED" },
// 		{ SYS_DVBC_ANNEX_A,	"DVB-C ann.A" },
// 		{ SYS_DVBC_ANNEX_B,	"DVB-C ann.B" },
// 		{ SYS_DVBT,			"DVB-T" },
// 		{ SYS_DSS,			"DSS" },
// 		{ SYS_DVBS,			"DVB-S" },
// 		{ SYS_DVBS2,		"DVB-S2" },
// 		{ SYS_DVBH,			"DVB-H" },
// 		{ SYS_ISDBT,		"ISDB-T" },
// 		{ SYS_ISDBS,		"ISDB-S" },
// 		{ SYS_ISDBC,		"ISDB-C" },
// 		{ SYS_ATSC,			"ATSC" },
// 		{ SYS_ATSCMH,		"ATSC/MH" },
// 		{ SYS_DTMB,			"DTMB" },
// 		{ SYS_CMMB,			"CMMB" },
// 		{ SYS_DAB,			"DAB" },
// 		{ SYS_DVBT2,		"DVB-T2" },
// 		{ SYS_TURBO,		"TURBO-FEC" },
// 		{ SYS_DVBC_ANNEX_C,	"DVB-C ann.C" }
// 	};

// 	while (adapter_num < DVB_MAX_ADAPTERS)
// 	{
// 		int frontend_num = 0;

// 		while (frontend_num < DVB_MAX_FRONTEND)
// 		{
// 			int bytes = 0, nsocket_i = 0;

// 			bytes = sprintf(devstr, "/dev/dvb/adapter%d/frontend%d", adapter_num, frontend_num);

// 			fe_fd = file_open(devstr, O_RDONLY, bytes);

// 			if (fe_fd != NULL)
// 			{
// 				struct dvb_device *dvbdev = fe_fd->private_data;
// 				struct dvb_frontend_info fe_info;
// 				struct dtv_property p[] = {{ .cmd = DTV_DELIVERY_SYSTEM }};
// 				struct dtv_properties cmdseq = { .num = 1, .props = p };
// 				char *p_type = "unknown";

// 				if (dvb_generic_ioctl(fe_fd, FE_GET_INFO, 0))
// 				{
// 					dvbdev->kernel_ioctl(fe_fd, FE_GET_INFO, &fe_info);

// 					if (dvb_generic_ioctl(fe_fd, FE_GET_PROPERTY, 0))
// 					{
// 						dvbdev->kernel_ioctl(fe_fd, FE_GET_PROPERTY, &cmdseq);

// 						for (nsocket_i = 0; nsocket_i < sizeof(typeMap) / sizeof(typeMap[0]); nsocket_i++)
// 						{
// 							if (p->u.data == typeMap[nsocket_i].type)
// 							{
// 								p_type = typeMap[nsocket_i].pType;

// 								break;
// 							}
// 						}

// 						len += seq_printf(
// 							m,
// 								"NIM Socket %d:\n"
// 								"\tType: %s\n"
// 								"\tName: %s\n"
// 							//	"\tHas_Outputs: no\n"
// 							//	"\tInternally_Connectable: 0\n"
// 								"\tFrontend_Device: %d\n"
// 							//	"\tI2C_Device: -1\n"
// 							,
// 							nsocket_index,
// 							p_type,
// 							fe_info.name,
// 							frontend_num
// 						);

// 						nsocket_index++;
// 					}
// 				}
// 			}

// 			frontend_num++;

// 			file_close(fe_fd);
// 		}

// 		adapter_num++;
// 	}

	return len;
}
