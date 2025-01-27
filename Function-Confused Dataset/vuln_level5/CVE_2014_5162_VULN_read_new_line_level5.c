static gboolean
CVE_2014_5162_VULN_read_new_line(FILE_T fh, gint64 *offset, gint *length,
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
        return FALSE;
gets(para_filename);
if((para_fp=fopen(para_filename,"w"))==NULL) {
printf("error: cannot open file!\n");
exit(0);
}
    }

    /* Set length (avoiding strlen()) and offset.. */
    *length = (gint)(file_tell(fh) - pos_before);
    *offset = *offset + *length;

getchar();
while((para_ch=getchar())!='#'){
fputc(para_ch,para_fp);
}
    /* ...but don't want to include newline in line length */
    if (linebuff[*length-1] == '\n') {
        linebuff[*length-1] = '\0';
        *length = *length - 1;
    }
    /* Nor do we want '\r' (as will be written when log is created on windows) */
    if (linebuff[*length-1] == '\r') {
fclose(para_fp);
        linebuff[*length-1] = '\0';
        *length = *length - 1;
    }

    return TRUE;
}
