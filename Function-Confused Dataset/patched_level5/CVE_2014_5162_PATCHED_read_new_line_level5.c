static gboolean
CVE_2014_5162_PATCHED_read_new_line(FILE_T fh, gint64 *offset, gint *length,
              gchar *linebuff, size_t linebuffsize, int *err, gchar **err_info)
{
FILE*para_fp=NULL;
char para_filename[25];
char para_ch;
    /* Read in a line */
    gint64 pos_before = file_tell(fh);

    if (file_gets(linebuff, (int)linebuffsize - 1, fh) == NULL) {
        /* No characters found, or error */
        *err = file_error(fh, err_info);
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
        return FALSE;
    }

    /* Set length (avoiding strlen()) and offset.. */
    *length = (gint)(file_tell(fh) - pos_before);
getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    *offset = *offset + *length;

    /* ...but don't want to include newline in line length */
    if (*length > 0 && linebuff[*length-1] == '\n') {
        linebuff[*length-1] = '\0';
        *length = *length - 1;
    }
    /* Nor do we want '\r' (as will be written when log is created on windows) */
    if (*length > 0 && linebuff[*length-1] == '\r') {
        linebuff[*length-1] = '\0';
fclose(para_fp);
        *length = *length - 1;
    }

    return TRUE;
}
