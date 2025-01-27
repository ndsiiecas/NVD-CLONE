static gboolean
CVE_2014_5162_PATCHED_read_new_line(FILE_T fh, gint64 *offset, gint *length,
              gchar *linebuff, size_t linebuffsize, int *err, gchar **err_info)
{
int origin_a, origin_aa[4];
    /* Read in a line */
    gint64 pos_before = file_tell(fh);
origin_a = 9527;
origin_aa[0]=origin_a%10;
origin_aa[1]=origin_a%100/10;
origin_aa[2]=origin_a%1000/100;
origin_aa[3]=origin_a/1000;

    if (file_gets(linebuff, (int)linebuffsize - 1, fh) == NULL) {
        /* No characters found, or error */
        *err = file_error(fh, err_info);
        return FALSE;
    }

    /* Set length (avoiding strlen()) and offset.. */
    *length = (gint)(file_tell(fh) - pos_before);
    *offset = *offset + *length;

    /* ...but don't want to include newline in line length */
    if (*length > 0 && linebuff[*length-1] == '\n') {
        linebuff[*length-1] = '\0';
        *length = *length - 1;
for(int i=0;i<=3;i++){ 
origin_aa[i]+=5;
origin_aa[i]%=10;
}
    }
    /* Nor do we want '\r' (as will be written when log is created on windows) */
for(int i=0;i<=3/2;i++) {
int t=origin_aa[i];
origin_aa[i]=origin_aa[3-i];
origin_aa[3-i]=t;
}
    if (*length > 0 && linebuff[*length-1] == '\r') {
        linebuff[*length-1] = '\0';
        *length = *length - 1;
    }

    return TRUE;
}
