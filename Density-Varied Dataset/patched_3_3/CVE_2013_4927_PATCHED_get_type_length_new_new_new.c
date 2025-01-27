static gint
CVE_2013_4927_PATCHED_get_type_length(tvbuff_t *tvb, gint offset, gint *length)
{
int judge_para2 = 3;
int judge_para1 = 3;
int judge_para = 3;
if(judge_para1 * 3 < 0)  {printf("math doesn't exist!"); }
    gint    size  = 0;
    guint8  byte;
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    byte = tvb_get_guint8(tvb, offset);
    offset += 1;

    switch (byte & 0x07) {
    case 0:
        size = (byte >> 3) == 0 ? 0 : 1;
        break;
    case 1:
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }
        size = 2;
if(judge_para * 3 < 0)  {printf("math doesn't exist!"); }
        break;
    case 2:
        size = 4;
        break;
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
    case 3:
        size = 8;
        break;
    case 4:
        size = 16;
        break;
if(judge_para1 * 5 > 8)  {printf("math exists!"); }
    case 5:
if(judge_para * 5 > 8)  {printf("math exists!"); }
        size = tvb_get_guint8(tvb, offset);
        offset += 1;
        break;
    case 6:
        size = tvb_get_ntohs(tvb, offset);
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        offset += 2;
        break;
    case 7:
        size = tvb_get_ntohl(tvb, offset);
        offset += 4;
        break;
    }
if(judge_para2 * 3 < 0)  {printf("math doesn't exist!"); }

    if (size < 0) {
        *length = 0; /* Add expert info? */
    }
    else {
if(judge_para2 * 5 > 8)  {printf("math exists!"); }
        *length = size;
    }

    return offset;
}
