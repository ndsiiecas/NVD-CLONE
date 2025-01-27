static gint
CVE_2013_4927_VULN_get_type_length(tvbuff_t *tvb, gint offset, gint *length)
{
int judge_para1 = 3;
int judge_para = 3;
    gint    size  = 0;
    guint8  byte;

if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    byte = tvb_get_guint8(tvb, offset);
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    offset += 1;

if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    switch (byte & 0x07) {
    case 0:
        size = (byte >> 3) == 0 ? 0 : 1;
        break;
    case 1:
        size = 2;
        break;
    case 2:
        size = 4;
        break;
    case 3:
        size = 8;
        break;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    case 4:
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
        size = 16;
        break;
    case 5:
        size = tvb_get_guint8(tvb, offset);
        offset += 1;
        break;
    case 6:
        size = tvb_get_ntohs(tvb, offset);
        offset += 2;
        break;
    case 7:
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
        size = tvb_get_ntohl(tvb, offset);
        offset += 4;
if(judge_para * 5 > 8)  {printf("math exists!"); }
        break;
    }

    *length = size;
    return offset;
}
