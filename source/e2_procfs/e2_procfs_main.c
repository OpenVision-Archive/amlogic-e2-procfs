/*
 * e2_proc_main.c
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

struct ProcStructure_s e2Proc[] =
{
	{cProcEntry, "progress"                                                         , NULL, e2procfs_progress_show, e2procfs_progress_write, NULL, ""},

	{cProcEntry, "bus/nim_sockets"                                                  , NULL, e2procfs_nim_sockets_show, e2procfs_nim_sockets_write, NULL, ""},
	{cProcDir  , "stb"                                                              , NULL, NULL, NULL, NULL, ""},
	{cProcDir  , "stb/audio"                                                        , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/audio/ac3"                                                    , NULL, e2procfs_ac3_show, e2procfs_ac3_write, NULL, ""},
	{cProcEntry, "stb/audio/audio_delay_pcm"                                        , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/audio/audio_delay_bitstream"                                  , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/audio/j1_mute"                                                , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/audio/ac3_choices"                                            , NULL, e2procfs_ac3choices_show, NULL, NULL, ""},
	{cProcEntry, "stb/audio/dts"                                                    , NULL, e2procfs_dts_show, e2procfs_dts_write, NULL, ""},
	{cProcEntry, "stb/audio/dts_choices"                                            , NULL, e2procfs_dtschoices_show, NULL, NULL, ""},

	{cProcDir  , "stb/frontend" 		                                        , NULL, NULL, NULL, NULL, ""},
	{cProcDir  , "stb/frontend/0"                                                   , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/frontend/0/mode"                                              , NULL, e2procfs_frontend_mode_show, e2procfs_frontend_mode_write, NULL, ""},

	{cProcDir  , "stb/info"                                                         , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/info/model"                                                   , NULL, e2procfs_info_model_show, NULL, NULL, ""},
	{cProcEntry, "stb/info/boxtype"                                                 , NULL, e2procfs_info_boxtype_show, NULL, NULL, ""},
	{cProcEntry, "stb/info/chipset"                                                 , NULL, e2procfs_info_chipset_show, NULL, NULL, ""},

	{cProcDir  , "stb/video"                                                        , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/alpha"                                                  , NULL, e2procfs_valpha_show, e2procfs_valpha_write, NULL, ""},
	{cProcEntry, "stb/video/aspect"                                                 , NULL, e2procfs_vaspect_show, NULL, NULL, ""},
	{cProcEntry, "stb/video/aspect_choices"                                         , NULL, e2procfs_vachoices_show, NULL, NULL, ""},
	{cProcEntry, "stb/video/force_dvi"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/policy"                                                 , NULL, e2procfs_vpolicy_show, NULL, NULL, ""},
	{cProcEntry, "stb/video/policy_choices"                                         , NULL, e2procfs_vpchoices_show, NULL, NULL, ""},
	{cProcEntry, "stb/video/videomode"                                              , NULL, e2procfs_vmode_show, e2procfs_vmode_write, NULL, ""},
	{cProcEntry, "stb/video/3d_mode"                                                , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/videomode_50hz"                                         , NULL, e2procfs_vmode50_show, e2procfs_vmode50_write, NULL, ""},
	{cProcEntry, "stb/video/videomode_60hz"                                         , NULL, e2procfs_vmode60_show, e2procfs_vmode60_write, NULL, ""},
	{cProcEntry, "stb/video/videomode_choices"                                      , NULL, e2procfs_vchoices_show, NULL, NULL, ""},
	{cProcEntry, "stb/video/videomode_50hz_choices"                                 , NULL, e2procfs_vchoices50_show, NULL, NULL, ""},
	{cProcEntry, "stb/video/videomode_60hz_choices"                                 , NULL, e2procfs_vchoices60_show, NULL, NULL, ""},
	{cProcEntry, "stb/video/videomode_preferred"                                    , NULL, e2procfs_vpreferred_show, NULL, NULL, ""},
	{cProcEntry, "stb/video/pal_v_start"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/pal_v_end"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/pal_h_start"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/pal_h_end"                                              , NULL, NULL, NULL, NULL, ""},

	{cProcDir  , "stb/avs"                                                          , NULL, NULL, NULL, NULL, ""},
	{cProcDir  , "stb/avs/0"                                                        , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/avs/0/colorformat"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/avs/0/colorformat_choices"                                    , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/avs/0/fb"                                                     , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/avs/0/input"                                                  , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/avs/0/sb"                                                     , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/avs/0/volume"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/avs/0/input_choices"                                          , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/avs/0/standby"                                                , NULL, NULL, NULL, NULL, ""},

	{cProcDir  , "stb/denc"                                                         , NULL, NULL, NULL, NULL, ""},
	{cProcDir  , "stb/denc/0"                                                       , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/denc/0/wss"                                                   , NULL, e2procfs_wss_denc_show, e2procfs_wss_denc_write, NULL, ""},
	{cProcEntry, "stb/denc/0/wss_choices"                                           , NULL, e2procfs_wssc_denc_show, NULL, NULL, ""},

	{cProcDir  , "stb/fb"                                                           , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fb/3dmode"                                                    , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fb/znorm"                                                     , NULL, NULL, NULL, NULL, ""},

	{cProcDir  , "stb/fp"                                                           , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fp/lnb_sense1"                                                , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fp/lnb_sense2"                                                , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fp/led0_pattern"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fp/led_pattern_speed"                                         , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fp/version"                                                   , NULL, e2procfs_fpver_show, NULL, NULL, ""},
	//rtc is disabled for now because it causes segmentation fault
	// {cProcEntry, "stb/fp/wakeup_time"                                               , NULL, e2procfs_fpwut_show, e2procfs_fpwut_write, NULL, ""},
	// {cProcEntry, "stb/fp/was_timer_wakeup"                                          , NULL, e2procfs_fpwtw_show, e2procfs_fpwtw_write, NULL, ""},
	// {cProcEntry, "stb/fp/rtc"                                                       , NULL, e2procfs_fprtc_show, e2procfs_fprtc_write, NULL, ""},

	{cProcDir  , "stb/tsmux"                                                        , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/tsmux/input0"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/tsmux/input1"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/tsmux/ci0_input"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/tsmux/ci1_input"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/tsmux/lnb_b_input"                                            , NULL, NULL, NULL, NULL, ""},

	{cProcDir  , "stb/misc"                                                         , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/misc/12V_output"                                              , NULL, NULL, NULL, NULL, ""},

	{cProcDir  , "stb/vmpeg"                                                        , NULL, NULL, NULL, NULL, ""},
	{cProcDir  , "stb/vmpeg/0"                                                      , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/dst_left"                                             , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/dst_top"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/dst_width"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/dst_height"                                           , NULL, NULL, e2procfs_vmpeg_dstheight_write, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/dst_all"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/yres"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/xres"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/aspect"                                               , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/0/framerate"                                            , NULL, NULL, NULL, NULL, ""},

	{cProcDir  , "stb/vmpeg/1"                                                      , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/dst_left"                                             , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/dst_top"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/dst_width"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/dst_height"                                           , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/dst_all"                                              , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/yres"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/xres"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/aspect"                                               , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/vmpeg/1/framerate"                                            , NULL, NULL, NULL, NULL, ""},

	{cProcDir  , "stb/hdmi"                                                         , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/hdmi/bypass_edid_checking"                                    , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/hdmi/enable_hdmi_resets"                                      , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/hdmi/output"                                                  , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/hdmi/output_choices"                                          , NULL, NULL, NULL, NULL, ""},
//	{cProcEntry, "stb/hdmi/audio_source"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/hdmi/audio_source_choices"                                    , NULL, NULL, NULL, NULL, ""},

	{cProcDir,   "stb/stream"                                                       , NULL, NULL, NULL, NULL, ""},
	{cProcDir,   "stb/stream/policy"                                                , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/stream/policy/AV_SYNC"                                        , NULL, NULL, NULL, NULL, "AV_SYNC"},
	{cProcEntry, "stb/stream/policy/TRICK_MODE_AUDIO"                               , NULL, NULL, NULL, NULL, "TRICK_MODE_AUDIO"},
	{cProcEntry, "stb/stream/policy/PLAY_24FPS_VIDEO_AT_25FPS"                      , NULL, NULL, NULL, NULL, "PLAY_24FPS_VIDEO_AT_25FPS"},
	{cProcEntry, "stb/stream/policy/MASTER_CLOCK"                                   , NULL, NULL, NULL, NULL, "MASTER_CLOCK"},
	{cProcEntry, "stb/stream/policy/EXTERNAL_TIME_MAPPING"                          , NULL, NULL, NULL, NULL, "EXTERNAL_TIME_MAPPING"},
	{cProcEntry, "stb/stream/policy/DISPLAY_FIRST_FRAME_EARLY"                      , NULL, NULL, NULL, NULL, "DISPLAY_FIRST_FRAME_EARLY"},
	{cProcEntry, "stb/stream/policy/STREAM_ONLY_KEY_FRAMES"                         , NULL, NULL, NULL, NULL, "STREAM_ONLY_KEY_FRAMES"},
	{cProcEntry, "stb/stream/policy/STREAM_SINGLE_GROUP_BETWEEN_DISCONTINUITIES"    , NULL, NULL, NULL, NULL, "STREAM_SINGLE_GROUP_BETWEEN_DISCONTINUITIES"},
	{cProcEntry, "stb/stream/policy/PLAYOUT_ON_TERMINATE"                           , NULL, NULL, NULL, NULL, "PLAYOUT_ON_TERMINATE"},
	{cProcEntry, "stb/stream/policy/PLAYOUT_ON_SWITCH"                              , NULL, NULL, NULL, NULL, "PLAYOUT_ON_SWITCH"},
	{cProcEntry, "stb/stream/policy/PLAYOUT_ON_DRAIN"                               , NULL, NULL, NULL, NULL, "PLAYOUT_ON_DRAIN"},
	{cProcEntry, "stb/stream/policy/TRICK_MODE_DOMAIN"                              , NULL, NULL, NULL, NULL, "TRICK_MODE_DOMAIN"},
	{cProcEntry, "stb/stream/policy/DISCARD_LATE_FRAMES"                            , NULL, NULL, NULL, NULL, "DISCARD_LATE_FRAMES"},
	{cProcEntry, "stb/stream/policy/REBASE_ON_DATA_DELIVERY_LATE"                   , NULL, NULL, NULL, NULL, "REBASE_ON_DATA_DELIVERY_LATE"},
	{cProcEntry, "stb/stream/policy/REBASE_ON_FRAME_DECODE_LATE"                    , NULL, NULL, NULL, NULL, "REBASE_ON_FRAME_DECODE_LATE"},
	{cProcEntry, "stb/stream/policy/LOWER_CODEC_DECODE_LIMITS_ON_FRAME_DECODE_LATE" , NULL, NULL, NULL, NULL, "LOWER_CODEC_DECODE_LIMITS_ON_FRAME_DECODE_LATE"},
	{cProcEntry, "stb/stream/policy/H264_ALLOW_NON_IDR_RESYNCHRONIZATION"           , NULL, NULL, NULL, NULL, "H264_ALLOW_NON_IDR_RESYNCHRONIZATION"},
	{cProcEntry, "stb/stream/policy/MPEG2_IGNORE_PROGESSIVE_FRAME_FLAG"             , NULL, NULL, NULL, NULL, "MPEG2_IGNORE_PROGESSIVE_FRAME_FLAG"},

	{cProcDir,   "stb/video/plane"                                                  , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/plane/psi_brightness"                                   , NULL, NULL, NULL, NULL, "psi_brightness"},
	{cProcEntry, "stb/video/plane/psi_saturation"                                   , NULL, NULL, NULL, NULL, "psi_saturation"},
	{cProcEntry, "stb/video/plane/psi_contrast"                                     , NULL, NULL, NULL, NULL, "psi_contrast"},
	{cProcEntry, "stb/video/plane/psi_tint"                                         , NULL, NULL, NULL, NULL, "psi_tint"},
	{cProcEntry, "stb/video/plane/psi_apply"                                        , NULL, NULL, NULL, NULL, "psi_apply"},
/*
	{cProcDir  , "stb/cec"                                                          , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/cec/state_activesource"                                       , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/cec/state_standby"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/cec/state_cecaddress"                                         , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/cec/onetouchplay"                                             , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/cec/systemstandby"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/cec/event_poll"                                               , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/cec/send"                                                     , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/plane/dei_fmd"                                          , NULL, NULL, NULL, NULL, "dei_fmd"},
	{cProcEntry, "stb/video/plane/dei_mode"                                         , NULL, NULL, NULL, NULL, "dei_mode"},
	{cProcEntry, "stb/video/plane/dei_ctrl"                                         , NULL, NULL, NULL, NULL, "dei_ctrl"},
	{cProcDir  , "stb/fan"                                                          , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fan/fan_ctrl"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcDir  , "stb/fan"                                                          , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/hdmi/cec"                                                     , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/fan/fan_ctrl"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/switch_type"                                            , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/switch"                                                 , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/video/switch_choices"                                         , NULL, NULL, NULL, NULL, ""},
*/
	{cProcDir  , "stb/player"                                                       , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/player/version"                                               , NULL, NULL, NULL, NULL, ""},

	{cProcDir  , "stb/aml"                                                          , NULL, NULL, NULL, NULL, ""},
	{cProcEntry, "stb/aml/videoinfo"                                                , NULL, e2procfs_amlinfo_show, e2procfs_amlinfo_write, NULL, ""},
	{cProcEntry, "stb/aml/osdinfo"                                                  , NULL, e2procfs_amlosd_show, e2procfs_amlosd_write, NULL, ""}
};

struct proc_dir_entry * find_proc_dir(char * name)
{
	int i;

	for (i = 0; i < sizeof(e2Proc) / sizeof(e2Proc[0]); i++)
	{
		if ((e2Proc[i].type == cProcDir) && (strcmp(name, e2Proc[i].name) == 0))
			return e2Proc[i].entry;
	}

	return NULL;
}

static int e2procfs_show(struct seq_file *m, void* data)
{
	struct ProcWriteInfo *proc_info = m->private;
	int len = seq_printf(m, "\n");
	int bytes = 0;
	char bufferfile[MAX_CHAR_LENGTH];

	bytes = sprintf(bufferfile, "e2procfs_show : proc_info->proc_i = %d\n", proc_info->proc_i);
	save_data_to_file("/tmp/e2procfs_show.txt", O_RDWR | O_CREAT | O_APPEND, bufferfile, bytes);

	return len;
}

static int e2procfs_open(struct inode *inode, struct file *file)
{
	struct ProcWriteInfo *proc_info;
	int i;
	char *path, *ptr = NULL, *e2Proc_fpath = NULL;

	proc_info = kmalloc(sizeof(struct ProcWriteInfo), GFP_KERNEL);
	if (proc_info == NULL)
		return -ENOMEM;

	path = kmalloc(PAGE_SIZE, GFP_KERNEL);
	e2Proc_fpath = kmalloc(PAGE_SIZE, GFP_KERNEL);
	ptr = d_path(&file->f_path, path, PAGE_SIZE);

	proc_info->proc_i = -EPERM;

	for (i = 0; i < sizeof(e2Proc) / sizeof(e2Proc[0]); i++)
	{
		int bytes = 0;
		char buffer[MAX_CHAR_LENGTH];

		sprintf(e2Proc_fpath, "/proc/%s", e2Proc[i].name);

		bytes = sprintf(buffer, "e2Proc : file->f_mode = %d / %s / %s == %s\n", file->f_mode, e2Proc[i].name, ptr, e2Proc_fpath);
//		save_data_to_file("/tmp/e2Proc.txt", O_RDWR | O_CREAT | O_APPEND, buffer, bytes);

//		if (e2Proc[i].type == cProcEntry && strstr(ptr, e2Proc[i].name))
		if (e2Proc[i].type == cProcEntry && !strcmp(ptr, e2Proc_fpath))
		{
			proc_info->proc_i = i;
			proc_info->count = -EPERM;

			if (file->f_mode & FMODE_READ)
			{
				if (e2Proc[i].read_proc != NULL)
				{
					if (e2Proc[i].proc_info != NULL)
					{
						proc_info = e2Proc[i].proc_info;
					}

					return single_open(file, e2Proc[i].read_proc, proc_info);
				}

				return single_open(file, e2procfs_show, proc_info);
			}
			else if (file->f_mode & FMODE_WRITE)
			{
				if (e2Proc[i].write_proc == NULL)
				{
					proc_info->proc_i = -EPERM;
				}

				file->private_data = proc_info;
			}

			break;
		}
	}

	return 0;
}

static ssize_t e2procfs_write(struct file *file, const char __user *ubuf,
			       size_t count, loff_t *ppos)
{
	struct ProcWriteInfo *proc_info = file->private_data;
	char *kbuf;

	kbuf = kmalloc(count + 1, GFP_KERNEL);
	if (!kbuf)
		return -ENOMEM;

	if (copy_from_user(kbuf, ubuf, count)) {
		count = -EFAULT;
	}
	else
	{
		kbuf[count] = '\0'; /* Just to make sure... */

		if (proc_info->proc_i >= 0)
		{
			int proc_i = proc_info->proc_i;

			proc_info->ubuf = ubuf;
			proc_info->count = count;
			e2Proc[proc_i].write_proc(proc_info, kbuf);
			e2Proc[proc_i].proc_info = proc_info;
		}
	}

	return count;
}

static unsigned int e2procfs_poll(struct file *file,
				   struct poll_table_struct *wait)
{
	unsigned int mask = 0;

#ifdef DEBUG
	printk(KERN_DEBUG "e2procfs: poll called (unimplemented)\n");
#endif

	return mask;
}

static int e2procfs_release(struct inode *inode, struct file *file)
{
//	struct ProcWriteInfo *proc_info = file->private_data;

#ifdef DEBUG
	printk(KERN_DEBUG "e2procfs: release called\n");
#endif
//	kfree(proc_info);

	return 0;
}

static const struct file_operations e2procfs_fops = {
	.owner          = THIS_MODULE,
	.open			= e2procfs_open,
	.read           = seq_read,
	.write          = e2procfs_write,
	.llseek         = no_llseek,
	.poll           = e2procfs_poll,
	.mmap           = NULL,
	.release        = e2procfs_release,
};

static int __init e2procfs_init_module(void)
{
	int i;
	char *path;
	char *name;

	for (i = 0; i < sizeof(e2Proc) / sizeof(e2Proc[0]); i++)
	{
		path = dirname(e2Proc[i].name);
		name = basename(e2Proc[i].name);

		switch (e2Proc[i].type)
		{
			case cProcDir:
				e2Proc[i].entry = proc_mkdir(name, find_proc_dir(path));

				if (e2Proc[i].entry == NULL)
				{
					printk("%s(): could not create entry %s\n", __func__, e2Proc[i].name);
				}

				break;
			case cProcEntry:
				e2Proc[i].entry = proc_create(
					(strcmp("bus", path) == 0) ? e2Proc[i].name : name,
					0,
					(strcmp("bus", path) == 0) ? NULL : find_proc_dir(path),
					&e2procfs_fops
				);

				break;
			default:
				printk("%s(): invalid type %d\n", __func__, e2Proc[i].type);
		}
	}

	return 0;
}

static void __exit e2procfs_cleanup_module(void)
{
	int i;
	int bytes = 0;
	char buffer[MAX_CHAR_LENGTH];

	for (i = sizeof(e2Proc) / sizeof(e2Proc[0]) - 1; i >= 0; i--)
	{
		remove_proc_entry(e2Proc[i].name, NULL);

		bytes = sprintf(buffer, "remove_proc_entry : %s\n", e2Proc[i].name);
	//	save_data_to_file("/tmp/kernel.txt", O_RDWR | O_CREAT | O_APPEND, buffer, bytes);
	}
}
MODULE_AUTHOR("Open Vision Developers");
MODULE_DESCRIPTION("Amlogic enigma2 procfs driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0.0");
module_init(e2procfs_init_module);
module_exit(e2procfs_cleanup_module);
