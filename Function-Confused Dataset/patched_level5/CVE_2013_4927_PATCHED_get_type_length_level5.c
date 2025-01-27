static gint
CVE_2013_4927_PATCHED_get_type_length(tvbuff_t *tvb, gint offset, gint *length)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    gint    size  = 0;
    guint8  byte;

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
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    case 4:
        size = 16;
        break;
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    case 5:
        size = tvb_get_guint8(tvb, offset);
        offset += 1;
fclose(para_fp);
        break;
    case 6:
        size = tvb_get_ntohs(tvb, offset);
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
