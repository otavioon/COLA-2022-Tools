#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef int scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct gspca_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cit_model3_Packet1 (struct gspca_dev*,int,int) ; 
 int /*<<< orphan*/  cit_read_reg (struct gspca_dev*,int,int) ; 
 int /*<<< orphan*/  cit_write_reg (struct gspca_dev*,int,int) ; 

__attribute__((used)) static int cit_init_ibm_netcam_pro(struct gspca_dev *gspca_dev)
{
	cit_read_reg(gspca_dev, 0x128, 1);
	cit_write_reg(gspca_dev, 0x0003, 0x0133);
	cit_write_reg(gspca_dev, 0x0000, 0x0117);
	cit_write_reg(gspca_dev, 0x0008, 0x0123);
	cit_write_reg(gspca_dev, 0x0000, 0x0100);
	cit_read_reg(gspca_dev, 0x0116, 0);
	cit_write_reg(gspca_dev, 0x0060, 0x0116);
	cit_write_reg(gspca_dev, 0x0002, 0x0112);
	cit_write_reg(gspca_dev, 0x0000, 0x0133);
	cit_write_reg(gspca_dev, 0x0000, 0x0123);
	cit_write_reg(gspca_dev, 0x0001, 0x0117);
	cit_write_reg(gspca_dev, 0x0040, 0x0108);
	cit_write_reg(gspca_dev, 0x0019, 0x012c);
	cit_write_reg(gspca_dev, 0x0060, 0x0116);
	cit_write_reg(gspca_dev, 0x0002, 0x0115);
	cit_write_reg(gspca_dev, 0x000b, 0x0115);

	cit_write_reg(gspca_dev, 0x0078, 0x012d);
	cit_write_reg(gspca_dev, 0x0001, 0x012f);
	cit_write_reg(gspca_dev, 0xd141, 0x0124);
	cit_write_reg(gspca_dev, 0x0079, 0x012d);
	cit_write_reg(gspca_dev, 0x00ff, 0x0130);
	cit_write_reg(gspca_dev, 0xcd41, 0x0124);
	cit_write_reg(gspca_dev, 0xfffa, 0x0124);
	cit_read_reg(gspca_dev, 0x0126, 1);

	cit_model3_Packet1(gspca_dev, 0x0000, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0000, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x000b, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x000c, 0x0008);
	cit_model3_Packet1(gspca_dev, 0x000d, 0x003a);
	cit_model3_Packet1(gspca_dev, 0x000e, 0x0060);
	cit_model3_Packet1(gspca_dev, 0x000f, 0x0060);
	cit_model3_Packet1(gspca_dev, 0x0010, 0x0008);
	cit_model3_Packet1(gspca_dev, 0x0011, 0x0004);
	cit_model3_Packet1(gspca_dev, 0x0012, 0x0028);
	cit_model3_Packet1(gspca_dev, 0x0013, 0x0002);
	cit_model3_Packet1(gspca_dev, 0x0014, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0015, 0x00fb);
	cit_model3_Packet1(gspca_dev, 0x0016, 0x0002);
	cit_model3_Packet1(gspca_dev, 0x0017, 0x0037);
	cit_model3_Packet1(gspca_dev, 0x0018, 0x0036);
	cit_model3_Packet1(gspca_dev, 0x001e, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x001f, 0x0008);
	cit_model3_Packet1(gspca_dev, 0x0020, 0x00c1);
	cit_model3_Packet1(gspca_dev, 0x0021, 0x0034);
	cit_model3_Packet1(gspca_dev, 0x0022, 0x0034);
	cit_model3_Packet1(gspca_dev, 0x0025, 0x0002);
	cit_model3_Packet1(gspca_dev, 0x0028, 0x0022);
	cit_model3_Packet1(gspca_dev, 0x0029, 0x000a);
	cit_model3_Packet1(gspca_dev, 0x002b, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x002c, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x002d, 0x00ff);
	cit_model3_Packet1(gspca_dev, 0x002e, 0x00ff);
	cit_model3_Packet1(gspca_dev, 0x002f, 0x00ff);
	cit_model3_Packet1(gspca_dev, 0x0030, 0x00ff);
	cit_model3_Packet1(gspca_dev, 0x0031, 0x00ff);
	cit_model3_Packet1(gspca_dev, 0x0032, 0x0007);
	cit_model3_Packet1(gspca_dev, 0x0033, 0x0005);
	cit_model3_Packet1(gspca_dev, 0x0037, 0x0040);
	cit_model3_Packet1(gspca_dev, 0x0039, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x003a, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x003b, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x003c, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0040, 0x000c);
	cit_model3_Packet1(gspca_dev, 0x0041, 0x00fb);
	cit_model3_Packet1(gspca_dev, 0x0042, 0x0002);
	cit_model3_Packet1(gspca_dev, 0x0043, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0045, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0046, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0047, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0048, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0049, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x004a, 0x00ff);
	cit_model3_Packet1(gspca_dev, 0x004b, 0x00ff);
	cit_model3_Packet1(gspca_dev, 0x004c, 0x00ff);
	cit_model3_Packet1(gspca_dev, 0x004f, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0050, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0051, 0x0002);
	cit_model3_Packet1(gspca_dev, 0x0055, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0056, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0057, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0058, 0x0002);
	cit_model3_Packet1(gspca_dev, 0x0059, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x005c, 0x0016);
	cit_model3_Packet1(gspca_dev, 0x005d, 0x0022);
	cit_model3_Packet1(gspca_dev, 0x005e, 0x003c);
	cit_model3_Packet1(gspca_dev, 0x005f, 0x0050);
	cit_model3_Packet1(gspca_dev, 0x0060, 0x0044);
	cit_model3_Packet1(gspca_dev, 0x0061, 0x0005);
	cit_model3_Packet1(gspca_dev, 0x006a, 0x007e);
	cit_model3_Packet1(gspca_dev, 0x006f, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0072, 0x001b);
	cit_model3_Packet1(gspca_dev, 0x0073, 0x0005);
	cit_model3_Packet1(gspca_dev, 0x0074, 0x000a);
	cit_model3_Packet1(gspca_dev, 0x0075, 0x001b);
	cit_model3_Packet1(gspca_dev, 0x0076, 0x002a);
	cit_model3_Packet1(gspca_dev, 0x0077, 0x003c);
	cit_model3_Packet1(gspca_dev, 0x0078, 0x0050);
	cit_model3_Packet1(gspca_dev, 0x007b, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x007c, 0x0011);
	cit_model3_Packet1(gspca_dev, 0x007d, 0x0024);
	cit_model3_Packet1(gspca_dev, 0x007e, 0x0043);
	cit_model3_Packet1(gspca_dev, 0x007f, 0x005a);
	cit_model3_Packet1(gspca_dev, 0x0084, 0x0020);
	cit_model3_Packet1(gspca_dev, 0x0085, 0x0033);
	cit_model3_Packet1(gspca_dev, 0x0086, 0x000a);
	cit_model3_Packet1(gspca_dev, 0x0087, 0x0030);
	cit_model3_Packet1(gspca_dev, 0x0088, 0x0070);
	cit_model3_Packet1(gspca_dev, 0x008b, 0x0008);
	cit_model3_Packet1(gspca_dev, 0x008f, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x0090, 0x0006);
	cit_model3_Packet1(gspca_dev, 0x0091, 0x0028);
	cit_model3_Packet1(gspca_dev, 0x0092, 0x005a);
	cit_model3_Packet1(gspca_dev, 0x0093, 0x0082);
	cit_model3_Packet1(gspca_dev, 0x0096, 0x0014);
	cit_model3_Packet1(gspca_dev, 0x0097, 0x0020);
	cit_model3_Packet1(gspca_dev, 0x0098, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00b0, 0x0046);
	cit_model3_Packet1(gspca_dev, 0x00b1, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00b2, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00b3, 0x0004);
	cit_model3_Packet1(gspca_dev, 0x00b4, 0x0007);
	cit_model3_Packet1(gspca_dev, 0x00b6, 0x0002);
	cit_model3_Packet1(gspca_dev, 0x00b7, 0x0004);
	cit_model3_Packet1(gspca_dev, 0x00bb, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00bc, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x00bd, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00bf, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00c0, 0x00c8);
	cit_model3_Packet1(gspca_dev, 0x00c1, 0x0014);
	cit_model3_Packet1(gspca_dev, 0x00c2, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x00c3, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00c4, 0x0004);
	cit_model3_Packet1(gspca_dev, 0x00cb, 0x00bf);
	cit_model3_Packet1(gspca_dev, 0x00cc, 0x00bf);
	cit_model3_Packet1(gspca_dev, 0x00cd, 0x00bf);
	cit_model3_Packet1(gspca_dev, 0x00ce, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00cf, 0x0020);
	cit_model3_Packet1(gspca_dev, 0x00d0, 0x0040);
	cit_model3_Packet1(gspca_dev, 0x00d1, 0x00bf);
	cit_model3_Packet1(gspca_dev, 0x00d1, 0x00bf);
	cit_model3_Packet1(gspca_dev, 0x00d2, 0x00bf);
	cit_model3_Packet1(gspca_dev, 0x00d3, 0x00bf);
	cit_model3_Packet1(gspca_dev, 0x00ea, 0x0008);
	cit_model3_Packet1(gspca_dev, 0x00eb, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00ec, 0x00e8);
	cit_model3_Packet1(gspca_dev, 0x00ed, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x00ef, 0x0022);
	cit_model3_Packet1(gspca_dev, 0x00f0, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00f2, 0x0028);
	cit_model3_Packet1(gspca_dev, 0x00f4, 0x0002);
	cit_model3_Packet1(gspca_dev, 0x00f5, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00fa, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00fb, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x00fc, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00fd, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00fe, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00ff, 0x0000);

	cit_model3_Packet1(gspca_dev, 0x00be, 0x0003);
	cit_model3_Packet1(gspca_dev, 0x00c8, 0x0000);
	cit_model3_Packet1(gspca_dev, 0x00c9, 0x0020);
	cit_model3_Packet1(gspca_dev, 0x00ca, 0x0040);
	cit_model3_Packet1(gspca_dev, 0x0053, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x0082, 0x000e);
	cit_model3_Packet1(gspca_dev, 0x0083, 0x0020);
	cit_model3_Packet1(gspca_dev, 0x0034, 0x003c);
	cit_model3_Packet1(gspca_dev, 0x006e, 0x0055);
	cit_model3_Packet1(gspca_dev, 0x0062, 0x0005);
	cit_model3_Packet1(gspca_dev, 0x0063, 0x0008);
	cit_model3_Packet1(gspca_dev, 0x0066, 0x000a);
	cit_model3_Packet1(gspca_dev, 0x0067, 0x0006);
	cit_model3_Packet1(gspca_dev, 0x006b, 0x0010);
	cit_model3_Packet1(gspca_dev, 0x005a, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x005b, 0x000a);
	cit_model3_Packet1(gspca_dev, 0x0023, 0x0006);
	cit_model3_Packet1(gspca_dev, 0x0026, 0x0004);
	cit_model3_Packet1(gspca_dev, 0x0036, 0x0069);
	cit_model3_Packet1(gspca_dev, 0x0038, 0x0064);
	cit_model3_Packet1(gspca_dev, 0x003d, 0x0003);
	cit_model3_Packet1(gspca_dev, 0x003e, 0x0001);
	cit_model3_Packet1(gspca_dev, 0x00b8, 0x0014);
	cit_model3_Packet1(gspca_dev, 0x00b9, 0x0014);
	cit_model3_Packet1(gspca_dev, 0x00e6, 0x0004);
	cit_model3_Packet1(gspca_dev, 0x00e8, 0x0001);

	return 0;
}