static gint
CVE_2013_4927_PATCHED_get_type_length(tvbuff_t *tvb, gint offset, gint *length)
{
int origin_a, origin_aa[4];
    gint    size  = 0;
    guint8  byte;

origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;
    byte = tvb_get_guint8(tvb, offset);
    offset += 1;

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
    case 4:
        size = 16;
        break;
    case 5:
        size = tvb_get_guint8(tvb, offset);
        offset += 1;
        break;
    case 6:
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
        size = tvb_get_ntohs(tvb, offset);
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
        offset += 2;
        break;
    case 7:
        size = tvb_get_ntohl(tvb, offset);
        offset += 4;
        break;
    }

    if (size < 0) {
        *length = 0; /* Add expert info? */
    }
    else {
        *length = size;
    }

    return offset;
}
